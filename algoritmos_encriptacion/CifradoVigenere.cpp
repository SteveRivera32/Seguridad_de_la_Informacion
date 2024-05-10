#include <iostream>
#include "Cifrados.hpp"

using namespace std;

void CifradoVigenere::cifrar(string input, string clave){
    //Arreglar clave
    for(int i = 0; i < clave.length(); i++){
        if(!isalpha(clave[i])){
            clave.erase(i, 1);
            i--;
            continue;
        }
        
        clave[i] = tolower(clave[i]);
    }
    
    //Generar un arreglo con las letras del abecedario
    char abecedario[26];
    for(int i = 0; i < 26; i++){
        abecedario[i] = 'a' + i;
    }
    
    //Generamos un string repitiendo la palabra clave hasta que sea del mismo tamaño que el input
    string oracionClave = "";
    for(int i = 0, j = 0; i < input.length(); i++){
        if(!isalpha(input[i])){
            oracionClave += ' ';
            continue;
        }

        oracionClave += clave[j % clave.length()];
        j++;
    }

    //Generamos el mensaje cifrado
    string cifrado = "";
    for(int i = 0; i < input.length(); i++){
        if(!isalpha(input[i])){
            cifrado += input[i];
            continue;
        }

        for(int j = 0; j < 26; j++){
            if(oracionClave[i] == abecedario[j]){
                cifrado += abecedario[(j + tolower(input[i]) - 'a') % 26];
                break;
            }
        }
    }

    //(j + tolower(input[i]) - 'a') % 26 = X
    //

    //Imprimir input, palabra clave y mensaje cifrado
    cout << "\nMensaje original: ";
    for(int i = 0; i < input.length(); i++){
        cout << "[" << input[i] << "] ";
    }
    cout << "\nOracion clave: ";
    for(int i = 0; i < input.length(); i++){
        cout << "[" << oracionClave[i] << "] ";
    }
    cout << "\nMensaje cifrado: ";
    for(int i = 0; i < input.length(); i++){
        cout << "[" << cifrado[i] << "] ";
    }

    cout << "\n\nEl mensaje cifrado en cifrado vigenere es: " << cifrado << "\n";
}

void CifradoVigenere::descifrar(string cifrado, string clave){
    //Arreglar clave
    for(int i = 0; i < clave.length(); i++){
        if(!isalpha(clave[i])){
            clave.erase(i, 1);
            i--;
            continue;
        }
        
        clave[i] = tolower(clave[i]);
    }

    //Generar un arreglo con las letras del abecedario
    char abecedario[26];
    for(int i = 0; i < 26; i++){
        abecedario[i] = 'a' + i;
    }

    //Generamos un string repitiendo la palabra clave hasta que sea del mismo tamaño que el input
    string oracionClave = "";
    for(int i = 0, j = 0; i < cifrado.length(); i++){
        if(!isalpha(cifrado[i])){
            oracionClave += ' ';
            continue;
        }

        oracionClave += clave[j % clave.length()];
        j++;
    }

    //Generamos el mensaje descifrado
    string mensaje = "";
    for(int i = 0; i < cifrado.length(); i++){
        if(!isalpha(cifrado[i])){
            mensaje += cifrado[i];
            continue;
        }

        for(int j = 0; j < 26; j++){
            if(tolower(cifrado[i]) == abecedario[j]){
                for(int f = 0; f < 26; f++){
                    if(oracionClave[i] == abecedario[f]){
                        mensaje += abecedario[(j - f + 26) % 26];
                        break;
                    }
                }
            }
        }
    }

    //Imprimir input, palabra clave y mensaje cifrado
    cout << "\nMensaje cifrado: ";
    for(int i = 0; i < cifrado.length(); i++){
        cout << "[" << cifrado[i] << "] ";
    }
    cout << "\nOracion clave: ";
    for(int i = 0; i < cifrado.length(); i++){
        cout << "[" << oracionClave[i] << "] ";
    }
    cout << "\nMensaje descifrado: ";
    for(int i = 0; i < cifrado.length(); i++){
        cout << "[" << mensaje[i] << "] ";
    }

    cout << "\n\nEl mensaje descifrado en cifrado vigenere es: " << mensaje << "\n";
}