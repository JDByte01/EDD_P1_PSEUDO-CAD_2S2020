#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H

#include <iostream>
#include <string>

using namespace std;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */


class Nodo_matriz
{
    public:
        Nodo_matriz();
        Nodo_matriz(string letra, string color, int x, int y, int id);
        virtual ~Nodo_matriz();
         //Get
        string getId(){ return this->id; }
        string getLetra(){ return this->letra; }
        string getColor(){ return this->color; }
        int getX(){ return this->x; }
        int getY(){ return this->y; }
        Nodo_matriz* getArriba(){ return this->arriba; }
        Nodo_matriz* getAbajo(){ return this->abajo; }
        Nodo_matriz* getDerecha(){ return this->derecha; }
        Nodo_matriz* getIzquierda(){ return this->izquierda; }
        //Set
        void setId(int id){ this->id = id; }
        void setLetra(string l){ this->letra = l; }
        void setColor(string c){ this->color = c; }
        void setX(int x){ this->x = x; }
        void setY(int y){ this->y = y; }
        void setArriba(Nodo_matriz* n){ this->arriba = n; }
        void setAbajo(Nodo_matriz* n){ this->abajo = n; }
        void setDerecha(Nodo_matriz* n){ this->derecha = n; }
        void setIzquierda(Nodo_matriz* n){ this->izquierda = n; }
        //Otros
        string getNodoGraphviz();
        string getRutaGraphviz();
        string getIdNodo();

    protected:

    private:
        int id; //id del objeto
        string letra;
        string color;
        int x;
        int y;

        Nodo_matriz* arriba;
        Nodo_matriz* abajo;
        Nodo_matriz* derecha;
        Nodo_matriz* izquierda;


};

#endif // NODO_MATRIZ_H
