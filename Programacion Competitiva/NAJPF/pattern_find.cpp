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


#define MU 1000000007
#define ULL unsigned long long
ULL hash[1000009];
void preHash(char[], int);
void solve(char[], char[], int, int); 

int main(){
    int t;
    std::cin >> t;  
    while(t--){
        char text[1000009] ,  pattern[1000009];
        std::cin >> text >> pattern; 
        int n , m ;
        n = strlen(text);
        m = strlen(pattern);
        solve(text , pattern , m , n);
    }
    return 0;
}

void preHash(char str[] , int n){
    hash[n] = 0;
    for(int i = n-1 , j = 1 ; i>=0 ; i-- , j++){
        hash[i] = hash[i+1]*MU + str[i] - 97;
    }
}
void solve(char text[] , char pattern[] , int p , int t){
    ULL p_hash = 0 , check , pre = 1;
    for(int i = p-1 ; i>=0 ; i--){
        p_hash = p_hash*MU + pattern[i] - 97;
        pre = pre*MU;
    }
    check = p_hash;
    std::vector<int> v;
    int flag = 0;
    preHash(text , t);
    for(int i = 0; i < t - p + 1 ; i++ ){
        if(hash[i] - pre*hash[i+p] == check){
            flag++;
            v.push_back(i+1);
        }
    }
    if(flag == 0)
        std::cout << "Not Found" << std::endl;
    else{
        std::cout << flag << std::endl;
        for(int i = 0 ; i < flag ; i++){
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
}