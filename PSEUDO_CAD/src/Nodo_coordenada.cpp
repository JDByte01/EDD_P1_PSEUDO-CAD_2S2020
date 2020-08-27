#include "Nodo_coordenada.h"

Nodo_coordenada::Nodo_coordenada()
{
    //Constructor
    this->x = 0;
    this->y = 0;
    this->siguiente = NULL;
}

Nodo_coordenada::Nodo_coordenada(int x, int y ){
    this->x = x;
    this->y = y;
    this->siguiente = NULL;
}

Nodo_coordenada::~Nodo_coordenada()
{
    //dtor
}


