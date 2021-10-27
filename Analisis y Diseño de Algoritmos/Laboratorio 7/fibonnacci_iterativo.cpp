#include<iostream>

int fibonacci_iterativo (int n){
	int i = 0;
	int j = 1;
	for (int k = 1; k < n; k++){	
	    int t;
	    t = i + j;
	    i = j;
	    j = t;
	}
	return j;
};

int main(){
    for (auto i = 0; i < 100; i++){
        std::cout<<"Fib_iterativo("<<i<<")= "<<fibonacci_iterativo(i)<<std::endl;    
    } 
    return 0;
}
