from tkinter import *
from tkinter import ttk
from tkinter import messagebox

ventana = Tk()
ventana.title("Movimiento Rectilineo Uniformemente Variado")
ventana.geometry("300x180")
ventana.resizable(0,0)

#variables
velocidad_inicial = StringVar()
velocidad_final = StringVar()
tiempo = StringVar()
distancia = StringVar()
aceleracion = StringVar()

def ventana_velocidad_inicial(): 
    ventana2 = Toplevel(ventana)
    ventana2.title("Velocidad inicial")
    ventana2.geometry("300x200")
    ventana2.resizable(0,0)

    #variables
    velocidad_final2 = StringVar()
    tiempo2 = StringVar()
    aceleracion2 = StringVar()

    #etiquetas
    etiqueta1 = Label(ventana2, text="Velocidad Final (m/s):")
    etiqueta1.place(x=10, y=10)

    etiqueta2 = Label(ventana2, text="Tiempo (s):")
    etiqueta2.place(x=10, y=40)

    etiqueta4 = Label(ventana2, text="Aceleracion (m/s^2):")
    etiqueta4.place(x=10, y=70)

    #cajas de texto
    caja1 = Entry(ventana2, textvariable=velocidad_final2)
    caja1.place(x=150, y=10)

    caja2 = Entry(ventana2, textvariable=tiempo2)
    caja2.place(x=150, y=40)

    caja4 = Entry(ventana2, textvariable=aceleracion2)
    caja4.place(x=150, y=70)

    #botones
    boton1 = Button(ventana2, text="Calcular", command=lambda: calcular_velocidad_inicial(velocidad_final2, tiempo2, aceleracion2))
    boton1.place(x=10, y=130)
    #muestra resultado
    etiqueta5 = Label(ventana2, text="Velocidad Inicial (m/s):")
    etiqueta5.place(x=10, y=160)

    caja5 = Entry(ventana2, textvariable=velocidad_inicial)
    caja5.place(x=150, y=160)

def ventana_velocidad_final():
    ventana3 = Toplevel(ventana)
    ventana3.title("Velocidad final")
    ventana3.geometry("300x200")
    ventana3.resizable(0,0)

    #variables
    velocidad_inicial3 = StringVar()
    tiempo3 = StringVar()
    aceleracion3 = StringVar()

    #etiquetas
    etiqueta1 = Label(ventana3, text="Velocidad Inicial (m/s):")
    etiqueta1.place(x=10, y=10)

    etiqueta2 = Label(ventana3, text="Tiempo (s):")
    etiqueta2.place(x=10, y=40)

    etiqueta4 = Label(ventana3, text="Aceleracion (m/s^2):")
    etiqueta4.place(x=10, y=70)

    #cajas de texto
    caja1 = Entry(ventana3, textvariable=velocidad_inicial3)
    caja1.place(x=150, y=10)

    caja2 = Entry(ventana3, textvariable=tiempo3)
    caja2.place(x=150, y=40)

    caja4 = Entry(ventana3, textvariable=aceleracion3)
    caja4.place(x=150, y=70)

    #botones
    boton1 = Button(ventana3, text="Calcular", command=lambda: calcular_velocidad_final(velocidad_inicial3, tiempo3, aceleracion3))
    boton1.place(x=10, y=130)
    #muestra resultado
    etiqueta5 = Label(ventana3, text="Velocidad Final (m/s):")
    etiqueta5.place(x=10, y=160)

    caja5 = Entry(ventana3, textvariable=velocidad_final)
    caja5.place(x=150, y=160)

def ventana_tiempo():
    ventana4 = Toplevel(ventana)
    ventana4.title("Tiempo")
    ventana4.geometry("300x200")
    ventana4.resizable(0,0)

    #variables
    velocidad_inicial4 = StringVar()
    velocidad_final4 = StringVar()
    aceleracion4 = StringVar()

    #etiquetas
    etiqueta1 = Label(ventana4, text="Velocidad Inicial (m/s):")
    etiqueta1.place(x=10, y=10)

    etiqueta2 = Label(ventana4, text="Velocidad Final (m/s):")
    etiqueta2.place(x=10, y=40)

    etiqueta4 = Label(ventana4, text="Aceleracion (m/s^2):")
    etiqueta4.place(x=10, y=70)

    #cajas de texto
    caja1 = Entry(ventana4, textvariable=velocidad_inicial4)
    caja1.place(x=150, y=10)

    caja2 = Entry(ventana4, textvariable=velocidad_final4)
    caja2.place(x=150, y=40)

    caja4 = Entry(ventana4, textvariable=aceleracion4)
    caja4.place(x=150, y=70)

    #botones
    boton1 = Button(ventana4, text="Calcular", command=lambda: calcular_tiempo(velocidad_inicial4, velocidad_final4, aceleracion4))
    boton1.place(x=10, y=130)
    #muestra resultado
    etiqueta5 = Label(ventana4, text="Tiempo (s):")
    etiqueta5.place(x=10, y=160)

    caja5 = Entry(ventana4, textvariable=tiempo)
    caja5.place(x=150, y=160)

def ventana_distancia():   
    ventana5 = Toplevel(ventana)
    ventana5.title("Distancia")
    ventana5.geometry("300x200")
    ventana5.resizable(0,0)

    #variables
    velocidad_inicial5 = StringVar()
    tiempo5 = StringVar()
    aceleracion5 = StringVar()

    #etiquetas
    etiqueta1 = Label(ventana5, text="Velocidad Inicial (m/s):")
    etiqueta1.place(x=10, y=10)

    etiqueta2 = Label(ventana5, text="Tiempo (s):")
    etiqueta2.place(x=10, y=40)

    etiqueta4 = Label(ventana5, text="Aceleracion (m/s^2):")
    etiqueta4.place(x=10, y=70)

    #cajas de texto
    caja1 = Entry(ventana5, textvariable=velocidad_inicial5)
    caja1.place(x=150, y=10)

    caja2 = Entry(ventana5, textvariable=tiempo5)
    caja2.place(x=150, y=40)

    caja4 = Entry(ventana5, textvariable=aceleracion5)
    caja4.place(x=150, y=70)

    #botones
    boton1 = Button(ventana5, text="Calcular", command=lambda: calcular_distancia(velocidad_inicial5, tiempo5, aceleracion5))
    boton1.place(x=10, y=130)
    #muestra resultado
    etiqueta5 = Label(ventana5, text="Distancia (m):")
    etiqueta5.place(x=10, y=160)

    caja5 = Entry(ventana5, textvariable=distancia)
    caja5.place(x=150, y=160)
    
def ventana_aceleracion():
    ventana6 = Toplevel(ventana)
    ventana6.title("Aceleracion")
    ventana6.geometry("300x200")
    ventana6.resizable(0,0)

    #variables
    velocidad_inicial6 = StringVar()
    velocidad_final6 = StringVar()
    tiempo6 = StringVar()

    #etiquetas
    etiqueta1 = Label(ventana6, text="Velocidad Inicial (m/s):")
    etiqueta1.place(x=10, y=10)

    etiqueta2 = Label(ventana6, text="Velocidad Final (m/s):")
    etiqueta2.place(x=10, y=40)

    etiqueta4 = Label(ventana6, text="Tiempo (s):")
    etiqueta4.place(x=10, y=70)

    #cajas de texto
    caja1 = Entry(ventana6, textvariable=velocidad_inicial6)
    caja1.place(x=150, y=10)

    caja2 = Entry(ventana6, textvariable=velocidad_final6)
    caja2.place(x=150, y=40)

    caja4 = Entry(ventana6, textvariable=tiempo6)
    caja4.place(x=150, y=70)

    #botones
    boton1 = Button(ventana6, text="Calcular", command=lambda: calcular_aceleracion(velocidad_inicial6, velocidad_final6, tiempo6))
    boton1.place(x=10, y=130)
    #muestra resultado
    etiqueta5 = Label(ventana6, text="Aceleracion (m/s^2):")
    etiqueta5.place(x=10, y=160)

    caja5 = Entry(ventana6, textvariable=aceleracion)
    caja5.place(x=150, y=160)

def calcular_acelaraion(velocidad_inicial, velocidad_final, tiempo):
    aceleracion.set((velocidad_final.get() - velocidad_inicial.get()) / tiempo.get())

def calcular_distancia(velocidad_inicial5, tiempo5, aceleracion5):
    distancia.set(float(velocidad_inicial5.get())*float(tiempo5.get())+0.5*float(aceleracion5.get())*float(tiempo5.get())**2)

def calcular_tiempo(velocidad_inicial4, velocidad_final4, aceleracion4):
    try:
        velocidad_inicial4 = float(velocidad_inicial4.get())
        velocidad_final4 = float(velocidad_final4.get())
        aceleracion4 = float(aceleracion4.get())
        tiempo.set((velocidad_final4 - velocidad_inicial4)/aceleracion4)
    except:
        messagebox.showerror("Error", "Ingrese valores validos")

def calcular_velocidad_final(velocidad_inicial3, tiempo3, aceleracion3):
    try:
        vi = float(velocidad_inicial3.get())
        t = float(tiempo3.get())
        a = float(aceleracion3.get())

        vf = vi + (a*t)
        velocidad_final.set(vf)
        return vf

    except:
        messagebox.showerror("Error", "No se puede calcular")

def calcular_velocidad_inicial(velocidad_final2, tiempo2, aceleracion2):
    try:
        vf = float(velocidad_final2.get())
        t = float(tiempo2.get())
        a = float(aceleracion2.get())

        vi = vf - (a*t)
        velocidad_inicial.set(vi)
        return vi

    except:
        messagebox.showerror("Error", "No se puede calcular")
     
boton1 = Button(ventana, text="Calcular velocidad inicial", command=ventana_velocidad_inicial, width=30 )
boton1.place(x=15, y=10)

boton2 = Button(ventana, text="Calcular velocidad final", command=ventana_velocidad_final, width=30)
boton2.place(x=15, y=40)

boton3 = Button(ventana, text="Calcular tiempo", command=ventana_tiempo, width=30)
boton3.place(x=15, y=70)

boton4 = Button(ventana, text="Calcular distancia", command=ventana_distancia, width=30)
boton4.place(x=15, y=100)

boton5 = Button(ventana, text="Calcular aceleracion", command= ventana_aceleracion, width=30)
boton5.place(x=15, y=130)


ventana.mainloop()