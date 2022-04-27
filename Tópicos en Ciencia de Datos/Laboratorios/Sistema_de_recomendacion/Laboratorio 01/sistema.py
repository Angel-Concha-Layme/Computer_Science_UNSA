from math import sqrt
from re import A, S, X
from tkinter import Y
import pandas as pd  
import numpy as np

#---------------------------------------------------------------------------------------------------------------------------------#
### CARGAR DATOS 
#---------------------------------------------------------------------------------------------------------------------------------#
Movie_ratings = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\Movie_Ratings.csv',delimiter=',')
processed_movie_rating = Movie_ratings.fillna(0)
Processed_Movie_Ratings = processed_movie_rating.to_dict(orient= 'index')

Music_ratings = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\Music_Ratings.csv',delimiter=',')
processed_music_rating = Music_ratings.fillna(0)
Processed_Music_Ratings = processed_music_rating.to_dict()#list 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA COSENO 
#---------------------------------------------------------------------------------------------------------------------------------#
def cosine_similarity(rating1, rating2):
    #compute numerator
    x_dot_y = 0
    for key in rating1:
        if key in rating2:
            x_dot_y += rating1[key]*rating2[key]

    #compute denominator
    size_x = 0
    size_y = 0

    for key in rating1:
        size_x += pow(rating1[key],2)
        size_y += pow(rating2[key],2)

    size_x = sqrt(size_x)
    size_y = sqrt(size_y)

    return x_dot_y/(size_x*size_y)
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA COSENO: esta vez no se tiene en cuenta los espacios en blanco
#---------------------------------------------------------------------------------------------------------------------------------#
def cosine_similarity_2(rating1, rating2):
    #compute numerator
    x_dot_y = 0
    for key in rating1:
        if key in rating2:
            x_dot_y += rating1[key]*rating2[key]
    #compute denominator
    size_x = 0
    size_y = 0

    for key in rating1:
        if rating2[key] != 0:
            size_x += pow(rating1[key],2)
    
    for key in rating2:
        if rating1[key] != 0:
            size_y += pow(rating2[key],2)

    size_x = sqrt(size_x)
    size_y = sqrt(size_y)

    return x_dot_y/(size_x*size_y)


#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#



#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA MINKOWSKI: Podemos generalizar la distancia de Manhattan y la distancia euclidiana a lo que se llama la métrica de distancia de Minkowski:
#---------------------------------------------------------------------------------------------------------------------------------#
def minkowski(rating1, rating2, r):
    distance = 0
    commonRatings = False
    for key in rating1:
        if key in rating2:
            distance += pow(abs(rating1[key] - rating2[key]), r)
            commonRatings = True
    if commonRatings:
        return pow(distance, 1/r)
    else:
        return 0 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA MANHATTAN
#---------------------------------------------------------------------------------------------------------------------------------#
def manhattan(rating1, rating2):
    distance = 0
    commonRatings = False 
    for key in rating1:
        if key in rating2 and rating1[key] != 0 and rating2[key] != 0:
            distance += abs(rating1[key] - rating2[key])
            commonRatings = True
    if commonRatings:
        return distance
    else:
        return -1 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA EUCLIDIANA
#---------------------------------------------------------------------------------------------------------------------------------#
def euclidean(rating1, rating2):
    distance = 0
    commonRatings = False 
    for key in rating1:
        if key in rating2:
            if rating1[key] != 0 and rating2[key] != 0:
                distance += pow(rating1[key] - rating2[key], 2)
                commonRatings = True
    if commonRatings:
        return sqrt(distance)
    else:
        return 0 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#

#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA EUCLIDIANA
#---------------------------------------------------------------------------------------------------------------------------------#
def euclidean_2(rating1, rating2):
    distance = 0
    commonRatings = False 
    for key in rating1:
        if key in rating2:
            distance += pow(rating1[key] - rating2[key], 2)
            commonRatings = True
    if commonRatings:
        return sqrt(distance)
    else:
        return 0 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#




#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA PEARSON: No se toman los valores faltantes (solo en el denominador)
#---------------------------------------------------------------------------------------------------------------------------------#
def pearson(rating1, rating2):
    #compute numerator
    sum_xy = 0
    sum_x = 0
    sum_y = 0
    sum_x2 = 0
    sum_y2 = 0
    n = 0
    for key in rating1:
        if key in rating2:
            if rating1[key] != 0 and rating2[key] != 0:
                n += 1
                sum_xy += rating1[key]*rating2[key]
                sum_x += rating1[key]
                sum_y += rating2[key]
                sum_x2 += pow(rating1[key],2)
                sum_y2 += pow(rating2[key],2)
    #compute denominator
    denominator = sqrt(sum_x2 - pow(sum_x,2)/n)*sqrt(sum_y2 - pow(sum_y,2)/n)
    if denominator == 0:
        return None
    else:
        return (sum_xy - (sum_x*sum_y)/n)/denominator

#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#



#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA PEARSON: se toman todos los valores
#---------------------------------------------------------------------------------------------------------------------------------#
def pearson_2(rating1, rating2):
    #compute numerator
    sum_xy = 0
    sum_x = 0
    sum_y = 0
    sum_x2 = 0
    sum_y2 = 0
    n = 0
    for key in rating1:
        if key in rating2:
            n += 1
            sum_xy += rating1[key]*rating2[key]
            sum_x += rating1[key]
            sum_y += rating2[key]
            sum_x2 += pow(rating1[key],2)
            sum_y2 += pow(rating2[key],2)
    #compute denominator
    denominator = sqrt(sum_x2 - pow(sum_x,2)/n)*sqrt(sum_y2 - pow(sum_y,2)/n)
    if denominator == 0:
        return None
    else:
        return (sum_xy - (sum_x*sum_y)/n)/denominator
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#
"""
def knn(usuario, usuarios):
    distancias =[]
    user=1
    for user in usuarios:
        distancias.append((euclidean(usuario, usuarios[user]), user))
    distancias.sort()
    return distancias

#knn(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings)

print(Processed_Music_Ratings['Angelica'])
print('\n')
#imprimir diccionario Processed_Music_Ratings

for key in Processed_Music_Ratings:
    print(Processed_Music_Ratings[key])

#imprimir a partir del segundo elemento
for key in Processed_Music_Ratings:
    for key2 in Processed_Music_Ratings[key]:
        # si key and key 2 son str
        if isinstance(key, str) and isinstance(key2, str):
            print(key, key2)
        # si key and key 2 son int
        elif isinstance(key, int) and isinstance(key2, int):
            print(key, key2)
""" 
    


#---------------------------------------------------------------------------------------------------------------------------------#
### PRUEBAS CON MUSIC_RATINGS
#---------------------------------------------------------------------------------------------------------------------------------#
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Angelica']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Bill']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Chan']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Dan']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Hailey']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Jordyn']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Sam']))
print(euclidean(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Veronica']))
print('\n')
print('EUCLIDIANA 2')
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Veronica']))
print('\n')
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Angelica']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Bill']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Chan']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Dan']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Hailey']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Jordyn']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Sam']))
print(euclidean_2(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Veronica']))


print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Bill'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Chan'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Dan'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Jordyn'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Angelica']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Sam'], Processed_Music_Ratings['Veronica']))

print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Angelica']))  
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Bill']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Chan']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Dan']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Hailey']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Jordyn']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Sam']))
print(manhattan(Processed_Music_Ratings['Veronica'], Processed_Music_Ratings['Veronica']))
