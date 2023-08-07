#include "NodoListaDoble.h"

NodoListaDoble::NodoListaDoble(std::string codigo, std::string nombre)
{
    //ctor
    this->Codigo = codigo;
    this->Nombre = nombre;
    this->Siguiente = 0;
    this->Anterior = 0;
}

NodoListaDoble::~NodoListaDoble()
{
    //dtor
}
