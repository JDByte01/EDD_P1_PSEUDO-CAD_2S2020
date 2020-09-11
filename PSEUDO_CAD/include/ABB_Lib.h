#ifndef ABB_LIB_H
#define ABB_LIB_H
#include <Nodo_objeto.h>

#include <iostream>

using namespace std;

/* Libreria
 * Arbol binario de busqueda
 * Almacena todos los objetos del programa en
 * su forma básica.
 */

class ABB_lib
{
    public:
        ABB_lib();
        virtual ~ABB_lib();

        bool existe(int id);
        Nodo_objeto* encontrar(int id);
        void insertar(Nodo_objeto* n);
        bool eliminar(int id);

        int getSize(){ return this->objetos; }
        string getGraphviz();

    private:
        Nodo_objeto* raiz;
        int objetos;

        bool existe(Nodo_objeto* raiz, int id);
        Nodo_objeto* encontrar(Nodo_objeto* raiz, int id);
        void insertar(Nodo_objeto* raiz, Nodo_objeto* n);
        void eliminar(Nodo_objeto* raiz, int id);

        string graphviz(Nodo_objeto* raiz);
};

#endif // ABB_LIB_H
