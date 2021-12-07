#include<iostream>
#include<string.h> 
#include<stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>
#include <cmath>   
using namespace std;

int main(){
    string line;
    setlocale(LC_ALL, "spanish");
    int cont = 0;
    int as = 20;

    while(getline(cin, line)){
        for (int k = 0; k < strlen(line.c_str()); k++){
            if(k == as){
                line.insert(k, "AQUI");
                as= as+20;
            }
            else{
                cont++;
            }  
            
        }
        as = abs(as - strlen(line.c_str()) - 20.0);
        cout << line << endl;
    }
    return 0;
}