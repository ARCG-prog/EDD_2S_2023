#include "NodoListaSimple.h"

NodoListaSimple::NodoListaSimple(int carnet)
{
    //ctor
    this->Carnet = carnet;
    this->Clases = 0;
    this->Siguiente = 0;
}

NodoListaSimple::~NodoListaSimple()
{
    //dtor
}
