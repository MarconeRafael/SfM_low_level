#include <iostream>
#include <vector>

// Estrutura para representar um descritor (simulação)
struct Descriptor {
    float x, y;  // Coordenadas do descritor (exemplo simples)
    float valor1, valor2;  // Valores que podem representar características do descritor
};

// Função para calcular a distância Euclidiana entre dois descritores manualmente (sem <cmath>)
float CalcularDistancia(const Descriptor& d1, const Descriptor& d2) {
    float dx = d1.x - d2.x;
    float dy = d1.y - d2.y;
    return dx * dx + dy * dy; // Retorna a distância ao quadrado (sem usar sqrt)
}

// Função para ordenar os vizinhos manualmente (sem <algorithm>)
void OrdenarVizinhos(std::vector<std::pair<float, Descriptor>>& vizinhos) {
    size_t n = vizinhos.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - 1 - i; ++j) {
            if (vizinhos[j].first > vizinhos[j + 1].first) {
                std::swap(vizinhos[j], vizinhos[j + 1]); // Troca manual dos elementos
            }
        }
    }
}

// Função para encontrar os K vizinhos mais próximos entre dois conjuntos de descritores
std::vector<std::vector<std::pair<float, Descriptor>>> KNNMatch(
    const std::vector<Descriptor>& descritores1,
    const std::vector<Descriptor>& descritores2,
    int k) {

    std::vector<std::vector<std::pair<float, Descriptor>>> correspondencias;

    // Para cada descritor na primeira imagem
    for (const auto& descritor1 : descritores1) {
        std::vector<std::pair<float, Descriptor>> vizinhos;

        // Para cada descritor na segunda imagem
        for (const auto& descritor2 : descritores2) {
            // Calcular a distância entre os descritores (distância Euclidiana)
            float distancia = CalcularDistancia(descritor1, descritor2);

            // Adicionar à lista de vizinhos (distância, descritor)
            vizinhos.push_back({distancia, descritor2});
        }

        // Ordenar vizinhos pela menor distância manualmente
        OrdenarVizinhos(vizinhos);

        // Selecionar os K vizinhos mais próximos
        std::vector<std::pair<float, Descriptor>> melhoresVizinhos;
        for (int i = 0; i < k; ++i) {
            melhoresVizinhos.push_back(vizinhos[i]);
        }

        // Adicionar ao conjunto final de correspondências
        correspondencias.push_back(melhoresVizinhos);
    }

    return correspondencias;
}

int main() {
    // Exemplo de descritores para as duas imagens
    std::vector<Descriptor> descriptorsLeft = {{0.0f, 0.0f, 1.0f, 2.0f}, {1.0f, 1.0f, 1.5f, 2.5f}};
    std::vector<Descriptor> descriptorsRight = {{0.1f, 0.1f, 1.1f, 2.1f}, {1.2f, 1.2f, 1.6f, 2.6f}, {0.9f, 0.9f, 1.4f, 2.4f}};

    // Encontrar correspondências entre os descritores das imagens esquerda e direita
    std::vector<std::vector<std::pair<float, Descriptor>>> matches = KNNMatch(descriptorsLeft, descriptorsRight, 2);

    // Exibir as correspondências encontradas
    for (size_t i = 0; i < matches.size(); ++i) {
        std::cout << "Correspondências para o descritor " << i + 1 << " da imagem esquerda:\n";
        for (const auto& match : matches[i]) {
            std::cout << "Distância: " << match.first << " - Descritor: (" << match.second.x << ", " << match.second.y << ")\n";
        }
    }

    return 0;
}
