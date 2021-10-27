#include<iostream>
int main(){
    int cases;
    std::cin>>cases;
    while (cases--){
        int n_temporal;
        std::cin>>n_temporal;
        std::cout << abs((((((n_temporal * 63) + 7492) * 5) - 498) / 10) % 10) << std::endl; // [* 567 / 9] - [* 235 / 47]
    }
}