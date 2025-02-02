#ifndef FILTRO5_H
#define FILTRO5_H

#include <iostream>

// Estrutura para representar um keypoint e seu ponto correspondente
struct Keypoint {
    float x, y;  // Coordenadas do keypoint
};

// Estrutura para representar uma correspondência (match)
struct Match {
    int indiceConsulta;      // Índice do keypoint na imagem esquerda
    int indiceTreinamento;   // Índice do keypoint na imagem direita
    float distancia;         // Distância entre os keypoints
};

// Função para aplicar o teste da razão de Lowe (Lowe's Ratio Test)
void AplicarTesteRazao(const Match matches[], int numMatches, Keypoint keyPointsLeft[], Keypoint keyPointsRight[]);

#endif // FILTRO5_H
