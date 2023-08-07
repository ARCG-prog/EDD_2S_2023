#ifndef NODOLISTASIMPLE_H
#define NODOLISTASIMPLE_H
#include <string>
#include "ClasesAlumno.h"


class NodoListaSimple
{
    public:
        int Carnet;
        ClasesAlumno *Clases;
        NodoListaSimple *Siguiente;
        NodoListaSimple(int carnet);
        virtual ~NodoListaSimple();

    protected:

    private:
};

#endif // NODOLISTASIMPLE_H
