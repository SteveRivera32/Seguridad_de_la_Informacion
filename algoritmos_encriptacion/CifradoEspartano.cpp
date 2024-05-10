#include <iostream>
#include "Cifrados.hpp"

using namespace std;
int filas = 6; //cantidad de filas de la escítala

void CifradoEspartano::cifrar(string input){
    //crear matriz que represente la escítala
    int columnas = 1;
    if(input.length() > filas){
        if(input.length() % filas == 0){
            columnas = input.length() / filas;
        } else {
            columnas += (input.length() / filas);
        }
    }
    char escitala[columnas][filas];

    //Rellenar la matriz con espacios
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            escitala[i][j] = ' ';
        }
    }

    //Escribir el mensaje en una matriz recorriendo de columna en columna
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            if(i*filas + j >= input.length()){
                escitala[i][j] = ' ';
            } else {
                escitala[i][j] = input[i*filas + j];
            }
        }
    }

    //Generar el mensaje cifrado leyendo de fila en fila
    string cifrado = "";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cifrado += escitala[j][i];
        }
    }

    //Imprimir matriz
    cout << "\nLa escitala es de " << filas << " filas y " << columnas << " columnas:\n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "[" << escitala[j][i] << "] ";
        }
        cout << "\n";
    }

    cout << "\nEl mensaje cifrado en cifrado espartano es: " << cifrado << "\n";
}

void CifradoEspartano::descifrar(string cifrado){
    //crear matriz que represente la escítala
    int columnas = 1; //las columnas se calculan dependiendo la longitud de la frase a cifrar
    if(cifrado.length() > filas){
        if(cifrado.length() % filas == 0){
            columnas = cifrado.length() / filas;
        } else {
            columnas += (cifrado.length() / filas);
        }
    }
    char escitala[columnas][filas];

    //Rellenar la matriz con espacios
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            escitala[i][j] = ' ';
        }
    }

    //Escribir el mensaje en una matriz recorriendo de fila en fila
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            if(i*columnas + j >= cifrado.length()){
                escitala[j][i] = ' ';
            } else {
                escitala[j][i] = cifrado[i*columnas + j];
            }
        }
    }

    //Generar el mensaje cifrado leyendo de columna en columna
    string mensaje = "";
    for(int i = 0; i < columnas; i++){
        for(int j = 0; j < filas; j++){
            mensaje += escitala[i][j];
        }
    }

    //Imprimir matriz
    cout << "\nLa matriz es: \n";
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << "[" << escitala[j][i] << "] ";
        }
        cout << "\n";
    }

    cout << "\nEl mensaje descifrado en cifrado espartano es: " << mensaje << "\n";
}