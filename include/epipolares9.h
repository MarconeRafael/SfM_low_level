#ifndef EPIPOLARES9_H
#define EPIPOLARES9_H

// Função para calcular as linhas epipolares, considerando que F é a matriz fundamental
void CalcularLinhasEpipolares(const double ptsDireita[][2], int numPts, const double F[3][3], double linhasEsquerda[][3]);

// Função para redimensionar as linhas epipolares (ajustando o coeficiente 'c')
void Redimensionar(double linhasEsquerda[][3], int numLinhas, double fator);

// Função para gerar uma cor aleatória
void GerarCorAleatoria(int &r, int &g, int &b);

// Função para calcular o ponto de interseção de uma linha com a borda vertical
void CalcularPontoDeInterseção(double x, const double linha[3], double &x0, double &y0);

// Função para desenhar uma linha na imagem (simulada)
void DesenharLinha(int &imagem, double x0, double y0, double x1, double y1);

// Função para desenhar um círculo na imagem (simulada)
void DesenharCirculo(int &imagem, double x, double y, int raio);

// Função para desenhar as linhas epipolares nas imagens
void DrawLines(int &img1, int &img2, const double linhas[3][3], const double pts1[][2], const double pts2[][2], int numPts);

#endif // EPIPOLARES9_H
