#include<iostream>
#include<string.h> 
#include<stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
using namespace std;

int main(){
    string line;
    setlocale(LC_CTYPE, "Spanish");
    //setlocale(LC_ALL, "spanish");
    //setlocale(LC_ALL,"");
    //setlocale(LC_ALL, "es_ES");
    //setlocale(LC_ALL,"es_ES.UTF8");
    while(getline(cin, line)){
        for (int k = 0; k < strlen(line.c_str()); k++){
            if (line[k] == 160)
                line[k] = 'a';
            if (line[k] == 130)
                line[k] = 'e';
            if (line[k] == 161)
                line[k] = 'i';
            if (line[k] == 162)
                line[k] = 'o';
            if (line[k] == 163)
                line[k] = 'u';
            
        }
        cout << line << endl;
    }
    return 0;
}