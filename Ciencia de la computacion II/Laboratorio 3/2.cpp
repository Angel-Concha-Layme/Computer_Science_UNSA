#include<iostream>

using namespace std;
 

void swap(int &, int &);
void invertirIterativamente(int *,int );
int invertirRecursivamente(int *, int ,int );
void print(int *,int );

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int tam=sizeof(arr)/sizeof(arr[0]);
   
	
	invertirIterativamente(arr,tam);
	print(arr,tam);
    invertirRecursivamente(arr,tam,0);
    print(arr,tam);

	return 0;
}

void invertirIterativamente(int *arr,int tam){
    int *arr_f=arr+tam-1;
    for(int i=0;i<tam/2;i++){
        swap(*arr++,*arr_f--);
    }
}

int invertirRecursivamente(int *arr, int tam,int i){	
    
    if(i<tam+1){
        int *arr_f=arr+tam-1;
        swap(*arr,*arr_f); 	
	    invertirRecursivamente(++arr,tam-2,++i);
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