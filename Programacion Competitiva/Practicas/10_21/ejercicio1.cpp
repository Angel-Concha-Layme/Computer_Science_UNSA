#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

//dada una lista, encontrar el mayor producto  que se puede obtener multiplicando dos elementos de la lista

int max_product_1(std::vector<int>&);
int max_product_2(std::vector<int>&);

int main(){
    std::vector<int> IN_vector = {1,6,5,8,9,9,8};
    max_product_1(IN_vector);
    max_product_2(IN_vector);
    return 0;
}

int max_product_1(std::vector<int> &IN_vector){
    int num_max_1=0, num_max_2=0;
    for (auto i = 0; i < IN_vector.size(); i++){
        if (num_max_1<=IN_vector[i]){
            num_max_2=num_max_1;
            num_max_1=IN_vector[i];
        }
    }
    std::cout<<num_max_1*num_max_2<<std::endl;
    return num_max_1*num_max_2;
}

int max_product_2(std::vector<int> &IN_vector){
    std::sort(IN_vector.begin(),IN_vector.end(),std::greater<int>());
    std::cout<<IN_vector[0]*IN_vector[1]<<std::endl;
    return IN_vector[0]*IN_vector[1];
}