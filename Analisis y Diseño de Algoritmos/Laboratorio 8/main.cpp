#include <iostream>
#include <vector>
#include "Square.cpp"

int main(){
    Square TEST;
    for (auto i = 0; i < 14; i++){
        for (auto j = 0; j < 14; j++){
            std::cout<<TEST.get_num_square(i,j)<<"  \t";
        }
        std::cout<<'\n';
    }
    return 0;
}