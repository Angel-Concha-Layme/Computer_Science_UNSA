from math import sqrt
from re import A, X
from tkinter import Y
import pandas as pd  
import numpy as np

#---------------------------------------------------------------------------------------------------------------------------------#
### CARGAR DATOS 
#---------------------------------------------------------------------------------------------------------------------------------#
ratings_data = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\Ratings.csv', delimiter=',')
movies_data = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos\MovieLens\Small\Movies.csv', delimiter=',')
movie_data = pd.merge(ratings_data, movies_data, on='movieId')

#funcion manhattan para dos usuarios (userId1, userId2)
def manhattan(userId1, userId2,test):
    user1 = test[test['userId'] == userId1]
    #print("user1 : \n ", user1)

    user2 = test[test['userId'] == userId2]
    #print("user2 : \n ", user2)

    #obtener los ratings de cada usuario
    user1_ratings = user1.drop(['userId',"title","genres","timestamp"], axis=1)
    user2_ratings = user2.drop(['userId',"title","genres","timestamp"], axis=1)

    #print("USER1 RATINGS : \n ", user1_ratings)
    #print("USER2 RATINGS : \n ", user2_ratings)

    #obtener las peliculas que ambos usuarios han visto
    #user1 = user1.drop(['userId', 'movieId', 'rating'], axis=1)
    #user2 = user2.drop(['userId', 'movieId', 'rating'], axis=1)

    distance = 0
    commonRatings = False
    for i in range(len(user1_ratings)):
        for j in range(len(user2_ratings)):
            if user1_ratings.iloc[i]['movieId'] !=0 and user2_ratings.iloc[j]['movieId'] !=0:
                if user1_ratings.iloc[i]['movieId'] == user2_ratings.iloc[j]['movieId']:
                    #print("user1_ratings.iloc[i]['movieId'] : ", user1_ratings.iloc[i]['movieId'], "user2_ratings.iloc[j]['movieId'] : ", user2_ratings.iloc[j]['movieId'])
                    distance += abs(user1_ratings.iloc[i]['rating'] - user2_ratings.iloc[j]['rating'])
                    commonRatings = True
    if commonRatings:
        return distance
    else:
        return "No existe parentesco entre los usuarios"





print(manhattan(3,32,movie_data))
