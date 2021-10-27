#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <stdio.h>
#include <queue>

//implementacion de clase kdtree
template<class T>
class kdtree{
    private:
        struct nodo{
            T dato;
            nodo* izq;
            nodo* der;
            nodo(T d){
                dato=d;
                izq=NULL;
                der=NULL;
            }
        };
        nodo* raiz;
        int altura;
        int nivel(nodo* n){
            if(n==NULL) return 0;
            return 1+std::max(nivel(n->izq),nivel(n->der));
        }
        void imprimir(nodo* n,int nivel){
            if(n==NULL) return;
            imprimir(n->der,nivel+1);
            for(int i=0;i<nivel;i++) std::cout<<"   ";
            std::cout<<n->dato<<std::endl;
            imprimir(n->izq,nivel+1);
        }
        void destruir(nodo* n){
            if(n==NULL) return;
            destruir(n->izq);
            destruir(n->der);
            delete n;
        }
        nodo* insertar(nodo* n,T d){
            if(n==NULL) return new nodo(d);
            if(d<n->dato) n->izq=insertar(n->izq,d);
            else n->der=insertar(n->der,d);
            return n;
        }
        nodo* buscar(nodo* n,T d){
            if(n==NULL) return NULL;
            if(n->dato==d) return n;
            if(d<n->dato) return buscar(n->izq,d);
            return buscar(n->der,d);
        }
        nodo* buscarMin(nodo* n){
            if(n==NULL) return NULL;
            if(n->izq==NULL) return n;
            return buscarMin(n->izq);
        }
        nodo* buscarMax(nodo* n){
            if(n==NULL) return NULL;
            if(n->der==NULL) return n;
            return buscarMax(n->der);
        }
        nodo* eliminar(nodo* n,T d){
            if(n==NULL) return NULL;
            if(d<n->dato) n->izq=eliminar(n->izq,d);
            else if(d>n->dato) n->der=eliminar(n->der,d);
            else{
                if(n->izq==NULL){
                    nodo* aux=n->der;
                    delete n;
                    return aux;
                }
                else if(n->der==NULL){
                    nodo* aux=n->izq;
                    delete n;
                    return aux;
                }
                nodo* aux=buscarMin(n->der);
                n->dato=aux->dato;
                n->der=eliminar(n->der,aux->dato);
            }
            return n;
        }
        void preorden(nodo* n,std::vector<T>& v){
            if(n==NULL) return;
            v.push_back(n->dato);
            preorden(n->izq,v);
            preorden(n->der,v);
        }
        void inorden(nodo* n,std::vector<T>& v){
            if(n==NULL) return;
            inorden(n->izq,v);
            v.push_back(n->dato);
            inorden(n->der,v);
        }
        void postorden(nodo* n,std::vector<T>& v){
            if(n==NULL) return;
            postorden(n->izq,v);
            postorden(n->der,v);
            v.push_back(n->dato);
        }
        void niveles(nodo* n,std::vector<T>& v){
            if(n==NULL) return;
            std::queue<nodo*> cola;
            cola.push(n);
            while(!cola.empty()){
                nodo* aux=cola.front();
                cola.pop();
                v.push_back(aux->dato);
                if(aux->izq!=NULL) cola.push(aux->izq);
                if(aux->der!=NULL) cola.push(aux->der);
            }
        }
        void imprimir(nodo* n,int nivel,int nivel_max){
            if(n==NULL) return;
            imprimir(n->der,nivel+1,nivel_max);
            for(int i=0;i<nivel;i++) std::cout<<"   ";
            std::cout<<n->dato<<std::endl;
            imprimir(n->izq,nivel+1,nivel_max);
        }
    public:
        kdtree(){
            raiz=NULL;
            altura=0;
        }
        ~kdtree(){
            destruir(raiz);
        }
        void insertar(T d){
            raiz=insertar(raiz,d);
        }
        bool buscar(T d){
            return buscar(raiz,d)!=NULL;
        }
        T buscarMin(){
            nodo* aux=buscarMin(raiz);
            if(aux==NULL) return NULL;
            return aux->dato;
        }
        T buscarMax(){
            nodo* aux=buscarMax(raiz);
            if(aux==NULL) return NULL;
            return aux->dato;
        }
        void eliminar(T d){
            raiz=eliminar(raiz,d);
        }
        void preorden(std::vector<T>& v){
            preorden(raiz,v);
        }
        void inorden(std::vector<T>& v){
            inorden(raiz,v);
        }
        void postorden(std::vector<T>& v){
            postorden(raiz,v);
        }
        void niveles(std::vector<T>& v){
            niveles(raiz,v);
        }
        void imprimir(){
            imprimir(raiz,0,nivel(raiz));
        }
};


main(){
    kdtree<int> arbol;
    arbol.insertar(5);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(2);
    arbol.insertar(4);
    arbol.insertar(6);
    arbol.insertar(8);
    arbol.insertar(1);
    arbol.insertar(9);
    std::vector<int> v;
    arbol.preorden(v);
    for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    std::cout<<std::endl;
    v.clear();
    arbol.inorden(v);
    for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    std::cout<<std::endl;
    v.clear();
    arbol.postorden(v);
    for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    std::cout<<std::endl;
    v.clear();
    arbol.niveles(v);
    for(int i=0;i<v.size();i++) std::cout<<v[i]<<" ";
    std::cout<<std::endl;
    arbol.imprimir();
    std::cout<<std::endl;
    arbol.eliminar(5);
    arbol.imprimir();
    std::cout<<std::endl;
    arbol.eliminar(3);
    arbol.imprimir();
    std::cout<<std::endl;
    arbol.eliminar(7);
    arbol.imprimir();
    std::cout<<std::endl;
    arbol.eliminar(2);
    arbol.imprimir();
    std::cout<<std::endl;
    
}

