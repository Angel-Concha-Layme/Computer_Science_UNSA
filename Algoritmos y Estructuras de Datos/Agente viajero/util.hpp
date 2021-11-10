#include <iostream>
using namespace std;

#ifndef _UTIL_H_
#define _UTIL_H_

void print(int **M, int V){
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
    
}

void printProcess(int &process, string message){
    cout << "[" << ++process << "] " << message <<"\n"<< endl;
}

#endif