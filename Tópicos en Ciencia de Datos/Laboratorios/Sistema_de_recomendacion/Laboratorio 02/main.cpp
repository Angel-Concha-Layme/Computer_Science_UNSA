#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <thread>
#include <pthread.h>
#include <chrono>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <typeinfo>
#include <tuple>

#include "Utils/Distancias.h"
#include "Utils/FileOp.h"
#include "Utils/Algoritmos.h"
#include "Utils/MyTime.h"

using namespace std;

#define NUM_THREADS 4

//11676 804.063s - 5min 32
//Movielens

typedef int MovieId;
typedef string MovieName;
typedef string MovieCategories;
typedef tuple<MovieName, MovieCategories> MovieRegister;

typedef int UserId;
typedef ValType Valoration;
typedef tuple<MovieId, Valoration> InterRegister;

typedef map<MovieId, Valoration> InterRegisterMap;

MyTime mytime;


void printInters(InterRegisterMap interMap){
	for(auto iter = interMap.begin(); iter != interMap.end(); ++iter){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

void printMovie(MovieRegister movie){
	cout<<get<0>(movie)<<" "<<get<1>(movie)<<endl;
}

void genVec(vector<InterRegisterMap> * vals, int whoId , int ini, int fin, InterRegisterMap * whoVals
				, vector<ValVecTuple> * res, map<int,ValType> * modules){
	int count = ini;
	ValVec a;
	ValVec b;
	ValVec c;
	InterRegisterMap::iterator findRes;
	for(auto iter = vals->begin() + ini; iter != vals->begin() + fin; ++iter, count++){
		if(count == whoId) continue;
		a.clear();
		b.clear();
		c.clear();
		for(auto iter2 = (*iter).begin(); iter2 != (*iter).end(); ++iter2){
			c.push_back(iter2->second);
		}
		(*modules)[count] = vectorModule(c);

		for(auto iter2 = whoVals->begin(); iter2 != whoVals->end(); ++iter2){
			findRes = (*iter).find(iter2->first);
			if(findRes != (*iter).end()){
				a.push_back(iter2->second);
				b.push_back(findRes->second);
			}
		}
		if(a.size() == 0) continue;
		res->push_back(make_tuple(count,a,b));
	}
}


int main(){
	cout<<"Cargando Base de Datos..."<<endl;
	mytime.init();
	
	auto bdMovies = getBd("ml/movies.csv", ';');
	auto bdInter = getBd("ml/ratings.csv", ',');
	
	mytime.end();
	cout<<"Done->";
	mytime.print();

	MovieId id = 0;

	cout<<"Generando estructura Movies..."<<endl;
	mytime.init();
	map<MovieId, MovieRegister> movieVec;
	for(auto iter = bdMovies.begin(); iter != bdMovies.end(); ++iter){
		id = stoi((*iter)[0]);
		movieVec[id] = make_tuple((*iter)[1], (*iter)[2]);
	}
	mytime.end();
	cout<<"Done->";
	mytime.print();


	cout<<"Generando estructura Inter..."<<endl;
	mytime.init();

	vector<InterRegisterMap> vals(673);
	Valoration val = 0;	

	MovieId id2 = 0;

	for(auto iter = bdInter.begin(); iter != bdInter.end(); ++iter){
		id = stoi((*iter)[0]);
		id2 = stoi((*iter)[1]);
		val = stof((*iter)[2]);
		vals[id][id2] = val;
	}
	mytime.end();
	cout<<"Done->";
	mytime.print();
	

	
	bdInter.clear();
	bdMovies.clear();


	int option = 0;
	int bd = 0;
	int dis = 0;
	int whoId = 0;
	int k = 0;
	auto whoVals = vals[0];

	InterRegisterMap::iterator findRes;
	UserId userId = 0;
	MovieId movieId = 0;
	vector<ValVecTuple> valsTuple;
	map<int,ValType> modules;
		ValVec bookVals;
	ValVec a;
	ValVec b;
	while(true){
		cout<<endl<<"1) Busqueda"<<endl;
		cout<<"2) KNN"<<endl;

		cout<<"Opcion->";
		cin>>option;
		cout<<endl;
		switch(option){
			case 1:{
				cout<<"1) Movies"<<endl;
				cout<<"2) Inter"<<endl;
				cout<<"Opcion->";
				cin>>bd;
				cout<<endl;
				switch(bd){
					case 1:{
						cout<<"Id->";
						cin>>movieId;
						printMovie(movieVec[movieId]);
						break;
					}
					case 2:{
						cout<<"Id->";
						cin>>userId;
						printInters(vals[userId]);
						break;
					}
				}
				break;
			}
			case 2:{
				cout<<"KNN de quien->";
				cin>>whoId;
				cout<<"K->";
				cin>>k;
				cout<<"Generando vectores..."<<endl;
				mytime.init();
				whoVals = vals[whoId];
				if(whoVals.size() == 0){
					cout<<"EL usuario "<<whoId<<" no tiene ninguna valoracion"<<endl;
					break;
				}
				
				mytime.end();
				cout<<"Done";
				cout<<endl<<endl;

				while(true){
					cout<<"1) Manhattan"<<endl;
					cout<<"2) Euclidean"<<endl;
					cout<<"3) Coseno"<<endl;
					cout<<"4) Pearson"<<endl;
					cout<<"Option->";
					cin>>dis;
					cout<<endl;
					mytime.init();
					switch(dis){
						case 2:{
							//auto res = KNN(valsTuple, whoId, k, cosenDistance, [](KNNTuple a,KNNTuple b) {return get<1>(a) > get<1>(b);});
							auto res = KNNCoseno(valsTuple, whoId, 20, modules);
							cout<<endl<<"Resultados del KNN:"<<endl<<endl;
							for(KNNTuple knnT : res){
								cout<<get<0>(knnT)<<" "<<get<1>(knnT)<<endl;
							}
							while(true){
								cout<<endl<<"ID de la pelicula a recomendar->";
								cin>>movieId;
								if(vals[whoId].find(movieId) != vals[whoId].end()){
									cout<<"El usuario ya puntuó la pelicula"<<endl;
								}
								else break;
							}
							bookVals.clear();
							for(KNNTuple knnT : res){
								findRes = vals[get<0>(knnT)].find(movieId);
								if(findRes == vals[get<0>(knnT)].end()){
									bookVals.push_back(NULL_VAL);
								}
								else{
									bookVals.push_back(findRes->second);
								}
							}

							Valoration mayorAc;
							for(int i = res.size() - 1; i > -1; i--){
								if(bookVals[i] != NULL_VAL){
									mayorAc = get<1>(res[i]) + 1;
									break;
								}
							}
							vector<ValType> newVals;
							for(KNNTuple knnT : res){
								newVals.push_back(abs(get<1>(knnT) - mayorAc));
							}
							ValType sum = 0;
							for(IndexType i = 0; i < res.size(); i++){
								if(bookVals[i] == NULL_VAL) continue;
								sum += newVals[i];
							}
							for(IndexType i = 0; i < res.size(); i++){
								if(bookVals[i] == NULL_VAL) continue;
								get<2>(res[i]) = newVals[i] / sum;
							}	
							cout<<endl<<"Influencias para la pelicula seleccionado:"<<endl<<endl;
							for(KNNTuple knnT : res){
								cout<<get<0>(knnT)<<" "<<get<1>(knnT)<<" "<<get<2>(knnT)<<endl;
							}
							mytime.end();
							cout<<"Done->";
							mytime.print();

							ValType proyectado = porcentajeProyectado(res, bookVals);
							cout<<endl<<"El porcentaje proyectado para la pelicula "<<get<0>(movieVec[movieId])<<" de los "<<k<<"-knn es "<<proyectado<<endl;
							break;
						}
						case 4:{
							auto res = KNN(valsTuple, whoId, k, personAprox, [](KNNTuple a,KNNTuple b) {return get<1>(a) > get<1>(b);});
							
							cout<<endl<<"Resultados del KNN:"<<endl<<endl;							
							for(KNNTuple knnT : res){
								cout<<get<0>(knnT)<<" "<<get<1>(knnT)<<endl;
							}
							

							while(true){
								cout<<endl<<"ID de la pelicula a recomendar->";
								cin>>movieId;
								if(vals[whoId].find(movieId) != vals[whoId].end()){
									cout<<"El usuario ya puntuó la pelicula"<<endl;
								}
								else break;
							}

							bookVals.clear();
							for(KNNTuple knnT : res){
								findRes = vals[get<0>(knnT)].find(movieId);
								if(findRes == vals[get<0>(knnT)].end()){
									bookVals.push_back(NULL_VAL);
								}
								else{
									bookVals.push_back(findRes->second);
								}
							}

							
							vector<KNNTuple> resRes;
							int kc = 0;
							for(IndexType i = 0; i < res.size(); i++, kc++){
								if(kc == k) break;
								if(bookVals[i] == NULL_VAL) continue;
								resRes.push_back(res[i]);
							}

							bookVals.clear();
							for(KNNTuple knnT : resRes){
								findRes = vals[get<0>(knnT)].find(movieId);
								if(findRes == vals[get<0>(knnT)].end()){
									bookVals.push_back(NULL_VAL);
								}
								else{
									bookVals.push_back(findRes->second);
								}
							}
							

							ValType sum = 0;
							for(IndexType i = 0; i < resRes.size(); i++){
								if(bookVals[i] == NULL_VAL) continue;
								sum += get<1>(resRes[i]);
							}
							for(IndexType i = 0; i < resRes.size(); i++){
								if(bookVals[i] == NULL_VAL) continue;
								get<2>(resRes[i]) = get<1>(resRes[i]) / sum;
							}


							cout<<endl<<"Influencias para la pelicula seleccionado:"<<endl<<endl;
							for(KNNTuple knnT : resRes){
								cout<<get<0>(knnT)<<" "<<get<1>(knnT)<<" "<<get<2>(knnT)<<endl;
							}
							mytime.end();
							cout<<"Done->";
							mytime.print();

							ValType proyectado = porcentajeProyectado(resRes, bookVals);
							cout<<endl<<"EL porcentaje proyectado para la pelicula "<<get<0>(movieVec[movieId])<<" de los "<<k<<"-knn es "<<proyectado<<endl;
							break;
						}
					}
					cout<<endl;
				}
				break;
			}
		}
		cout<<endl;
	}
}