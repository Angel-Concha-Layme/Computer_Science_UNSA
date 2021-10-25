#include <iostream>
#include <vector>
#include <fstream>
#include "grafo.h"



int main()
{
    std::vector<int> entrada;
    std::string cadena;
    std::ifstream input;
    input.open("entrada.txt");

    int numeroDeNodos = 1053;
    int numeroDeAristas = 0;
    int nodoInicial_Final = 712;
    int valor = 0;

    int k = 0;
    while(!input.eof())
    {
        input>> cadena;

        if (k == 0)
        {
            numeroDeAristas = std::stoi(cadena);
        }
        else if (k == 1)
        {
            nodoInicial_Final = std::stoi(cadena);
        }
        
        else
        {
            valor = std::stoi(cadena);
            entrada.push_back(valor);
        }

        
        cadena = "";
        k++;
    }
    input.close();

   
    Grafo grafo(numeroDeNodos, nodoInicial_Final);
    int U, V, P;

    for (int k = 0; k < entrada.size(); k +=  3)
    {
        U = entrada[k];
        V = entrada[k+1];
        P = entrada[k+2];
        
        grafo.insertarArista(U, V, P);
    }

    
    grafo.Prim();
    //grafo.mostrarRelaciones();



    auto Recorrido = grafo.obtenerCiclo(grafo.relacionesDelArbolDeExpansionMinima);
    
    int pesoTotal = 0;
    int nodo_actual = Recorrido[0].nodoA;


    //Crear archivo de Salida
    std::ofstream salida("salida.txt");
    std::vector<int> cicloDeSalida;


    cicloDeSalida.push_back(nodo_actual);
    for (int k = 0; k < Recorrido.size(); k++)
    {
        pesoTotal += grafo.matrizDeAdyacencia[nodo_actual-1][Recorrido[k].nodoB-1];
        cicloDeSalida.push_back( Recorrido[k].nodoB );
        nodo_actual = Recorrido[k].nodoB;
    }
    
        
    salida <<  pesoTotal << "\n";
    salida <<  Recorrido.size() +1 << "\n";

    for (int k = 0; k < cicloDeSalida.size(); k++)
    {
        salida <<  cicloDeSalida[k] << "\n";
    }

    salida.close();
    std::cout<< "Archivo exitosamente creado\n";
    
    return 0;
}
