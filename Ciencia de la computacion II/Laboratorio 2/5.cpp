#include<iostream>
#include<ctime>
unsigned t0,t1;

void concat(char [], char[],int);

int main(){
    t0=clock();
    char a[]={"hola"};
    //----"suponemos que arr2 puede contener arr1----//
    char b[14]={"como estas"};
    //----el tamaño de b será la suma de tamaños de ambos array's----//

    concat(a,b,sizeof(b));

    for (int i = 0; i < sizeof(b); i++)
    {
        std::cout<<b[i]<<std::endl;
    }
    
    
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<<"Execution time: "  << time <<std::endl;
    return 0;
}

void concat(char arr1[],char arr2[],int tam2){
    int cont=0; //cuenta caracteres de b2 (ocupados)
    //----contamos cuantos caracteres tiene b (arr2[]) para poder concatenar a(arr1[])----//
    for (int i = 0; i < tam2; i++)
    {
        if (arr2[i]!='\0')
        {
            cont++;
        }
    }
    //----Concatenamos arr1[]----//
    for (int i = cont; i < tam2; i++)
    {
        arr2[i]=arr1[i-cont];
    }
}