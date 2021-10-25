#include<iostream>
#include<string>
#include<string.h>
#include<ctime>
unsigned t0,t1;

//----CLASE CURSO----//
class Curso
{
private:
    std::string nombre;
    std::string codigo;
    int numAlumnos;
public:
    Curso();
    Curso(std::string,std::string,int);

    std::string getNombre();
    std::string getCodigo();
    int getNroAlumnos();
    void setNombre(const std::string nombre);
    void setCodigo(const std::string codigo);
    void setNumAlumnos(const int numAlumnos);

    ~Curso();
};

Curso::Curso(){

}

Curso::Curso(std::string _a,std::string _b,int _c)
{
    nombre = _a;
    codigo = _b;
    numAlumnos = _c;
}

Curso::~Curso()
{
}


std::string Curso::getNombre(){
    return nombre;
}
std::string Curso::getCodigo(){
    return codigo;
}
int Curso::getNroAlumnos(){
    return numAlumnos;
}
void Curso::setNombre(const std::string nombre2){
    nombre=nombre2;
}   
void Curso::setCodigo(const std::string codigo2){
    codigo=codigo2;
}
void Curso::setNumAlumnos(const int numAlumnos2){
    numAlumnos=numAlumnos2;
}

//----CLASE ARREGLO DE CURSOS----//
class ArregloDeCursos
{
private:
    int size;
    Curso *Cursos;
public:
    ArregloDeCursos(){size=0; Cursos=new Curso[0];};
    ArregloDeCursos(const Curso alpha[], const int size);
    ~ArregloDeCursos();
    void resize(int size);
    void push_back(const Curso &c);
    void insert(const int posicion, const Curso &c);
    void remove(const int pos);
    const int getSize();
    void clear();

};

ArregloDeCursos::ArregloDeCursos(const Curso _arr[],const int _size)
{
    size=_size;
    Cursos= new Curso[size];
    for (int i = 0; i < size; i++)
    {
        Cursos[i]=_arr[i];
    }
    
}

ArregloDeCursos::~ArregloDeCursos()
{
}

void ArregloDeCursos::resize(const int size2){
    Curso *pts = new Curso[size2];
    int minSize=(size2>size?size:size2);

    for (int i = 0; i < minSize; i++)
    {
        pts[i]=Cursos[i];
    }
    delete[] Cursos;
    size=size2;
    Cursos =pts;

}
void ArregloDeCursos::push_back(const Curso &c){
    resize(size +1);
    Cursos[size-1]=c;
}
void ArregloDeCursos::insert(const int posicion, const Curso &c){
    resize(size+1);
    for (int i = size-1; i < posicion; i--){
        Cursos[i]=Cursos[i-1];
    }
    Cursos[posicion]=c;
}
void ArregloDeCursos::remove(const int pos){
    for (int i = 0; i < size; i++)
    {
        if (i==pos)
        {
            while (i<size-1)
            {
                Cursos[i]=Cursos[i+1];
            }  
        }
    } 
}
const int ArregloDeCursos::getSize(){
    return size;
}
void ArregloDeCursos::clear(){
    delete[] Cursos;
}

int main()
{
    t0=clock();
    //----Instanciamos objetos de la clase Curso----//
    //----Los objetos de la clase ArregloDeCursos Contienen punteros que apuntan a objetos de la clase Curso----//


    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution time: " << time <<std::endl;
    return 0;
}
