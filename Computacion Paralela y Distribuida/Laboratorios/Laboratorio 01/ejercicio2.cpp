#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

#include "Generador.hpp"
#include "Cronometro.hpp"


int **A, **B, **C; 

void multiplicacion_clasica(int);
void prueba();

int main(){
    prueba();
}


void multiplicacion_clasica(int tammano){
    crear_matriz_2D_random(A,tammano,tammano,1,5);
    crear_matriz_2D_random(B,tammano,tammano,1,5);
    crear_matriz_2D_vacia(C,tammano,tammano);

    Cronometro timer01;
    timer01.start();
    for(int i = 0; i < tammano; ++i){
        for(int j = 0; j < tammano; ++j){
            for(int k = 0; k < tammano; ++k){
                *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
            }
        }
    }
    std::cout<<"MULTIPLICACION CLASICA - tamanno: "<< tammano <<": ";
    timer01.stop();

    for(int i = 0; i < tammano; ++i){
        delete[] *(A+i);
        delete[] *(B+i);
        delete[] *(C+i);
    }
    delete[] A;
    delete[] B;
    delete[] C;
}

void prueba(){
    for (auto i = 200; i <=1400 ; i+=200){
        multiplicacion_clasica(i);
        std::cout<<'\n';
    }
}