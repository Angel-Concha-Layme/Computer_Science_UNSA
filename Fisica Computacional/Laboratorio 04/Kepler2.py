"""
Implementar un código computacional para la solución de la segunda
ley de Kepler.
"""

import tkinter as tk

ventana = tk.Tk()
ventana.title("Segunda ley de kepler")
ventana.geometry("400x300")


planeta1 = tk.Label(ventana, text="PLANETA 1")
planeta1.place(x=10, y=10)
masa1 = tk.Label(ventana, text="Ingrese la masa del planeta 1 en kg")
masa1.place(x=10, y=30)
radio1 = tk.Label(ventana, text="Ingrese el radio del planeta 1 en m")
radio1.place(x=10, y=50)
velocidad1 = tk.Label(ventana, text="Ingrese la velocidad del planeta 1 en m/s")
velocidad1.place(x=10, y=70)
planeta2 = tk.Label(ventana, text="PLANETA 2")
planeta2.place(x=10, y=100)
masa2 = tk.Label(ventana, text="Ingrese la masa del planeta 2 en kg")
masa2.place(x=10, y=120)
radio2 = tk.Label(ventana, text="Ingrese el radio del planeta 2 en m")
radio2.place(x=10, y=140)
velocidad2 = tk.Label(ventana, text="Ingrese la velocidad del planeta 2 en m/s")
velocidad2.place(x=10, y=160)



masa1 = tk.Entry(ventana)
masa1.place(x=240, y=30)
radio1 = tk.Entry(ventana)
radio1.place(x=240, y=50)
velocidad1 = tk.Entry(ventana)
velocidad1.place(x=240, y=70)
masa2 = tk.Entry(ventana)
masa2.place(x=240, y=120)
radio2 = tk.Entry(ventana)
radio2.place(x=240, y=140)
velocidad2 = tk.Entry(ventana)
velocidad2.place(x=240, y=160)


resultado = tk.Label(ventana, text=" ")
resultado.place(x=10, y=200)
resultado.config(fg="red", font=("Verdana",11)) 


def limpiar():
    masa1.delete(0, tk.END)
    radio1.delete(0, tk.END)
    velocidad1.delete(0, tk.END)
    masa2.delete(0, tk.END)
    radio2.delete(0, tk.END)
    velocidad2.delete(0, tk.END)
    resultado.config(text=" ")

def segunda_kepler():
    m1 = float(masa1.get())
    m2 = float(masa2.get())
    r1 = float(radio1.get())
    r2 = float(radio2.get())
    v1 = float(velocidad1.get())
    v2 = float(velocidad2.get())
    l1 = m1*r1*v1
    l2 = m2*r2*v2
    if l1 == l2:
        resultado.config(text="La ley de kepler se cumple para estos planetas")
    else:
        resultado.config(text="La ley de kepler no se cumple para estos planetas")



boton = tk.Button(ventana, text="Calcular", command=segunda_kepler)
boton.place(x=10, y=250)

boton2 = tk.Button(ventana, text="Limpiar", command=limpiar)
boton2.place(x=100, y=250)



ventana.mainloop()


