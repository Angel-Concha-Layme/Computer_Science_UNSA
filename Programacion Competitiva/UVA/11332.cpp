#include <iostream>

int getG(int n);

int main(){
    int num;
    std::cin >> num;
    while (num != 0){
        std::cout << getG(num) << std::endl;
        std::cin >> num;    
    }
}

int getG(int n){
    if (n / 10 == 0)
        return n;
    else{
        int newNum(0);
        while (n){
            newNum += n % 10;
            n /= 10;
        }
        return getG(newNum);
    }
}