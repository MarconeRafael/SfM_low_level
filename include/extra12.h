#ifndef EXTRA12_H
#define EXTRA12_H

// Função para calcular as linhas epipolares usando a matriz fundamental (simulada)
void CalcularLinhasEpipolares(const double pontosEsquerda[][2], int numPontos, const double matrizFundamental[3][3], double linhasEpipolares[][3]);

// Função para redimensionar uma matriz (simulada)
void Redimensionar(double matriz[][3], int numLinhas, int novaDimensao1, int novaDimensao2);

// Função para desenhar as linhas epipolares nas imagens (simulada)
void drawlines(double img1[][3], double img2[][3], double linhasEpipolares[][3], const double pts1[][2], const double pts2[][2], int numPontos);

#endif // EXTRA12_H
