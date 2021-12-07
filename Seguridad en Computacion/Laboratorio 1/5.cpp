#include<iostream>
#include<string.h> 
#include<stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <fstream>
#include<iomanip>
#include<vector>

using namespace std;


void frecuencias(string line, ifstream &file){
    const int cant_letras = 'z'-'a'+1; //número de letras
    vector<int> diccionario(cant_letras); 

    while (getline(file, line)) {
        for (int k = 0; k < strlen(line.c_str()); k++){
            if(line[k] >= 'a' && line[k] <= 'z')
                diccionario[line[k] - 'a']++;
        }

    }
    int letra = 96;
    for (size_t i = 0; i < diccionario.size(); ++i) {
        cout <<  char(++letra)<< " : " << diccionario.at(i) << endl;
    }
}

int main(){
    string line;
    setlocale(LC_ALL, "spanish");

    ifstream file;
    file.open("HERALDOSNEGROS_pre.txt");

    frecuencias(line, file);

    return 0;
}