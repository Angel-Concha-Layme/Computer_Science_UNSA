import pandas as pd
import numpy as np

def data_filter(user, movie, rating, timestamp):
    return {"userId": user, "movieId": movie, "rating": rating, "timestamp": timestamp}


# dado un titulo de pelicula, devuelve el id de la pelicula con numpy
def tittle_to_movieID(tittle):
    df = pd.read_csv(r"C:\Users\aconc\Desktop\Mis_archivos\Computer_Science_UNSA\Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Laboratorio 05\Movies.csv")
    for i in range(len(df)):
        if df["title"][i]==tittle:
            return df["movieId"][i]
    

def formMatrix(): # Forma la matriz de datos
    matrix = {}
    #f = open(r"C:\Users\aconc\Desktop\Mis_archivos\Computer_Science_UNSA\Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Laboratorio 05\Ratings.csv")
    f = open(r"C:\Users\aconc\Desktop\Mis_archivos\Computer_Science_UNSA\Tópicos en Ciencia de Datos\Laboratorios\Sistema_de_recomendacion\Laboratorio 05\dataset_book.csv")
    lines = f.readlines() 
    for line in lines: 
        userId, movieId, rating, timestamp = line.split(",")
        data = data_filter(userId, movieId, rating, timestamp) 
        if data["userId"] in matrix:
            matrix[data["userId"]][data["movieId"]] = data["rating"]
        else:  
            matrix[data["userId"]] = {data["movieId"]: data["rating"]}
    f.close()
    return matrix

def cal_avg(user_vector):
    user_sum = 0.0
    for i in user_vector:
        user_sum += float(user_vector[i])
    avg = user_sum / len(user_vector)
    return avg

def SlopeOne(matrix, test_user, test_movie):
    predict_list = []  
    movie_list_of_test_user = matrix[test_user] 

    for movie in movie_list_of_test_user:  
        sum_of_differences = 0.0 
        user_num = 0 
        for user in matrix:  
            user_movie = matrix[user]  
            if test_movie in user_movie and movie in user_movie: 
                print( "user_movie[test_movie]: ", user_movie[test_movie], "user_movie[movie]: ", user_movie[movie])
                sum_of_differences += float(user_movie[test_movie]) - float(user_movie[movie])  
                print("sum_of_differences: ", sum_of_differences)
                user_num += 1
        print("SUM OF DIFFERENCES: ", sum_of_differences, "USER NUM: ", user_num)
        if user_num:  
            standard_deviation = sum_of_differences / user_num 
            print("standard_deviation: ", standard_deviation)
            predict_rate = float(movie_list_of_test_user[movie]) + float(standard_deviation)  # Prediccion de la pelicula 
            print("movie_list_of_test_user[movie]", float(movie_list_of_test_user[movie]),"standard_deviation", float(standard_deviation))
            predict_list.append((predict_rate, user_num)) # Agrega la prediccion a la lista
            print("predict_list: ", predict_list)
            print("---------------------------------------------------------------------------------------------------------------------")

    if not predict_list: 
        avg = cal_avg(movie_list_of_test_user)
        print(avg)
        return avg

    numerator = 0.0  # Molcula de la prediccion
    denominator = 0.0  # Denominador de la prediccion
    for predict in predict_list: 
        numerator += predict[0]
        print("numerator: ", numerator,"predict[0]: ", predict[0])  
    denominator = len(predict_list)
    
    print('Longitud de la lista de predicción:', denominator)
    result = numerator / denominator
    print("numerator: ", numerator , "denominator: ", denominator)
    print('Puntaje de predicción: ', result)
    return numerator / denominator


#slopeOne(formMatrix(), '2', '3')


def SlopeOne_h(matrix, test_user, test_movie):
    predict_list = []  
    movie_list_of_test_user = matrix[test_user]  
    for movie in movie_list_of_test_user:  
        sum_of_differences = 0.0
        user_num = 0
        for user in matrix:  
            user_movie = matrix[user]  
            if test_movie in user_movie and movie in user_movie: 
                print( "user_movie[test_movie]: ", user_movie[test_movie], "user_movie[movie]: ", user_movie[movie])
                sum_of_differences += float(user_movie[test_movie]) - float(user_movie[movie])  
                print("sum_of_differences: ", sum_of_differences)
                user_num += 1
        if user_num:  
            standard_deviation = sum_of_differences / user_num 
            print("standard_deviation: ", standard_deviation)
            predict_rate = float(movie_list_of_test_user[movie]) + float(standard_deviation)  # Prediccion de la pelicula 
            print("movie_list_of_test_user[movie]", float(movie_list_of_test_user[movie]),"standard_deviation", float(standard_deviation))
            predict_list.append((predict_rate, user_num)) # Agrega la prediccion a la lista
            print("predict_list: ", predict_list)
            print("---------------------------------------------------------------------------------------------------------------------")
    if not predict_list:
        avg = cal_avg(movie_list_of_test_user)
        return avg
    numerator = 0.0  
    denominator = 0.0 
    for predict in predict_list:
        numerator += predict[0] * predict[1] 
        denominator += predict[1]  
    print('predict_list:', predict_list)
    print('numerator: ', numerator)
    print('denominator:', denominator)
    result = numerator / denominator
    print('result: ', result)
    return numerator / denominator

#SlopeOne_h(formMatrix(), '2', '3')

def prediction():
    movieID = input("Ingrese el ID de la pelicula | ingrese -1 si no tiene el ID: ")
    tittle = input("Ingrese el titulo de la pelicula: ")
    userID = input("Ingrese el ID del usuario: ")

    if movieID == '-1':
        movieID = tittle_to_movieID(tittle)

    SlopeOne(formMatrix(), userID, movieID)
    print("---------------------------------------------------------------------------------------------------------------------")
    print("---------------------------------------------------------------------------------------------------------------------")
    SlopeOne_h(formMatrix(), userID, movieID)


prediction()

