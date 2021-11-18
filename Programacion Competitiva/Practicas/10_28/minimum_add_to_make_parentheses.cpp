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


int minAddToMakeValid(std::string s) {
    std::stack<char>A;
    if(s.empty()) return 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            A.push(s[i]);
        }
        else{
            if(!A.empty() && A.top()=='(' && s[i]==')'){
                A.pop();
            }
            else{
                A.push(s[i]);
            }
        }
    }
    return A.size();
}
int main(){
    std::string s = "()))((";
    std::cout<<minAddToMakeValid(s);
    return 0;
}