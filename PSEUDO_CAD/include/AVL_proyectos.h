#ifndef AVL_PROYECTOS_H
#define AVL_PROYECTOS_H

#include <Nodo_proyecto.h>
#include <Lista_proyectos.h>

#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class AVL_proyectos
{
    public:
        AVL_proyectos();
        virtual ~AVL_proyectos();

        Nodo_proyecto* getRaiz(){ return this->raiz; }
        void setRaiz(Nodo_proyecto* n){ this->raiz = n; }

        void cargarJSON(json j);
        string getGraphviz(string nombre);

        //Funciones
        int altura(Nodo_proyecto* n);
        int maximo(int a, int b){ return (a > b) ? a : b; }
        Nodo_proyecto* rotarDerecha(Nodo_proyecto* y);
        Nodo_proyecto* rotarIzquierda(Nodo_proyecto* x);
        int getBalance(Nodo_proyecto* n);
        void insertar(Nodo_proyecto* n);
        void insertar(string proyecto);
        Nodo_proyecto* valorMinimo(Nodo_proyecto* n);
        bool eliminar(int id);
        Nodo_proyecto* buscar(int id);

        //Recorrer Árbol AVL
        void imprimir();
        void imprimirListaAZ();
        void imprimirListaZA();
        void llenarLista();

    protected:

    private:

        Nodo_proyecto* raiz;
        Lista_proyectos* lista;

        //Funciones
        Nodo_proyecto* insertar(Nodo_proyecto* raiz, Nodo_proyecto* n);
        Nodo_proyecto* eliminar(Nodo_proyecto* raiz, int id);
        Nodo_proyecto* buscar(Nodo_proyecto* raiz, int id);

        //Recorrer
        void imprimir(Nodo_proyecto* n);
        void llenarLista(Nodo_proyecto* n);
};

#endif // AVL_PROYECTOS_H
