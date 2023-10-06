from nodoGrafo import NodoGrafo
import os

class Grafo():
    def __init__(self):
        self.principal = None

    '''
    V = {1, 4, 5, 7, 9}
    A= {(1,2), (1, 3), (1,4), (3, 4)}

    1 -> 2 -> 3 -> 4
    2
    3 -> 4
    4

    contador = 0
    valor = input("ingrese un valor entre 1 y 100) 5
    while(contador < 101):
        if valor == contador:
            break
        contador += 1
    return
    return valorX
    '''

    def insertarFila(self, u):
        nuevo = NodoGrafo(u)
        if self.principal == None:
            self.principal = nuevo
        else:
            aux = self.principal
            while aux is not None:
                if aux.valor == nuevo.valor:
                    return
                if aux.abajo is None:
                    break
                aux = aux.abajo
            aux.abajo = nuevo

    def insertarColumna(self, u, v):
        nuevo = NodoGrafo(v)
        if self.principal is not None and self.principal.valor == u:
            aux = self.principal
            while aux.siguiente is not None:
                aux = aux.siguiente
            aux.siguiente = nuevo
        else:
            aux = self.principal
            while aux is not None:
                if aux.valor == u:
                    break
                aux = aux.abajo
            if aux is not None:
                while aux.siguiente is not None:
                    aux = aux.siguiente
                aux.siguiente = nuevo   

    def verMatriz(self):
        aux = self.principal 
        while aux is not None:
            temp = aux.siguiente
            if temp is None:
                print("\nNodo {} No tiene conexion".format(aux.valor), end='') 
            else:
                print("\nNodo {} tiene conexion con ".format(aux.valor), end='') 
                while temp is not None:
                    print(" {} ".format(temp.valor), end='')     
                    temp = temp.siguiente
            aux = aux.abajo    

    def agregarNodo(self, u, v):
        self.insertarColumna(u, v)
        return
    
    def Grafico(self):
        cadena = "digraph finite_state_machine { \n rankdir=LR;\n node [shape = circle];\n"
        aux = self.principal
        while aux is not None:
            temp = aux.siguiente            
            while temp is not None:
                cadena += "\"{}\" -> \"{}\";\n".format(aux.valor, temp.valor)
                temp = temp.siguiente
            aux = aux.abajo
        cadena += "}"
        archivo = "grafo.jpg"
        a = open("grafo.dot","w")
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg grafo.dot -o " + archivo)
        return