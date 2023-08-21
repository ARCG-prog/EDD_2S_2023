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
void Lista::Insertar(std::string nombre, std::string password)
{
    NodoLista *nuevo = new NodoLista(nombre, password);
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
        cout << aux->EmpleadoSistema->Nombre << endl;
        aux = aux->Siguiente;
        contador++;
    }
}

void Lista::LeerArchivo(std::string nombre_archivo)
{
    try
    {
        ifstream lectura;
        lectura.open(nombre_archivo, ios::in);
        bool encabezado = false;
        for(std::string fila; std::getline(lectura,fila);)
        {
            std::stringstream lineas(fila);
            std::string nombre;
            std::string password;
            if(encabezado)
            {
                getline(lineas, nombre, ',');
                getline(lineas, password, ',');
                this->Insertar(nombre, password);
            }
            else{
                encabezado = true;
            }

        }
    }
    catch(exception)
    {
        cout << "No se pudo leer el archivo" << endl;
    }
}
