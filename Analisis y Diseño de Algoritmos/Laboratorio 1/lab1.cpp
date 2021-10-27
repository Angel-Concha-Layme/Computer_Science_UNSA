#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<math.h>

int costo_total;
int comparaciones;
int asignaciones;
int objeto;
int arreglo;

void start();
void genera_vector(int, int);
void print_array(int[], int);
//Bubble sort 
void bubbleSort(int[], int);
void swap(int *, int *);
//Insertion sort
void insertSort(int[], int);
void bubble_insert(int[],int);




//Funcion main
int main(){
    srand(time(NULL));
    start();
    return 0;
}





void start(){
    for (int i = 1000; i <= 10000; i+=1000){
        genera_vector(10,i+1);
    }
}

void genera_vector(int a, int b){
    int num;
    int *arr_cp;
    arr_cp=new int [b];

    for (int i = 0; i < a ; i++){
        for (int j = 0; j < b-1; j++){  //VACIAR ARREGLO -> SE SOBRE-ESCRIBE
            //num=-b+rand()%b+rand()%(b+2);
            //LLENAR ARREGLO
            //arr_cp[j]=num;  
            arr_cp[j]=-b+rand()%b+rand()%(b+2);         
        }
        bubble_insert(arr_cp,b-1);
    }
}

void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}


void bubbleSort(int arr[], int n) { 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
    print_array(arr,n);
} 

void insertSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    print_array(arr,n);
}

void bubble_insert(int arr[],int size){
    int *arr_cp;
    arr_cp=new int [size]; 
    for (int i = 0; i < size; i++){
        arr_cp[i]=arr[i];
    }  
    bubbleSort(arr,size);
    insertSort(arr_cp,size);
}

void print_array(int arr[],int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout<<std::endl;
}
