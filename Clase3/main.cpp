#include <iostream>
#include "Matriz.h"
#include <string>

using namespace std;

int main()
{
    //std::string nombre;
    //cin >> nombre;

    //cout << "El archivo es " << nombre << endl;

    Matriz *matriz = new Matriz();

    matriz->InsertarElemento(0,0);
    matriz->InsertarElemento(2,2);
    matriz->InsertarElemento(1,1);
    matriz->InsertarElemento(3,3);

    matriz->InsertarElemento(4,0);
    matriz->InsertarElemento(5,1);

    matriz->InsertarElemento(5,4);
    matriz->InsertarElemento(4,5);

    matriz->InsertarElemento(1,2);
    matriz->InsertarElemento(1,3);

    matriz->InsertarElemento(1000,1000);

    matriz->Graficar();
    cout << "Hello world!" << endl;
    return 0;
}
