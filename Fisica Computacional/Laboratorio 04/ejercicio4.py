"""
Implementar un código computacional para determinar la estrellaución de
la tercera ley de Kepler para cualquier planeta que describa una órbita
elíptica.
"""

import math
import tkinter as tk

G = 6.67408e-11 

ventana = tk.Tk()
ventana.title("Periodo orbital")
ventana.geometry("430x220")

#variables
masa_estrella =tk.Label (ventana, text="Ingrese la masa de la estrella en kg:")
masa_estrella.place(x=10, y=10)
distancia_estrella_planeta = tk.Label(ventana, text="Ingrese la distancia de la estrella al planeta en m:")
distancia_estrella_planeta.place(x=10, y=50)
radio_planeta = tk.Label(ventana, text="Ingrese el radio del planeta en m:")
radio_planeta.place(x=10, y=90)
periodo_orbital = tk.Label(ventana, text="El periodo orbital del planeta es (dias): ")
periodo_orbital.place(x=10, y=130)

#entradas
masa_estrella = tk.Entry(ventana)
masa_estrella.place(x=280, y=10)
distancia_estrella_planeta = tk.Entry(ventana)
distancia_estrella_planeta.place(x=280, y=50)
radio_planeta = tk.Entry(ventana)
radio_planeta.place(x=280, y=90)

#salidas
periodo_orbital = tk.Entry(ventana, state="readonly")
periodo_orbital.place(x=280, y=130)

def periodo_orbital_kepler():
    masa_estrella_ = float(masa_estrella.get())
    print (masa_estrella_)
    radio_orbital = float(distancia_estrella_planeta.get())+float(radio_planeta.get())
    print (radio_orbital)
    K = 4*(math.pi**2)/(G*masa_estrella_)
    T = math.sqrt(K*(radio_orbital**3))
    T = T/60/60/24 #periodo orbital en dias
    periodo_orbital.config(state="normal")
    periodo_orbital.delete(0, tk.END)
    periodo_orbital.insert(0, T)
    periodo_orbital.config(state="readonly")


def limpiar():
    masa_estrella.delete(0, tk.END)
    distancia_estrella_planeta.delete(0, tk.END)
    radio_planeta.delete(0, tk.END)
    periodo_orbital.config(state="normal")
    periodo_orbital.delete(0, tk.END)
    periodo_orbital.config(state="readonly")


boton_calcular = tk.Button(ventana, text="Calcular", command=periodo_orbital_kepler)
boton_calcular.place(x=10, y=170)
boton_limpiar = tk.Button(ventana, text="Limpiar", command=limpiar)
boton_limpiar.place(x=100, y=170)

ventana.mainloop()




#Tierra
#masa_estrella = 1.989e30# 1989000000000000000000000000000
#radio_orbital_tierra = 1.496e11 #Rt+h, donde h es la distancia de la tierra al estrella y Rt es el radio de la tierra
#Rt= 6371000, h= 149600000000

