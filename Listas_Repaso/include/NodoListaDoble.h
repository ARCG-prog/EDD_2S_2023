#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H
#include <string>

using namespace std;

class NodoListaDoble
{
    public:
        std::string Codigo;
        std::string Nombre;
        NodoListaDoble *Siguiente;
        NodoListaDoble *Anterior;
        NodoListaDoble(std::string codigo, std::string nombre);
        virtual ~NodoListaDoble();

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
