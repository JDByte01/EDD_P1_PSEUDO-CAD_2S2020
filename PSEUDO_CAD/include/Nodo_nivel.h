#ifndef NODO_NIVEL_H
#define NODO_NIVEL_H

#include <ABB_nivel.h>
#include <Matriz_nivel.h>
#include <Nodo_objeto.h>

#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Nodo_nivel
{
    public:
        Nodo_nivel();
        virtual ~Nodo_nivel();

        //Get
        string getNombre(){ return this->nombre; }
        int getObjetos(){ return this->objetos; }
        int getParedes(){ return this->paredes; }
        int getVentanas(){ return this->ventanas; }
        Nodo_nivel* getSiguiente(){ return this->siguiente; }
        ABB_nivel* getArbol(){ return this->arbol; }
        Matriz_nivel* getMatriz(){ return this->matriz; }

        //Set
        void setNombre(string nombre){ this->nombre = nombre; }
        void setSiguiente(Nodo_nivel* n){ this->siguiente = n; }

        //Otors
        void cargarJSON(json j);
        void addObjeto(Nodo_objeto* n);
        void addPared(Nodo_objeto* n);
        void addVentana(Nodo_objeto* n);
        void mostrarNivel();

    protected:

    private:
        string nombre;
        int objetos; //cantidad de objetos en el nivel
        int paredes; //Cantidad de paredes en el nivel
        int ventanas; //Cantidad de ventanas en el nivel

        Nodo_nivel* siguiente;
        ABB_nivel* arbol;
        Matriz_nivel* matriz;
};

#endif // NODO_NIVEL_H
