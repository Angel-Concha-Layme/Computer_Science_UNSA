from math import *
import pandas as pd
import numpy as np
import tkinter as tk
from tkinter import *


ratingDf=pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\Ratings.csv', delimiter=',')
moviesDf=pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\MovieLens\Small\Movies.csv', delimiter=',')
users=dict()

arr=np.array(ratingDf.iloc[:,])
arrMov=np.array(moviesDf.iloc[:,])

#diccionario de rating
for i in arr:
    userId, movieId = int(i[0]), int(i[1]) 
    rating = float(i[2])
    if userId not in users:
        users[userId] = {movieId: rating}
    else:
        users[userId][movieId] = rating

movies=dict()
#diccionario de peliculas
for i in arrMov:
    movieId = int(i[0])
    movieTitle = i[1]
    movies[movieId] = movieTitle

print("Completado")

"""
#Contamos los elementos junto con sus caracteristicas
print("Cantidad de usuarios")
print(len(users))
print("Cantidad de peliculas")
print(len(movies))
print("Nro Registros promedio por pelicula")
promedio=0
for i in users:
    promedio=promedio+len(users[i])
print(promedio/len(users))
print("Porcentaje de uso %")
print( (promedio/len(users))*100/len(movies))



print("Cantidad de usuarios")
print(len(users))
print("Cantidad de peliculas")
print(len(movies))
print("Nro Registros promedio por pelicula")
promedio=0
maximo=0
minimo=len(movies)
id_max=0
id_min=0
for i in users:
    promedio=promedio+len(users[i])
    if len(users[i])>maximo:
        maximo=len(users[i])
        id_max=i
    if len(users[i])<minimo:
        minimo=len(users[i])
        id_min=i
print(promedio/len(users))
print("Porcentaje de uso %")
print( (promedio/len(users))*100/len(movies))
print("Minimo %")
print(minimo)
print((minimo)*100/len(movies))
print("Maximo %")
print(maximo)
print((maximo)*100/len(movies))
print("id del maximo")
print(id_max)
print("id del minimo")
print(id_min)

"""


def cosine(rating_1, rating_2):
    xy=0
    xx=0
    yy=0
    ing=True

    for i in rating_1:
        if i in rating_2:
            xy=xy+rating_1[i]*rating_2[i]
            xx=xx+rating_1[i]*rating_1[i]
            yy=yy+rating_2[i]*rating_2[i]
            ing=False
    
    if xx==0 or yy==0 or ing:
        ang=-100
    else:
        ang=xy/(sqrt(xx)*sqrt(yy))
    return ang

def pearson(rating_1,rating_2):
    xy=0
    x=0
    y=0
    xx=0
    yy=0
    n=0
    
    for i in rating_1:
        if i in rating_2:
            n=n+1
            xy=xy+rating_1[i]*rating_2[i]
            x=x+rating_1[i]
            y=y+rating_2[i]
            xx=xx+rating_1[i]*rating_1[i]
            yy=yy+rating_2[i]*rating_2[i]
            
    if n==0:
        r=-100
    else:
        if sqrt(xx-(x*x/n))==0 or sqrt(yy-(y*y/n))==0:
            r=-1
        else:
            r=(xy-((x*y)/n))/(sqrt(xx-(x*x/n))*sqrt(yy-(y*y/n)))
    return r

def manhattan(rating_1, rating_2):
    distance = 0.0
    ing=True
    for i in rating_1:
        if i in rating_2:
            distance = distance + abs(rating_1[i] - rating_2[i])
            ing=False
    if ing:
        return -100
    else:
        return distance

def euclidean(rating_1, rating_2):
    distance = 0.0
    ing=True
    for i in rating_1:
        if i in rating_2:
            distance += (rating_1[i] - rating_2[i])**2 
            ing=False
    if ing:
        return -100
    else:
        return sqrt(distance)

def get_neighbors(users,id_test,distancia):
    distances = list()
    for i in users:
        if (i!=id_test):
            dist = distancia(users[i],users[id_test])
            if dist!=-100:
                distances.append((i,dist))
    distances.sort(key=lambda tup: tup[1])
    return distances


def knn(result,users,persona,vecinos,distancia):
    neighbors = get_neighbors(users,persona,distancia)
    contador=0
    if distancia==euclidean or distancia==manhattan:
        for i in range( len(users.keys()) ):
            result[neighbors[i][0]+1] =neighbors[i][1]
            contador=contador+1
            if contador==vecinos:
                break            
    else:
        for i in range( len(users.keys()) ):
            result[neighbors[len(neighbors)-i-1][0]+1] = neighbors[len(neighbors)-i-1][1]
            contador=contador+1
            if contador==vecinos:
                break


def recomendacion(users,persona,vecinos,distancia,nro_peliculas):
    result=dict()
    knn(result,users,persona,vecinos,distancia)
    recom = list()
    #halla los k vecinos mas cercanos
    for peli in movies:
        #calcula los factores de influecnia de los k vecinos sobre la pelicula peli de movies
        calificacion=0
        total=0
        cantidad=0
        #sumatoria de distancia
        for i in result:
            if peli in users[i]:
                total=total+result[i]
                cantidad=cantidad+1
        #sumatoria de peso
        for i in result:
            if peli in users[i]:
                calificacion=calificacion+result[i]*users[i][peli]
                
        #puede no haber coincidencia ninguna, en ese caso total=0
        if total !=0:
            #si la recomendacion es de 2 o menos personas no tiene mucha validez
            if cantidad>2:
                recom.append((peli,calificacion/total))
                
    #ordenamos los valores recomendados para saber cual le gusta mas
    recom.sort(key=lambda tup: tup[1])
    i=0
    j=0
    while(i<len(recom) and j<nro_peliculas ):
        if recom[len(recom)-i-1][1]>0: 
            print(movies[recom[len(recom)-i-1][0]]+" con puntaje de: "+str(recom[len(recom)-i-1][1]))
            j=j+1
        i=i+1


"""
persona = 500
vecinos=10
result=dict()
knn(result,users,persona,vecinos,euclidean)
"""

"""
persona = 380
vecinos=10
result=dict()
knn(result,users,persona,vecinos,manhattan)
"""

"""
persona = 580
vecinos=10
result=dict()
knn(result,users,persona,vecinos,pearson)
"""

"""
persona = 580
vecinos=10
result=dict()
knn(result,users,persona,vecinos,cosine)
"""

import time
start_time = time.time() 
recomendacion(users,580,10,euclidean,10)
print("--- %s seconds ---" % (time.time() - start_time))
