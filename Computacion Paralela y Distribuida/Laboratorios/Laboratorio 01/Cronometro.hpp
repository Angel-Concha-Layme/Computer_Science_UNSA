#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>


class Cronometro{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> _inicio;
public:
    Cronometro(){};
    void start(){
        _inicio = std::chrono::high_resolution_clock::now();       
    }
    void stop(){
        std::chrono::time_point<std::chrono::high_resolution_clock> final = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float,std::milli> tiempo_total = final - _inicio;
        std::cout<<tiempo_total.count()<<" ms.\n";
    }
};
