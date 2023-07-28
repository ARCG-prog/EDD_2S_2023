#include <stdio.h>
#include <stdlib.h>

//void insertar();

typedef struct node
{
    int carnet;
    struct node *siguiente;
    struct node *anterior;
} Node;

Node *Primero = NULL;
Node *Ultimo = NULL; // Node *Ultimo = 0; Node *Ultimo = nullptr;

void insertar(int dato){
    Node *nuevoNodo = (Node *) malloc(sizeof(Node)); // Node *nuevoNodo = new Node();
    nuevoNodo->carnet = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    
    if (Primero == NULL){
        Primero = nuevoNodo;
        Ultimo = nuevoNodo;
    }else{
        Ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = Ultimo;
        Ultimo = nuevoNodo;
    }
}

void eliminar(int dato){
    Node *aux = Primero;
    while(aux != NULL){
        if(aux->carnet == dato){
            if(aux == Primero){ //aux = 0x00001, Primero = 0x00001
                Primero = aux->siguiente;
                Primero->anterior = NULL;
            }else if(aux == Ultimo) {
                Ultimo =  aux->anterior;
                Ultimo->siguiente = NULL;
            }else{
                aux->anterior->siguiente = aux->siguiente;
                aux->siguiente->anterior = aux->anterior;
            }
            free(aux); // delete aux;
            return;
        }
        aux = aux->siguiente;
    }
}

void imprimir(){
    Node *aux = Primero;
    printf("Lista: ");
    while(aux != NULL){
        printf("%d ", aux->carnet);
        aux = aux->siguiente;
    }
    printf("\n");
}


int main()
{
    /* code */
    insertar(1);
    insertar(2);
    insertar(3);
    insertar(4);
    insertar(5);
    imprimir();
    eliminar(2);
    imprimir();
    return 0;
}


/*
agregar(int a, int *b){
    a++; 0x000003
    *(b)++; 0x00002
    
}

int a = 1; 0x000001
int b = 1; 0x000002
agregar(a, &b);
imprimir(a); // 1
imprimir(b); // 2

* -> ver el valor
& -> el espacio de memoria
*/


