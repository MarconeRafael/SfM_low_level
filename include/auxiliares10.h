#ifndef AUXILIARES10_H
#define AUXILIARES10_H

// Função para calcular as linhas epipolares usando a matriz fundamental (simulada)
void CalcularLinhasEpipolares(const double pontosDireita[][2], int numPontos, const double matrizFundamental[3][3], double linhasEpipolares[][3]);

// Função para redimensionar uma matriz (simulada)
void Redimensionar(double matriz[][3], int numLinhas, int novaDimensao1, int novaDimensao2);

#endif // AUXILIARES10_H
