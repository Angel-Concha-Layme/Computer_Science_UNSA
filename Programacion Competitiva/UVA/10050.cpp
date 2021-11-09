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


int main(){
    int ar[4000],N,P,i,x,sum,T,j;
    std::cin>>T;

    while(T--){
        std::cin>>N>>P;
        for(i=1;i<=N;i++){
            ar[i]=0;
        }
        
        for(i=1; i<=P; i++){
            std::cin>>x;
            for(j=x;j<=N;j+=x){
                ar[j]=1;
            }
        }

        sum=0;
        for(i=1; i<=N; i++){
            if(i%7!=0&&i%7!=6)
            sum+=ar[i];
        }

        std::cout<<sum<<'\n';
    }
    return 0;
}