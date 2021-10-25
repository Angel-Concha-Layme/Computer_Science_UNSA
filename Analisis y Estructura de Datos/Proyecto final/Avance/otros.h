
struct Relacion
{
    int nodoA;
    int nodoB;
};

struct Arista
{
    int peso;
    int nodo_1;
    int nodo_2;
};

struct Dupla
{
    Arista arista;
    int indice;
};


Dupla minimaArista(std::vector<Arista> lista_de_aristas)
{
    Dupla dupla;
    Arista min = lista_de_aristas[0];
    dupla.indice = 0;
    for (int k = 1; k < lista_de_aristas.size(); k++)
    {
        if (lista_de_aristas[k].peso < min.peso)        
        {
            min = lista_de_aristas[k];
            dupla.indice = k;
        }
    }
    dupla.arista = min;

    return dupla;
}

bool estaEnLista(int nodo, std::vector<int> lista_de_nodos)
{
    for (int k = 0; k < lista_de_nodos.size(); k++ )
    {
        if (lista_de_nodos[k] == nodo)
        {
            return true;
        }
    }
    return false;
}




