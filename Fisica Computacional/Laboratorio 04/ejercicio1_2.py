"""
A partir de la segunda ley de movimiento de Newton y la ley de gravitación universal realice un código que permita determinar el valor de
la gravedad para cualquier planeta del sistema planetario solar.
"""

import tkinter as tk
import math as m 

G = 6.67408e-11

ventana = tk.Tk()
ventana.title("Gravedad y Densidad de un planeta")
ventana.geometry("405x200")


masa = tk.Label(ventana, text="Ingrese la masa del planeta en kg") 
masa.place(x=10, y=10)

radio = tk.Label(ventana, text="Ingrese el radio del planeta en m")
radio.place(x=10, y=50)

gravedad = tk.Label(ventana, text="La gravedad del planeta es (m/s²): ")
gravedad.place(x=10, y=90)

densidad = tk.Label(ventana, text="La densidad del planeta es (g/cm³): ")
densidad.place(x=10, y=130)



masa = tk.Entry(ventana)
masa.place(x=205, y=10)

radio = tk.Entry(ventana)
radio.place(x=205, y=50)

gravedad = tk.Entry(ventana, state="readonly")
gravedad.place(x=205, y=90)

densidad = tk.Entry(ventana, state="readonly")
densidad.place(x=205, y=130)



def limpiar():
    masa.delete(0, tk.END)
    radio.delete(0, tk.END)
    gravedad.config(state="normal")
    gravedad.delete(0, tk.END)
    gravedad.config(state="readonly")
    densidad.config(state="normal")
    densidad.delete(0, tk.END)
    densidad.config(state="readonly")

def calcular():
    calcular_gravedad()
    calcular_densidad()

def calcular_gravedad():
    m = float(masa.get())
    r = float(radio.get())
    g = G*m/r**2

    gravedad.config(state="normal")
    gravedad.delete(0, tk.END)
    gravedad.insert(0, g)
    gravedad.config(state="readonly")

def calcular_densidad():
    g = float(gravedad.get())
    r = float(radio.get())
    
    p = ((3*g)/(4*m.pi*G*r))/1000
    densidad.config(state="normal")
    densidad.delete(0, tk.END)
    densidad.insert(0, p)
    densidad.config(state="readonly")


boton_calcular = tk.Button(ventana, text="Calcular", command=calcular )
boton_calcular.place(x=340, y=25)
boton_calcular.config(width=6)

boton_limpiar = tk.Button(ventana, text="Limpiar", command=limpiar )
boton_limpiar.place(x=340, y=65)
boton_limpiar.config(width=6)


ventana.mainloop()

#EJEMPLO TIERRA
#5,9722 × 10^24= 5972200000000000000000000
#6,371 × 10^6= 6371000






