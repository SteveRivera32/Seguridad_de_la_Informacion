#include <iostream>
#include <string>
#include "Cifrados.hpp"

using namespace std;

int main(){
    CifradoEspartano cifradoEspartano;
    CifradoCesar cifradoCesar;
    CifradoVigenere cifradoVigenere;

    string input, claveString;
    int opcion, tipoCifrado, claveNum;

    cout << "\n------------------OPCIONES DE ENCRIPTACION------------------"
        << "\n1. Cifrar"
        << "\n2. Descifrar"
        << "\nEscriba el numero de la opcion:";
    cin >> opcion;

    cin.ignore();

    cout << "\nInput: ";
    getline(cin, input);
    
    cout << "\n------------------ALGORITMOS------------------"
        << "\n1. Cifrado Espartano"
        << "\n2. Cifrado Cesar"
        << "\n3. Cifrado de Vigenere"
        << "\nEscriba el numero de la opcion: ";
    cin >> tipoCifrado;

    cin.ignore();

    switch(tipoCifrado){
        case 1:
            if(opcion == 1){
                cifradoEspartano.cifrar(input);
            } else if (opcion == 2){
                cifradoEspartano.descifrar(input);
            }
            break;
        case 2:
            if(opcion == 1){
                cout << "Ingrese la cantidad de movimientos hacia la derecha:";
                cin >> claveNum;
                cifradoCesar.cifrar(input, claveNum);
            } else if (opcion == 2){
                cout << "Ingrese la cantidad de movimientos hacia la izquierda:";
                cin >> claveNum;
                cifradoCesar.descifrar(input, claveNum);
            }
            break;
        case 3:
            cout << "Ingrese la clave a utilizar: ";
            getline(cin, claveString);
            if(opcion == 1){
                cifradoVigenere.cifrar(input, claveString);
            } else if (opcion == 2){
                cifradoVigenere.descifrar(input, claveString);
            }
            break;
        default:
            cout << "Opcion no valida\n";
            break;
    }

    return 0;
}