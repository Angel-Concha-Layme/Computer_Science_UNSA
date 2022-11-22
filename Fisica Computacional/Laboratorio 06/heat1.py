import numpy as np
import matplotlib.pyplot as plt
k = 1.172E-5

#T0: temperatura interna
#T1: temperatura en la frontera 1
#T2: temperatura en la frontera 2
#T3: temperatura en la frontera 3
#T4: temperatura en la frontera 4
#tf: tiempo final
#dt: paso de tiempo
#nx: numero de puntos en la direccion x
#ny: numero de puntos en la direccion y


def ecuacion_calor(T0,T1,T2,T3,T4,tf,dt,nx,ny):
    #parametros fisicos
    Lx = 0.1 # longitud de la barra
    Ly = 0.1 # ancho de la barra

    # calcular el largo de la celda en las direcciones x e y
    dx = Lx/nx; # longitud de la celda en la direccion x
    dy = Ly/ny; # longitud de la celda en la direccion y

    # Numeros de courant 
    r1 = k*dt/(dx**2); # numero de Courant en la direccion x
    r2 = k*dt/(dy**2); # numero de Courant en la direccion y

    if (r1 > 0.5 or r2 > 0.5): # si el numero de Courant es mayor a 0.5, el metodo no es estable y no se puede usar para resolver la ecuacion
        raise TypeError('Unstable Solution!')

    T = np.zeros((nx,ny,int(tf/dt))) # matriz de temperatura

    # Condiciones iniciales
    for i in range(0,nx-1): 
        for j in range(1,ny-1):
            T[i,j,0] = T0

    # condiciones de frontera
    for i in range(0,nx):
        T[i,0,0]=T1
        T[i,ny-1,0]=T2

    for j in range(0,ny):
        T[0,j,0]=T3
        T[nx-1,j,0]=T4

    # generacion de malla 2D
    X = np.linspace(0, Lx, nx, endpoint=True)
    Y = np.linspace(0, Ly, ny, endpoint=True)
    X, Y = np.meshgrid(X, Y)

    # solucion numerica de la ecuacion de ecuacion_calor en 2D usando el metodo de diferencias finitas
    for t in range (0,int(tf/dt)-1):
        for i in range(1,(nx-1)):
            for j in range (1,(ny-1)):				
                a=(T[i+1,j,t]-2*T[i,j,t]+T[i-1,j,t])/dx**2
                b=(T[i,j+1,t]-2*T[i,j,t]+T[i,j-1,t])/dy**2
                T[i,j,t+1]=k*dt*(a+b)+T[i,j,t]

    fig = plt.figure()
    ax = fig.add_subplot(111, projection = '3d')
    ax.plot_surface(X, Y, T[:,:,int(tf/dt)-1], cmap = 'gist_rainbow_r', edgecolor = 'none')
    ax.set_xlabel('X [m]')
    ax.set_ylabel('Y [m]')
    ax.set_zlabel('T [°]')

    plt.show()

    return T

#EJEMPLOS
ecuacion_calor(1,0,0,0,0,10,0.1,40,40)
ecuacion_calor(1,0,0,0,0,5,0.1,10,10)
ecuacion_calor(1,0,0,0,0,80,0.1,19,19)
