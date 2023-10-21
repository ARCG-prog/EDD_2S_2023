from grafo import Grafo

grafoGeneral = Grafo()
grafoGeneral1 = Grafo()


vertices = ["T1-PY-100","T2-PY-100","T3-PY-100","T4-PY-100","T5-PY-100"]
for valor in vertices:
    grafoGeneral.insertarFila(valor)
grafoGeneral.agregarNodo("T3-PY-100","T1-PY-100")
grafoGeneral.agregarNodo("T3-PY-100","T2-PY-100")
grafoGeneral.agregarNodo("T5-PY-100","T3-PY-100")
grafoGeneral.agregarNodo("T5-PY-100","T4-PY-100")
print("Tareas con sus antecesores")
grafoGeneral.verMatriz()
grafoGeneral.Grafico()


print('\n')
for valor in vertices:
    grafoGeneral1.insertarFila(valor)
grafoGeneral1.agregarNodo("T1-PY-100","T3-PY-100")
grafoGeneral1.agregarNodo("T2-PY-100","T3-PY-100")
grafoGeneral1.agregarNodo("T3-PY-100","T5-PY-100")
grafoGeneral1.agregarNodo("T4-PY-100","T5-PY-100")
print("Tareas con sus sucesores")
grafoGeneral1.verMatriz()
#grafoGeneral1.Grafico()
