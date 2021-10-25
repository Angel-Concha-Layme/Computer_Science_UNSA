#include<iostream>
#include<ctime>

unsigned t1,t0;

int sumaRecursiva(int*,int);
int sumaIterativa(int* , int);

int main()
{
    t0=clock();
    int num[]={1,2,3,4,5,6,7,8,9,10};

    int result2=sumaRecursiva(num,sizeof(num)/4);
    int result3=sumaIterativa(num,sizeof(num)/4); 

    std::cout<<result2<<std::endl;
    std::cout<<result3<<std::endl;
    
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution Time: " << time <<std::endl;  

    return 0;
}


int sumaRecursiva( int * arr0 ,int size){ 
    if (size==1){
        return *arr0;
    }
    else
    {
       return *arr0+size-1  + sumaRecursiva(arr0,size-1);
    }
}


int sumaIterativa(int * arr0, int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum+=*arr0++;
    }
    
    return sum;   
}

