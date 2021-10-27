#include<iostream>
#include<vector>

bool algorithm(int[], int);

int main(){
    int arr_numeros[]={1,2,3,4,5,6,9};
    int size=sizeof(arr_numeros)/sizeof(arr_numeros[0]);

    algorithm(arr_numeros,size);
    return 0;
}
bool algorithm(int arr[],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n ; k++){
                std::cout<<arr[j]+arr[k]<<" ";
               /* if (arr[j]+arr[k]==arr[i]){
                    std::cout<<arr[j]<<" + "<<arr[k]<<" = "<<arr[i]<<std::endl;
                }*/
                
            }
            
        }
    }
    return true;
}




