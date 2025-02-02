#ifndef KEYPOINTS2_H
#define KEYPOINTS2_H

#include <vector>

// Estrutura para representar um keypoint
struct Keypoint {
    int x, y;
    float escala;
    float orientacao;
};

// Função para detectar bordas de maneira simplificada (exemplo: detecção de borda simples)
unsigned char* DetectarBordas(unsigned char* imagem, int largura, int altura);

// Função para criar uma estrutura de keypoint (simplificada)
Keypoint CriarKeypoint(int x, int y, float escala, float orientacao);

// Função para gerar descritores (simplificação)
std::vector<float> GerarDescritor(Keypoint keypoint, unsigned char* imagem, int largura, int altura);

// Função para detectar keypoints e calcular descritores (simulação)
void DetectarKeypointsEComputarDescritores(unsigned char* imagem, int largura, int altura, 
                                            std::vector<Keypoint>& keypoints, std::vector<std::vector<float>>& descritores);

#endif // KEYPOINTS2_H
