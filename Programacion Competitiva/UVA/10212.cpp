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

#define LL long long int

int main(){
    LL a,b;
    while(std::cin>>a>>b){
        if(b==0) std::cout<<1<<std::endl;
        else{
            LL ans=1;
            LL c=a-b+1;
            for(LL i=a;i>=c;i--){
                ans*=i;
                while(ans%10==0)
                    ans/=10;

                ans=ans%1000000000;

            }
            std::cout<<ans%10<<std::endl;
        }
    }
    return 0;
}
