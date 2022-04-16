import numpy as np

lista = [1,23,31,40,56,16]

#Ejercicio 01
""""
for i in range(len(lista)):
    print(lista[i])
"""

#Ejercicio 02
"""
for i in range (len(lista)):
    print(lista[i]*2)  
"""

#Ejercicio 03: 
"""
pares =[]
for i in range(len(lista)):
    if lista[i]%2 != 0:
        pares.append(lista[i])

for i in range(len(pares)):
    print(pares[i])
"""

#Ejercicio 04:
"""
lista2=['oi',2,2.5,'top','python',45]
for i in range(len(lista2)):
    if type(lista2[i]) == str:
        print(lista2[i])
"""

#Ejercicio 05:
"""
my_list = [0, 10, 20, 30, 40, 50, 60, 70]
print(my_list[-1])
"""

#Ejercicio 06:
"""
my_list = [0, 10, 20, 30, 40, 50, 60, 70]
print(my_list[:4])
"""



#Ejercicio 07:
"""
my_list = [0, 10, 20, 30, 40, 50, 60, 70]
print(my_list[:-1])
"""


#Ejercicio 09:
"""
lista = ['a', 'a', 'b', 'a', 'c', 'd', 'e', 'b', 'b', 'c']
diccionario = {}
for i in range(len(lista)):
    if lista[i] not in diccionario:
        diccionario[lista[i]] = 1
    else:
        diccionario[lista[i]] += 1

print(diccionario)
"""

#Ejercicio 10:
"""
def producto_escalar(lista1,lista2):
    producto = 0
    for i in range(len(lista1)):
        producto += lista1[i]*lista2[i]
    print(producto)

producto_escalar([1,2,3],[0,4,7])
"""



#Ejercicio 11:
array_1D = [7,2,9,10]
array_2D = [[5.2,3.0,4.5],[9.1,0.1,0.3]]
array_3D = [[[1,4,7],[2,3,4]],[[2,9,7],[3,4,5]],[[1,3,0],[0,1,2]],[[9,6,9],[6,7,8]]]


def print_array_1D(array):
    for i in range(len(array)):
        print(array[i],end=" ")
    print()

def print_array_2D(array):
    for i in range(len(array)):
        for j in range(len(array[i])):
            print(array[i][j],end=" ")
        print()

def print_array_3D(array):
    for i in range(len(array)):
        for j in range(len(array[i])):
            for k in range(len(array[i][j])):
                print(array[i][j][k],end=" ")
            print()

#IMPRIMIR DIMENSION DE ARRAY
"""
print("Dimensiones de array_1D: ",np.shape(array_1D))
print("Dimensiones de array_2D: ",np.shape(array_2D))
print("Dimensiones de array_3D: ",np.shape(array_3D))
"""

#IMPRIMIR EL NUMERO DE ELEMENTOS DE CADA DIMENSION
"""
print("Nro. de elementos de array_1D: ",np.size(array_1D))
print("Nro. de elementos de array_2D: ",np.size(array_2D))
print("Nro. de elementos de array_3D: ",np.size(array_3D))
"""



#GENERAR ARRAY 2X2 CON VALORES CERO
"""
def generar_array_2x2():
    array_2x2 = np.zeros((2,2))
    print(array_2x2)
generar_array_2x2()
"""

#GENERAR ARRAY 3X2 CON VALORES ALEATORIOS
"""
def generar_array_3x2():
    array_3x2 = np.random.rand(3,2)
    print(array_3x2)
generar_array_3x2()
"""

#GENERAR UN ARRAY CON VALORES DEL 0 AL 4
def generar_array_3x2():
    array_3x2 = np.arange(0,4)
    print(array_3x2)
generar_array_3x2()






