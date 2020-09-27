#include "Nodo_lista.h"

Nodo_lista::Nodo_lista(int id, string nombre, int niveles)
{
    //Constructor
    this->id = id;
    this->nombre = nombre;
    this->niveles = niveles;

    this->siguiente = NULL;
    this->anterior = NULL;

}

Nodo_lista::~Nodo_lista()
{
    this->id = 0;
    this->nombre = "";
    this->niveles = 0;

    this->siguiente = NULL;
    this->anterior = NULL;
}

void Nodo_lista::imprimir(){
    cout << " | -> (" << to_string(this->id) << ") " << this->nombre << ", N(" << to_string(this->niveles) << ")" << endl;
}


