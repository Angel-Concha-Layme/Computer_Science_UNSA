from cgi import print_arguments
from math import sqrt
from re import X
from tkinter import Y
from traceback import print_tb
import pandas as pd  
import numpy as np

#---------------------------------------------------------------------------------------------------------------------------------#
### CARGAR DATOS 
#---------------------------------------------------------------------------------------------------------------------------------#
Movie_ratings = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Movie_Ratings.csv',delimiter=',')
processed_movie_rating = Movie_ratings.fillna(0)
Processed_Movie_Ratings = processed_movie_rating.to_dict()

Music_ratings = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Music_Ratings.csv',delimiter=',')
processed_music_rating = Music_ratings.fillna(0)
Processed_Music_Ratings = processed_music_rating.to_dict()
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA COSENO 
#---------------------------------------------------------------------------------------------------------------------------------#
def cosine_similarity(rating1, rating2):
    #compute numerator
    x = 0
    y = 0
    for key in rating1:
        x += pow(rating1[key],2)
    for key in rating2:
        y += pow(rating2[key],2)
    
    x = sqrt(x) 
    y = sqrt(y)

    #compute denominator
    sum_xy = 0
    for key in rating1:
        if key in rating2:
            sum_xy += rating1[key]*rating2[key]
    return sum_xy/(x*y)
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
            distance += pow(abs(rating1[key] - rating2[key]), 2)
            commonRatings = True
    if commonRatings:
        return sqrt(distance)
    else:
        return 0 
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#


#---------------------------------------------------------------------------------------------------------------------------------#
### METRICA DE DISTANCIA PEARSON
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
        return 0
    else:
        return (sum_xy - (sum_x*sum_y)/n)/denominator
#---------------------------------------------------------------------------------------------------------------------------------#
#---------------------------------------------------------------------------------------------------------------------------------#




#print(cosine_similarity(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Veronica']))
#print(cosine_similarity(Processed_Movie_Ratings['Jeff'], Processed_Movie_Ratings['Jessica']))


#print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Veronica']))
#print(manhattan(Processed_Music_Ratings['Hailey'], Processed_Music_Ratings['Jordyn']))
#print(manhattan(Processed_Movie_Ratings['Bryan'], Processed_Movie_Ratings['Thomas']))
    
    
#print(cosine_similarity(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Veronica']))
#print(cosine_similarity(Processed_Movie_Ratings['Bryan'], Processed_Movie_Ratings['Thomas']))


print(pearson(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Bill']))
print(pearson(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Hailey']))
print(pearson(Processed_Music_Ratings['Angelica'], Processed_Music_Ratings['Jordyn']))