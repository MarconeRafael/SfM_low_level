#ifndef REDIMENSIONAR13_H
#define REDIMENSIONAR13_H

// Função para calcular as linhas epipolares utilizando a matriz fundamental
void CalcularLinhasEpipolares(double pontosEsquerda[][2], int numPontos, double matrizFundamental[3][3], double linhasEpipolares[][3]);

// Função para redimensionar uma matriz para novas dimensões
void Redimensionar(double matriz[][3], int numLinhas, int novaDimensao1, int novaDimensao2);

// Função para desenhar as linhas epipolares nas imagens (simulada)
void drawlines(double img1[][3], double img2[][3], double linhasEpipolares[][3], double pts1[][2], double pts2[][2], int numPontos);

#endif // REDIMENSIONAR13_H
