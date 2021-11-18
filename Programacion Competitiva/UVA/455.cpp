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
    int t;
    std::cin >> t;
    std::string str;
    std::vector<int> cou;
    for(auto i=1;i<=t;i++){
        std::cin >> str;
        int len = str.length();
        for(auto j=1;j<=len;j++){
            std::string sum ="";
            std::string sub = str.substr(0,j);
            int sublen =sub.length();
            for(int k=0;k<len/sublen;k++){
                sum+=sub;
            }
            if(sum==str){
                std::cout << sublen <<std::endl;
                break;
            }
        }
        if(i!=t)
           std::cout << std::endl;
    }
}