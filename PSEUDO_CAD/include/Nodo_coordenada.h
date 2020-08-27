#ifndef NODO_COORDENADA_H
#define NODO_COORDENADA_H

#include <iostream>

using namespace std;

class Nodo_coordenada
{
    public:
        Nodo_coordenada();
        Nodo_coordenada(int x, int y);
        virtual ~Nodo_coordenada();

        //Get
        int getX(){ return this->x; }
        int getY(){ return this->y; }
        Nodo_coordenada* getSiguiente(){ return this->siguiente; }

        //Set
        void setX(int n){ this->x = n; }
        void setY(int n){ this->y = n; }
        void setSiguiente(Nodo_coordenada* n){ this->siguiente = n; }

    private:
        int x;
        int y;
        Nodo_coordenada* siguiente;
};

#endif // NODO_COORDENADA_H
