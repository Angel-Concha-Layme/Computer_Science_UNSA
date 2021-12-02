#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>

#define mx 35000

bool is_prime[mx + 10]; 

std::vector <int> prime , ana;
void sieve() {
    is_prime[0] = 1 ;
    is_prime[1] = 1 ;
    for(int i = 4 ; i <= mx ; i += 2)
        is_prime[i] = 1 ;
    for(int i = 3 ; i * i <= mx ; i += 2) {
        if( !is_prime[i] ) {
            for(int j =  i * i ; j <= mx ; j += i + i) {
                is_prime[j] = 1 ;
            }
        }
    }
    prime.push_back(2) ;
    for(int i = 3 ; i <= mx ; i += 2 ) {
        if(!is_prime[i] ) {
            prime.push_back(i) ;
        }
    }
}

int main() {
    sieve() ;
    int x , y ;
    while(std::cin >> x >> y) { 
        if(x == 0 && y == 0)
            break ;
        if( x > y) 
            std::swap(x , y) ;
        int i = 0 ;
        while(prime[i] < x)
            i++ ;
        while(prime[i + 2] <= y) {
            if(prime[i + 2] - prime[i + 1] == prime[i + 1] - prime[i]) {
                int start = i ;
                int end = i + 2 ;
                int diff = prime[i + 1] - prime[i] ;
                while( i + 3 < prime.size() && prime[i + 3] - prime[i + 2] == diff) {
                    end++ ;
                    i++ ;
                }
                if(prime[end] <= y) {
                    if(start == 0 || prime[start] - prime[start - 1] != diff) {
                        std::cout << prime[start] ;
                        for(int i = start + 1 ; i <= end ; i++) {
                            std::cout << " " << prime[i] ;
                        }
                        std::cout << "\n" ;
                    }
                }
                else 
                    break ;
            }
            i++ ;
        }
    }
    return 0 ;
}