#include <iostream>
#include <fstream>

// Função para ler uma imagem binária e convertê-la para escala de cinza
unsigned char* LerImagemEmEscalaDeCinza(const char* caminhoImagem, int& largura, int& altura) {
    // Abrir o arquivo em modo binário
    std::ifstream arquivo(caminhoImagem, std::ios::binary);
    
    if (!arquivo) {
        std::cout << "Erro: Arquivo não encontrado!" << std::endl;
        return nullptr;
    }

    // Ler a imagem (apenas um exemplo simples, não se trata de um formato real de imagem)
    // Definindo a largura e a altura da imagem (em um caso real, seria necessário lidar com os cabeçalhos de imagem)
    largura = 100;  // Exemplo fixo para largura
    altura = 100;   // Exemplo fixo para altura
    
    // Alocação de memória para a matriz de pixels
    unsigned char* imagem = new unsigned char[largura * altura * 3]; // 3 bytes por pixel (RGB)

    // Ler os dados da imagem
    arquivo.read(reinterpret_cast<char*>(imagem), largura * altura * 3);

    // Fechar o arquivo
    arquivo.close();

    // Converter para escala de cinza
    unsigned char* matrizCinza = new unsigned char[largura * altura];
    for (int i = 0; i < largura * altura; ++i) {
        // Supondo uma conversão simples para escala de cinza (média dos valores RGB)
        unsigned char r = imagem[i * 3];     // R
        unsigned char g = imagem[i * 3 + 1]; // G
        unsigned char b = imagem[i * 3 + 2]; // B
        
        // Fórmula de conversão simples para escala de cinza
        matrizCinza[i] = static_cast<unsigned char>(0.3 * r + 0.59 * g + 0.11 * b);
    }

    // Liberar a memória da imagem original em RGB
    delete[] imagem;

    return matrizCinza;
}

int main() {
    int largura, altura;

    // Carregar as imagens esquerda e direita em escala de cinza
    unsigned char* imgLeft = LerImagemEmEscalaDeCinza("image_l.png", largura, altura);
    unsigned char* imgRight = LerImagemEmEscalaDeCinza("image_r.png", largura, altura);

    if (imgLeft != nullptr && imgRight != nullptr) {
        std::cout << "Imagens carregadas com sucesso em escala de cinza!" << std::endl;

        // Aqui você pode fazer algum processamento adicional com imgLeft e imgRight
    }

    // Liberar memória
    delete[] imgLeft;
    delete[] imgRight;

    return 0;
}
