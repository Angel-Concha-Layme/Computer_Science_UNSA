#include<iostream>
#include<ctime>

unsigned t0,t1;
//----Prototipos de las funciones----//
void reverseIterativa(int [],int);
void reverseRecursiva(int [],int&);
int shift(int [], int&); // elimina la primer variables de un arreglo, y retorna esta
void concat(int [], int&,int); //concatena variables (una por una) | Su funcionamiento es el opuesto al de shift (sin retornar ningun valor)    
void swap(int&,int&); //intercambio convencional con ayuda de un auxiliar

int main(){
    t0=clock();
    int array[]={1,2,3,4,5,6,7,8,9};
    int tamanio=sizeof(array)/4;

    reverseIterativa(array,sizeof(array)/4);
    
    reverseRecursiva(array,tamanio);
    
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution Time" << time <<std::endl;
    
    return 0;
}

//----Definiciones de las funciones----//

void reverseIterativa(int arr[],int tam){
    for (int i = 0; i < tam/2; i++)
    {
        swap(arr[i],arr[tam-i-1]);
    }    
}

void reverseRecursiva(int array[],int& tam){
    if (tam==1)
    {
        array=array;
    }
    else
    {
        int primero=shift(array,tam); //primero es la variable que borra shift (el "primero")
        reverseRecursiva(array,tam); //la funcion se llama recursivamente 'tam' veces
        concat(array,tam,primero); //usamos concat para concatenar los "primeros" de shift
    }        
}

void swap(int& inicio, int& fin){
    int aux=inicio;
    inicio=fin;
    fin=aux;
}

int shift(int arr[], int& tam){
    int elem1=arr[0];
    tam=tam-1;
    int *aux = new int[tam];
    for (int i = 0; i < tam; i++)
    {
        aux[i]=arr[i+1];
    }

    for (int i = 0; i < tam; i++)
    {
        arr[i]=aux[i];
    }
    return elem1;
}

void concat(int arr[], int& tam,int primero){
    tam=tam+1;
    int *aux =new int[tam];
    arr[tam-1]=primero;
    for (int i = 0; i < tam; i++)
    {  
        aux[i]=arr[i];
    }
}