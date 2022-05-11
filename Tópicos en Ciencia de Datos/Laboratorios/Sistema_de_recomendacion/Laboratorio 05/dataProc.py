from numpy import kaiser


def data_filter(user, movie, rating, timestamp):
    return {"userId": user, "movieId": movie, "rating": rating, "timestamp": timestamp}


def formMatrix(): # Forma la matriz de datos
    matrix = {}
    f = open(r"C:\Users\aconc\Desktop\Mis_archivos\Computer_Science_UNSA\Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Laboratorio 05\Ratings.csv")
    lines = f.readlines() # Lee todas las lineas del archivo
    for line in lines: # Para cada linea
        #separar datos por comas
        userId, movieId, rating, timestamp = line.split(",")
        data = data_filter(userId, movieId, rating, timestamp) # Crea un diccionario con los datos
        if data["userId"] in matrix:
            matrix[data["userId"]][data["movieId"]] = data["rating"]
        else:  
            matrix[data["userId"]] = {data["movieId"]: data["rating"]}
    f.close()
    #print(matrix)

# {'1': {'1': '4', '3': '4', '6': '4'}, '3': {'72378': '0.5'}, '4': {'21': '3', '32': '2'}, '5': {'608': '3'}}
    return matrix

formMatrix()