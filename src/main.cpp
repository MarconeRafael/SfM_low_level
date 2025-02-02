#include <iostream>
#include <vector>
#include <map>
#include "keypoints2.h"       // Arquivo de cabeçalho para funções de keypoints
#include "kd_trees3.h"        // Arquivo de cabeçalho para o FLANN Matcher
#include "distancia4.h"       // Arquivo de cabeçalho para KNN e correspondências
#include "filtro5.h"          // Arquivo de cabeçalho para teste da razão
#include "lmeds6.h"           // Arquivo de cabeçalho para matriz fundamental
#include "linhas7.h"          // Arquivo de cabeçalho para desenhar linhas epipolares
#include "utils8.h"           // Arquivo de cabeçalho para desenhar linhas
#include "epipolares9.h"      // Arquivo de cabeçalho para linhas epipolares
#include "verifica_img_empy1.h" // Arquivo de cabeçalho para verificar imagens
#include "ler_img0s.h"        // Arquivo de cabeçalho para carregar imagens

int main() {
    int largura, altura;

    // Carregar as imagens esquerda e direita em escala de cinza
    unsigned char* imgLeft = LerImagemEmEscalaDeCinza("image_l.png", largura, altura);
    unsigned char* imgRight = LerImagemEmEscalaDeCinza("image_r.png", largura, altura);

    if (imgLeft != nullptr && imgRight != nullptr) {
        std::cout << "Imagens carregadas com sucesso em escala de cinza!" << std::endl;

        // Detectar keypoints e calcular descritores nas imagens esquerda e direita
        std::vector<Keypoint> keyPointsLeft, keyPointsRight;
        std::vector<std::vector<float>> descriptorsLeft, descriptorsRight;
        DetectarKeypointsEComputarDescritores(imgLeft, largura, altura, keyPointsLeft, descriptorsLeft);
        DetectarKeypointsEComputarDescritores(imgRight, largura, altura, keyPointsRight, descriptorsRight);

        std::cout << "Número de keypoints detectados na imagem esquerda: " << keyPointsLeft.size() << std::endl;
        std::cout << "Número de keypoints detectados na imagem direita: " << keyPointsRight.size() << std::endl;

        // Encontrar correspondências entre os descritores das imagens esquerda e direita
        std::vector<std::vector<std::pair<float, Descriptor>>> matches = KNNMatch(descriptorsLeft, descriptorsRight, 2);

        for (size_t i = 0; i < matches.size(); ++i) {
            std::cout << "Correspondências para o descritor " << i + 1 << " da imagem esquerda:\n";
            for (const auto& match : matches[i]) {
                std::cout << "Distância: " << match.first << " - Descritor: (" << match.second.x << ", " << match.second.y << ")\n";
            }
        }

        // Aplicar o teste da razão (Lowe’s ratio test)
        Match matchesArray[5] = {
            {0, 0, 0.2}, {1, 1, 0.4}, {2, 2, 0.1}, {3, 3, 0.5}, {4, 4, 0.3}
        };
        Keypoint keyPointsLeftArray[5] = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {4.0, 4.0}};
        Keypoint keyPointsRightArray[5] = {{0.1, 0.1}, {1.1, 1.1}, {2.1, 2.1}, {3.1, 3.1}, {4.1, 4.1}};
        AplicarTesteRazao(matchesArray, 5, keyPointsLeftArray, keyPointsRightArray);

        // Exemplo de pontos correspondentes nas imagens esquerda e direita
        std::vector<std::pair<float, float>> ptsLeft = {{10.5, 20.5}, {30.2, 40.8}, {50.7, 60.3}, {70.5, 80.1}};
        std::vector<std::pair<float, float>> ptsRight = {{11.0, 21.0}, {31.0, 41.0}, {51.0, 61.0}, {71.0, 81.0}};
        auto ptsLeftInteiros = ConverterParaInteiros(ptsLeft);
        auto ptsRightInteiros = ConverterParaInteiros(ptsRight);
        auto [F, mask] = CalcularMatrizFundamental(ptsLeftInteiros, ptsRightInteiros, "LMEDS");

        std::vector<std::pair<float, float>> ptsLeftInliers;
        std::vector<std::pair<float, float>> ptsRightInliers;
        for (size_t i = 0; i < mask.size(); ++i) {
            if (mask[i] == 1) {
                ptsLeftInliers.push_back(ptsLeft[i]);
                ptsRightInliers.push_back(ptsRight[i]);
            }
        }

        // Atualizar as listas com os pontos inliers
        ptsLeft = ptsLeftInliers;
        ptsRight = ptsRightInliers;

        std::cout << "Pontos Inliers (Imagem Esquerda):\n";
        for (const auto& p : ptsLeft) {
            std::cout << "(" << p.first << ", " << p.second << ")\n";
        }

        std::cout << "Pontos Inliers (Imagem Direita):\n";
        for (const auto& p : ptsRight) {
            std::cout << "(" << p.first << ", " << p.second << ")\n";
        }

        // Redimensionar as linhas epipolares e desenhá-las
        double linhasEsquerda[3][3];  // Matriz para armazenar as linhas epipolares
        CalcularLinhasEpipolares(ptsRight, 3, F, linhasEsquerda);
        Redimensionar(linhasEsquerda, 3, 3, 3);
        DrawLines(0, 0, linhasEsquerda, ptsLeft, ptsRight);
    } else {
        std::cout << "Erro ao carregar as imagens!" << std::endl;
    }

    // Liberar memória
    delete[] imgLeft;
    delete[] imgRight;

    return 0;
}
