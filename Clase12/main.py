from ArbolMerkle import *
from nodos import *
from bloque import BlockChain
import json

Aarbol = ArbolMerkle()
bloques = BlockChain()
arboles = []

class empleado():
    def __init__(self, nombre, contrasena, codigo):
        self.empleado = nombre
        self.contrasena = contrasena
        self.codigo = codigo
        self.ewallet = "" 
        self.fecha = fechaactual()

empleado1 = empleado("Cristian", "12", "BDEV-100")


with open('prueba.json', 'r', encoding='utf-8') as archivo:
    datos = json.load(archivo)

for i in range(len(datos['eWallet'])):
    if datos['eWallet'][i]['empleado'] == empleado1.codigo:
        empleado1.ewallet = datos['eWallet'][i]['id']

print(empleado1.ewallet)

temp = [["PY-100", "BDEV-100"], ["PY-100", "QA-100"], ["PY-100", "FDEV-100"]]




'''
recorrer el arreglo, 
aux1 = [] -> PY-100
recorrer aux1 ->
    aux[i] = BDEV-100
    aux = tablahash.buscarwallet(temp[0][1]) -> str -> empleado.ewallet
    arbol.AgregarBloque(aux, 129, temp[0][0])
'''

