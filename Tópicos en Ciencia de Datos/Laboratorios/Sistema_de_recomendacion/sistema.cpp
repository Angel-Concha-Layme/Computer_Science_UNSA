#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<vector>

struct Nodo{
    std::string atributo;
    float dato;
    Nodo *sig;
};


class Data{
    private:
        Nodo *inicio;
        Nodo *fin;
        int tam;
    public:
        Data(){
            inicio = NULL;
            fin = NULL;
            tam = 0;
        }
        void insertar(std::string atributo, float dato){
            Nodo *nuevo = new Nodo;
            nuevo->atributo = atributo;
            nuevo->dato = dato;
            nuevo->sig = NULL;
            if(inicio == NULL){
                inicio = nuevo;
                fin = nuevo;
            }else{
                fin->sig = nuevo;
                fin = nuevo;
            }
            tam++;
        }
        void mostrar(){
            Nodo *aux = inicio;
            while(aux != NULL){
                std::cout << aux->atributo << " " << aux->dato << std::endl;
                aux = aux->sig;
            }
        }
        void eliminar(std::string atributo){
            Nodo *aux = inicio;
            Nodo *aux2 = inicio;
            while(aux != NULL){
                if(aux->atributo == atributo){
                    if(aux == inicio){
                        inicio = inicio->sig;
                        delete aux;
                        tam--;
                    }else{
                        aux2->sig = aux->sig;
                        delete aux;
                        tam--;
                    }
                }
                aux2 = aux;
                aux = aux->sig;
            }
        }
        void buscar(std::string atributo){
            Nodo *aux = inicio;
            while(aux != NULL){
                if(aux->atributo == atributo){
                    std::cout << aux->dato << std::endl;
                }
                aux = aux->sig;
            }
        }
        void modificar(std::string atributo, float dato){
            Nodo *aux = inicio;
            while(aux != NULL){
                if(aux->atributo == atributo){
                    aux->dato = dato;
                }
                aux = aux->sig;
            }
        }
        void graficar(){
            Nodo *aux = inicio;
            while(aux != NULL){
                std::cout << "\"" << aux->atributo << "\"" << "->" << aux->dato << std::endl;
                aux = aux->sig;
            }
        }
        
        float manhattan(Data* list){
            float distancia = 0.0;
            Nodo *aux = inicio;
            Nodo *aux2 = list->inicio;
            while(aux != NULL){
                while(aux2 != NULL){
                    if(aux->atributo == aux2->atributo && aux->dato !=0 && aux2->dato !=0){
                        distancia += std::abs(aux->dato - aux2->dato);
                    }
                    aux2 = aux2->sig;
                }
                aux = aux->sig;
                aux2 = list->inicio;
            }
            return distancia;
        }
        
        float euclidea(Data* list){
            float distancia = 0.0;
            Nodo *aux = inicio;
            Nodo *aux2 = list->inicio;
            while(aux != NULL){
                while(aux2 != NULL){
                    if(aux->atributo == aux2->atributo && aux->dato !=0 && aux2->dato !=0){
                        distancia += std::pow(aux->dato - aux2->dato, 2);
                    }
                    aux2 = aux2->sig;
                }
                aux = aux->sig;
                aux2 = list->inicio;
            }
            return std::sqrt(distancia);
        }
};


std::vector<std::string> recommend(Data *d, Data*[], int); // Usuario - Lista de usuarios
std::vector<float> computeNearestNeighbor(Data *d, Data*[], int);





int main(){
    Data Angelica;
    Angelica.insertar("Blues Traveler", 3.5);
    Angelica.insertar("Broken Bells", 2.0);
    Angelica.insertar("Deadmau5", 0.0);
    Angelica.insertar("Norah Jones", 4.5);
    Angelica.insertar("Phoenix", 5.0);
    Angelica.insertar("Slightly Stoopid", 1.5);
    Angelica.insertar("The Strokes", 2.5);
    Angelica.insertar("Vampire Weekend", 2.0);

    Data Chan;
    Chan.insertar("Blues Traveler", 5.0);
    Chan.insertar("Broken Bells", 1.0);
    Chan.insertar("Deadmau5", 1.0);
    Chan.insertar("Norah Jones", 3.0);
    Chan.insertar("Phoenix", 5.0);
    Chan.insertar("Slightly Stoopid", 1.0);
    Chan.insertar("The Strokes", 0.0);
    Chan.insertar("Vampire Weekend", 0.0);

    Data Bill;
    Bill.insertar("Blues Traveler", 2.0);
    Bill.insertar("Broken Bells", 3.5);
    Bill.insertar("Deadmau5", 4.0);
    Bill.insertar("Norah Jones", 0.0);
    Bill.insertar("Phoenix", 2.0);
    Bill.insertar("Slightly Stoopid", 3.5);
    Bill.insertar("The Strokes", 0.0);
    Bill.insertar("Vampire Weekend", 3.0);

    Data Dan;
    Dan.insertar("Blues Traveler", 3.0);
    Dan.insertar("Broken Bells", 4.0);
    Dan.insertar("Deadmau5", 4.5);
    Dan.insertar("Norah Jones", 0.0);
    Dan.insertar("Phoenix", 3.0);
    Dan.insertar("Slightly Stoopid", 4.5);
    Dan.insertar("The Strokes", 4.0);
    Dan.insertar("Vampire Weekend", 2.0);

    Data Hailey;
    Hailey.insertar("Blues Traveler", 0.0);
    Hailey.insertar("Broken Bells", 4.0);
    Hailey.insertar("Deadmau5", 1.0);
    Hailey.insertar("Norah Jones", 4.0);
    Hailey.insertar("Phoenix", 0.0);
    Hailey.insertar("Slightly Stoopid", 0.0);
    Hailey.insertar("The Strokes", 4.0);
    Hailey.insertar("Vampire Weekend", 1.0);

    Data Jordyn;
    Jordyn.insertar("Blues Traveler", 0.0);
    Jordyn.insertar("Broken Bells", 4.5);
    Jordyn.insertar("Deadmau5", 4.0);
    Jordyn.insertar("Norah Jones", 5.0);
    Jordyn.insertar("Phoenix", 5.0);
    Jordyn.insertar("Slightly Stoopid", 4.5);
    Jordyn.insertar("The Strokes", 4.0);
    Jordyn.insertar("Vampire Weekend", 4.0);

    Data Sam;
    Sam.insertar("Blues Traveler", 5.0);
    Sam.insertar("Broken Bells", 2.0);
    Sam.insertar("Deadmau5", 0.0);
    Sam.insertar("Norah Jones", 3.0);
    Sam.insertar("Phoenix", 5.0);
    Sam.insertar("Slightly Stoopid", 4.0);
    Sam.insertar("The Strokes", 5.0);
    Sam.insertar("Vampire Weekend", 0.0);

    Data Veronica;
    Veronica.insertar("Blues Traveler", 3.0);
    Veronica.insertar("Broken Bells", 0.0);
    Veronica.insertar("Deadmau5", 0.0);
    Veronica.insertar("Norah Jones", 5.0);
    Veronica.insertar("Phoenix", 4.0);
    Veronica.insertar("Slightly Stoopid", 2.5);
    Veronica.insertar("The Strokes", 3.0);
    Veronica.insertar("Vampire Weekend", 0.0);


    Data *datos[8] = {&Angelica, &Bill, &Chan, &Dan, &Hailey, &Jordyn, &Sam, &Veronica};
    int size = sizeof(datos)/sizeof(datos[0]);

    //recommend(&Angelica, datos,size); //prueba (usuario dentro de la data)

    float distancia=Hailey.manhattan(&Jordyn);
    std::cout<<"Distancia Manhattan: "<<distancia<<std::endl;

    return 0;
}


std::vector<std::string> recommend(Data *d, Data* datos[], int size){
    std::vector<float> distancias = computeNearestNeighbor(d, datos, size);
    std::vector<std::string> recomendaciones;
    //Vecino mas cercano distancias[indice] -> datos[indice]
}

std::vector<float> computeNearestNeighbor(Data *d, Data* datos[], int size){
    std::vector<float> distancias;
    for (auto i = 1; i < size; i++){
        float distancia = d->manhattan(datos[i]);
        distancias.push_back(distancia);
    }
    return distancias;
}