#include<iostream>

int fibonnacci_aritmetica_modular(int n, int m){ // fib (n) % m
	int a = 0;  //n - 2
	int b = 1;  //n - 1
	
	for (auto k = 1; k < n; k++){	
		int c;  //n
		c = a % m + b % m;  //f(n) = f(n-1) + f(n-2)
		a = b;  // n-2 = f(n-2)
		b = c;   // n - 1 = f(n)
	}
	return b % m; 
}

int main(){
    std::cout<< fibonnacci_aritmetica_modular(1073741824,1048576);
    return 0;
}