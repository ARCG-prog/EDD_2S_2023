from ArbolMerkle import *
from nodos import *
import hashlib
import os 

#No es necesario
import time

class BlockChain():
    def __init__(self) -> None:
        self.inicio = None
        self.bloque_creados = 0
    
    def InsertarBloque(self, fecha, data):
        if self.inicio is None:
            encrypt = self._encriptacionSHA256(str(self.bloque_creados)+ fecha + data)
            nuevoNodo = NodoBloque(str(self.bloque_creados), fecha, data, '0000', encrypt)
            self.inicio = nuevoNodo
            self.bloque_creados += 1
        else:
            encrypt = self._encriptacionSHA256(str(self.bloque_creados)+ fecha + data)
            aux = self.inicio
            while aux.siguiente is not None:
                aux = aux.siguiente
            nuevoNodo = NodoBloque(str(self.bloque_creados), fecha, data, aux.valor['hash'], encrypt)
            nuevoNodo.anterior = aux
            aux.siguiente = nuevoNodo
            self.bloque_creados += 1
        
    def Graficar(self):
        cadena = ''
        archivo = "blockchain.jpg"
        a = open("blockchain.dot","w")
        if self.inicio is not None:
            cadena += "digraph arbol { node [shape=box]; "
            aux = self.inicio
            cont = 0
            while aux.siguiente is not None:
                cadena += "nodo{}[label=".format(cont) 
                cadena += "<"
                cadena += "<B>Index:</B> {} <br /> <B>Timestamp:</B> {} <br /> <B>Data:</B> {} <br /> <B>PreviousHash:</B> {} <br /> <B>Hash:</B> {}".format(aux.valor['index'], aux.valor['timestamp'], aux.valor['data'][:20], aux.valor['previoushash'][:20], aux.valor['hash'][:20])
                cadena += ">]\n"
                aux = aux.siguiente
                cont += 1
            cadena += "nodo{}[label=".format(cont) 
            cadena += "<"
            cadena += "<B>Index:</B> {} <br /> <B>Timestamp:</B> {} <br /> <B>Data:</B> {} <br /> <B>PreviousHash:</B> {} <br /> <B>Hash:</B> {}".format(aux.valor['index'], aux.valor['timestamp'], aux.valor['data'][:20], aux.valor['previoushash'][:20], aux.valor['hash'][:20])
            cadena += ">]\n"
            for i in range(cont):
                cadena += "nodo{} -> ".format(i)
            cadena += "nodo{}".format(cont)
            cadena += "}"
        a.write(cadena)
        a.close()
        os.system("dot -Tjpg blockchain.dot -o " + archivo)

    def _encriptacionSHA256(self, cadena):
        obj = hashlib.sha256()
        obj.update(cadena.encode('utf-8'))
        resultado = obj.hexdigest()
        return resultado #a15387bc
    


arbol = ArbolMerkle()
arbol1 = ArbolMerkle()
arbol2 = ArbolMerkle()
bloques = BlockChain()
arboles = []

print("Primer Arbol")
arbol.AgregarBloque("201700918", 125, "PY-100")
arbol.AgregarBloque("201700919", 178, "PY-100")
arbol.AgregarBloque("201700920", 145, "PY-100")
arbol.AgregarBloque("201700921", 256, "PY-100")
arbol.AgregarBloque("201700922", 300, "PY-100")
raiz = arbol.GenerarArbol()
arboles.append(raiz)
arbol.graficar("100")

bloques.InsertarBloque(fechaactual(), raiz.valor)

time.sleep(10)
print("Segundo Arbol")
arbol1.AgregarBloque("201700918", 129, "PY-101")
arbol1.AgregarBloque("201700919", 170, "PY-101")
arbol1.AgregarBloque("201700920", 125, "PY-101")
arbol1.AgregarBloque("201700921", 289, "PY-101")
raiz = arbol1.GenerarArbol()
arboles.append(raiz)
arbol1.graficar("101")

bloques.InsertarBloque(fechaactual(), raiz.valor)

time.sleep(10)
print("Tercer Arbol")
arbol2.AgregarBloque("201700918", 120, "PY-102")
arbol2.AgregarBloque("201700919", 163, "PY-102")
arbol2.AgregarBloque("201700920", 110, "PY-102")
raiz = arbol2.GenerarArbol()
arboles.append(raiz)
arbol2.graficar("102")

bloques.InsertarBloque(fechaactual(), raiz.valor)

bloques.Graficar()

print(arboles)
print("Terminado")