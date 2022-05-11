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
				if temp == row[0]:
					temp_dict[row[1]] = float(row[2]) 
				else:                                                           
					users[temp] = temp_dict
					temp = row[0]
					temp_dict = { }
					temp_dict[row[1]] = float(row[2])
class recommender:
        def __init__(self, data, k=1): 
                self.frequencies = {} 
                self.deviations = {} 
                self.k = k 
                self.username2id = {} 
                self.userid2name = {} 
                self.productid2name = {} 
                if type(data).__name__ == 'dict': 
                    self.data = data
        def convertProductID2name(self, id):
            if id in self.productid2name: 
                return self.productid2name[id] 
            else:
                return id 
        def computeDeviations(self):
            for ratings in self.data.values(): 
                for (item, rating) in ratings.items():   
                    self.frequencies.setdefault(item, {}) 
                    self.deviations.setdefault(item, {}) 
                    for (item2, rating2) in ratings.items(): 
                        if item != item2 : 
                            self.frequencies[item].setdefault(item2, 0) 
                            self.deviations[item].setdefault(item2, 0.0) 
                            self.frequencies[item][item2] += 1 
                            self.deviations[item][item2] += rating - rating2 
                            #print()	
                            #print("ratings: ", ratings)
                            #print("frequencies: ", self.frequencies.items())
                            #print("deviations: ", self.deviations.items())
                            				        
            for (item, ratings) in self.deviations.items():			
                for item2 in ratings:
                    ratings[item2] /= self.frequencies[item][item2] #calcula la desviacion

            print("frequencies: ", self.frequencies.items())
            
        def slopeOneRecommendations(self, userRatings):
            predictions = {}
            frequencies = {}
            for (userItem, userRating) in userRatings.items(): 
                for (diffItem, diffRatings) in self.deviations.items(): 
                    #print()
                    #print("Desviations Items: ", self.deviations.items())
                    if diffItem not in userRatings and userItem in self.deviations[diffItem]:
                        freq = self.frequencies[diffItem][userItem] 
                        predictions.setdefault(diffItem, 0.0) 
                        frequencies.setdefault(diffItem, 0) 
                        predictions[diffItem] += (diffRatings[userItem] + userRating) * freq
                        frequencies[diffItem] += freq 
            predictions =  [(self.convertProductID2name(k),v / frequencies[k]) for (k, v) in predictions.items()]
            predictions.sort(key=lambda artistTuple: artistTuple[1],reverse = True) #ordena las peliculas por su prediccion
            #print()
            #print("PREDICTION:", predictions)
            return predictions

#print(users)
#print(users.keys())

trans_to_dict()
r= recommender(users2)
r.computeDeviations()

print(r.slopeOneRecommendations(users2["Ben"]))

#print(r.slopeOneRecommendations(users['30'])[0:5])


#r.slopeOneRecommendations(users['5'])[0:5] 
#imprimir salida en un txt

#with open("randomfile.txt", "w") as external_file:
#    add_text = "This text will be added to the file"
#    print(add_text, file=external_file)
#    external_file.close()
#r.slopeOneRecommendations(users2["Ben"])
#r.slopeOneRecommendations(users2["Clara"])
#r.slopeOneRecommendations(users2["Daisy"])