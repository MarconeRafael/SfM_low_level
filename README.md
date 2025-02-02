
# Projeto de Visão Computacional

Este projeto implementa técnicas de visão computacional para correspondência de pontos entre duas imagens, utilizando operações como detecção de keypoints, correspondência de descritores, cálculo da matriz fundamental, e desenhando linhas epipolares.

## Funcionalidades

- **Carregamento de Imagens**: Carrega imagens em escala de cinza para processamento.
- **Detecção de Keypoints**: Detecta pontos de interesse nas imagens utilizando técnicas de visão computacional.
- **Correspondência de Descritores**: Encontra correspondências entre os descritores das imagens esquerda e direita usando KNN.
- **Teste da Razão (Lowe’s Ratio Test)**: Aplica o teste da razão para filtrar correspondências de baixa qualidade.
- **Cálculo da Matriz Fundamental**: Calcula a matriz fundamental usando o algoritmo LMEDS.
- **Linhas Epipolares**: Calcula e desenha linhas epipolares sobre as imagens.

## Requisitos

- **C++11**: O projeto utiliza o padrão C++11 ou superior.
- **CMake**: Sistema de build para compilar o projeto.
- **Bibliotecas Externas**: (Opcional) Caso deseje utilizar o OpenCV, você pode descomentar a parte do código no `CMakeLists.txt` para buscar e vincular o OpenCV.

### Dependências

Se você deseja usar bibliotecas externas como o OpenCV, instale-as antes de rodar o projeto. O código está configurado para buscar automaticamente as bibliotecas do OpenCV no `CMakeLists.txt`.

```bash
sudo apt-get install libopencv-dev  # Para sistemas baseados em Debian/Ubuntu
```

## Estrutura do Projeto

```
├── CMakeLists.txt        # Arquivo de configuração do CMake
├── src/                  # Código fonte (.cpp)
│   ├── keypoints2.cpp     # Funções para detectar keypoints e descritores
│   ├── kd_trees3.cpp      # Função para criação do FLANN Matcher
│   ├── distancia4.cpp     # Função para KNN e encontrar correspondências
│   ├── filtro5.cpp        # Função para aplicar o teste da razão
│   ├── lmeds6.cpp         # Função para calcular a matriz fundamental
│   ├── linhas7.cpp        # Função para desenhar linhas epipolares
│   ├── utils8.cpp         # Função para desenhar linhas em imagens
│   ├── epipolares9.cpp    # Função para calcular e desenhar linhas epipolares
│   ├── verifica_img_empy1.cpp  # Função para verificar se as imagens estão carregadas
│   └── ler_img0s.cpp      # Função para carregar as imagens
└── README.md             # Este arquivo
```

## Compilação e Execução

### Passo 1: Clonar o repositório

```bash
git clone https://github.com/seu-usuario/ComputerVisionProject.git
cd ComputerVisionProject
```

### Passo 2: Criar o diretório de build

```bash
mkdir build
cd build
```

### Passo 3: Rodar o CMake para configurar o projeto

```bash
cmake ..
```

### Passo 4: Compilar o projeto

```bash
make
```

### Passo 5: Executar o aplicativo

Após a compilação, você pode rodar o projeto executando o seguinte comando:

```bash
./ComputerVisionApp
```

## Exemplos de Entrada

O projeto espera duas imagens de entrada: `image_l.png` (imagem esquerda) e `image_r.png` (imagem direita). Certifique-se de que as imagens estejam na mesma pasta que o executável ou forneça o caminho completo para as imagens no código.

## Contribuição

Se você deseja contribuir com o projeto, por favor, siga as etapas abaixo:

1. Faça um fork do projeto.
2. Crie uma branch para a sua modificação (`git checkout -b feature/nova-funcionalidade`).
3. Faça as modificações necessárias e commit (`git commit -am 'Adicionando nova funcionalidade'`).
4. Faça o push para a sua branch (`git push origin feature/nova-funcionalidade`).
5. Abra um Pull Request para a branch `main`.

## Licença

Este projeto está licenciado sob a [MIT License](LICENSE).
