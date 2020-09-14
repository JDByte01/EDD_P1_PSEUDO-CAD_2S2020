#ifndef ABB_LIB_H
#define ABB_LIB_H
#include <Nodo_objeto.h>
#include <nlohmann/json.hpp>

#include <iostream>

using namespace std;
using json = nlohmann::json;

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
    bool estaVacio();

    void imprimir();

    int getSize()
    {
        return this->objetos;
    }
    string getGraphviz(string nombre);

    void cargarJSON(json lib);

    Nodo_objeto* getRaiz(){ return this->raiz; }
    void setRaiz(Nodo_objeto* n){ this->raiz = n; }

private:
    Nodo_objeto* raiz;
    int objetos;

    //Variables graphviz
    string graphIn = "digraph G{\n";
    string g_initA = "ratio = \"auto\";\nlabel = \"ABB - ";
    string g_initB = "\";\n";
    string g_node = "node [fontsize = 12, shape = box];\n";
    string g_nodes = "";

    bool existe(Nodo_objeto* raiz, int id);
    Nodo_objeto* encontrar(Nodo_objeto* raiz, int id);
    void insertar(Nodo_objeto* raiz, Nodo_objeto* n);

    void imprimir(Nodo_objeto* raiz);

    string graphviz(Nodo_objeto* raiz, string txt);
};

#endif // ABB_LIB_H
