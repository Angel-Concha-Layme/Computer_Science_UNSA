#include <vector>
#include "otros.h"

class Grafo
{
public:
    Grafo(int n, int i_f);
    int numero_de_nodos;
    int **matrizDeAdyacencia;
    int nodo_inicial_final;
    std::vector<Relacion> relacionesDelArbolDeExpansionMinima;
    std::vector<Arista> *lista_de_aristas;
    std::vector<Arista> *lista_de_aristas_del_MST;
    void insertarArista(int nombre_de_nodo1, int nombre_de_nodo2, int peso);
    void Prim();
    void mostrar();
    void mostrarRelaciones();
    void sumaDeCaminos();
    Relacion buscaEnLista(std::vector<Relacion> &lista_de_relaciones, int nodo);
    std::vector<Relacion> obtenerCiclo(std::vector<Relacion> lista_de_relaciones );
    std::vector<Relacion> Optimizacion(std::vector<Relacion> listaDeRelaciones);
    ~Grafo();
};

Grafo::Grafo(int n, int i_f)
{
    numero_de_nodos = n;
    nodo_inicial_final = i_f;
    matrizDeAdyacencia = new int *[numero_de_nodos];

    for (int i = 0; i < numero_de_nodos ; i++)
    {
        matrizDeAdyacencia[i] = new int[numero_de_nodos];

        for (int j = 0; j < numero_de_nodos ; j++)
        {
            matrizDeAdyacencia[i][j] = -1;
        }
    }

    lista_de_aristas = new std::vector<Arista>[numero_de_nodos];
    lista_de_aristas_del_MST = new std::vector<Arista>[numero_de_nodos];
}

void Grafo::insertarArista(int nombre_de_nodo1, int nombre_de_nodo2, int peso)
{
    matrizDeAdyacencia[nombre_de_nodo1 - 1][nombre_de_nodo2 - 1] = peso;
    matrizDeAdyacencia[nombre_de_nodo2 - 1][nombre_de_nodo1 - 1] = peso;
}

void Grafo::Prim()
{
    Arista A_Auxiliar; //nodo que tomara valores para ser insertado

    for (int i = 0; i < numero_de_nodos ; i++)
    {
        for (int j = 0; j < numero_de_nodos ; j++)
        {
            if (matrizDeAdyacencia[i][j] != -1)
            {
                A_Auxiliar.nodo_1 = i+1;
                A_Auxiliar.nodo_2 = j+1;
                A_Auxiliar.peso = matrizDeAdyacencia[i][j];

                //se crea una lista de vectores, los cuales almacenan las aristas
                //que conectan al nodo i-esimo con los nodos adyacentes a este
                lista_de_aristas[i].push_back(A_Auxiliar);
            }
        }
    }


    
    
    std::vector<int> lista_de_nodos_visitados;

    Arista Arista_auxiliar;
    Dupla bloque;
    Dupla bloque_actual;
    int indice_a_eliminar;
    int contador = 1;
    Relacion relacion;

    lista_de_nodos_visitados.push_back(nodo_inicial_final);

    while(lista_de_nodos_visitados.size()< numero_de_nodos)
    {
        bloque_actual.arista.peso = 10000;
       
        for (int k = 0; k < lista_de_nodos_visitados.size(); k++)
        {
            if (! lista_de_aristas[lista_de_nodos_visitados[k] -1].empty())
            {
                bloque = minimaArista(lista_de_aristas[lista_de_nodos_visitados[k] -1] );
                if (bloque.arista.peso < bloque_actual.arista.peso)
                {
                    bloque_actual = bloque;
                    indice_a_eliminar = lista_de_nodos_visitados[k] -1;
                }            
            }
            //else{ std::cout<<"empty\t"; }
        }

        if (bloque_actual.arista.peso != 10000)
        {
            if(! estaEnLista(bloque_actual.arista.nodo_2, lista_de_nodos_visitados))
            {
                lista_de_nodos_visitados.push_back(bloque_actual.arista.nodo_2);
                relacion.nodoA = bloque_actual.arista.nodo_1;
                relacion.nodoB = bloque_actual.arista.nodo_2;
                //std::cout<< contador<<" - "<<relacion.nodoA<<" : "<< relacion.nodoB<<"\n";
                contador++;
                relacionesDelArbolDeExpansionMinima.push_back(relacion);
            }
            lista_de_aristas[indice_a_eliminar].erase(lista_de_aristas[indice_a_eliminar].begin()+bloque_actual.indice);
        }
        else{ std::cout<<"not ok\n"; }
    }

    std::cout<< "Arbol de Expansion minima creado exitosamente\n";
}

void Grafo::mostrar()
{
    int contador = 0;
    for (int i = 0; i < numero_de_nodos ; i++)
    {
        std::cout<<contador<<" ";
        for (int j = 0; j < 50; j++)
        {
            std::cout << matrizDeAdyacencia[i][j] << "  ";
        }
        std::cout << "\n";
        contador++;
    }
}


void Grafo::mostrarRelaciones()
{
    std::cout<< "Relaciones: \n";
    for (int k = 0; k < relacionesDelArbolDeExpansionMinima.size(); k++)
    {
        std::cout<< relacionesDelArbolDeExpansionMinima[k].nodoA<< " : "<< relacionesDelArbolDeExpansionMinima[k].nodoB<<"\n";
    }
}

/*
void Grafo::sumaDeCaminos()
{
    int suma = 0;
    Relacion r;
    for (int k = 0; k < relacionesDelArbolDeExpansionMinima.size(); k++)
    {
        r = relacionesDelArbolDeExpansionMinima[k];
        suma += (matrizDeAdyacencia[r.nodoA -1][r.nodoB -1] *2);
    }
    std::cout<<"La suma es: "<<suma;
}
*/


Grafo::~Grafo()
{
    for (int i = 0; i < numero_de_nodos ; i++)
    {
        delete[] matrizDeAdyacencia[i];
    }

    delete[] matrizDeAdyacencia;
    delete[] lista_de_aristas;
    delete[] lista_de_aristas_del_MST;
}




Relacion Grafo::buscaEnLista(std::vector<Relacion> &lista_de_relaciones, int nodo)
{
    Relacion rel;
    rel.nodoA = -1;
    rel.nodoB = -1;

    for(int k = 0; k < lista_de_relaciones.size(); k++)
    {
        if(lista_de_relaciones[k].nodoA == nodo )
        {
            rel = lista_de_relaciones[k];
            lista_de_relaciones.erase(lista_de_relaciones.begin() + k);
            return rel;
        }
    }
    return rel;
}



std::vector<Relacion> Grafo::obtenerCiclo(std::vector<Relacion> lista_de_relaciones )
{
    int nodo_actual = nodo_inicial_final;
    std::vector<Relacion> Ciclo;
    std::vector<Relacion> lista_auxiliar;
    Relacion relacion_actual;
    Relacion relacion_auxiliar;

    while(!lista_de_relaciones.empty() || !lista_auxiliar.empty())
    {
        relacion_auxiliar = buscaEnLista(lista_de_relaciones, nodo_actual);
        if (relacion_auxiliar.nodoA == -1 && relacion_auxiliar.nodoB == -1)
        {
            relacion_auxiliar.nodoA = lista_auxiliar.back().nodoB;
            relacion_auxiliar.nodoB = lista_auxiliar.back().nodoA;
        }

        relacion_actual = relacion_auxiliar;
        Ciclo.push_back(relacion_actual);

        if (lista_auxiliar.empty())
        {
            lista_auxiliar.push_back(relacion_actual);
        }
        else if (relacion_actual.nodoA != lista_auxiliar.back().nodoB || relacion_actual.nodoB != lista_auxiliar.back().nodoA)
        {
            lista_auxiliar.push_back(relacion_actual);
        }
        else if (relacion_actual.nodoA == lista_auxiliar.back().nodoB && relacion_actual.nodoB == lista_auxiliar.back().nodoA)
        {
            lista_auxiliar.pop_back();
        }
        nodo_actual = relacion_actual.nodoB;
    }

    return Ciclo;

}







/* Ignora esto, es mi avance de la optimizacion
std::vector<Relacion> Grafo::Optimizacion(std::vector<Relacion> listaDeRelaciones)
{

    Relacion temp;
    //Se llena la lista de aristas del MST
    for (int k = 0; k < listaDeRelaciones.size(); k++)
    {
        temp = listaDeRelaciones[k];

        lista_de_aristas_del_MST[temp.nodoA -1].push_back( temp.nodoB);
        lista_de_aristas_del_MST[temp.nodoB -1].push_back( temp.nodoA);
    }



    bool auxBool = false;
    std::vector<Relacion> CicloOptimizado;
    std::vector<Relacion> lista_auxiliar;
    Relacion relacion_actual;
    Relacion relacion_anterior;
    Relacion relacion_auxiliar;
    int indice_actual = 0;

    int k = 0;
    

    while(!listaDeRelaciones.empty() || !lista_auxiliar.empty())
    {
        relacion_actual = listaDeRelaciones[k];
        if( lista_de_aristas_del_MST[relacion_actual.nodoA].size() == 1 || auxBool) // nodo actual es nodo terminal 
        {
            relacion_auxiliar = relacion_actual;
            indice_actual = lista_auxiliar.size() -1;

            while(lista_de_aristas_del_MST[relacion_auxiliar.nodoB].size() == 2 )
            {
                if( matrizDeAdyacencia[relacion_actual.nodoA][relacion_auxiliar.nodoB] != -1)
                {
                    while(lista_auxiliar.back() != relacion_auxiliar) // elimnar las arsitas ganadas por un 'ciclo'
                    {
                        lista_auxiliar.pop_back();
                    }
                    break;
                    auxBool = false;
                }
                else 
                {
                    auxBool = true
                }               
                relacion_auxiliar = lista_auxiliar[indice_actual];
                indice_actual--;
            }
            lista_auxiliar.pop_back();
            auxBool = true;
        }
        else
        {
            lista_auxiliar.push_back(relacion_actual);
        }
        
       k++;
    }
*/

}
