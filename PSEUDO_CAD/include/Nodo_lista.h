#ifndef NODO_LISTA_H
#define NODO_LISTA_H

#include <iostream>
#include <string>

using namespace std;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Nodo_lista
{
    public:
        Nodo_lista(int id, string nombre, int niveles);
        virtual ~Nodo_lista();

        int getId() { return id; }
        void setId(int val) { id = val; }
        string getNombre() { return nombre; }
        void setNombre(string val) { nombre = val; }
        int getNiveles() { return niveles; }
        void setNiveles(int val) { niveles = val; }
        Nodo_lista* getSiguiente(){ return siguiente; }
        void setSiguiente(Nodo_lista* val){ siguiente = val; }
        Nodo_lista* getAnterior(){ return anterior; }
        void setAnterior(Nodo_lista* val){ anterior = val; }

        void imprimir();

    protected:

    private:
        int id;
        string nombre;
        int niveles;

        Nodo_lista* siguiente;
        Nodo_lista* anterior;
};

#endif // NODO_LISTA_H
