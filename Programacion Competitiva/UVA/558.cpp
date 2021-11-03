#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>


const int Inf = 1e9; // 1,000,000,000
const int MaxNumStars = 1005;

struct Edge{ 
    int to; 
    int c; 
};

std::vector<Edge> edges[MaxNumStars]; //lista de adyacencia
int distances[MaxNumStars]; //distancia de un nodo a otro

int main(){
    int T;
    std::cin >> T;
    
    while (T--){
        int N, E; //N: numero de nodos, E: numero de aristas
        std::cin >> N >> E;
        
        for (int i = 0; i < N; ++i){
            edges[i].clear();
            distances[i] = Inf;
        }
        Edge e;
        while (E--){
            int x;
            std::cin >> x >> e.to >> e.c;
            edges[x].push_back(e);  //agrega una arista
        }
        
        for (int t = 0; t < N - 1; ++t){
            for (int j = 0; j < N; ++j){
                for (int e = 0; e < edges[j].size(); ++e){
                    distances[edges[j][e].to] = std::min(distances[edges[j][e].to], distances[j] + edges[j][e].c); //actualiza la distancia
                }
            }
        }
         
        bool canGoLower = false; //si puede ir a una distancia menor
        
        for (int j = 0; j < N; ++j){
            for (int e = 0; e < edges[j].size(); ++e){
                canGoLower |= distances[edges[j][e].to] > distances[j] + edges[j][e].c; //si alguna distancia es mayor a la distancia actual + la capacidad de la arista
            }
        }
        std::cout << (canGoLower ? "possible\n" : "not possible\n");
    }
}