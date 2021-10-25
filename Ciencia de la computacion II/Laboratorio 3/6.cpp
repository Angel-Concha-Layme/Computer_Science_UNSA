 #include <iostream>

using namespace std;

int tamRec(char *);
void strcpi(char *, char *);

int main()
{	
    char arrA[50]={"Angel"};
    char arrB[50]={"borrar"};
  
    char* ptr1,*ptr2;
    ptr1=arrA;
    ptr2=arrB;

    strcpi(ptr1,ptr2);

    cout<<arrB;
    cout<<endl;

    return 0;
    
}


int tamRec(char *arr){
    if(*arr++=='\0')
        return 0;
    else
        return 1+tamRec(arr);
}
void strcpi(char *arrA, char *arrB){
    while(*arrA!='\0'){
        *arrB=*arrA;
        arrB++;
        arrA++;
    }
    char *arr_f=arrB+tamRec(arrA);
    *arr_f='\0';

}