#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <stack>

inline bool IsLowerCharacter(char);

int main(){
    std::string in;
    std::set<std::string> words;
    
    while (std::cin >> in){
        int size = in.size();
        
        std::string current = "";
        for (int i = 0; i < size; ++i){
            char c = tolower(in[i]);
            if (IsLowerCharacter(c))
                current += c;
            else if (current != "")
            {
                words.insert(current);
                current = "";
            }
        }
        if (current != "")
            words.insert(current);
    }
    
    for (std::set<std::string>::iterator iter = words.begin(); iter != words.end(); ++iter)
        std::cout << *iter << '\n';
}

inline bool IsLowerCharacter(char c){
    return c >= 'a' && c <= 'z';
}