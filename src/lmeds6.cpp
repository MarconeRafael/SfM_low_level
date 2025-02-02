#include <iostream>
#include <vector>

// Função para converter pontos para coordenadas inteiras
std::vector<std::pair<int, int>> ConverterParaInteiros(const std::vector<std::pair<float, float>>& pontos) {
    std::vector<std::pair<int, int>> pontosInteiros;
    for (const auto& ponto : pontos) {
        pontosInteiros.push_back({static_cast<int>(ponto.first), static_cast<int>(ponto.second)});
    }
    return pontosInteiros;
}

// Função para calcular a matriz fundamental utilizando o método LMEDS (Least Median of Squares)
std::pair<std::vector<std::vector<float>>, std::vector<int>> CalcularMatrizFundamental(
    const std::vector<std::pair<int, int>>& ptsLeft,
    const std::vector<std::pair<int, int>>& ptsRight,
    const std::string& metodo
) {
    // Implementação simples do cálculo de uma matriz fundamental e da máscara de inliers
    std::vector<std::vector<float>> F = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};  // Exemplo de matriz fundamental fictícia
    std::vector<int> mask(ptsLeft.size(), 1);  // Máscara de inliers, inicialmente todos os pontos são inliers

    // Método LMEDS - exemplo fictício
    if (metodo == "LMEDS") {
        for (size_t i = 0; i < ptsLeft.size(); ++i) {
            // Aqui, você faria os cálculos reais para determinar quais pontos são inliers
            // Por exemplo, verificando a distância entre os pontos e a matriz fundamental
            if (i % 2 == 0) {
                mask[i] = 1;  // Inlier
            } else {
                mask[i] = 0;  // Outlier
            }
        }
    }

    return {F, mask};
}

int main() {
    // Exemplo de pontos correspondentes nas imagens esquerda e direita
    std::vector<std::pair<float, float>> ptsLeft = {{10.5, 20.5}, {30.2, 40.8}, {50.7, 60.3}, {70.5, 80.1}};
    std::vector<std::pair<float, float>> ptsRight = {{11.0, 21.0}, {31.0, 41.0}, {51.0, 61.0}, {71.0, 81.0}};

    // Converter para inteiros (coordenadas discretas)
    auto ptsLeftInteiros = ConverterParaInteiros(ptsLeft);
    auto ptsRightInteiros = ConverterParaInteiros(ptsRight);

    // Calcular a matriz fundamental usando LMEDS
    auto [F, mask] = CalcularMatrizFundamental(ptsLeftInteiros, ptsRightInteiros, "LMEDS");

    // Selecionar apenas os pontos inliers
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

    // Exibir resultados
    std::cout << "Pontos Inliers (Imagem Esquerda):\n";
    for (const auto& p : ptsLeft) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    std::cout << "Pontos Inliers (Imagem Direita):\n";
    for (const auto& p : ptsRight) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
