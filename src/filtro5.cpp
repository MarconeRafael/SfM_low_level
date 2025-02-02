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
void AplicarTesteRazao(const Match matches[], int numMatches, Keypoint keyPointsLeft[], Keypoint keyPointsRight[]) {
    // Listas para armazenar as correspondências filtradas e pontos correspondentes
    Match goodMatches[100];  // Vamos limitar o número de boas correspondências a 100
    Keypoint ptsLeft[100];
    Keypoint ptsRight[100];

    int numGoodMatches = 0;

    // Para cada par de correspondências
    for (int i = 0; i < numMatches - 1; ++i) {
        // Pega a correspondência m e n
        Match m = matches[i];
        Match n = matches[i + 1];

        // Aplica o teste da razão (Lowe’s ratio test)
        if (m.distancia < 0.8 * n.distancia) {
            // Se passar no teste, adiciona à lista de boas correspondências
            goodMatches[numGoodMatches] = m;
            ptsLeft[numGoodMatches] = keyPointsLeft[m.indiceConsulta];
            ptsRight[numGoodMatches] = keyPointsRight[m.indiceTreinamento];

            // Incrementa o número de boas correspondências
            numGoodMatches++;
        }
    }

    // Exibe as boas correspondências
    std::cout << "Número de boas correspondências: " << numGoodMatches << std::endl;
    for (int i = 0; i < numGoodMatches; ++i) {
        std::cout << "Correspondência " << i + 1 << " - Ponto Esquerda: (" << ptsLeft[i].x << ", " << ptsLeft[i].y << ")"
                  << " - Ponto Direita: (" << ptsRight[i].x << ", " << ptsRight[i].y << ")" << std::endl;
    }
}

int main() {
    // Exemplo de matches e keypoints
    Match matches[5] = {
        {0, 0, 0.2}, {1, 1, 0.4}, {2, 2, 0.1}, {3, 3, 0.5}, {4, 4, 0.3}
    };
    Keypoint keyPointsLeft[5] = {{0.0, 0.0}, {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {4.0, 4.0}};
    Keypoint keyPointsRight[5] = {{0.1, 0.1}, {1.1, 1.1}, {2.1, 2.1}, {3.1, 3.1}, {4.1, 4.1}};

    // Aplicar o teste da razão (Lowe’s ratio test)
    AplicarTesteRazao(matches, 5, keyPointsLeft, keyPointsRight);

    return 0;
}
