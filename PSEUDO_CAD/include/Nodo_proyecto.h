#ifndef NODO_PROYECTO_H
#define NODO_PROYECTO_H

#include <Nodo_nivel.h>
#include <Lista_nivel.h>

#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Nodo_proyecto
{
    public:
        Nodo_proyecto();
        Nodo_proyecto(string nombre, Lista_nivel* l);
        virtual ~Nodo_proyecto();

        //Get
        int getId(){ return this->id; }
        int getAltura(){ return this->altura; }
        string getNombre(){ return this->nombre; }
        Lista_nivel* getNiveles(){ return this->niveles; }
        Nodo_proyecto* getIzquierda(){ return this->izquierda; }
        Nodo_proyecto* getDerecha(){ return this->derecha; }

        //Set
        void setAltura(int x){ this->altura = x; }
        void setNombre(string nombre){ this->nombre = nombre; setID(nombre); }
        void setNiveles(Lista_nivel* l){ this->niveles = l; }
        void setIzquierda(Nodo_proyecto* n){ this->izquierda = n; }
        void setDerecha(Nodo_proyecto* n){ this->derecha = n; }

        //Otros
        int sizeNiveles();
        void setID(string nombre);
        string getGraphviz();
        string getJSON();
        void cargarJSON(json j);
        void imprimir();

    protected:

    private:
        int id;
        int altura;
        string nombre;

        Lista_nivel* niveles;

        Nodo_proyecto* izquierda;
        Nodo_proyecto* derecha;
};

#endif // NODO_PROYECTO_H
