#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>

#define INF 999999

using namespace std;

#include "util.hpp"
#include "nn.hpp"

void floydWarshall(int **dist, int **states, int V){
    for (size_t k = 0; k < V; k++)
        for (size_t i = 0; i < V; i++)
            for (size_t j = 0; j < V; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    states[i][j] = states[k][j];
                }
            }
}

vector<int> processCircuit(vector<int> circuit, int **D, int **G, int **S){
    vector<int> newCircuit;
    for(auto it = circuit.begin(); it != circuit.end()-1; ++it){
        list<int> aux;
        int start = *it, end = *(it+1);
        while (S[start] != S[end]){
            end = S[start][end];
            aux.push_front(end);
        }
        for (auto it = aux.begin(); it != aux.end(); ++it){
            newCircuit.push_back(*it);
        }
        
    }
    newCircuit.push_back(*(circuit.end()-1));
    return newCircuit;
}

vector<int> preProcess(vector<int> v1){
    auto itLeft = find(v1.begin(), v1.end(), 711);
    auto itRight = find(v1.begin(), v1.end(), 711);

    vector<int> v;
    for (; itRight != (v1.end() - 1); ++itRight){
        v.push_back(*itRight);
    }
    
    for (auto it = v1.begin(); it != itLeft; ++it){
        v.push_back(*it);
    }
    v.push_back(711);
    return v;
}

int main(){
    int V,E,start, process = 0;
    int **graph;
    int **dist;
    int **states;

    printProcess(process, "Abriendo archivo de entrada");
    ifstream inputFile {"entrada.txt", ios::in};
    if (!inputFile.is_open()){
        cerr << "No se pudo abrir el archivo" << endl;
        exit(EXIT_FAILURE);
    }

    int initdata[3] = {0};
    for (size_t i = 0; i < 3; i++){
        inputFile >> initdata[i];
    }

    V = initdata[0];
    E = initdata[1];
    start = initdata[2];

    printProcess(process, "Creando matrices");
    graph = new int*[V];
    dist = new int*[V];
    states = new int*[V];

    for (size_t i = 0; i < V; i++){
        graph[i] = new int [V];
        for (size_t j = 0; j < V; j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
    for (size_t i = 0; i < V; i++){
        dist[i] = new int [V];
        for (size_t j = 0; j < V; j++){
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
    for (size_t i = 0; i < V; i++){
        states[i] = new int [V];
        for (size_t j = 0; j < V; j++){
            states[i][j] = i;
        }
    }
    printProcess(process, "Matrices inicializadas");
    printProcess(process, "Llenando datos desde archivo");
    int centinel1, centinel2;
    for (size_t i = 0; i < V; i++){
        inputFile >> centinel1 >> centinel2;
    }
    int u,v,c, f=1;
    for (size_t i = 0; i < E; i++){
        inputFile >> u >> v >> c;
        graph[u-f][v-f] = graph[v-f][u-f] = c;
        dist[u-f][v-f] = dist[v-f][u-f] = c;
    }
    inputFile.close();
    printProcess(process, "Archivo cerrado");

    printProcess(process, "Aplicando wharsall");
    floydWarshall(dist, states, V);

    printProcess(process, "Aplicando vecino mas cercano");
    
    int maxResult = 30000;
    vector<int> circuitSolved;
    for (size_t i = 0; i < V; i++){
        NN tsp(dist, V);
        tsp.solve(i);
        if(tsp.pathLength < maxResult){
            cout << "nuevo min " << tsp.pathLength << endl;
            maxResult = tsp.pathLength;
            circuitSolved = tsp.circuit;
        }
            
    }

    cout << maxResult << endl;
    cout << circuitSolved.front() << endl;
    cout << *(circuitSolved.end() - 2) << endl;

    vector<int> circuitB = preProcess(circuitSolved);
    cout << circuitB.front() << " " << *(circuitB.end()-2) << endl;

    printProcess(process, "Ciclo en bruto obtenido");
    vector<int> circuit = circuitB;
    cout << "Tamaño del ciclo  bruto: " <<circuit.size() << endl;

    printProcess(process, "Procesar ciclo en bruto");
    vector<int> circuitComplete = processCircuit(circuit, dist, graph, states);
    printProcess(process, "Ciclo en bruto procesado");

    cout << "Tamaño del ciclo total: " << circuitComplete.size() << endl;

    printProcess(process, "Sobreescribiendo resultados en archivo.");
    ofstream oFile("salida.txt", ios::out);
    
    int pesoTotal = 0;
    
    if(!oFile){
        cout << "No se pudo abrir archivo de salida\n";
    }else{
        for(auto i = circuitComplete.begin(); i != circuitComplete.end() - 1; ++i){
            pesoTotal += graph[(*i)][(*(i+1))];
        }
    }
    cout << "Peso total del ciclo:" << pesoTotal << endl;

    oFile << pesoTotal << endl;
    oFile << circuitComplete.size() << endl;
    for (auto it = circuitComplete.begin(); it != circuitComplete.end() - 1; ++it)
    {
        oFile << (*it) + 1 << endl;
    }
    oFile << *(circuitComplete.end()-1) + 1;

    oFile.close();
    printProcess(process, "Archivo de salida cerrado");
    printProcess(process, "Tareas terminadas");


    printProcess(process, "Destruyendo matrices");
    for (size_t i = 0; i < V; i++){
        delete [] graph[i];
        delete [] dist[i];
    }
    delete [] graph;
    delete [] dist;

    return 0;
}