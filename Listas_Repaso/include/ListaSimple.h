#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H
#include "NodoListaSimple.h"
#include "ClasesAlumno.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


class ListaSimple
{
    public:
        NodoListaSimple *Primero;
        void InsertarCarnet(int carnet);
        void InsertarClase(int carnet, std::string clase);
        void graficar();
        void MostrarClases();
        int Tamanio;
        ListaSimple();
        virtual ~ListaSimple();

    protected:

    private:
        std::string textoGrafica();
        std::string textoGraficaClase();
};

#endif // LISTASIMPLE_H
