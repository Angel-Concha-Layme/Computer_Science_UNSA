#include<iostream>

double fibonacci_iterativo (int n){
	double i = 0;
	double j = 1;
	for (auto k = 1; k < n; k++){	
	    double t;
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
