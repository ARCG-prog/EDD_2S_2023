#ifndef MATRIZ_H
#define MATRIZ_H
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>

#include "NodoMatriz.h"

using namespace std;

class Matriz
{
    public:
        NodoMatriz *Raiz;
        void InsertarElemento(int x, int y);
        void Graficar();
        Matriz();
        virtual ~Matriz();

    protected:

    private:
        NodoMatriz *buscarF(int y);
        NodoMatriz *buscarC(int x);
        NodoMatriz *nueva_columna(int x);
        NodoMatriz *nueva_fila(int y);
        NodoMatriz *insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila);
        NodoMatriz *insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna);
};

#endif // MATRIZ_H
