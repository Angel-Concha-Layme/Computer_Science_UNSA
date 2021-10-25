#include<iostream>
#include<ctime>
#include<ctime>
unsigned t0,t1;

//----Clase 'Node'----//
class Node
{
private:
	int elem;   //----Valor (entero) del nodo----//
	Node *next; //----Puntero al proximo nodo----//
public:
	Node(int);
	~Node();
	int getElem();
	void setElem(int);
	Node* getNext();
	void setNext(Node*);
};

//----Constructor----//
Node::Node(int _elem){
	elem = _elem;
	next = nullptr;
}

Node::~Node(){

}
//****-----*****----****----****----****----****----****----****//
    //----Acceso y modificacion de variables miembro----//
//****-----*****----****----****----****----****----****----****//

int Node::getElem(){
    return elem;    //----Retorna elem (valor entero)----//
}

void Node::setElem(int _elem){
    elem = _elem;   //----Cambia el valor de elem (valor entero)----//
}

Node* Node::getNext(){
    return next;
}

void Node::setNext(Node* _next){
    next = _next;
}


//----Clase Linkedlist----//
class LinkedList
{
private:
	Node *head; //----puntero a nodo----//
	int size;   //----tamanio de Linkedlist----//
public:
	LinkedList();
	LinkedList(int);
	~LinkedList();
	void insert(int);
	void remove(int);
	void print();
};

//----Contructor 1----//
LinkedList::LinkedList(){
	head = nullptr; //----null----//
	size = 0;       //----tamanio de linkedlist = 0----//
}
//----Constructor 2----//
LinkedList::LinkedList(int newElem){
	head = new Node(newElem);   //----si tamanio es 1 head debe apuntar a el nuevo nodo----//
	size = 1;       //----tamanio de linkedslist = 1----//
}
//----Destructor -> 'liberamos' la memoria utilizada, usamos "delete"----//
LinkedList::~LinkedList(){
	Node *cursor;
	while(head != nullptr){ //----Condicion para liberar memoria----//
		cursor = head;
		cursor = head->getNext();   //----Elimina de forma secuencial----//
		delete cursor;
	}
}
//----Insertar un nuevo elemnto (nodo) en linkedlist----//
void LinkedList::insert(int newElem){
	if(!size)   //----verificamos tamanio = 0----//
		head = new Node(newElem);   //----En caso de ser '0' el nuevo elemento es el unico de limkedlist, head = new Node(newElem)----//
	else{
        //----Tenemos que ordenar los elemetos (enteros de forma creciente)----//
        //----Trabajamos con sus valores y modificamos sus punteros a 'next'----//
		Node *cursor = head;
		Node *previous = nullptr;

		while(cursor != nullptr and cursor->getElem() <= newElem){
			previous = cursor;
			cursor = cursor->getNext();
		}

		Node *temp = new Node(newElem);
		if (previous == nullptr){
			temp->setNext(head);
			head = temp;
		}
		else{
			temp->setNext(cursor);
			previous->setNext(temp);
		}
	}
	size++;
}

void LinkedList::remove(int index){ //----Eliminamos el nodo [indice]----//
	Node *cursor = head;
	if(index != 0){
		for (int i = 0; i < index - 1; i++){
            cursor = cursor->getNext();
        }
        Node *nodeRem = cursor->getNext();
        cursor->setNext(nodeRem->getNext());
        cursor = nodeRem;
	}
	else
		head = head->getNext();
	delete cursor;
	size--; //----Modificamos el tamanio----//
}

//----Clasico print----//
void LinkedList::print(){
	Node *cursor = head;
	std::cout << "[ ";
	for(int i=0; i<=size-1; i++){ //----usamos getElem para obtener los valores----//
		std::cout << cursor->getElem() << " ";
		cursor = cursor->getNext();//----usamos getNext para desplazarnos al siguiente nodo----//
	}
	std::cout<< "]"<< std::endl;
}


int main(){
    t0=clock();

    LinkedList* Linkedlist1 = new LinkedList(12); 
	std::cout << "Inicializando Linkedlist [12]"<<std::endl;

    std::cout <<"Linkedlist= "; 
    Linkedlist1->print();

    Linkedlist1->insert(10);
	std::cout << "Inserta '10'  "<<std::endl;
    std::cout << "Linkedlist= "; 
    Linkedlist1->print();

    Linkedlist1->insert(95);
	std::cout << "Inserta '95'  "<<std::endl;
    std::cout << "Linkedlist= "; 
    Linkedlist1->print();

    Linkedlist1->insert(1);
	std::cout << "Inserta '1'  "<<std::endl;
    std::cout << "Linkedlist= "; 
    Linkedlist1->print();

    Linkedlist1->insert(50);
	std::cout << "Inserta '50'  "<<std::endl;
    std::cout << "Linkedlist= "; 
    Linkedlist1->print();

    Linkedlist1->remove(1);
	std::cout << "Elimina el elemto de la posicion 2"<<std::endl;
	std::cout << "Linkedlist= "; Linkedlist1->print(); 

    std::cout<<std::endl;
    t1=clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    std::cout<< "Execution time: " << time <<std::endl;

	return 0;
}