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

int gcd(int, int);

int main(){
    int sum=0,n=0;
    while(std::cin>>n){ 
        if(n==0)
            break;
        sum=0;
        for(auto i=1;i<n;i++){
            for(auto j=i+1;j<=n;j++){
                sum+=gcd(i,j);
            }
        }
        std::cout<<sum<<std::endl;
    }

    return 0;
}

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}