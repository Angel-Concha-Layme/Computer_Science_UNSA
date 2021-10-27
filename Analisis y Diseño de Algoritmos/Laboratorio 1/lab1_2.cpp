//ANALISIS Y DISENO DE ALGORITMOS
//ANGEL TOMAS CONCHA LAYME
#include<iostream>
#include<stdlib.h>
#include<ctime> 
 
unsigned t0_b, t1_b,t0_i, t1_i;

double costo_total ,comparaciones, asignaciones, objeto, arreglo;
double timeB;
double timeI;

//NUMEROS ALEATORIOS, CRECIENTES O DECRECIENTES
//std::string regla_generacion= "creciente";
//std::string regla_generacion = "decreciente";
std::string regla_generacion = "aleatorio";


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
    /*
    std::cout<<"asignaciones: " <<asignaciones<<std::endl;
    std::cout<<"comparaciones: "<<comparaciones<<std::endl;
    std::cout<<"objetos: "      <<objeto<<std::endl;
    std::cout<<"arreglo: "      <<arreglo<<std::endl;
    std::cout<<"TOTAL: "        << (2*asignaciones)+(8*comparaciones)+(200*objeto)+(50*arreglo)<<std::endl;
    */


    std::cout << "Execution Time Bubble Sort: " << timeB << std::endl;   
    std::cout << "Execution Time Insertion Sort: " << timeI << std::endl;
    return 0;
}

void start(){
    asignaciones++;
    for (int i = 1000; i <= 10000; i+=1000){
        comparaciones++;
        asignaciones++;
        genera_vector(10,i+1); //GENERA 10 ARREGLOS DE 1000, 2000,..., 10000
    }
    comparaciones++;
}

void genera_vector(int a, int b){
    int *arr_cp;
    arr_cp=new int [b];
    arreglo+=10*b;

    if (regla_generacion=="creciente"){
        comparaciones++;
        for (int j = 0; j < a; j++){
            comparaciones++;
            for (int i = 0; i < b; i++){
                comparaciones++;
                arr_cp[i]=i+1;
                asignaciones+=2;
            }
            //AMBAS BUSQUEDAS SIMULTANEMENTE
            //bubble_insert(arr_cp,b);

            //INSERTION_SORT
            //insertSort(arr_cp,b);
            //BUBBLE_SORT  
            //bubbleSort(arr_cp,b);

        }   
        comparaciones++;
    }

    if (regla_generacion == "decreciente"){
        comparaciones++;
        asignaciones++;
        for (int i = 0; i < a; i++){
            comparaciones++;
            asignaciones++;
            for (int j = 0; j < b; j++){
              comparaciones++; 
              arr_cp[j]=b-j; 
              asignaciones+=2;
            }
            //AMBAS BUSQUEDAS SIMULTANEMENTE
            bubble_insert(arr_cp,b); 

            //INSERTION_SORT
            //insertSort(arr_cp,b);

            //BUBBLE_SORT    
            //bubbleSort(arr_cp,b);
        }
        comparaciones++;
    }
    
    if (regla_generacion=="aleatorio"){
        comparaciones++;
        asignaciones++;
        for (int i = 0; i < a ; i++){
            comparaciones++;
            asignaciones++;
            for (int j = 0; j < b-1; j++){  //VACIAR ARREGLO -> SE SOBRE-ESCRIBE
                comparaciones++;
                //LLENAR ARREGLO
                arr_cp[j]=-b+rand()%b+rand()%(b+2);   
                asignaciones+=2;
            }
            //AMBAS BUSQUEDAS SIMULTANEMENTE
            bubble_insert(arr_cp,b-1);

            //INSERTION_SORT
            //insertSort(arr_cp,b);

            //BUBBLE_SORT 
            //bubbleSort(arr_cp,b);  

        }   
        comparaciones++;
    } 
}

//SWAP_CLASICO
void swap(int *xp, int *yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
    asignaciones+=3;
}

//BUBBLE_SORT CLASICO
void bubbleSort(int arr[], int n){ 
    t0_b=clock();
    for (int i = 0; i < n-1; i++){
        comparaciones++;
        for (int j = 0; j < n-i-1; j++){
            comparaciones++;
            if (arr[j] > arr[j+1]){
                comparaciones++; 
                swap(&arr[j], &arr[j+1]);
            } 
        }
    }  
    t1_b=clock();
    timeB += (double(t1_b-t0_b)/CLOCKS_PER_SEC);
} 

//INSERTION_SORT CLASICO
void insertSort(int arr[], int n){
    t0_i=clock();
    int i, key, j;
    for (i = 1; i < n; i++){
        comparaciones++;
        key = arr[i];
        j = i - 1;
        asignaciones+=2;
        while (j >= 0 && arr[j] > key){
            comparaciones+=2;
            arr[j + 1] = arr[j];
            j = j - 1;
            asignaciones+=2;
        }
        comparaciones+=2;
        arr[j + 1] = key;
        asignaciones++;
    }
    t1_i=clock();
    timeI += (double(t1_i-t0_i)/CLOCKS_PER_SEC);
}

void bubble_insert(int arr[],int size){
    int *arr_cp; 
    arr_cp=new int [size];  // 'ARREGLO_COPIA'
    arreglo+=size*10;
    for (int i = 0; i < size; i++){ //COPIANDO VALORES A 'ARREGLO_COPIA' 
        comparaciones++;
        arr_cp[i]=arr[i];
        asignaciones++;
    }  
    comparaciones++;
    bubbleSort(arr,size);
    insertSort(arr_cp,size);
}

//IMPRIMER ARREGLO - NO SE UTILIZA
void print_array(int arr[],int size){
    for (int i = 0; i < size; i++){
        std::cout << arr[i] <<" ";
    }
    std::cout<<std::endl;
}
