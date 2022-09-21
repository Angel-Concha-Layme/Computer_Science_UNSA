#include <iostream>

#include "Generador.hpp"
#include "Cronometro.hpp"

int **A, **B, **C;


void multiplicacion_bloques(int);
void prueba();


int main(){
    prueba();
}

void multiplicacion_bloques(int tammano){
    crear_matriz_2D_random(A,tammano,tammano,1,5);
    crear_matriz_2D_random(B,tammano,tammano,1,5);
    crear_matriz_2D_vacia(C,tammano,tammano);

    Cronometro timer01;
    timer01.start();
    int blocksize=tammano/2;
    for (int ii = 0; ii < tammano; ii+=blocksize)
        for (int jj = 0; jj < tammano; jj+=blocksize)
            for (int kk = 0; kk < tammano; kk+=blocksize)
                for (int i = ii; i < ii+blocksize; i++)
                    for (int j = jj; j < jj+blocksize; j++)
                        for (int k = kk; k < kk+blocksize; k++)
                            *(*(C+i)+j) += *(*(A+i)+k) * *(*(B+k)+j);
    std::cout<<"MULTIPLICACION BLOQUES - tamanno: "<< tammano <<": ";
    timer01.stop();

}

void prueba(){
    for (auto i = 200; i <=1400 ; i+=200){
        multiplicacion_bloques(i);
        std::cout<<'\n';
    }
}