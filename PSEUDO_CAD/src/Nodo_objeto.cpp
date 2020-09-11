#include "Nodo_objeto.h"

Nodo_objeto::Nodo_objeto()
{
    //Constructor
    this->identificador = 0;
    this->nombre = "";
    this->letra = "";
    this->color = "";
    this->puntos = new Lista_puntos();
    this->izquierda = NULL;
    this->derecha = NULL;
}

Nodo_objeto::~Nodo_objeto()
{
    //dtor
}

void Nodo_objeto::insertarPunto(int x, int y){
    this->puntos->insertar(x,y);
}

void Nodo_objeto::imprimirNodo(){
    cout << " ["<<this->identificador << "]Objero: "<< this->nombre << " - " << this->letra << "("<<this->color<<")" << endl;
}

string Nodo_objeto::getNodoGraphviz(){
    return "";
}