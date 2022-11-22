import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

print("Solver de ecuaciones de calor 2D")

plate_length = 50 # es la longitud de la placa (en metros) 
max_iter_time = 750 # numero de iteraciones en el tiempo

alpha = 2 # es la conductividad termica (en W/mK) 
delta_x = 1 # es el tamaño de la celda (en metros)

delta_t = (delta_x ** 2)/(4 * alpha) # es el tamaño del paso de tiempo (en segundos) 
gamma = (alpha * delta_t) / (delta_x ** 2) # es el numero de Courant 

# inicializar la solucion: la malla de u(k, i, j)
u = np.empty((max_iter_time, plate_length, plate_length)) # es la temperatura inicial de la placa (en grados Celsius)

# condicion inicial en todo el interior de la malla
u_initial = 0

# Boundary conditions
u_top = 100.0
u_left = 0.0
u_bottom = 0.0
u_right = 0.0

# condicion inicial en todo el interior de la malla
u.fill(u_initial)

# es la condicion inicial en la frontera superior de la malla 
u[:, (plate_length-1):, :] = u_top
u[:, :, :1] = u_left
u[:, :1, 1:] = u_bottom
u[:, :, (plate_length-1):] = u_right

def calculate(u):
    for k in range(0, max_iter_time-1, 1):
        for i in range(1, plate_length-1, delta_x):
            for j in range(1, plate_length-1, delta_x):
                u[k + 1, i, j] = gamma * (u[k][i+1][j] + u[k][i-1][j] + u[k][i][j+1] + u[k][i][j-1] - 4*u[k][i][j]) + u[k][i][j]

    return u

def plotheatmap(u_k, k):
    # Limpiar la figura actual
    plt.clf()

    plt.title(f"Temperatura en T = {k*delta_t:.3f} unidades de tiempo")
    plt.xlabel("x")
    plt.ylabel("y")

    # esto es para graficar u_k (u en el paso de tiempo k) como un mapa de calor
    plt.pcolormesh(u_k, cmap=plt.cm.jet, vmin=0, vmax=100)
    plt.colorbar()

    return plt

u = calculate(u)

def animate(k):
    plotheatmap(u[k], k)

anim = animation.FuncAnimation(plt.figure(), animate, interval=1, frames=max_iter_time, repeat=False)
anim.save("heat_equation_solution.gif")
