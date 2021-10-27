#include"random.cpp"
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<string.h>
#include<sstream>
#include<stdexcept>
#include<iterator>

//-----------------------------------------------------------------------------------------------------------------***
//PROTOTIPOS DE FUNCION
void start(); //INICIA EL PROGRAMA: SE CREAN VECTORES ALEATORIOS DE TAMAÑO [10,20,30...,10000] Y SE ORDENAN CON LOS ALGORITMOS MERGESORT Y INSERTION SORT
void sort(std::vector<int> &);
void mergeSort(std::vector<int>&, std::vector<int>&, std::vector<int>&);
void insertionSort(std::vector<int> &);
void print_vector(std::vector<int>);
//-----------------------------------------------------------------------------------------------------------------***

//-----------------------------------------------------------------------------------------------------------------***
//VARIABLES PARA MEDIR TIEMPOS DE ORDENAMIENTO.
unsigned initial_time_merge, final_time_merge, initial_time_insertion, final_time_insertion;
double total_time_merge, total_time_insertion;
//-----------------------------------------------------------------------------------------------------------------***

//-----------------------------------------------------------------------------------------------------------------***
//ESTRUCTURA QUE GUARDA EL TAMAÑO DEL VECTOR Y EL TIEMPO QUE TARDA EN SER ORDENADO.
struct size_time{
    int size;
    double time;
};
//-----------------------------------------------------------------------------------------------------------------***

//-----------------------------------------------------------------------------------------------------------------***
//VECTORES DE TIPO [SIZE-TIME] : ESTRUCTURA QUE GUARDA EL TAMAÑO DEL VECTOR Y EL TIEMPO QUE TARDA EN SER ORDENADO.
std::vector<size_time> time_merge;
std::vector<size_time> time_insertion;
//-----------------------------------------------------------------------------------------------------------------***

//-----------------------------------------------------------------------------------------------------------------***
//FUNCION MAIN
int main() {    
    start();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------***

void sort(std::vector<int> & bar) {
    if (bar.size() <= 1) return;

    int mid = bar.size() / 2;
    std::vector<int> left;
    std::vector<int> right;

    for (size_t j = 0; j < mid;j++)
        left.push_back(bar[j]);
    for (size_t j = 0; j < (bar.size()) - mid; j++)
        right.push_back(bar[mid + j]);

    sort(left);
    sort(right);
    mergeSort(left, right, bar);
}

void mergeSort(std::vector<int>&left, std::vector<int>& right, std::vector<int>& bars){
    int nL = left.size();
    int nR = right.size();
    int i = 0, j = 0, k = 0;

    while (j < nL && k < nR) 
    {
        if (left[j] < right[k]) {
            bars[i] = left[j];
            j++;
        }
        else {
            bars[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < nL) {
        bars[i] = left[j];
        j++; i++;
    }
    while (k < nR) {
        bars[i] = right[k];
        k++; i++;
    }
}

void insertionSort(std::vector<int> &vec){
    for (auto it = vec.begin(); it != vec.end(); it++){
        auto const insertion_point =
        std::upper_bound(vec.begin(), it, *it);
        std::rotate(insertion_point, it, it+1);
    }
}

void print_vector(std::vector<int> vector){
    for (int i = 0; i < vector.size() ; i++){
        std::cout<<vector[i]<<" ";
    }
    std::cout<<std::endl;
}

void start(){
    std::vector<int> vector_merge;
    std::vector<int> vector_insertion;
    int contador=0;
    for (int i = 0; i <= 1000; i+=10){
        std::vector<int> vector_main;
        random<int> test(i,vector_main); 

//-----------------------------------------------------------------------------------------------------------------*** 
//VECTORES QUE SERAN ORDENADOS MEDIANTE MERGESORT Y INSERTIONSORT RESPECTIVAMENTE       
        vector_merge=test.get_vector();
        vector_insertion=test.get_vector();
//-----------------------------------------------------------------------------------------------------------------***    

//-----------------------------------------------------------------------------------------------------------------***    
//MERGE SORT
        initial_time_merge = clock();
        sort(vector_merge); //SE ORDENA EL VECTOR
        final_time_merge = clock();
        total_time_merge = (double(final_time_merge - initial_time_merge)/100000000);
        size_time data_merge;
        data_merge.size=i;
        data_merge.time=total_time_merge;
        time_merge.push_back(data_merge);
 
        
        initial_time_merge=0;
        final_time_merge=0;
        total_time_merge=0;
        
//-----------------------------------------------------------------------------------------------------------------***    


//-----------------------------------------------------------------------------------------------------------------***    
//INSERTION SORT
        initial_time_insertion = clock();
        insertionSort(vector_insertion); //SE ORDENA EL VECTOR
        final_time_insertion = clock();
        total_time_insertion = (double(final_time_insertion - initial_time_insertion)/100000000);

        size_time data_insertion;
        data_insertion.size = i;
        data_insertion.time = total_time_insertion;
        time_insertion.push_back(data_insertion);
        
        initial_time_insertion=0;
        final_time_insertion=0;
        total_time_insertion=0;
        
//-----------------------------------------------------------------------------------------------------------------***    
    }

//-----------------------------------------------------------------------------------------------------------------*** 
//MOSTRAR RESULTADOS  MERGESORT
    std::cout<<"MERGE_SORT_SIZE"<<std::endl;
    for (int i = 0; i < time_merge.size() ; i++){
        std::cout<<time_merge[i].size<<" ";
    }
    std::cout<<'\n'<<std::endl;
    std::cout<<"MERGE_SORT_TIME"<<std::endl;
    for (int i = 0; i < time_merge.size() ; i++){
        std::cout<<time_merge[i].time<<" ";
    }    
//-----------------------------------------------------------------------------------------------------------------***    
    std::cout<<'\n'<<std::endl;

//-----------------------------------------------------------------------------------------------------------------*** 
//MOSTRAR RESULTADOS  INSERTION SORT
    std::cout<<"INSERTION_SORT_SIZE"<<std::endl;
    for (int i = 0; i <time_insertion.size() ; i++){
        std::cout<<time_insertion[i].size<<" ";
    }
    std::cout<<'\n'<<std::endl;
    std::cout<<"INSERTION_SORT_TIME"<<std::endl;
    for (int i = 0; i <time_insertion.size() ; i++){
        std::cout<<time_insertion[i].time<<" ";
    }    
    
//-----------------------------------------------------------------------------------------------------------------***     
}
