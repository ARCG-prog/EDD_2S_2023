#include <iostream>
#include "ListaSimple.h"
#include "ListaDobleEnlazada.h"

using namespace std;

int main()
{
    ListaSimple *listaSimple = new ListaSimple();
    listaSimple->InsertarCarnet(202000001);
    listaSimple->InsertarCarnet(202000002);
    listaSimple->InsertarCarnet(202000003);
    listaSimple->InsertarClase(202000003, "EDD");
    listaSimple->InsertarClase(202000003, "Orga");
    listaSimple->InsertarClase(202000003, "Compi 1");
    listaSimple->InsertarClase(202000001, "EDD");
    listaSimple->InsertarClase(202000001, "Archivos");
    listaSimple->MostrarClases();
    listaSimple->graficar();

    /*Lista Doblemente Enlazada*/
    ListaDobleEnlazada *listaDoble = new ListaDobleEnlazada();
    listaDoble->Insertar("BDEV-001","Cristian");
    listaDoble->Insertar("BDEV-002","Cristian");
    listaDoble->Insertar("BDEV-003","Cristian");
    listaDoble->Insertar("BDEV-004","Cristian");
    listaDoble->Insertar("BDEV-005","Cristian");
    listaDoble->Insertar("BDEV-006","Cristian");
    listaDoble->graficar();
    cout << "Hello world!" << endl;
    return 0;
}
