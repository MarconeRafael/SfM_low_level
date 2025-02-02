# Definindo a versão mínima do CMake
cmake_minimum_required(VERSION 3.10)

# Definindo o nome do projeto
project(ComputerVisionProject)

# Definindo o padrão C++ a ser usado
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adicionando o diretório src e include ao caminho de inclusão
include_directories(src include)

# Adicionando todos os arquivos .cpp da pasta src ao projeto
file(GLOB SOURCES "src/*.cpp")

# Definindo o executável do projeto
add_executable(ComputerVisionApp ${SOURCES})

# Se precisar linkar com bibliotecas externas (por exemplo, OpenCV), descomente a linha abaixo
# find_package(OpenCV REQUIRED)
# target_link_libraries(ComputerVisionApp ${OpenCV_LIBS})
