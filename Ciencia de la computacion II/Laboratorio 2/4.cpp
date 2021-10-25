#include<iostream>
#include<string.h>
#include<string>

#include<ctime>

unsigned t0,t1;

//----Prototipos de funciones----//
int tamIterativo(const char [], int);
int tamRecursivo(const char [], int);

int main(){
    t0=clock();
    int numCaracteres=0;

    char cadena[]={"¿hola Como estas?"};
    int tamanio=sizeof(cadena)-1; //no contaremos el caracter de fin de cadena
    
    //----llamamos a las funciones e imprimimos----//
    numCaracteres=tamIterativo(cadena,tamanio);
    std::cout<<numCaracteres<<std::endl;    

    numCaracteres=tamRecursivo(cadena,tamanio);
    std::cout<<numCaracteres<<std::endl;

    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<<"Execution time: "<< time <<std::endl;
    
    return 0;
}

int tamIterativo(const char arr[], int tam){
    int cont=0; //cont almacena el tamaño del arreglo
    for (int i = 0; i < tam; i++)
    {
        cont++; //por cada [i]  ->  cont+=1
    }
    return cont;
}

int tamRecursivo(const char arr[], int tam){
    //----Caso base----//
    if (tam==1)
    {
        return 1;
    }
    else
    {
        tam--;
        return tamRecursivo(arr,tam)+1; //Funcion se llama a si misma y suma 1 por cada vez qu3e lo hace  
    } 
}
