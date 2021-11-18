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
    int a[3001],b[3001],number,check,flag,i;
    while(std::cin >> number){
        flag=1;

        for(i=0;i<number;i++){
            std::cin>>a[i];
        }

        for(i=1;i<number;i++){
            b[i]=abs(a[i]-a[i-1]);
        }
        std::sort(b,b+i);

        for(i=1;i<number;i++){
            if(b[i]!=i){
                flag=0;
                break;
            }
        }
 
        if(flag==0){
            std::cout<<"Not jolly\n";
        }
        else{
            std::cout<<"Jolly\n";
        }
    }
	return 0;
}