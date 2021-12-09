#include<iostream>
#include<string.h> 
#include<stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main(){
    string line;
    setlocale(LC_CTYPE, "Spanish");
    //setlocale(LC_ALL, "spanish");
    //setlocale(LC_ALL,"");
    //setlocale(LC_ALL, "es_ES");
    //setlocale(LC_ALL,"es_ES.UTF8");

    ofstream file;
    file.open("HERALDOSNEGROS_pre.txt");

    while(getline(cin, line)){
        const char CaracteresIndeseados[] = {'¡', '!', ';', ' ', '.',','};
        int Switch = 0;

        for (int i = 0; i < strlen(line.c_str()); i++)
        {
            for (int j = 0; j < strlen(CaracteresIndeseados); j++)
                if (line[i] == CaracteresIndeseados[j]) Switch = 1;

            if (Switch == 0){
                file << line[i];
            }
                
            Switch = 0;
        }
        file << '\n';
    }
    file.close();
    return 0;
}