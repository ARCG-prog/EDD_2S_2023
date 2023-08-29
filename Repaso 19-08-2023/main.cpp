#include <iostream>
#include "Matriz.h"
#include "Lista.h"
#include "ColaPrioridad.h"
#include "ListaDoble.h"
#include <string>


using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    Matriz *matrizN = new Matriz();
    std::string nombre, password;
    /** Lista **/
    Lista *lista = new Lista();
    lista->LeerArchivo("empleados.csv");
/*
    cout << "Nombre: ";
    std::getline(std::cin, nombre); //Estudiante 1
    cout << "\nPassword: ";
    std::getline(std::cin, password);
    lista->Insertar(nombre, password);
*/
    //lista->VerLista();

    /** Cola **/
    ColaPrioridad *cola = new ColaPrioridad();
    cola->Encolar("Proyecto1","C");
    cola->Encolar("Proyecto2","A");
    cola->Encolar("Proyecto3","B");
    cola->Encolar("Proyecto4","A");
    cola->VerProyectos();
    cola->Ordenar();
    cout << "" << endl;
    cola->VerProyectos();
    /**
    Proyecto 2 -> Proyecto 4 - Proyecto 3 -> Proyecto 1
    */

    std::string cadena1 = "A"; //75
    std::string cadena2 = "B"; //76
    //cout << cadena1.compare(cadena2) << endl; // -1
    //cout << cadena2.compare(cadena1) << endl; // 1
    //cout << cadena1.compare(cadena1) << endl; // 0

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

    matrizN->BuscarProyecto("PY-100","Generar Consultas");
    matrizN->BuscarProyecto("PY-100","Generar Consultas 1");
    matrizN->BuscarProyecto("PY-100","Generar Consultas 2");
    matrizN->BuscarProyecto("PY-100","Generar Consultas 3");

    matrizN->BuscarEmpleado("PY-100","Generar Consultas 3","BDEV-100");
    matrizN->BuscarEmpleado("PY-100","Generar Consultas 3","BDEV-100");

    /** Lista Doble Enlazada*/
    ListaDoble *listaDoble = new ListaDoble();
    listaDoble->Insertar("PY-100","Generar Consultas","");
    listaDoble->Insertar("PY-100","Generar Consultas 1","");
    listaDoble->Insertar("PY-100","Generar Consultas 2","");
    listaDoble->Insertar("PY-100","Generar Consultas 3","");

    listaDoble->Asignar("PY-100","Generar Consultas 3","BDEV-100");
    listaDoble->Asignar("PY-100","Generar Consultas 1","BDEV-103");

    /**
    Crear Tarea
        a que proyecto va? Eligen proyecto
        Cual es el nombre? asigna el nombre

    Asignar Tarea
        que proyecto va a elegir? imprimen los proyectos
        mostrar tareas de ese proyecto? hacer un metodo que imprima las tareas cuando el codigo coincida
        solicitar codigoTarea o bien el nombre.
        muestran los empleados. imprimir los codigos de los empleados
        eligen que empleado
    */

    /**
        Generar el json todo viene de la matriz
        GenerarFuncion JSON
        recorrer la matriz solamente en columnas
            columna->Proyecto_c->Codigo
            columna->Proyecto_c->Nombre
            columna->Tareas->DarTareas

        DarTareas -> devolver un string donde se recorre la lista entera y se jala los 2 atributos
    */


    return 0;
}
