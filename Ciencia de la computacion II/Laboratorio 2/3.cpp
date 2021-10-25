#include<iostream>
#include<ctime>

unsigned t0,t1;

//----Ordenamiento burbuja convencional----//

//----Prototipos de las funciones----//
void ordAscendente(int [],int);
void swap(int&,int&);

int main(){
    t0=clock();
    
    int array[]={3,5,2,1,1,1,23,3};

    ordAscendente(array,sizeof(array)/4);

    for (int i = 0; i < sizeof(array)/4; i++)
    {
        std::cout<<array[i]<<std::endl;
    }
    
    //----Tiempo de ejecución----//
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<<"Execution time: "<< time <<std::endl;
    
    return 0;
}

//----Definiciones de las funciones----//
void ordAscendente(int arr[],int tam){      //Ordenamiento Burbuja convencional
   for (int i = 0; i < tam; i++)
   {
       for (int j = 0; j < tam; j++)
        {
            if (arr[j]>=arr[j+1])
                {
                    swap(arr[j],arr[j+1]);  //si se cumple ('>=' -> Ascendente)... hacemoos un 'swap' 
                }
       }  
   }
}

void swap(int& inicio, int& fin){ //----funcion swap convencional----//
    int aux=inicio;
    inicio=fin;
    fin=aux;
}