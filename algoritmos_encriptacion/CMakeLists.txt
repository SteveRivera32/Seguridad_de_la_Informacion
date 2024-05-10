cmake_minimum_required(VERSION 3.0)  # Versión mínima de CMake requerida
project(Encriptadores)  # Nombre del proyecto y lenguaje (C++)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_SOURCE_DIR})

# Agregar el ejecutable
add_executable(${PROJECT_NAME}
    Cifrados.hpp
    CifradoEspartano.cpp
    CifradoCesar.cpp
    CifradoVigenere.cpp
    main.cpp
 )