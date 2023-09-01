from nodoABB import Nodo_ABB
import os

class Arbol_ABB():
    def __init__(self):
        self.raiz = None
    
    def Insertar(self, valor):
        self.raiz = self.InsertarNodo(valor, self.raiz)

    def InsertarNodo(self, valor, raiz):
        if raiz is None:
            return Nodo_ABB(valor)
        else:
            if raiz.valor == valor:
                raiz.valor = valor
            elif raiz.valor > valor:
                raiz.izquierdo = self.InsertarNodo(valor, raiz.izquierdo)
            elif raiz.valor < valor:
                raiz.derecho = self.InsertarNodo(valor, raiz.derecho)
        return raiz
    
    def recorridoInorden(self):
        self.Inorden(self.raiz)

    def Inorden(self, raiz):
        if raiz is not None:
            self.Inorden(raiz.izquierdo)
            print(raiz.valor, end=' ')
            self.Inorden(raiz.derecho)

    def recorridoPreOrden(self):
        self.PreOrden(self.raiz)
    
    def PreOrden(self, raiz):
        if raiz is not None:
            print(raiz.valor, end=' ')
            self.PreOrden(raiz.izquierdo)
            self.PreOrden(raiz.derecho)

    def recorridoPostOrden(self):
        self.PostOrden(self.raiz)

    def PostOrden(self, raiz):
        if raiz is not None:
            self.PostOrden(raiz.izquierdo)
            self.PostOrden(raiz.derecho)
            print(raiz.valor, end=' ')

    def graficar(self):
        cadena = ''
        archivo = "arbolABB.jpg"
        a = open("arbolABB.dot","w")
        if self.raiz is not None:
            cadena += "digraph arbol {"
            cadena += self.retornarValoresArbol(self.raiz, 0)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg arbolABB.dot -o " + archivo)
        os.system(archivo)


    def retornarValoresArbol(self, raiz, id):
        cadena = ''
        numero = id + 1
        if raiz is not None:
            cadena += "\""
            cadena += str(raiz.valor)
            cadena += "\" ;\n"
            if(raiz.izquierdo is not None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> {}".format(raiz.valor, self.retornarValoresArbol(raiz.izquierdo, numero), raiz.valor, self.retornarValoresArbol(raiz.derecho, numero))
                cadena += "{" + "rank=same" + "\"{}\" -> \"{}\" [style=invis]; ".format(raiz.izquierdo.valor, raiz.derecho.valor) + "} \n"
            elif(raiz.izquierdo is not None and raiz.derecho is None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> {} \"{}\" -> x{}[style=invis];\n".format(raiz.valor, self.retornarValoresArbol(raiz.izquierdo, numero), raiz.valor, numero)
                cadena += "{" + "rank=same " + "\"{}\" -> x{} [style=invis]; ".format(raiz.izquierdo.valor, numero) + "} \n"
            elif(raiz.izquierdo is None and raiz.derecho is not None):
                cadena += "x{} [label=\"\",width=.1,style=invis];\n".format(numero)
                cadena += "\"{}\" -> x{}[style=invis]; \n \"{}\" -> {}".format(raiz.valor, numero, raiz.valor, self.retornarValoresArbol(raiz.derecho, numero))
                cadena += "{" + "rank=same " + "x{} -> \"{}\" [style=invis]; ".format(numero, raiz.derecho.valor) + "} \n"
        return cadena