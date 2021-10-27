#include<iostream>

int fib_recursivo(int n){  //fibonacci de manera recursiva
	if(n < 2 ) 
		return n; 
	else
		return fib_recursivo(n-1) + fib_recursivo(n-2);
}

int main(){
    for (auto i = 0; i < 100; i++){
        std::cout<<"Fib_recursivo("<<i<<")= "<<fib_recursivo(i)<<std::endl;    
    } 
    return 0;
}

