from math import sqrt
from csv import *

from numpy import unicode_

users2 = {"Amy": {"Taylor Swift": 4, "PSY": 3, "Whitney Houston": 4},
          "Ben": {"Taylor Swift": 5, "PSY": 2},
          "Clara": {"PSY": 3.5, "Whitney Houston": 4},
          "Daisy": {"Taylor Swift": 5, "Whitney Houston": 3}}

users = {} #diccionario de usuarios y sus peliculas y ratings 
def trans_to_dict():
	with open(r"C:\Users\aconc\Desktop\Mis_archivos\Computer_Science_UNSA\Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Laboratorio 4\Ratings.csv"  )as csv_file:
		temp = '1'  
		temp_dict = { }
		for i,line in enumerate(csv_file):
			row = line.split(',')
			if i != 0:
				if temp == row[0]: #si el usuario es el mismo que el anterior
					temp_dict[row[1]] = float(row[2]) #agrega la pelicula y su rating
				else:                                                           
					users[temp] = temp_dict #agrega el usuario y sus peliculas y ratings
					temp = row[0] #cambia el usuario
					temp_dict = { } #limpia el diccionario
					temp_dict[row[1]] = float(row[2])
class recommender:
        def __init__(self, data, k=1): #k es el numero de peliculas que se recomienda
                self.frequencies = {} #diccionario de frecuencias
                self.deviations = {} #diccionario de desviaciones
                self.k = k #numero de peliculas que se recomienda
                self.username2id = {} #diccionario de usuarios
                self.userid2name = {} #diccionario de nombres de usuarios
                self.productid2name = {} #diccionario de nombres de peliculas
                if type(data).__name__ == 'dict': 
                    self.data = data
        def convertProductID2name(self, id): #convierte el id de la pelicula a su nombre
            if id in self.productid2name: #si el id esta en el diccionario
                return self.productid2name[id] #devuelve el nombre de la pelicula
            else:
                return id #si no esta devuelve el id
        def computeDeviations(self):#calcula las desviaciones
            for ratings in self.data.values(): #para cada usuario de la base de datos de ratings 
                for (item, rating) in ratings.items():  #para cada pelicula de cada usuario de la base de datos de ratings
                    self.frequencies.setdefault(item, {}) #crea el diccionario de frecuencias de la pelicula en el diccionario de frecuencias
                    self.deviations.setdefault(item, {}) #crea el diccionario de desviaciones de la pelicula en el diccionario de desviaciones
                    for (item2, rating2) in ratings.items(): #para cada pelicula de cada usuario de la base de datos de ratings 
                        if item != item2 : #si la pelicula es diferente a la pelicula 2
                            self.frequencies[item].setdefault(item2, 0) #crea el diccionario de frecuencias de la pelicula 2 en el diccionario de frecuencias de la pelicula 1
                            self.deviations[item].setdefault(item2, 0.0) #crea el diccionario de desviaciones de la pelicula 2 en el diccionario de desviaciones de la pelicula 1
                            self.frequencies[item][item2] += 1 #aumenta en 1 la frecuencia de la pelicula 2 en el diccionario de frecuencias de la pelicula 1
                            self.deviations[item][item2] += rating - rating2 #aumenta en el rating de la pelicula 2 en el diccionario de desviaciones de la pelicula 1
                            #print()	
                            #print("ratings: ", ratings)
                            #print("frequencies: ", self.frequencies.items())
                            #print("deviations: ", self.deviations.items())
                            				        
            for (item, ratings) in self.deviations.items():			
                for item2 in ratings:
                    ratings[item2] /= self.frequencies[item][item2] #calcula la desviacion
            
        def slopeOneRecommendations(self, userRatings):
            predictions = {}
            frequencies = {}
            for (userItem, userRating) in userRatings.items(): 
                for (diffItem, diffRatings) in self.deviations.items(): 
                    #print()
                    #print("Desviations Items: ", self.deviations.items())
                    if diffItem not in userRatings and userItem in self.deviations[diffItem]:
                        freq = self.frequencies[diffItem][userItem] #frecuencia de la pelicula
                        predictions.setdefault(diffItem, 0.0) #prediccion de la pelicula
                        frequencies.setdefault(diffItem, 0) #frecuencia de la pelicula
                        predictions[diffItem] += (diffRatings[userItem] + userRating) * freq
                        frequencies[diffItem] += freq #frecuencia de la pelicula
            predictions =  [(self.convertProductID2name(k),
                                v / frequencies[k])
                                for (k, v) in predictions.items()]
            predictions.sort(key=lambda artistTuple: artistTuple[1],reverse = True) #ordena las peliculas por su prediccion
            with open("randomfile.txt", "w") as external_file:
                add_text = predictions
                print(add_text, file=external_file)
                external_file.close()
            return predictions

#print(users)
#print(users.keys())

trans_to_dict()
r= recommender(users)
r.computeDeviations()

r.slopeOneRecommendations(users['585'])[0:5]

#r.slopeOneRecommendations(users['5'])[0:5] 
#imprimir salida en un txt
#r.slopeOneRecommendations(users2["Ben"])
#r.slopeOneRecommendations(users2["Clara"])
#r.slopeOneRecommendations(users2["Daisy"])

print("Done")