#ifndef KD_TREES3_H
#define KD_TREES3_H

#include <vector>
#include <map>

// Constantes para o índice do FLANN
const int FLANN_INDEX_KDTREE = 0;

// Estrutura de um ponto (simulando keypoints ou descritores)
struct Point {
    float x, y;
};

// Estrutura para representar o FLANN Matcher (simulada)
struct FLANNMatcher {
    std::vector<Point> index;  // Estrutura de indexação (KD-Tree simulada)
    int searchChecks;          // Número de verificações na busca

    // Função para buscar vizinhos mais próximos (simulação)
    std::vector<Point> BuscarVizinhos(const Point& query, int numVizinhos);
};

// Função para criar o índice KD-Tree (simulação)
std::vector<Point> CriarKDTree(int numArvores);

// Função para criar o FLANN Matcher
FLANNMatcher CriarFLANNMatcher(std::map<std::string, int> indexParams, std::map<std::string, int> searchParams);

#endif // KD_TREES3_H
