import tkinter as tk
from tkinter import ttk
from tkinter import messagebox


#ventana
ventana = tk.Tk()
ventana.title("Ecuacion de primer grado")
ventana.geometry("400x300")

#variables
Elongacion = tk.StringVar() #x
Amplitud = tk.StringVar() #A 
Frecuencia = tk.StringVar() #f
Periodo = tk.StringVar() #T
Frecuenta_angular = tk.StringVar() #w

#etiquetas
etiqueta1 = ttk.Label(text="Elongacion")