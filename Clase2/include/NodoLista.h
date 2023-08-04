#ifndef NODOLISTA_H
#define NODOLISTA_H

#include <string>
using namespace std;

class NodoLista
{
    public:
        std::string Nombre;
        std::string Codigo;
        NodoLista *Siguiente;
        NodoLista *Anterior;
        NodoLista(std::string codigo, std::string nombre);
        virtual ~NodoLista();

    protected:

    private:
};

#endif // NODOLISTA_H
