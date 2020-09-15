#ifndef LISTA_NIVEL_H
#define LISTA_NIVEL_H

#include <Nodo_nivel.h>

#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Lista_nivel
{
    public:
        Lista_nivel();
        virtual ~Lista_nivel();

        //Get
        int getSize(){ return this->size; }
        Nodo_nivel* getInicio(){ return this->inicio; }

        //Set
        void setInicio(Nodo_nivel* n){ this->inicio = n; }

        //Otros
        void cargarJSON(json j);
        void insertarNivel(Nodo_nivel* n);
        void nuevoNivel(int nombre);
        void eliminarNivel(int nombre);
        bool estaVacio(){ return this->inicio == NULL; }
        Nodo_nivel* buscarNivel(int nombre);
        void imprimir();

    protected:

    private:
        int size; //cantidad de niveles en el proyecto

        Nodo_nivel* inicio;
};

#endif // LISTA_NIVEL_H
