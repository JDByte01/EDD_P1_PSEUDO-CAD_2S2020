#ifndef LISTA_PUNTOS_H
#define LISTA_PUNTOS_H
#include <Nodo_coordenada.h>

#include <iostream>

using namespace std;

class Lista_puntos
{
    public:
        Lista_puntos();
        virtual ~Lista_puntos();

        void insertar(int x, int y);
        bool existe(int x, int y);
        void vaciar();
        void imprimir();

        //Get
        Nodo_coordenada* getInicio(){ return this->inicio; }

    private:
        Nodo_coordenada* inicio;
};

#endif // LISTA_PUNTOS_H
