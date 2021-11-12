#include <bits/stdc++.h>

int main(){
    int year;
    std::cin >> year;
    int day = 256;

    if(year >= 1700 && year <= 1917 ){
        if ( year % 4 == 0 ){
            std::cout << "12.09." << year << std::endl;
        }
        else{
            std::cout << "13.09." << year << std::endl;
        }
    }

    else if ( year == 1918 ){
        std::cout << "26.09.1918" << std::endl;
    }

    else if ( year >= 1919 && year <= 2700 ){
        if ( year % 400 == 0 || ( year % 4 == 0 && year % 100 != 0 ) ){
            std::cout << "12.09." << year << std::endl;
        }
        else{
            std::cout << "13.09." << year << std::endl;
        }
    }
    return 0;
}