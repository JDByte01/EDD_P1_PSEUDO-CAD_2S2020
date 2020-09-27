#ifndef LISTA_PROYECTOS_H
#define LISTA_PROYECTOS_H

#include <Nodo_lista.h>

#include <iostream>
#include <string>

using namespace std;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Lista_proyectos
{
    public:
        Lista_proyectos();
        virtual ~Lista_proyectos();

        Nodo_lista* getInicio() { return inicio; }
        void setInicio(Nodo_lista* val) { inicio = val; }
        Nodo_lista* getFinal() { return fin; }
        void setFinal(Nodo_lista* val) { fin = val; }

        void insertar(int id, string nombre, int niveles);

        void imprimirAZ();
        void imprimirZA();

    protected:

    private:
        Nodo_lista* inicio;
        Nodo_lista* fin;
};

#endif // LISTA_PROYECTOS_H
