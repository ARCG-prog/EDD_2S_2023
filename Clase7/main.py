from arbolAVL import Arbol_AVL

arbol = Arbol_AVL()
#arbol.Insertar(50)
#arbol.Insertar(30)
#arbol.Insertar(70)
#arbol.Insertar(60)
#arbol.Insertar(10)
#arbol.Insertar(20)
#arbol.Insertar(80)

#Como generar un arbol degenerado
arbol.Insertar(10)
arbol.Insertar(20)
arbol.Insertar(30)
arbol.Insertar(40)
arbol.Insertar(50)
arbol.Insertar(60)
arbol.Insertar(70)


print("Recorrido Inorden")
arbol.recorridoInorden()
print("\nRecorrido PreOrden")
arbol.recorridoPreOrden()
print("\nRecorrido PostOrden")
arbol.recorridoPostOrden()

arbol.graficar()


# 6! = 6 * 5 * 4 * 3 * 2 * 1
def factorial_iterativo(n):
    resultado = 1
    while n > 0:
        resultado *= n
        n -= 1
    return resultado

def factorial_recursivo(n):
    if n == 0:
        return 1
    else:
        return n * factorial_recursivo(n-1)

print("") 
print(factorial_iterativo(6)) #720
print(factorial_recursivo(6)) #720