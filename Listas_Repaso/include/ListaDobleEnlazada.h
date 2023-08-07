#ifndef LISTADOBLEENLAZADA_H
#define LISTADOBLEENLAZADA_H
#include "NodoListaDoble.h"

#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;


class ListaDobleEnlazada
{
    public:
        NodoListaDoble *Primero;
        NodoListaDoble *Ultimo;
        int Tamanio;
        void Insertar(std::string codigo, std::string nombre);
        void graficar();
        ListaDobleEnlazada();
        virtual ~ListaDobleEnlazada();

    protected:

    private:
        std::string g_circular(NodoListaDoble *&raiz, int tamanio);
};

#endif // LISTADOBLEENLAZADA_H
