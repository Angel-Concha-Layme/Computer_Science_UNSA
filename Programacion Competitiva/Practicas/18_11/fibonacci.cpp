#include<iostream>
#include<vector>

//fibonacci recursivo 
int fibonacci(int n){
    if(n<=1)
        return n;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}

//fibonacci iterativo
int fibonacci_iterativo(int n){
    int a=0,b=1,c=0;
    for(int i=0;i<n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
//fibonacci con aritmetica modular
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

//fibonnacci con memoizacion
int fibonacci_memoizacion(int n,int *memo){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(memo[n]!=0)
        return memo[n];
    memo[n]=fibonacci_memoizacion(n-1,memo)+fibonacci_memoizacion(n-2,memo);
    return memo[n];
}

//fibonacci con tabla
int fibonacci_tabla(int n){
    int memo[n+1];
    for(int i=0;i<=n;i++)
        memo[i]=0;
    return fibonacci_memoizacion(n,memo);
}

//fibonnaci bottom up con vector
long fib_bottomup(int n){
    if (n <= 1){
        return n;
    }
    std::vector<long> fib(n+1);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}



int main(){

}

