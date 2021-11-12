#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string highest_value_palindrome(std::string s, int k);

int main(){
    int n,k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::cout << highest_value_palindrome(s, k) << std::endl;

    return 0;
}


std::string highest_value_palindrome(std::string s, int k){
    std::vector<bool> changed(s.size(), false);
    for(int i=0; i<s.size() / 2; ++i){
        int j=s.size()-1-i;
        if(s[i] > s[j]){
            s[j] = s[i];
            changed[j] = true;
            k--;
        }
        else if(s[i] < s[j]){
            s[i] = s[j];
            changed[i] = true;
            k--;
        }
    }

    if(k < 0)
    return "-1"; 
    if(k == 0)
    return s; 

    for(int i=0; i<s.size() / 2; ++i){
        int j=s.size()-1-i;

        if(s[i] < '9' && k >= (2 - changed[i] - changed[j])){
            s[i] = '9';
            s[j] = '9';

            k -= (2 - changed[i] - changed[j]);
        }
    }
    if(k > 0 && (s.size() % 2) == 1){
        s[(s.size() / 2)] = '9';
    }
    
    return s;
}