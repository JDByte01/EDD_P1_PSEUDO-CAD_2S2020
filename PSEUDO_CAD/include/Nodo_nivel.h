#ifndef NODO_NIVEL_H
#define NODO_NIVEL_H

#include <ABB_nivel.h>
#include <Matriz_nivel.h>
#include <Nodo_objeto.h>
#include <Archivo.h>

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
        int getNombre(){ return this->nombre; }
        int getObjetos(){ return this->objetos; }
        int getParedes(){ return this->paredes; }
        int getVentanas(){ return this->ventanas; }
        Nodo_nivel* getSiguiente(){ return this->siguiente; }
        ABB_nivel* getArbol(){ return this->arbol; }
        Matriz_nivel* getMatriz(){ return this->matriz; }

        //Set
        void setNombre(int nombre){ this->nombre = nombre; }
        void setSiguiente(Nodo_nivel* n){ this->siguiente = n; }

        //Otors
        void cargarJSON(json j);
        void cargarParedesJSON(json j);
        void cargarVentanasJSON(json j);
        void cargarObjetosJSON(json j);
        void mostrarNivel(int id);
        int getX();
        int getY();

    protected:

    private:
        int nombre;
        int objetos; //cantidad de objetos en el nivel
        int paredes; //Cantidad de paredes en el nivel
        int ventanas; //Cantidad de ventanas en el nivel

        Nodo_nivel* siguiente;
        ABB_nivel* arbol;
        Matriz_nivel* matriz;
        Archivo* archivo;

        string nombreABB = "";
        string nombreMatrix = "";

        //auxiliares
        //int lix, lsx, liy, lsy, dx, dy;
};

#endif // NODO_NIVEL_H
