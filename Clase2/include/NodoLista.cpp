#include "NodoLista.h"

NodoLista::NodoLista(std::string codigo, std::string nombre)
{
    //this.Codigo == JAVA
    // self.Codigo == Python
    this->Codigo = codigo;
    this->Nombre = nombre;
    this->Siguiente = 0;
    this->Anterior = 0;
}

NodoLista::~NodoLista()
{
    //dtor
}
