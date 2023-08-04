#include "Lista.h"

Lista::Lista()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

Lista::~Lista()
{
    //dtor
}

//Primero se coloca el tipo de la funcion, luego a que clase pertenece, nombre
void Lista::Insertar(std::string codigo, std::string nombre)
{
    NodoLista *nuevo = new NodoLista(codigo,nombre);
    if(this->Primero == 0)
    {
        /*------------------*/
        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        /*Nos volamos esto*/
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoLista *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;//No existe en doble enlazada
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo; //No exites ne doble enlazada
        this->Tamanio++;
    }
}

void Lista::VerLista()
{
    NodoLista *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->Codigo << endl;
        aux = aux->Siguiente;
        contador++;
    }
}

int Lista::Sumar()
{
    return 1+1;
}
