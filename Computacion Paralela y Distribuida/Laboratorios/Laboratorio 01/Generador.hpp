#include <iostream>
#include <stdlib.h>
#include <time.h>       
#include <chrono>
#include <vector>

void crear_matriz_2D_vacia(int **&M, int filas, int columnas){
    M = new int *[filas];
    for(int i=0 ; i < filas ; i++)
        *(M+i)= new int [columnas]();
}


void imprimir_matriz_2D(int **&M, int filas, int columnas){
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++)
            std::cout <<"\t"<< *(*(M+i)+j);
        std::cout << std::endl;
    }
}

void crear_matriz_2D_random(int **&M, int filas, int columnas, int valor_minimo, int valor_maximo){
    srand (time(NULL));
    int rand_rango = valor_maximo-valor_minimo+1; //+1 para incluir el valor maximo para pruebas pequeñas
    M = new int *[filas];
    for(int i = 0; i < filas ; i++){ 
        *(M+i)= new int [columnas]();
        for(int j=0 ; j < columnas ; j++)  
            *(*(M+i)+j) = rand() % rand_rango + valor_minimo;
    }
}
