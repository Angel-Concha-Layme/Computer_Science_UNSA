#ifndef RANDOM_H
#define RANDOM_H

#include<iostream>
#include<stdlib.h>
#include<ctime> 
#include<conio.h>
#include<vector>

//CLASE RANDOM -> GENERA NUMEROS ALEATORIOS

class random{
private:
    int size;
    std::vector<int> vector_prueba;
public:
    std::vector<int> get_vector();
    void print_vector();
    random(int);
    ~random();
};

//CONSTRUCTOR DE LA CLASE 'RANDOM'
random::random(int max_min){
    size = max_min;
    std::vector<int> vector;
    vector_prueba=vector;
    for (int i = 0; i < size; i++){
        vector_prueba.push_back((rand() % (size + 1)) - (rand() % (size + 1)));     
    } 
}

//DESTRUCTOR DE LA CLASE 'RANDOM'
random::~random(){
}

std::vector<int> random::get_vector(){
    return vector_prueba; 
}

void random::print_vector(){
    for (int i = 0; i <vector_prueba.size() ; i++){
        std::cout<<vector_prueba[i]<<" ";
    }
    std::cout<<std::endl;
}

#endif 