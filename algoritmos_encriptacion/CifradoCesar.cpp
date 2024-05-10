#include <iostream>
#include "Cifrados.hpp"
#include <cctype>

using namespace std;

void CifradoCesar::cifrar(string input, int clave){
    //Generar un arreglo con las letras del abecedario
    char abecedario[26];
    for(int i = 0; i < 26; i++){
        abecedario[i] = 'a' + i;
    }

    //Generar el mensaje cifrado
    string cifrado = "";
    for(int i = 0; i < input.length(); i++){
        if(!isalpha(input[i])){
            cifrado += input[i];
            continue;
        }

        for(int j = 0; j < 26; j++){
            if(tolower(input[i]) == abecedario[j]){
                cifrado += abecedario[(j + clave) % 26];
                break;
            }
        }
    }

    //Imprimir input y mensaje cifrado
    cout << "\nMensaje original: ";
    for(int i = 0; i < input.length(); i++){
        cout << "[" << input[i] << "] ";
    }
    cout << "\nMensaje cifrado: ";
    for(int i = 0; i < cifrado.length(); i++){
        cout << "[" << cifrado[i] << "] ";
    }

    cout << "\n\nEl mensaje cifrado en cifrado cesar es: " << cifrado << "\n";
}

void CifradoCesar::descifrar(string cifrado, int clave){
    //Generar un arreglo con las letras del abecedario
    char abecedario[26];
    for(int i = 0; i < 26; i++){
        abecedario[i] = 'a' + i;
    }

    //Generar el mensaje descifrado
    string mensaje = "";
    for(int i = 0; i < cifrado.length(); i++){
        if(!isalpha(cifrado[i])){
            mensaje += cifrado[i];
            continue;
        }

        for(int j = 0; j < 26; j++){
            if(tolower(cifrado[i]) == abecedario[j]){
                mensaje += abecedario[(j - clave + 26) % 26];
                break;
            }
        }
    }

    //Imprimir input y mensaje cifrado
    cout << "\nMensaje cifrado: ";
    for(int i = 0; i < cifrado.length(); i++){
        cout << "[" << cifrado[i] << "] ";
    }
    cout << "\nMensaje original: ";
    for(int i = 0; i < mensaje.length(); i++){
        cout << "[" << mensaje[i] << "] ";
    }

    cout << "\n\nEl mensaje descifrado en cifrado cesar es: " << mensaje << "\n";
}