from tkinter import *
from tkinter import scrolledtext
from tkinter.ttk import *
from function import *

root = Tk()
root.geometry('500x650') 
root.title("Calculadora de funciones Hash")

entrada = Label(root, text="Ingrese el texto a cifrar", font=("Arial", 12))
entrada.grid(row=0, column=0, pady=10)

box_entrada = scrolledtext.ScrolledText(root,width=57,height=10)
box_entrada.grid(row=1,column=0, sticky=W+E, padx=10, pady=10)

tipo = Label(root, text="Seleccione el tipo de algoritmo", font=("Arial", 12))
tipo.grid(row=2, column=0, sticky=W, padx=30)


################## combobox para seleccionar algoritmo ##################

selected_combo = StringVar()

combo = Combobox(root, textvariable=selected_combo)
combo['values']= ("MD4", "MD5", "SHA1", "SHA256", "HMAC")
combo.current(0) 
combo.grid(row=3, column=0, sticky=W, padx=30, pady=10)

def func(event):
    global lbl_clave
    global clave

    if selected_combo.get() == "HMAC":
        lbl_clave = Label(root, text="Clave", font=("Arial", 12))
        lbl_clave.grid(row=4, column=0, sticky=W, padx=30)

        clave = Entry(root,width=40)
        clave.grid(row=4, column=0)

combo.bind('<<ComboboxSelected>>', func)

################## cifrando ##################

def cifrar():
    global opcion

    opcion = combo.get()
    texto = box_entrada.get("1.0", END)
    texto = texto.rstrip('\r\n')

    if opcion == "MD5":
        resultado = MD5(texto)
    elif opcion == "MD4":
        resultado = MD4(texto)
    elif opcion == "SHA1":
        resultado = SHA1(texto)
    elif opcion == "SHA256":
        resultado = SHA256(texto)
    elif opcion == "HMAC":
        resultado = HMACall(clave.get(),texto)

    global salida
    global box_salida
    global lbl1
    global box_salida1
    global lbl2
    global box_salida2
    global lbl3
    global box_salida3

    salida = Label(root, text="Texto cifrado", font=("Arial", 12))
    salida.grid(row=5, column=0, pady=10)

    if opcion != "HMAC":
        box_salida = scrolledtext.ScrolledText(root,width=57,height=10)
        box_salida.grid(row=6,column=0, sticky=W+E, padx=10, pady=10)

        box_salida.insert(INSERT,resultado)

    else: 
        lbl1 = Label(root, text="HMAC-MD5", font=("Arial", 10))
        lbl1.grid(row=6, column=0, sticky=W, padx=5)

        box_salida1 = scrolledtext.ScrolledText(root,width=57,height=3)
        box_salida1.grid(row=7,column=0, sticky=W+E, padx=5, pady=5)
        box_salida1.insert(INSERT,resultado[0])

        lbl2 = Label(root, text="HMAC-SHA256", font=("Arial", 10))
        lbl2.grid(row=8, column=0, sticky=W, padx=5)

        box_salida2 = scrolledtext.ScrolledText(root,width=57,height=3)
        box_salida2.grid(row=9,column=0, sticky=W+E, padx=5, pady=5)
        box_salida2.insert(INSERT,resultado[1])

        lbl3 = Label(root, text="HMAC-SHA1", font=("Arial", 10))
        lbl3.grid(row=10, column=0, sticky=W, padx=5)

        box_salida3 = scrolledtext.ScrolledText(root,width=57,height=3)
        box_salida3.grid(row=11,column=0, sticky=W+E, padx=5, pady=5)
        box_salida3.insert(INSERT,resultado[2])
    

    btn_cifrar['state'] = DISABLED
        
################## limpiar ##################

def limpiar():

    if opcion == "HMAC":
        clave.destroy()
        lbl_clave.destroy()
        salida.destroy()
        lbl1.destroy()
        box_salida1.frame.destroy()
        lbl2.destroy()
        box_salida2.frame.destroy()
        lbl3.destroy()
        box_salida3.frame.destroy()
    else:
        salida.destroy()
        box_salida.frame.destroy()
    
    btn_cifrar['state'] = NORMAL


###########################

btn_cifrar = Button(root, text="Cifrar", command=cifrar)
btn_cifrar.grid(row=3, column=0, sticky=E, padx=150, pady=10)

btn_limpiar = Button(root, text="Limpiar", command=limpiar)
btn_limpiar.grid(row=3, column=0, sticky=E, padx=30, pady=10)

root.mainloop()