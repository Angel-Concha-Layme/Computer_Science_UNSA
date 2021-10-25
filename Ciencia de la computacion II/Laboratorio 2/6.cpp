#include<iostream>
#include<ctime>

unsigned t0,t1;

void strcpy(char [],char[]);

int main(){
    t0=clock();
    char a[100]="HOLA";
    char b[100]="MUNDO";
    
    strcpy(a,b);
    
    //----Imprime "destino" (cadena destino ++ cadena inicial)----//
    for (int i = 0; i < 100; i++)
    {
        std::cout<<b[i]<<std::endl;    
    }
      
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution time: "<< time <<std::endl;
    
    return 0;
}

void strcpy(char origen[],char destino[]){
    int cont=0; //calmacena caracteres "ocupados" 
    //----cont = caracteres "llenos" de destino----//
    for (int  i = 0; destino[i] != '\0'; i++)
    {
        cont++;
        
    }
    //----copia caracteres de origen a destino gracias a cont----//
    for (int  i = 0; origen[i] != '\0'; i++)
    {
        destino[i+cont]=origen[i];
    }
}