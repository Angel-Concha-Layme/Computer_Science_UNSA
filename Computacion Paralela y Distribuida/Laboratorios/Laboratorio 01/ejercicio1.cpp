#include <iostream>
#include <ctime>
#include <chrono>
#include <vector>

#include "Cronometro.hpp"


void prueba();
void loop1(int);
void loop2(int);

int main(){
    prueba();
}

void prueba(){
    for (auto i = 1000; i < 16000; i+=1000){
        loop1(i);
        loop2(i);
        std::cout<<'\n';
    }
}

void loop1(int tamanno){
    const int MAX = tamanno;
    double **A, *x, *y;
    A = new double*[MAX];
    x = new double[MAX];
    y = new double[MAX];

    for (int i = 0; i < MAX; i++){
        A[i] = new double[MAX];
        for (int j = 0; j < MAX; j++)
            A[i][j] = std::rand() % 1000;
    }

    for (int i = 0; i < MAX; i++){
        x[i] = std::rand() % 1000;
        y[i] = 0;
    }
    
    Cronometro timer01;
    timer01.start();
    for (auto i = 0; i < MAX; i++){
        for (auto j = 0; j < MAX; j++){
            y[i] += A[i][j]*x[j];
        }
    }
    std::cout<<"LOOP 1 - tamanno: "<< MAX <<": ";
    timer01.stop();

    for (auto i = 0; i < MAX; i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] x;
    delete[] y;

}

void loop2(int tamanno){
    const int MAX = tamanno;
    double **A, *x, *y;
    A = new double*[MAX];
    x = new double[MAX];
    y = new double[MAX];

    for (int i = 0; i < MAX; i++){
        A[i] = new double[MAX];
        for (int j = 0; j < MAX; j++)
            A[i][j] = std::rand() % 1000;
    }

    for (int i = 0; i < MAX; i++){
        x[i] = std::rand() % 1000;
        y[i] = 0;
    }
    
    Cronometro timer01;
    timer01.start();
    for (auto j = 0; j < MAX; j++){
        for (auto i = 0; i < MAX; i++){
            y[i] += A[i][j]*x[j];
        }
    }
    std::cout<<"LOOP 2 - tamanno: "<< MAX <<": ";
    timer01.stop();

    for (auto i = 0; i < MAX; i++){
        delete[] A[i];
    }
    delete[] A;
    delete[] x;
    delete[] y;

}