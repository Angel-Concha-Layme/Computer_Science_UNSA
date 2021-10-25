#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>

void letterXletter(const char[],int);

int main(){
    char a[20];
    int z;
    std::cout<<"CONSOLA: "<<std::endl;
    std::cin.getline(a,20,'\n');
    
    z=strlen(a);
    std::cout<<"RESULT: "<<std::endl;
    letterXletter(a,z);

} 
void letterXletter(const char entrada[],int size){
    for (int i = 0; i < size; i++)
    {
        std::cout<<entrada[i]<<std::endl;
    }
}