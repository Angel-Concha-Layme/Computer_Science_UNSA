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
    int tc,n,sec,mile,juice;
    int kase;
    while(std::cin>>tc){
        kase=1;
        while(tc--){
        std::cin>>n;
        mile=juice=0;
            while(n--){
            std::cin>>sec;
            mile+=(sec/30) * 10 + 10;
            juice+=(sec/60) * 15 + 15;
            }
        if(mile<juice){
            std::cout<<"Case "<<kase<<": "<<"Mile "<<mile<<std::endl;
        }
        else if(juice<mile){
            std::cout<<"Case "<<kase<<": "<<"Juice "<<juice<<std::endl;
        } 
        else if(mile==juice){
            std::cout<<"Case "<<kase<<": "<<"Mile Juice "<<mile<<std::endl;}
        kase++;
        }
    }
    return 0;
}