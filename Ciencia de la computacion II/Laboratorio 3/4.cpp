#include <iostream>

using namespace std;

int tamIterativo(char *);
int tamRecursivo(char *);

int main()
{

    char arr[]="123456789";
    char *ptr;
    ptr=arr;
	
	
    cout<<"Iterativo: "<<tamIterativo(ptr)<<endl;
    cout<<"Recursivo: "<<tamRecursivo(ptr)<<endl;
    return 0;
}


int tamIterativo(char *arr){
    int cont=0;

    while (*arr++!='\0'){
        cont++;
    }
    return cont;
}
int tamRecursivo(char *arr){
    if(*arr++=='\0')
        return 0;
    else
        return 1+tamRecursivo(arr);
}