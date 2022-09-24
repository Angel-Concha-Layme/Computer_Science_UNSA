from tkinter import *
from tkinter import ttk
from tkinter import messagebox

ventana = Tk()
ventana.title("Movimiento Rectilineo Uniforme")
ventana.geometry("300x150")
ventana.resizable(0,0)

#variables
velocidad = StringVar()
tiempo = StringVar()
distancia = StringVar()

#funciones
def calcular():
    if velocidad.get() == "" and tiempo.get() != "" and distancia.get() != "":
        velocidad.set(str(float(distancia.get())/float(tiempo.get())))
    elif velocidad.get() != "" and tiempo.get() == "" and distancia.get() != "":
        tiempo.set(str(float(distancia.get())/float(velocidad.get())))
    elif velocidad.get() != "" and tiempo.get() != "" and distancia.get() == "":
        distancia.set(str(float(velocidad.get())*float(tiempo.get())))
    else:
        messagebox.showerror("Error", "Solo debe dejar un campo vacio")

def limpiar():
    velocidad.set("")
    tiempo.set("")
    distancia.set("")
    messagebox.showinfo("Limpiar", "Campos limpiados")

def salir():
    ventana.destroy()

#etiquetas
etiqueta1 = Label(ventana, text="Velocidad (m/s):")
etiqueta1.place(x=10, y=10)
etiqueta2 = Label(ventana, text="Tiempo (s):")
etiqueta2.place(x=10, y=40)
etiqueta3 = Label(ventana, text="Distancia (m):")
etiqueta3.place(x=10, y=70)

#cajas de texto
caja1 = Entry(ventana, textvariable=velocidad)
caja1.place(x=120, y=10)
caja2 = Entry(ventana, textvariable=tiempo)
caja2.place(x=120, y=40)
caja3 = Entry(ventana, textvariable=distancia)
caja3.place(x=120, y=70)

#botones
boton1 = Button(ventana, text="Calcular", command=calcular)
boton1.place(x=10, y=100)
boton2 = Button(ventana, text="Limpiar", command=limpiar)
boton2.place(x=80, y=100)
boton3 = Button(ventana, text="Salir", command=salir)
boton3.place(x=150, y=100)

ventana.mainloop()