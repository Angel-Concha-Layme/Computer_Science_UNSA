
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<string.h>
#include<sstream>
#include<stdexcept>
#include<iterator>

//-----------------------------------------------------------------------------------------------------------------***
//ESTRUCTURA QUE GUARDA EL TAMAÑO DEL VECTOR Y EL TIEMPO QUE TARDA EN SER ORDENADO.
struct size_time{
    int size;
    double time;
};
//-----------------------------------------------------------------------------------------------------------------***

//-----------------------------------------------------------------------------------------------------------------***
//VECTORES DE TIPO [SIZE-TIME] : ESTRUCTURA QUE GUARDA EL TAMAÑO DEL VECTOR Y EL TIEMPO QUE TARDA EN SER ORDENADO.
std::vector<size_time> time_merge;
std::vector<size_time> time_insertion;
//-----------------------------------------------------------------------------------------------------------------***


int main(){
    size_time data;
    data.size=2;
    data.time=3.5564;
    time_merge.push_back(data);

    for (int i = 0; i < time_merge.size(); i++){
        std::cout<<time_merge[i].size<<time_merge[i].time;
    }
    
    return 0;
}
