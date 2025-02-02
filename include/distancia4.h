#ifndef DISTANCIA4_H
#define DISTANCIA4_H

#include <vector>

// Estrutura para representar um descritor (simulação)
struct Descriptor {
    float x, y;  // Coordenadas do descritor (exemplo simples)
    float valor1, valor2;  // Valores que podem representar características do descritor
};

// Função para calcular a distância Euclidiana entre dois descritores manualmente (sem <cmath>)
float CalcularDistancia(const Descriptor& d1, const Descriptor& d2);

// Função para ordenar os vizinhos manualmente (sem <algorithm>)
void OrdenarVizinhos(std::vector<std::pair<float, Descriptor>>& vizinhos);

// Função para encontrar os K vizinhos mais próximos entre dois conjuntos de descritores
std::vector<std::vector<std::pair<float, Descriptor>>> KNNMatch(
    const std::vector<Descriptor>& descritores1,
    const std::vector<Descriptor>& descritores2,
    int k);

#endif // DISTANCIA4_H
