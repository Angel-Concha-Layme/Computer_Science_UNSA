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
            if(line[k]>96 & line[k]<123)
                line[k] = line[k] - 32;
            if (line[k] == 160) // A con tilde
                line[k] = 181;
            if (line[k] == 130) // E con tilde
                line[k] = 144;
            if (line[k] == 161) // I con tilde
                line[k] = 214;
            if (line[k] == 162) // O con tilde
                line[k] = 224;
            if (line[k] == 163) // U con tilde
                line[k] = 223;
            if (line[k] == 164) // Ñ con tilde
                line[k] = 165;
        }
        cout << line << endl;
    }

    return 0;
}