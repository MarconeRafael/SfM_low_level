#ifndef LMEDS6_H
#define LMEDS6_H

#include <vector>
#include <utility>
#include <string>

// Função para converter pontos para coordenadas inteiras
std::vector<std::pair<int, int>> ConverterParaInteiros(const std::vector<std::pair<float, float>>& pontos);

// Função para calcular a matriz fundamental utilizando o método LMEDS (Least Median of Squares)
std::pair<std::vector<std::vector<float>>, std::vector<int>> CalcularMatrizFundamental(
    const std::vector<std::pair<int, int>>& ptsLeft,
    const std::vector<std::pair<int, int>>& ptsRight,
    const std::string& metodo
);

#endif // LMEDS6_H
