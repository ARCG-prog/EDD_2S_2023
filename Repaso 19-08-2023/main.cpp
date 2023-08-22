#include <iostream>
#include "Matriz.h"
#include "Lista.h"
#include "ColaPrioridad.h"
#include <string>


using namespace std;

void sumar();

int main()
{
    cout << "Hello world!" << endl;
    Matriz *matrizN = new Matriz();
    std::string nombre, password;
    /** Lista **/
    Lista *lista = new Lista();
    lista->LeerArchivo("empleados.csv");
/*
    cout << "Nombre: " << endl;
    cin >> nombre;
    cout << "Password: " << endl;
    cin >> password;
    lista->Insertar(nombre, password);
*/
    lista->VerLista();

    /** Cola **/
    ColaPrioridad *cola = new ColaPrioridad();
    cola->Encolar("Proyecto1","A");
    cola->Encolar("Proyecto2","A");
    cola->Encolar("Proyecto3","B");
    cola->Encolar("Proyecto4","C");
    cola->VerProyectos();

    std::string cadena1 = "A"; //75
    std::string cadena2 = "B"; //76
    cout << cadena1.compare(cadena2) << endl; // -1
    cout << cadena2.compare(cadena1) << endl; // 1
    cout << cadena1.compare(cadena1) << endl; // 0

    /** Matriz **/
    while(cola->Primero)
    {
        matrizN->insertar_proyecto(cola);
        cola->Descolar();
    }

    matrizN->insertar_empleado(lista);
    matrizN->asignarProyecto("Cristian Suy","PY-101");
    matrizN->asignarProyecto("Alberto Mejia","PY-100");
    matrizN->asignarProyecto("Alberto Mejia","PY-103");
    matrizN->asignarProyecto("Hector Gomez","PY-103");

    matrizN->Graficar();



    return 0;
}
