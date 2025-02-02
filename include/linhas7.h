#ifndef LINHAS6_H
#define LINHAS6_H

#include <vector>
#include <utility>

// Função para obter as dimensões de uma imagem
std::pair<int, int> ObterDimensões(const std::vector<std::vector<int>>& img);

// Função para converter imagem para formato colorido (simulação)
std::vector<std::vector<int>> ConverterParaColorido(const std::vector<std::vector<int>>& img);

// Função para gerar uma cor aleatória
std::vector<int> GerarCorAleatoria();

// Função para calcular o ponto de interseção de uma linha com as bordas
std::pair<int, int> CalcularPontoDeInterseção(int x, const std::vector<int>& linha);

// Função para desenhar uma linha
std::vector<std::vector<int>> DesenharLinha(std::vector<std::vector<int>>& img, std::pair<int, int> pt1, std::pair<int, int> pt2, const std::vector<int>& cor, int espessura);

// Função para desenhar um círculo
std::vector<std::vector<int>> DesenharCirculo(std::vector<std::vector<int>>& img, std::pair<int, int> centro, int raio, const std::vector<int>& cor, int espessura);

// Função principal para desenhar linhas e pontos de correspondência
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> drawlines(
    std::vector<std::vector<int>>& img1, 
    std::vector<std::vector<int>>& img2, 
    const std::vector<std::vector<int>>& linhas, 
    const std::vector<std::pair<int, int>>& pts1, 
    const std::vector<std::pair<int, int>>& pts2
);

#endif // LINHAS6_H
