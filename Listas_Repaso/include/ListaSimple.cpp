#include "ListaSimple.h"

ListaSimple::ListaSimple()
{
    //ctor
    this->Primero = 0;
    this->Tamanio = 0;
}

ListaSimple::~ListaSimple()
{
    //dtor
}

void ListaSimple::InsertarCarnet(int carnet)
{
    NodoListaSimple *nuevo = new NodoListaSimple(carnet);
    if(this->Primero == 0)
    {
        this->Primero = nuevo;
        this->Tamanio++;
    }
    else{
        NodoListaSimple *aux = this->Primero;
        while(aux->Siguiente != 0)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevo;
        this->Tamanio++;
    }
}

void ListaSimple::InsertarClase(int carnet, std::string clase)
{
    NodoListaSimple *aux = this->Primero; // 1 2 3 4
    while(aux != 0)
    {
        if(aux->Carnet == carnet){
            ClasesAlumno *nuevaClase = new ClasesAlumno(clase);
            if(aux->Clases == 0){
                aux->Clases = nuevaClase;
            }else{
                ClasesAlumno *aux1 = aux->Clases;
                while(aux1->Abajo != 0){
                    aux1 = aux1->Abajo;
                }
                aux1->Abajo = nuevaClase;
            }
            return;
        }
        aux = aux->Siguiente;
    }
    cout << "no lo encontre" << endl;
}

void ListaSimple::MostrarClases()
{
    NodoListaSimple *aux = this->Primero;
    while(aux != 0)
    {
        if(aux->Clases != 0){
            cout << "Clases del Alumno" << aux->Carnet << endl;
            ClasesAlumno *aux1 = aux->Clases;
            while(aux1 != 0){
                cout << aux1->Clase << endl;
                aux1 = aux1->Abajo;
            }
        }else{
            cout << "El Alumno " << aux->Carnet <<" No tiene clases" << endl;
        }
        aux = aux->Siguiente;
    }
}

std::string ListaSimple::textoGrafica()
{
    std::string cuerpo = "";
    NodoListaSimple *aux = this->Primero;
    for(int i = 0; i < this->Tamanio; i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=std::to_string(aux->Carnet);
        cuerpo+="\"]; \n";
        aux = aux->Siguiente;
    }
    for(int i = 0; i < (this->Tamanio-1); i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+=" -> nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+="\n";
    }
    return cuerpo;
}

std::string ListaSimple::textoGraficaClase()
{
    std::string cuerpo = "";
    NodoListaSimple *aux = this->Primero;
    cuerpo+="{rank=min;\n";
    for(int i = 0; i < this->Tamanio; i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=std::to_string(aux->Carnet);
        cuerpo+="\", shape=box, rankdir=LR, group=";
        cuerpo+=std::to_string(i);
        cuerpo+="]; \n";
        aux = aux->Siguiente;
    }
    cuerpo+="}\n";

    aux = this->Primero;
    cuerpo+="{rank=same;\n";
    for(int i = 0; i < this->Tamanio; i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=std::to_string(aux->Carnet);
        cuerpo+="\", shape=box, rankdir=LR, group=";
        cuerpo+=std::to_string(i);
        cuerpo+="]; \n";
        aux = aux->Siguiente;
    }
    cuerpo+="}\n";
    /*Iniciamos nuevamente para listas*/
    aux = this->Primero;
    int contador = 0;
    for(int i = 0; i < this->Tamanio; i++)
    {
        if(aux->Clases != 0){
            ClasesAlumno *aux1 = aux->Clases;
            while(aux1 != 0){
                cuerpo+="{rank=same;\n";
                cuerpo+="nodoL";
                cuerpo+=std::to_string(i);
                cuerpo+=std::to_string(contador);
                cuerpo+="[label=\"";
                cuerpo+=aux1->Clase;
                cuerpo+="\", group=";
                cuerpo+=std::to_string(i);
                cuerpo+="]; \n";
                cuerpo+="}\n";
                contador++;
                aux1 = aux1->Abajo;
            }
        }
        contador = 0;
        aux = aux->Siguiente;
    }
    for(int i = 0; i < (this->Tamanio-1); i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+=" -> nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+="\n";
    }

    aux = this->Primero;
    contador = 0;
    for(int i = 0; i < this->Tamanio; i++)
    {
        if(aux->Clases != 0){
            ClasesAlumno *aux1 = aux->Clases;
            cuerpo+="\nnodo";
            cuerpo+=std::to_string(i);
            while(aux1 != 0){
                cuerpo+=" -> nodoL";
                cuerpo+=std::to_string(i);
                cuerpo+=std::to_string(contador);
                contador++;
                aux1 = aux1->Abajo;
            }
        }
        contador = 0;
        aux = aux->Siguiente;
    }
    return cuerpo;
}

void ListaSimple::graficar()
{
    ofstream archivo;
    archivo.open("ListaSimple.dot",ios::out);
    if(archivo.fail())
    {
        cout << "Se produjo un error" << endl;
    }else{
        archivo << "digraph migrafica{\n rankdir=UD; \n node[shape=box]" << textoGraficaClase() << "\n }";
        archivo.close();
    }

    try{
        system("dot -Tjpg ListaSimple.dot -o ListaSimple.jpg");
    }catch(exception e){
        cout << "Error al generar imagen";
    }
}


