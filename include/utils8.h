#ifndef UTILS8_H
#define UTILS8_H

// Função para gerar um número aleatório entre min e max
int Aleatorio(int min, int max);

// Função para calcular o ponto de interseção de uma linha com a borda vertical
void CalcularPontoDeInterseção(double x, const double linha[3], double &x0, double &y0);

// Função para desenhar uma linha na imagem (simulada)
void DesenharLinha(int &imagem, double x0, double y0, double x1, double y1);

// Função para desenhar um círculo na imagem (simulada)
void DesenharCirculo(int &imagem, double x, double y, int raio);

// Função para gerar uma cor aleatória
void GerarCorAleatoria(int &r, int &g, int &b);

// Função para simular a execução de "drawlines" com duas imagens e pontos
void DrawLines(int &img1, int &img2, const double linhas[3], const double pts1[2], const double pts2[2]);

#endif // UTILS8_H
