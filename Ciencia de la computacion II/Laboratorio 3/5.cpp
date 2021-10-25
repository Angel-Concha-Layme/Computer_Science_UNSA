#include <iostream>

using namespace std;


int tamRec(char *);
void shift_Concat(char *,char *);

int main()
{
    char arrA[50]={"123456789"};
    
    char arrB[50]={"123456789"};
   
    char* ptr1,*ptr2;

    ptr1=arrA;
    ptr2=arrB;

	shift_Concat(ptr2,ptr1);

    cout<<ptr2;
    cout<<endl;
    return 0;
}

int tamRec(char *arr){
    if(*arr++=='\0')
        return 0;
    else
        return 1+tamRec(arr);
}
void shift_Concat(char *arrB,char *arrA){
	int tamB=tamRec(arrB);
	int tamA=tamRec(arrA);
	char *arr_fB=arrB+tamB;
    char *arr_fN=arrB+tamB+tamA;
    for(int i=0;i<tamA;i++)
        *arr_fB++=*arrA++;
    *arr_fN='\0';
}