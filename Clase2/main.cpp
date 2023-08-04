#include <iostream>
#include "Lista.h"

using namespace std;

void sumar_valor(int i);
void sumar_referencia(int *i);

int main()
{
    int z = 1; // Z = 1, 0xABC1539
    int *x = &z; // x = 0xABC1539

    cout << "Valor de Z antes de funcion valor" << endl;
    cout << *x << endl;

    sumar_valor(z);
    cout << "Valor de Z despues de funcion valor" << endl;
    cout << z << endl;

    sumar_referencia(&z);
    cout << "Valor de Z despues de funcion referencia" << endl;
    cout << z << endl;

    /*
    *   Inicio de la lista
    */


    cout << "Lista Doble Circular" << endl;

    Lista *listaDobleCircular = new Lista();

    listaDobleCircular->Insertar("BDEV-001","Cristian");
    listaDobleCircular->Insertar("BDEV-002","Cristian");
    listaDobleCircular->Insertar("BDEV-003","Cristian");
    listaDobleCircular->Insertar("BDEV-004","Cristian");
    listaDobleCircular->VerLista();

    cout << "Hello world!" << endl;
    return 0;
}

void sumar_valor(int i)
{
    i++;
    cout << "DENTRO DE FUNCION POR VALOR" << endl;
    cout << i << endl;
}

void sumar_referencia(int *i)
{
    (*i)++;
    cout << "DENTRO DE FUNCION POR REFERENCIA" << endl;
    cout << i << endl;
}
