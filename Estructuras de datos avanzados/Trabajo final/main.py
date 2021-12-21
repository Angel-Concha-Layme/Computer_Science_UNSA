from openpyxl import load_workbook 
from KDTree import *
import file_reader
import os
from time import sleep

print("Procesando datos...")
workbook_read = load_workbook(filename="processed_data.xlsx")
sheet_read = workbook_read.active

tree = KDTree(12)
points = []

# read until end of file
for k in range(2, 5646):
    data = []
    # decimal value of hex
    try:
        data.append(int(sheet_read["A" + str(k)].value, 16))
    except:
        data.append(float(sheet_read["A" + str(k)].value.replace(",", ".")))
    data.append(sheet_read["B" + str(k)].value)
    data.append(sheet_read["C" + str(k)].value)
    data.append(sheet_read["D" + str(k)].value)
    data.append(sheet_read["E" + str(k)].value)
    data.append(sheet_read["F" + str(k)].value)
    data.append(sheet_read["G" + str(k)].value)
    data.append(sheet_read["H" + str(k)].value)
    data.append(sheet_read["I" + str(k)].value)
    data.append(sheet_read["J" + str(k)].value)
    data.append(sheet_read["K" + str(k)].value)
    data.append(sheet_read["L" + str(k)].value)

    punto = Point(data)
    points.append(punto)

labels =[
    "Patient ID",
    "SARS-Cov-2 exam result",
    "Patient age quantile",
    "Hematocrit",
    "Platelets",
    "Mean platelet volume",
    "Mean corpuscular hemoglobin concentration (MCHC)",
    "Leukocytes",
    "Basophils",
    "Eosinophils",
    "Monocytes",
    "Proteina C reativa mg/dL"
]

print("Construyendo el arbol...")
tree.build(points)
tree.set_labels(labels)

def print_tree(tree):
    print_ = input("Desea imprimir el arbol? (s/n)\n")
    if print_ == "s":
        tree.print_tree()


def get_knn(tree):
    print("Ingrese los valores del punto: ")
    data = [eval(item) for item in input().split()] 
    p = Point(data)
    k = int(input("Ingrese el numero de vecinos mas cercanos: "))
    temp = tree.KNN(p, k)
    for point in temp:
        print(point.data)


def get_range_query(tree):
    rango = Range(tree.dimension)
    rango.set_range()
    temp = tree.range_query(rango)
    print()
    for point in temp:
        print(point.data)



#  main loop
while True:
    print("\n\n")
    print(" ------------------------------------------------------------- ")
    print("|            Operaciones principales del KD-Tree              |")
    print(" ------------------------------------------------------------- ")
    print("|                                                             |")
    print("| 1. Imprimir el arbol                                        |")
    print("| 2. Obtener los k vecinos mas cercanos                       |")
    print("| 3. Obtener los puntos que estan dentro del rango            |")
    print("| 4. Salir                                                    |")
    print("|                                                             |")
    print(" ------------------------------------------------------------- ")
    print("|                                                             ")
    print("| Ingrese una opcion:   ", end="")
    opcion = int(input())
    print("|                                                             ")
    print(" ------------------------------------------------------------- ")
    sleep(1)
    os.system('cls')

    if opcion == 1:
        print_tree(tree)
    elif opcion == 2:
        get_knn(tree)
    elif opcion == 3:
        get_range_query(tree)
    elif opcion == 4:
        break
    else:
        print("Opcion invalida")
    input()
    # clear screen
    os.system('cls')