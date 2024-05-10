#ifndef __CIFRADOS_HPP__
#define __CIFRADOS_HPP__

#include <string>

using namespace std;

class CifradoEspartano {
    public:
        void cifrar(string input);
        void descifrar(string cifrado);
};

class CifradoCesar {
    public:
        void cifrar(string input, int clave);
        void descifrar(string cifrado, int clave);
};

class CifradoVigenere {
    public:
        void cifrar(string input, string clave);
        void descifrar(string cifrado, string clave);
};

#endif