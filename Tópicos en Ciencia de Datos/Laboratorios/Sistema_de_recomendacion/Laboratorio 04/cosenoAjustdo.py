import codecs 
from math import sqrt
import numpy as np
import pandas as pd

from matplotlib.pyplot import get

users = {"Amy": {"Taylor Swift": 4, "PSY": 3, "Whitney Houston": 4},
          "Ben": {"Taylor Swift": 5, "PSY": 2},
          "Clara": {"PSY": 3.5, "Whitney Houston": 4},
          "Daisy": {"Taylor Swift": 5, "Whitney Houston": 3}}

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

#slope one algorithm
def slopeOne(userId, movieId):
   ratings = users[userId]
   print(ratings)

slopeOne(1,1)

