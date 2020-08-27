#include "Lista_puntos.h"

Lista_puntos::Lista_puntos()
{
    //Constructor
    this->inicio = NULL;
}

Lista_puntos::~Lista_puntos()
{
    //dtor
}

//insertar

void Lista_puntos::insertar(int x, int y){
    Nodo_coordenada* nodo = new Nodo_coordenada(x,y);

    if(this->inicio != NULL){
        Nodo_coordenada* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            temp = temp->getSiguiente();
        }
        temp->setSiguiente(nodo);
    } else {
        this->inicio = nodo;
    }
}

//Existe
bool Lista_puntos::existe(int x, int y){
    if(this->inicio != NULL){
        Nodo_coordenada* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            if(temp->getX() == x && temp->getY() == y){
                return true;
            }
            temp = temp->getSiguiente();
        }
        if(temp->getX() == x && temp->getY() == y){
            return true;
        }else {
            return false;
        }
    } else {
        return false;
    }
}

void Lista_puntos::vaciar(){
    delete this->inicio;
    this->inicio = NULL;
}

void Lista_puntos::imprimir(){
    if(this->inicio != NULL){
        cout << " Lista de puntos: "<< endl;
        Nodo_coordenada* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            cout << "(" << temp->getX() << ", " << temp->getY() << ")" << endl;
            temp = temp->getSiguiente();
        }
        cout << "(" << temp->getX() << ", " << temp->getY() << ")" << endl;
    } else {
        cout << "Lista de puntos vacia..." << endl;
    }
}
