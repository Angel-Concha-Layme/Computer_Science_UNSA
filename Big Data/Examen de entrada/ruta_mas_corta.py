
def encontrar_ruta_mas_corta(matriz):
    m = len(matriz)  
    n = len(matriz[0])

    accumulated_costs = [[0] * n for _ in range(m)]  

    accumulated_costs[0][0] = matriz[0][0]
    
    # columna 1 - pesos
    for i in range(1, m):
        accumulated_costs[i][0] = accumulated_costs[i-1][0] + matriz[i][0]

    # fila 1 - pesos 
    for j in range(1, n):
        accumulated_costs[0][j] = accumulated_costs[0][j-1] + matriz[0][j]

    # ruta más corta
    for i in range(1, m):
        for j in range(1, n):
            accumulated_costs[i][j] = min(accumulated_costs[i-1][j], accumulated_costs[i][j-1]) + matriz[i][j]

    
    # construir la ruta
    ruta = []
    i = m - 1
    j = n - 1
    ruta.append((i, j)) 


    while i > 0 or j > 0:
        if i == 0:
            j -= 1
        elif j == 0:
            i -= 1
        else:
            if accumulated_costs[i-1][j] < accumulated_costs[i][j-1]:
                i -= 1
            else:
                j -= 1
        ruta.append((i, j))


    ruta.reverse()  # superior izquierda a inferior derecha

    #print("Ruta:")
    #for pos in ruta:
        #i, j = pos
        #valor = matriz[i][j]
        #print(f"Posicion: ({i}, {j}), Valor: {valor}")
    print("Costo total:", accumulated_costs[m-1][n-1])


def encontrar_ruta_mas_corta2(matriz):
    m = len(matriz)  # número de filas
    n = len(matriz[0])  # número de columnas

    # Creamos una matriz auxiliar para almacenar los costos acumulados
    dp = [[0] * n for _ in range(m)]

    # Inicializamos la primera fila
    dp[0][0] = matriz[0][0]
    for j in range(1, n):
        dp[0][j] = dp[0][j-1] + matriz[0][j]

    # Inicializamos la primera columna
    for i in range(1, m):
        dp[i][0] = dp[i-1][0] + matriz[i][0]

    # Calculamos los costos acumulados y la ruta más corta
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matriz[i][j]

    # Construimos la ruta más corta
    ruta = []
    i = 0
    j = 0
    ruta.append((i, j))  # Agregamos la posición inicial

    while i < m-1 or j < n-1:
        if i == m-1:
            j += 1
        elif j == n-1:
            i += 1
        else:
            if dp[i+1][j] < dp[i][j+1]:
                i += 1
            else:
                j += 1
        ruta.append((i, j))

    print("Costo total:", dp[m-1][n-1])


def leer_matriz_desde_archivo(nombre_archivo):
    matriz = []
    with open(nombre_archivo, 'r') as archivo:
        for linea in archivo:
            fila = list(map(int, linea.strip().split()))
            matriz.append(fila)
    return matriz

nombre_archivo = 'Examen de entrada\matriz.txt'
matriz = leer_matriz_desde_archivo(nombre_archivo)


encontrar_ruta_mas_corta(matriz)
encontrar_ruta_mas_corta2(matriz)


