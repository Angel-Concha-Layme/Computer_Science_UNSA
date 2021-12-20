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

int a[10000]; 

int main(){
    int n, m, i, j, x, temp; 

    while(std::cin >> n){ 
        a[0]=1;
        m=1;
        temp=0;
        for(i=1; i<=n; i++){
            for(j=0; j<m; j++){
                x=a[j]*i+temp; 
                a[j]=x%10; 
                temp=x/10; 
            }

            while(temp>0){
                a[m]=temp%10;
                temp=temp/10;
                m++;
            }
        }
        a[m]='\0';
        std::cout << n << "!\n";
        for(j=m-1; j>=0; j--){
            std::cout << a[j];
        }
        std::cout << std::endl;
    }
    return 0;
}