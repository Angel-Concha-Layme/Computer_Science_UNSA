#ifndef RANDOM_H
#define RANDOM_H

#include<iostream>
#include<stdlib.h>
#include<ctime> 
#include<conio.h>
#include<vector>

//CLASE RANDOM -> GENERA NUMEROS ALEATORIOS
template<class data_generic>
class random{
private:
    data_generic size;
    std::vector<data_generic> vector_prueba;
public:
    data_generic get_size();
    std::vector<data_generic> get_vector();
    void print_vector();
    random(data_generic, std::vector<data_generic>);
    ~random();
};

//CONSTRUCTOR DE LA CLASE 'RANDOM'
template<class data_generic>
random<data_generic>::random(data_generic max_min,std::vector<data_generic> vector){
    size = max_min;
    vector_prueba=vector;
    for (int i = 0; i < size; i++){
        vector_prueba.push_back((rand() % (size + 1)) - (rand() % (size + 1)));     
    } 
}

//DESTRUCTOR DE LA CLASE 'RANDOM'
template<class data_generic>
random<data_generic>::~random(){
}

template<class data_generic>
data_generic random<data_generic>::get_size(){
    return size;
}

template<class data_generic>
std::vector<data_generic> random<data_generic>::get_vector(){
    return vector_prueba; 
}

template<class data_generic>
void random<data_generic>::print_vector(){
    for (int i = 0; i <vector_prueba.size() ; i++){
        std::cout<<vector_prueba[i]<<" ";
    }
    std::cout<<std::endl;
}

#endif 