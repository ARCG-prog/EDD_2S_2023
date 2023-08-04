#ifndef LISTA_H
#define LISTA_H
#include "NodoLista.h"
#include <string>
#include <iostream>

using namespace std;

class Lista
{
    public:
        NodoLista *Primero;
        int Tamanio;
        void Insertar(std::string codigo, std::string nombre);
        void VerLista();
        int Sumar();
        Lista();
        virtual ~Lista();

    protected:

    private:
};

#endif // LISTA_H
