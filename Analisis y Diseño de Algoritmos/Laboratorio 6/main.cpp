#include<iostream>
#include<vector>
#include<math.h>
#include"random.cpp"


float max(std::vector<int>);
int Partition(std::vector<int>&, int, int, int &);
void Quicksort_internal(std::vector<int>&, int, int, int &);
void Quicksort(std::vector<int>&, int, int &);

void start_parte1();
void start_parte2();

int main(){
    srand(time(NULL));
    std::cout<<"-------------------------"<<std::endl;
    std::cout<<"----  LABORATORIO 6  ----"<<std::endl;
    std::cout<<"-------------------------"<<std::endl;
    start_parte1();
    std::cout<<'\n'<<std::endl;
    start_parte2();
    return 0;
}

void start_parte1(){
    std::cout<<"PARTE 1"<<std::endl;
    int size_vector=256;
    while (size_vector<=1048576){ //2^20
        float contador=0;   
        for (int i = 0; i < 200 ; i++){ //crear 200 arreglos de tamaño 256, 512, 1028, ...    
            random arreglo(size_vector);
            contador+=max(arreglo.get_vector());
        }
        std::cout<<"n: "<< size_vector <<std::endl;
        std::cout<<"Promedio: "<<contador/200<< std::endl;
        std::cout<<"1+ln(n): " <<log(size_vector)<<std::endl;
        std::cout<<"---- ---- ---- ---- "<<std::endl;
        size_vector*=2;
    }
}

void start_parte2(){
    std::cout<<"PARTE 2"<<std::endl;
    int size_vector=256;
    while (size_vector<=1048576){ //2^20
        int contador=0;
        int comparaciones=0;
        for (int i = 0; i < 10 ; i++){ //crear 200 arreglos de tamaño 512, 1028, ...    
            random arreglo(size_vector);
            std::vector<int> prueba = arreglo.get_vector();
            Quicksort(prueba,size_vector,comparaciones);
            contador+=comparaciones;
        }
        std::cout<<"n: "<< size_vector*2 <<std::endl;
        std::cout<<"promedio: "<<contador/10<<std::endl;
        std::cout<<"n*log_2(n): " <<size_vector*(log2(size_vector))<<std::endl;
        std::cout<<"---- ---- ---- ---- "<<std::endl;
        size_vector*=2;
    }
}

float max(std::vector<int> vector){
    float exe=0.0; //variable para contar las veces que se ejecuta el algoritmo.
    int max=vector.front();
    for (auto i = 1; i < vector.size(); i++){
        if (vector[i]>max){
            max=vector[i];
            exe++;
        }
    }
    return exe;
}

int Partition(std::vector<int> &v, int start, int end, int &comparaciones){
	int pivot = end;
	int j = start;
	for(int i=start;i<end;++i){
		if(v[i]<v[pivot]){
			std::swap(v[i],v[j]);
			++j;
            comparaciones+=2;
		}
	}
	std::swap(v[j],v[pivot]);
	return j;
}


void Quicksort_internal(std::vector<int> &v, int start, int end, int &comparaciones){
	if(start<end){
		int p = Partition(v,start,end,comparaciones);
		Quicksort_internal(v,start,p-1,comparaciones);
		Quicksort_internal(v,p+1,end,comparaciones);
	}
	
}

void Quicksort(std::vector<int> &v,int size, int &comparaciones){
    comparaciones=0;
    Quicksort_internal(v,0,size-1,comparaciones);
}



