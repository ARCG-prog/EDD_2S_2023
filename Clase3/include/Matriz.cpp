#include "Matriz.h"

Matriz::Matriz()
{
    //ctor
    this->Raiz = new NodoMatriz("RAIZ",-1,-1);
}

Matriz::~Matriz()
{
    //dtor
}

NodoMatriz* Matriz::buscarF(int y)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosY == y)
        {
            return aux;
        }
        aux = aux->Abajo;
    }
    return 0;
}

NodoMatriz* Matriz::buscarC(int x)
{
    NodoMatriz *aux = this->Raiz;
    while(aux != 0)
    {
        if(aux->PosX == x)
        {
            return aux;
        }
        aux = aux->Siguiente;
    }
    return 0;
}

NodoMatriz* Matriz::insertar_columna(NodoMatriz *nuevo, NodoMatriz *cabeza_columna)
{
    NodoMatriz *temp = cabeza_columna;
    bool piv = false;
    while(true)
    {
        if(temp->PosX == nuevo->PosX){
            temp->PosY = nuevo->PosY;
            temp->Coordenada = nuevo->Coordenada;
            return temp;
        }else if(temp->PosX > nuevo->PosX){

            piv = true;
            break;
        }
        if(temp->Siguiente){
            temp = temp->Siguiente;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Siguiente = temp;
        nuevo->Anterior = temp->Anterior;
        temp->Anterior->Siguiente = nuevo;
        temp->Anterior=nuevo;
    }
    else
    {
        nuevo->Anterior = temp;
        temp->Siguiente = nuevo;
    }
    return nuevo;
}

NodoMatriz* Matriz::insertar_fila(NodoMatriz *nuevo, NodoMatriz *cabeza_fila)
{
    NodoMatriz *temp = cabeza_fila;
    bool piv = false;
    while(true)
    {
        if(temp->PosY==nuevo->PosY){
            temp->PosX = nuevo->PosX;
            temp->Coordenada = nuevo->Coordenada;
            return temp;
        }else if(temp->PosY > nuevo->PosY){
            piv=true;
            break;
        }
        if(temp->Abajo){
            temp = temp->Abajo;
        }else{
            break;
        }
    }
    if(piv)
    {
        nuevo->Abajo = temp;
        nuevo->Arriba = temp->Arriba;
        temp->Arriba->Abajo = nuevo;
        temp->Arriba = nuevo;
    }
    else
    {
        nuevo->Arriba = temp;
        temp->Abajo = nuevo;
    }
    return nuevo;
}

NodoMatriz* Matriz::nueva_fila(int y)
{
    std::string fil = "F";
    fil += std::to_string(y);
    NodoMatriz *fila = this->insertar_fila(new NodoMatriz(fil, -1, y),this->Raiz);
    return fila;
}

NodoMatriz* Matriz::nueva_columna(int x)
{
    std::string col = "C";
    col += std::to_string(x);
    NodoMatriz *columna = this->insertar_columna(new NodoMatriz(col, x, -1), this->Raiz);
    return columna;
}

void Matriz::InsertarElemento(int x, int y)
{
    std::string coordenada = std::to_string(x);
    coordenada += ",";
    coordenada += std::to_string(y);
    NodoMatriz *nuevo = new NodoMatriz(coordenada, x, y);
    NodoMatriz *nodo_Columna = this->buscarC(x);
    NodoMatriz *nodo_Fila = this->buscarF(y);

    if(nodo_Columna == 0 && nodo_Fila == 0)
    {
        nodo_Columna = this->nueva_columna(x);
        nodo_Fila = this->nueva_fila(y);
        nuevo = this->insertar_fila(nuevo, nodo_Columna);
        nuevo = this->insertar_columna(nuevo, nodo_Fila);
    }
    else if(nodo_Columna == 0 && nodo_Fila != 0)
    {
        nodo_Columna = this->nueva_columna(x);
        nuevo = this->insertar_fila(nuevo, nodo_Columna);
        nuevo = this->insertar_columna(nuevo, nodo_Fila);
    }
    else if(nodo_Columna != 0 && nodo_Fila == 0)
    {
        nodo_Fila = this->nueva_fila(y);
        nuevo = this->insertar_fila(nuevo, nodo_Columna);
        nuevo = this->insertar_columna(nuevo, nodo_Fila);
    }
    else if(nodo_Columna != 0 && nodo_Fila != 0)
    {
        nuevo = this->insertar_fila(nuevo, nodo_Columna);
        nuevo = this->insertar_columna(nuevo, nodo_Fila);
    }

}

void Matriz::Graficar()
{
    ofstream archivo;
    std::string texto = "";
	std::string nombre_archivo = "matriz.dot";
	std::string nombre_imagen = "matriz.jpg";
	NodoMatriz *aux1 = this->Raiz;
	NodoMatriz *aux2 = this->Raiz;
	NodoMatriz *aux3 = this->Raiz;
	archivo.open(nombre_archivo, ios::out);
	if ( aux1 != 0 ) {
		archivo << "digraph MatrizCapa{ \n node[shape=box] \n rankdir=UD;\n";
        /** Creacion de los nodos actuales */
        /*while( aux1 != 0 ) {
            archivo << "nodo" << (aux1->PosX+1) << (aux1->PosY+1) << "[label=\"" << aux1->Proyecto << "\" ,rankdir=LR,group=" << (aux1->PosX+1) << "]; \n";
            aux1 = aux1->Siguiente;
        }
        archivo << "}";*/
        while( aux2 != 0 ) {
            aux1 = aux2;
            archivo << "{rank=same; \n";
            while( aux1 != 0 ) {
                archivo << "nodo" << (aux1->PosX+1) << (aux1->PosY+1) << "[label=\"" << aux1->Coordenada << "\" ,group=" << (aux1->PosX+1) << "]; \n";
                aux1 = aux1->Siguiente;
            }
            archivo << "} \n";
            aux2 = aux2->Abajo;
        }
        /** Conexiones entre los nodos de la matriz */
        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Siguiente != 0 ) {
                archivo << "nodo" << (aux1->PosX+1) << (aux1->PosY+1) << " -> " << "nodo" << (aux1->Siguiente->PosX+1) << (aux1->Siguiente->PosY+1) << " [dir=both];\n";
                aux1 = aux1->Siguiente;
            }
            aux2 = aux2->Abajo;
        }
        aux2 = aux3;
        while( aux2 != 0 ) {
            aux1 = aux2;
            while( aux1->Abajo != 0 ) {
                archivo << "nodo" << (aux1->PosX+1) << (aux1->PosY+1) << " -> " << "nodo" << (aux1->Abajo->PosX+1) << (aux1->Abajo->PosY+1) << " [dir=both];\n";
                aux1 = aux1->Abajo;
            }
            aux2 = aux2->Siguiente;
        }
        archivo << "} \n";
	} else {
		texto = "No hay elementos en la matriz";
	}

	archivo.close();
    std::string codigo_cmd="dot -Tjpg ";
    codigo_cmd+=nombre_archivo;
    codigo_cmd+=" -o ";
    codigo_cmd+=nombre_imagen;
    char j[codigo_cmd.size()+1];
    strcpy(j,codigo_cmd.c_str());
    cout << j << endl;
    system(j);
}


