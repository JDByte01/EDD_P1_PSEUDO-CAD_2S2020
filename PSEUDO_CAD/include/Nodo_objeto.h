#ifndef NODO_OBJETO_H
#define NODO_OBJETO_H

#include<Lista_puntos.h>
#include <iostream>

using namespace std;

class Nodo_objeto
{
    public:
        Nodo_objeto();
        virtual ~Nodo_objeto();

        //Get
        int getIdentificador(){ return this->identificador; }
        string getNombre(){ return this->nombre; }
        string getLetra(){ return this->letra; }
        string getColor(){ return this->color; }
        Lista_puntos* getPuntos(){ return this->puntos; }
        Nodo_objeto* getIzquierda(){ return this->izquierda; }
        Nodo_objeto* getDerecha(){ return this->derecha; }

        //Set
        void setIdentificador(int id){ this->identificador = id; }
        void setNombre(string nombre){ this->nombre = nombre; }
        void setLetra(string letra){ this->letra = letra; }
        void setColor(string color){ this->color = color; }
        void setPuntos(Lista_puntos* l){ this->puntos = l; }
        void setIzquierda(Nodo_objeto* n){ this->izquierda = n; }
        void setDerecha(Nodo_objeto* n){ this->derecha = n; }

        //Otros
        void insertarPunto(int x, int y);
        string getNodoGraphviz();
        void imprimirNodo();


    private:
        int identificador;
        string nombre;
        string letra;
        string color;
        Lista_puntos* puntos;

        Nodo_objeto* izquierda;
        Nodo_objeto* derecha;

};

#endif // NODO_OBJETO_H
