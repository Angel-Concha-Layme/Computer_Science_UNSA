#include<iostream>
#include<string.h> 
#include<stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
using namespace std;

int main(){
    string line;
    setlocale(LC_ALL, "spanish");
    //setlocale(LC_ALL,"");
    //setlocale(LC_ALL, "es_ES");
    //setlocale(LC_ALL,"es_ES.UTF8");

    while(getline(cin, line)){
        for (int k = 0; k < strlen(line.c_str()); k++){
            if (line[k] == 'j' || line[k] == 'h')
                line[k] = 'i';
            if (line[k] == 164)
                line[k] = 'n';
            if (line[k] == 'k')
                line[k] = 'l';
            if (line[k] == 'u' || line[k] == 'w')
                line[k] = 'v';
            if (line[k] == 'y')
                line[k] = 'z';
            
        }
        cout << line << endl;
    }

    return 0;
}