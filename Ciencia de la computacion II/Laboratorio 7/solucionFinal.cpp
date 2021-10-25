#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>

unsigned t0,t1;

std::string TO_UPPER1(std::string);
std::string TO_UPPER2(std::string &&);
std::string &TO_UPPER3(std::string &);

int main(){
    t0=clock();

    std::string TEXTO("Texto de prueba");
    std::cout<< TO_UPPER1(TEXTO)<<std::endl;
    std::cout<< TO_UPPER2(TEXTO)<<std::endl;
    std::cout<< TO_UPPER3(TEXTO)<<std::endl;
    t1=clock();     
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution Time: " << time <<std::endl; 

    return 0;
}

std::string TO_UPPER1(std::string in){
    std::transform(in.begin(), in.end(), in.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c); });
    return in;
}

std::string &TO_UPPER2(std::string &in){
    std::transform(in.begin(), in.end(), in.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c);});
    return in;
}

std::string TO_UPPER3(std::string &&in){
    std::transform(in.begin(), in.end(), in.begin(), [](unsigned char c) -> unsigned char { return std::toupper(c);});
    return std::move(in);
}











