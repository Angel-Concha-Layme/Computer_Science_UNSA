#include <iostream>

using namespace std;

void swap(int &, int &);
void ordAscendente(int *, int);
void print(int *,int );
int main()
{
    int arr[]={3,5,8,4,6,2,7};
    int tam=sizeof(arr)/sizeof(arr[0]);

    int *ptr;
    ptr=arr;

  	ordAscendente(ptr,tam);
	print(ptr,tam);

    return 0;
}


void ordAscendente(int *arr, int t){
    int *ptr=arr;
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){
            ptr=arr+j;
            if(*arr>*ptr){
                swap(*arr,*ptr);
            }
        }
        arr++;
    }

}

void print(int *arr,int tam){
    
	for(int i=0; i<tam;i++){
		cout<<*arr<<" ";
        arr++;
    }
	cout<<endl;
} 

void swap(int &a, int &b)
{
    a^=b;
    b^=a;
    a^=b;
}
