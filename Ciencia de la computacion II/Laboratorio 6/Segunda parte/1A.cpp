#include <iostream>
using namespace std;

template<typename T>
class Nodo{
    T data;
    Nodo<T> *next;
    template<typename U>
    friend class Lista;

    template<typename N>
    friend class Iterator;
};

template<typename T>
class Lista{
public:
    Nodo<T> *head;
public:
    void insertar(T);
    void imprimir();
    void buscar(T);
    void eliminar(T);
    template<typename N>
    friend class Iterator;
    Lista(){
        head=NULL;
    }
    ~Lista(){
        Nodo<T> *recor=head;
        Nodo<T> *bor;
        while(recor!=NULL)
        {
            bor=recor;
            recor=recor->next;
            delete bor;
        }
    }
};

template<typename T>
void Lista<T>::insertar(T x)
{
    Nodo<T> *nuevo=new Nodo<T>();
    nuevo->data=x;

    Nodo<T> *aux1=head;
    Nodo<T> *aux2;

    while(aux1!=NULL &&  aux1->data< x)
    {
        aux2=aux1;
        aux1=aux1->next;
    }
    if(head==aux1)
    {
        head=nuevo;
    }
    else
    {
        aux2->next=nuevo;
    }
    nuevo->next=aux1;
}

template<typename T>
void Lista<T>::imprimir()
{
    Nodo<T> *rec=head;
    while(rec!=NULL)
    {
        cout<<rec->data<<"->";
        rec=rec->next;
    }
    cout<<"NULL";
}
template<typename T>
void Lista<T>::buscar(T x)
{
    Nodo<T>* actual=head;
    bool existe=false;
    while(actual!=NULL && actual->data<=x)
    {
        if(actual->data==x)
            existe=true;
        actual=actual->next;
    }
    if(existe==true)
    {
        cout<<"el numero si existe y es ="<<x;
    }
    else{
        cout<<"el numero no existe";
    }
}
template<typename T>
void Lista<T>::eliminar(T x)
{
    Nodo<T> *aux=head;
    Nodo<T> *anterior=NULL;
    while((aux!=NULL) && (aux->data!=x))
    {
        anterior=aux;
        aux=aux->next;
    }
    if(aux==NULL)
    {
        cout<<"EL ELEMENTO NO EXISTE";
    }
    else if(anterior==NULL)
    {
        head=head->next;
        delete aux;
    }
    else{
        anterior->next=aux->next;
        delete aux;
    }
}

template<typename T>
class Iterator{
private:
    Nodo<T> *ptr;
    Nodo<T> *anterior;
public:
    void operator=(Nodo<T> *);
    int operator ++();
    int operator--();
    T operator *();
    void operator ==(T);
    void operator !=(T);
    int datos();
    bool hasMore();
    bool found(T);
   
};



template<typename T>
void Iterator<T>::operator=(Nodo<T> *nodo){
    ptr=nodo;
    anterior=nodo;
}

template<typename T>
int Iterator<T>::operator ++(){
        anterior=ptr;
        ptr=ptr->next;
}

template<typename T>
int Iterator<T>::operator--(){
        ptr=anterior;
}

template<typename T>
T Iterator<T>::operator *(){
        return ptr->data;
}

template<typename T>
void Iterator<T>::operator ==(T nodo){
    if(ptr->data==nodo)
        cout<<"se encontro el dato :"<<ptr->data;
    else{
        cout<<"no- se encontro "<<endl; 
    }
}

template<typename T>
void Iterator<T>::operator !=(T nodo){
    if(ptr->data!=nodo)
        cout<<"es diferente el dato :"<<ptr->data<<endl;
    else{
        cout<<"no se encontro "<<endl;
    }
}

template<typename T>
int Iterator<T>::datos(){
        cout<<ptr->data<<" ";
}

template<typename T>
bool Iterator<T>::hasMore(){
    if(ptr->next!= NULL)
        return false;
    else
        return true;
}

template<typename T>
bool Iterator<T>::found(T n){
    if(ptr->data == n){
        return true;
    }
    Nodo<T> *temp = ptr;
    while(temp->next != NULL){   
    if(temp->next->data == n){
        return true;
        }
    }
}

int main(){
    Lista<int> l;
    l.insertar(-8);
    l.insertar(8);
    l.insertar(5);
    l.insertar(4);
    l.insertar(15);
    l.insertar(50);
    l.insertar(20);
    l.imprimir();
    cout<<endl;
    l.buscar(8);
    l.eliminar(8);
    cout<<endl;
    l.imprimir();
    Iterator<int> iterador;
    iterador=l.head;
    iterador.datos();
    *iterador;
    ++iterador;
    --iterador;
    *iterador;
    iterador==1;
    iterador!=5;
	return 0;
}
