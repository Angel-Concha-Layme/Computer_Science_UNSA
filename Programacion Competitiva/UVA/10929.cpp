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


/*-----------------------------------------------------------------
La regla de divisibilidad del 11:
    Un número es divisible por 11 si, y sólo si, la suma alternada
    de sus dígitos (es decir, se va alternando suma y resta) es
    múltiplo de 11 (incluido el 0).
-----------------------------------------------------------------*/


int main() {
    std::string n ;
    int odd, even; 
    while(std::getline(std::cin,n) && n!="0"){
        odd = 0;
        even = 0;
        for(int i = 0;i<n.length();i++){
            if(i%2==0)
                even += n[i] - '0';
            else
                odd += n[i]- '0';
        }
        std::cout << n << " is ";
        if(abs(odd-even)%11!=0){
            std::cout << "not ";
        }
        std::cout << "a multiple of 11.\n";
    }
    return 0;
}
