#include<iostream>
#include<string>
#include<utility>

void f(std::string &);  // Funcion que recibe una referencia normal.
void f(std::string &&); // Funcion que recibe una referencia a rvalue
std::string EscribirTexto();

int main(){  

    std::string texto = "Hola u.u";
    std::string textoFinal;
    
    f(texto);                   // Llama a la primera sobrecarga.
    f("Hola u.u");              // Llama a la segunda sobrecarga.
    f(std::string("Hola u.u")); // Llama a la segunda sobrecarga.
    f(std::move(texto));        // Llama a la segunda sobrecarga.


    //std::move(texto); //No hace nada
    return 0;
}

void f(std::string &s){}
void f(std::string &&s){}
std::string EscribirTexto(){
    std::string Texto("Profesor un puntito mas xdxd");
    return std::move(Texto);
}





