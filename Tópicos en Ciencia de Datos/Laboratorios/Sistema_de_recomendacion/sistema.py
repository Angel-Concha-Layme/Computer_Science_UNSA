import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

datos = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Datos.csv',delimiter=';')
#print(datos)

Movie_rating = pd.read_csv('Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Movie_Ratings.csv',delimiter=',')
#ignorar espacios vacios
dictionary = Movie_rating.to_dict()
print(dictionary)

#recorrer los las filas del dataset
#for i in range(len(datos)):
#    for j in range(len(datos.columns)):
#        print(datos.iloc[i,j],end=' ')
#    print('\n')



#visualizar los datos del dataset como coordenadas (x,y) para cada fila
#for i in range(len(datos)):
#    plt.plot(datos.iloc[:,0],datos.iloc[:,i+1])
#    plt.legend(datos.columns[1:])
#plt.show()
    


data=   {'Unnamed: 0': {0: 'Alien', 1: 'Avatar', 2: 'Blade Runner', 3: 'Braveheart', 4: 'Dodgeball', 5: 'Forest Gump', 6: 'Gladiator', 7: 'Jaws', 8: 'Kazaam', 9: 'Lord of the Rings', 10: 'Napolean Dynamite', 11: 'Old School', 12: 'Pootie Tang', 13: 'Pulp Fiction', 14: 'Scarface', 15: 'Shawshank Redemption', 16: 'Snakes on a Plane', 17: 
        'Spiderman', 18: 'Star Wars', 19: 'The Dark Knight', 20: 'The Happening', 21: 'The Matrix', 22: 'Toy Story', 23: 'Village', 24: 'You Got Mail'},
        'Patrick C': {0: 1.0, 1: 4.0, 2: 5.0, 3: 4.0, 4: 5.0, 5: 4.0, 6: np.NaN, 7: np.NaN, 8: 2.0, 9: 4.0, 10: 3.0, 11: 3.0, 12: np.NaN, 13: np.NaN, 14: np.NaN, 15: 5.0, 16: 4.0, 17: 4.0, 18: 5.0, 19: 4.0, 20: 1.0, 21: 3.0, 22: 4.0, 23: np.NaN, 24: 1.0},
        'Heather': {0: np.NaN, 1: 5.0, 2: np.NaN, 3: np.NaN, 4: 4.0, 5: 5.0, 6: 5.0, 7: 5.0, 8: np.NaN, 9: 4.0, 10: 4.0, 11: np.NaN, 12: np.NaN, 13: np.NaN, 14: 4.0, 15: np.NaN, 16: 1.0, 17: 3.0, 18: 5.0, 19: 5.0, 20: np.NaN, 21: 4.0, 22: 3.0, 23: 2.0, 24: np.NaN},
        'Bryan': {0: 2.0, 1: 5.0, 2: np.NaN, 3: 5.0, 4: 3.0, 5: 4.0, 6: 5.0, 7: 4.0, 8: 3.0, 9: 3.0, 10: 1.0, 11: 4.0, 12: 1.0, 13: 4.0, 14: np.NaN, 15: 5.0, 16: 2.0, 17: 4.0, 18: 4.0, 19: 5.0, 20: np.NaN, 21: 3.0, 22: 3.0, 23: 3.0, 24: 1.0},
        'Patrick T': {0: np.NaN, 1: 4.0, 2: np.NaN, 3: np.NaN, 4: 2.0, 5: 3.0, 6: np.NaN, 7: np.NaN, 8: 5.0, 9: 2.0, 10: 1.0, 11: 5.0, 12: 1.0, 13: np.NaN, 14: np.NaN, 15: np.NaN, 16: np.NaN, 17:4.0, 18: 5.0, 19: 4.0, 20: np.NaN, 21: 5.0, 22: 4.0, 23: 1.0, 24: 1.0},
        'Thomas': {0: 5.0, 1: 2.0, 2: 5.0, 3: 4.0, 4: 4.0, 5: 3.0, 6: 4.0, 7: 4.0, 8: 2.0, 9: np.NaN, 10: 5.0, 11: 5.0, 12: np.NaN, 13: 4.0, 14: 5.0, 15: np.NaN, 16: 4.0, 17: 5.0, 18: 5.0, 19: 4.0, 20: 1.0, 21: 4.0, 22: 4.0, 23: 1.0, 24: 1.0},
        'aaron': {0: 4.0, 1: np.NaN, 2: 4.0, 3: 4.0, 4: np.NaN, 5: np.NaN, 6: 4.0, 7: np.NaN, 8: np.NaN, 9: 5.0, 10: 1.0, 11: np.NaN, 12: np.NaN, 13: 3.0, 14: 4.0, 15: 5.0, 16: np.NaN, 17: 3.0, 18: 3.0, 19: np.NaN, 20: np.NaN, 21: 4.0, 22: 5.0, 23: np.NaN, 24: 3.0},
        'vanessa': {0: np.NaN, 1: 4.0, 2: np.NaN, 3: 3.0, 4: 4.0, 5: 4.0, 6: 4.0, 7: 2.0, 8: np.NaN, 9: 2.0, 10: 4.0, 11: 3.0, 12: 1.0, 13: np.NaN, 14: 4.0, 15: np.NaN, 16: np.NaN, 17: np.NaN, 18: 3.0, 19: np.NaN, 20: np.NaN, 21: 4.0, 22: 4.0, 23: 2.0, 24: np.NaN},
        'greg': {0: np.NaN, 1: 3.0, 2: 1.0, 3: 4.0, 4: 5.0, 5: 5.0, 6: 5.0, 7: 3.0, 8: np.NaN, 9: 3.0, 10: 4.0, 11: 5.0, 12: np.NaN, 13: 4.0, 14: 4.0, 15: 5.0, 16: np.NaN, 17: 4.0, 18: 5.0, 19: 4.0, 20: np.NaN, 21: 4.0, 22: 5.0, 23: np.NaN, 24: np.NaN},
        'brian': {0: 4.0, 1: np.NaN, 2: 5.0, 3: 4.0, 4: 3.0, 5: 5.0, 6: 5.0, 7: 3.0, 8: 1.0, 9: 5.0, 10: 4.0, 11: 4.0, 12: 1.0, 13: 5.0, 14: np.NaN, 15: 5.0, 16: 3.0, 17: 4.0, 18: 5.0, 19: 4.0, 20: 2.0, 21: 5.0, 22: 5.0, 23: 4.0, 24: 3.0},
        'ben': {0: np.NaN, 1: 3.0, 2: 5.0, 3: np.NaN, 4: 4.0, 5: 5.0, 6: 5.0, 7: 1.0, 8: np.NaN, 9: 2.0, 10: 4.0, 11: 4.0, 12: 1.0, 13: 4.0, 14: 4.0, 15: 5.0, 16: 2.0, 17: 4.0, 18: 5.0, 19: 5.0, 20: np.NaN, 21: 4.0, 22: 5.0, 23: 3.0, 24: np.NaN},
        'Katherine': {0: np.NaN, 1: 5.0, 2: np.NaN, 3: 3.0, 4: 5.0, 5: 5.0, 6: 3.0, 7: np.NaN, 8: 2.0, 9: 4.0, 10: 2.0, 11: np.NaN, 12: np.NaN, 13: np.NaN, 14: np.NaN, 15: np.NaN, 16: np.NaN, 17: 5.0, 18: 5.0, 19: np.NaN, 20: np.NaN, 21: 4.0, 22: 5.0, 23: np.NaN, 24: np.NaN},
        'Jonathan': {0: np.NaN, 1: 4.0, 2: np.NaN, 3: 4.0, 4: 5.0, 5: 5.0, 6: 4.0, 7: 3.0, 8: 2.0, 9: 4.0, 10: 3.0, 11: 5.0, 12: np.NaN, 13: 5.0, 14: 4.0, 15: np.NaN, 16: np.NaN, 17: 3.0, 18: 5.0, 19: 5.0, 20: np.NaN, 21: 5.0, 22: 5.0, 23: np.NaN, 24: 2.0},
        'Zwe': {0: np.NaN, 1: 4.0, 2: np.NaN, 3: 3.0, 4: 3.0, 5: 5.0, 6: 3.0, 7: 2.0, 8: 2.0, 9: 3.0, 10: 3.0, 11: 4.0, 12: 2.0, 13: 4.0, 14: np.NaN, 15: 4.0, 16: 1.0, 17: 4.0, 18: 4.0, 19: 5.0, 20: 1.0, 21: 4.0, 22: 4.0, 23: 4.0, 24: 2.0},
        'Erin': {0: np.NaN, 1: 4.0, 2: np.NaN, 3: 4.0, 4: 3.0, 5: 5.0, 6: np.NaN, 7: 3.0, 8: 1.0, 9: 4.0, 10: 2.0, 11: np.NaN, 12: np.NaN, 13: np.NaN, 14: np.NaN, 15: np.NaN, 16: np.NaN, 17: 3.0, 18: 3.0, 19: np.NaN, 20: np.NaN, 21: 4.0, 22: 5.0, 23: np.NaN, 24: np.NaN},
        'Chris': {0: 2.0, 1: 1.0, 2: 5.0, 3: 2.0, 4: 3.0, 5: 3.0, 6: 3.0, 7: 2.0, 8: 1.0, 9: 3.0, 10: 1.0, 11: 5.0, 12: 3.0, 13: 5.0, 14: 3.0, 15: 4.0, 16: 3.0, 17: 2.0, 18: 4.0, 19: 3.0, 20: 1.0, 21: 4.0, 22: 3.0, 23: 3.0, 24: np.NaN},
        'Zak': {0: np.NaN, 1: 5.0, 2: np.NaN, 3: 5.0, 4: 3.0, 5: 5.0, 6: 5.0, 7: np.NaN, 8: 1.0, 9: 4.0, 10: 1.0, 11: 5.0, 12: np.NaN, 13: 5.0, 14: 3.0, 15: np.NaN, 16: np.NaN, 17: 3.0, 18: 5.0, 19: 5.0, 20: 1.0, 21: 5.0, 22: 4.0, 23: 4.0, 24: 2.0},
        'Matt': {0: np.NaN, 1: np.NaN, 2: np.NaN, 3: np.NaN, 4: np.NaN, 5: 4.0, 6: np.NaN, 7: np.NaN, 8: np.NaN, 9: 1.0, 10: 3.0, 11: np.NaN, 12: np.NaN, 13: np.NaN, 14: np.NaN, 15: np.NaN, 16: 1.0, 17: 3.0, 18: np.NaN, 19: np.NaN, 20: np.NaN, 21: np.NaN, 22: 4.0, 23: np.NaN, 24: np.NaN},
        'Chris.1': {0: 4.0, 1: np.NaN, 2: 3.0, 3: 4.0, 4: 3.0, 5: 5.0, 6: 3.0, 7: 5.0, 8: np.NaN, 9: 4.0, 10: 1.0, 11: 4.0, 12: 1.0, 13: 5.0, 14: 2.0, 15: 4.0, 16: 3.0, 17: 2.0, 18: 5.0, 19: 4.0, 20: np.NaN, 21: 2.0, 22: 4.0, 23: 1.0, 24: 1.0},
        'Josh': {0: 3.0, 1: 4.0, 2: np.NaN, 3: np.NaN, 4: np.NaN, 5: 4.0, 6: 4.0, 7: 5.0, 8: np.NaN, 9: np.NaN, 10: np.NaN, 11: np.NaN, 12: np.NaN, 13: np.NaN, 14: np.NaN, 15: np.NaN, 16: np.NaN, 17: 4.0, 18: 5.0, 19: 4.0, 20: np.NaN, 21: 5.0, 22: 4.0, 23: 4.0, 24: np.NaN},
        'Amy': {0: np.NaN, 1: 3.0, 2: 3.0, 3: 3.0, 4: 4.0, 5: 4.0, 6: np.NaN, 7: 3.0, 8: 1.0, 9: np.NaN, 10: 2.0, 11: 3.0, 12: np.NaN, 13: 4.0, 14: np.NaN, 15: 2.0, 16: 2.0, 17: 3.0, 18: np.NaN, 19: 4.0, 20: np.NaN, 21: 5.0, 22: 4.0, 23: np.NaN, 24: 2.0},
        'Valerie': {0: np.NaN, 1: 2.0, 2: 3.0, 3: 4.0, 4: 3.0, 5: 5.0, 6: 3.0, 7: 2.0, 8: 1.0, 9: 5.0, 10: 5.0, 11: 3.0, 12: np.NaN, 13: 3.0, 14: 4.0, 15: 5.0, 16: 1.0, 17: 5.0, 18: 5.0, 19: 5.0, 20: 1.0, 21: 4.0, 22: 5.0, 23: 2.0, 24: 2.0},
        'Gary': {0: 2.0, 1: 1.0, 2: 1.0, 3: 5.0, 4: 4.0, 5: 4.0, 6: 3.0, 7: 4.0, 8: 1.0, 9: 3.0, 10: 4.0, 11: 5.0, 12: np.NaN, 13: 3.0, 14: 3.0, 15: 5.0, 16: 2.0, 17: 2.0, 18: 5.0, 19: np.NaN, 20: np.NaN, 21: 2.0, 22: 4.0, 23: np.NaN, 24: 1.0},
        'Stephen': {0: 5.0, 1: 4.0, 2: np.NaN, 3: 5.0, 4: 3.0, 5: 1.0, 6: 4.0, 7: 2.0, 8: np.NaN, 9: 5.0, 10: 2.0, 11: np.NaN, 12: np.NaN, 13: 3.0, 14: np.NaN, 15: np.NaN, 16: np.NaN, 17: 3.0, 18: 5.0, 19: 4.0, 20: 1.0, 21: 5.0, 22: 4.0, 23: 2.0, 24: 2.0},
        'Jessica': {0: np.NaN, 1: np.NaN, 2: np.NaN, 3: np.NaN, 4: np.NaN, 5: 4.0, 6: np.NaN, 7: 3.0, 8: 1.0, 9: 3.0, 10: 2.0, 11: 2.0, 12: np.NaN, 13: 4.0, 14: np.NaN, 15: np.NaN, 16: 2.0, 17: 3.0, 18: 5.0, 19: 5.0, 20: np.NaN, 21: np.NaN, 22: 5.0, 23: np.NaN, 24: np.NaN}, 
        'Jeff': {0: 4.0, 1: 4.0, 2: 5.0, 3: 4.0, 4: 3.0, 5: 4.0, 6: 4.0, 7: 5.0, 8: 1.0, 9: 3.0, 10: 3.0, 11: 3.0, 12: 5.0, 13: 3.0, 14: np.NaN, 15: np.NaN, 16: 1.0, 17: 4.0, 18: 5.0, 19: 5.0, 20: np.NaN, 21: 5.0, 22: 5.0, 23: 2.0, 24: 2.0}
        }
        









    




