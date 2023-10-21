import json
from grafo import Grafo


class NodoLista:
    def __init__(self, id_tarea, empleado):
        self.id_tarea = id_tarea
        self.empleado = empleado
        self.siguiente = None


class Lista:
    def __init__(self):
        self.primero = None

    def insertar(self, valor, empleado):
        nuevo = NodoLista(valor, empleado)
        if self.primero is None:
            self.primero = nuevo
        else:
            aux = self.primero
            while aux.siguiente is not None:
                aux = aux.siguiente
            aux.siguiente = nuevo

    def mostrar(self):
        aux = self.primero
        while aux is not None:
            print(aux.id_tarea)
            aux = aux.siguiente

    def listaEmpleados(self, empleado):
        listaAux = Lista()
        aux = self.primero
        while aux is not None:
            if aux.empleado == empleado:
                listaAux.insertar(aux.id_tarea, aux.empleado)
            aux = aux.siguiente
        return listaAux


contador = 1
listaGeneral = Lista()
listaEmpleado = None


with open('datos.json', 'r', encoding='utf-8') as archivo:
    datos = json.load(archivo)

for i in range(len(datos['Proyectos'])):
    if len(datos['Proyectos'][i]['tareas']) > 0:
        for j in range(len(datos['Proyectos'][i]['tareas'])):
            listaGeneral.insertar(
                'T'+str(contador)+'-' + datos['Proyectos'][i]['id'], datos['Proyectos'][i]['tareas'][j]['empleado'])
            contador += 1
    contador = 1

listaEmpleado = listaGeneral.listaEmpleados('FDEV-201')


grafoGeneral = Grafo()
grafoGeneral.inicio('PY-100')

with open('tareas.json', 'r', encoding='utf-8') as archivo:
    datos = json.load(archivo)

# grafoGeneral.agregarNodo(datos['Tareas'][i]['proyecto'], datos['Tareas'][i]['codigo'])
for i in range(len(datos['Tareas'])):
    grafoGeneral.insertarFila(datos['Tareas'][i]['codigo'])
    if len(datos['Tareas'][i]['antecesor']) > 0:
        for j in range(len(datos['Tareas'][i]['antecesor'])):
            grafoGeneral.agregarNodo(
                datos['Tareas'][i]['codigo'], datos['Tareas'][i]['antecesor'][j]['codigo'])


grafoGeneral.CambiarEstadoTarea('T1-PY-100', 2)
grafoGeneral.CambiarEstadoTarea('T2-PY-100', 2)
grafoGeneral.CambiarEstadoTarea('T2-PY-100', 3)
grafoGeneral.CambiarEstadoTarea('T4-PY-100', 2)
grafoGeneral.CambiarEstadoTarea('T5-PY-100', 2)
grafoGeneral.CambiarEstadoTarea('T7-PY-100', 2)
grafoGeneral.CambiarEstadoTarea('T8-PY-100', 2)
