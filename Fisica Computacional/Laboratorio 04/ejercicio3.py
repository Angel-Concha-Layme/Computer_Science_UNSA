"""
Implementar un código computacional para la solución de la segunda
ley de Kepler.
"""
import tkinter as tk

ventana = tk.Tk()
ventana.title("Segunda ley de kepler")
ventana.geometry("400x300")

masa = tk.Label(ventana, text="Ingrese la masa del planeta en kg")
masa.place(x=10, y=10)
velocidad = tk.Label(ventana, text="Ingrese la velocidad del planeta en m/s")
velocidad.place(x=10, y=30)
radio = tk.Label(ventana, text="Ingrese el radio del planeta en m")
radio.place(x=10, y=50)
tiempo = tk.Label(ventana, text="Ingrese el tiempo en segundos")
tiempo.place(x=10, y=70)
resultado = tk.Label(ventana, text="El cambio de area en m^2 es: ")
resultado.place(x=10, y=140)



masa = tk.Entry(ventana)
masa.place(x=240, y=10)
velocidad = tk.Entry(ventana)
velocidad.place(x=240, y=30)
radio = tk.Entry(ventana)
radio.place(x=240, y=50)
tiempo = tk.Entry(ventana)
tiempo.place(x=240, y=70)
resultado = tk.Entry(ventana, state="readonly")
resultado.place(x=240, y=140)



def ley_2_kepler():
    M_p = float(masa.get())
    V_p = float(velocidad.get())
    R_p = float(radio.get())
    t = float(tiempo.get())

    area = M_p * V_p * R_p / (2 * M_p) * t

    resultado.config(state="normal")
    resultado.delete(0, tk.END)
    resultado.insert(0, area)
    resultado.config(state="readonly")

def limpiar():
    masa.delete(0, tk.END)
    velocidad.delete(0, tk.END)
    radio.delete(0, tk.END)
    tiempo.delete(0, tk.END)
    resultado.config(state="normal")
    resultado.delete(0, tk.END)
    resultado.config(state="readonly")


calcular = tk.Button(ventana, text="Calcular", command=ley_2_kepler)
calcular.place(x=10, y=100)


limpiar = tk.Button(ventana, text="Limpiar", command=limpiar)
limpiar.place(x=100, y=100)


ventana.mainloop()