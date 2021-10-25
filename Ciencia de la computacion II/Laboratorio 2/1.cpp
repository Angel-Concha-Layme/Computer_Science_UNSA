#include<iostream>
#include<ctime>

unsigned t1,t0;

//----Prototipos de las funciones----//
int sumaRecursiva(const int [],int);
int sumaRecursiva2(const int [],int);
int sumaIterativa(const int [],int);

int main()
{
    t0=clock();
    int num[]={1,2,3,4,5};

    //----llamada a las funciones----//
    int result1=sumaRecursiva(num,(sizeof(num)/4)-1);
    int result2=sumaRecursiva2(num,sizeof(num)/4);
    int result3=sumaIterativa(num,sizeof(num)/4); //int -> 4 bytes

    //----IMprime resultados----//
    std::cout<<result1<<std::endl;
    std::cout<<result2<<std::endl;
    std::cout<<result3<<std::endl;
    
    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution Time: " << time <<std::endl;  

    return 0;
}

//----Definición de las funciones----//

//----En las funciones recursivas (2) la forma de ciclar los datos es distinta, esto se debe al caso base----//
//----Por esto tambien los parametros son difrentes----//
int sumaRecursiva(const int array[],int tamanio){ //tamanio original -1
    //----Caso base --> 0----//
    if (tamanio==0){
        return array[0];
    }
    else
    {
        tamanio--; //tam reduce por caso base
        return array[tamanio+1] + sumaRecursiva(array,tamanio);//suma recursiva |(tamanio+1)-> caso base   
    }
}

int sumaRecursiva2(const int array[],int tamanio){ //tamanio original
    //----Caso base ---> 1----//
    if (tamanio==1){
        return array[0];
    }
    else
    {
        //----como el caso base empezo con 1 , el array tienes pos -1 ----//
        return array[tamanio-1] + sumaRecursiva2(array,tamanio-1); //tamanio-1 por el caso base    
    }
}
//suma iterativa convencional
int sumaIterativa(const int array[], int tamanio){
    int sum=0; // instanciamos una variable que almacenara la suma y luego será el valor que retorne la función
    for (int i = 0; i < tamanio; i++)
    {
        sum+=array[i]; //se almacenan en suma las sumas de las variables del array
    }
    return sum;   
}

