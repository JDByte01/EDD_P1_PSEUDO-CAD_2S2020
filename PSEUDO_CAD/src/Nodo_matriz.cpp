#include "Nodo_matriz.h"

Nodo_matriz::Nodo_matriz()
{
    //Constructor
    this->id = "";
    this->letra = "";
    this->color = "";
    this->x = 0;
    this->y = 0;

    this->arriba = NULL;
    this->abajo = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
}

Nodo_matriz::Nodo_matriz(string letra, string color, int x, int y){
    //Insertar nodo
    this->id = "N" + letra + to_string(x) + to_string(y) ;
    this->letra = "";
    this->color = "";
    this->x = 0;
    this->y = 0;

    this->arriba = NULL;
    this->abajo = NULL;
    this->derecha = NULL;
    this->izquierda = NULL;
}

Nodo_matriz::~Nodo_matriz()
{
    //Destructor
    this->id = "";
    this->letra = "";
    this->color = "";
    this->x = 0;
    this->y = 0;

    delete this->arriba;
    delete this->abajo;
    delete this->derecha;
    delete this->izquierda;
}

/** \brief Genera estructura de nodo Graphviz
 *
 * \return string
 *
 */

 string Nodo_matriz::getNodoGraphviz(){
    //
    string txt = "";

    if(x > 0 && y > 0)
        txt.append(this->id);
        txt = this->id + " [label = \""+ this->letra +"\", width = 1, group = "+ to_string(this->x) +" ]\n";

    /// Y5  [label = "5"   width = 1.5 style = filled, group = 0 ];
    if(x == 0)
        txt = this->id + " [label = \""+ to_string(this->y) +"\", width = 1.5, style = filled, group = 0 ]\n";

    ///X9 [label = "9"  width = 1 style = filled, group = 9 ];
    if(y == 0)
        txt = this->id + " [label = \""+ to_string(this->x) +"\", width = 1, style = filled, group = "+ to_string(this->x) +" ]\n";

    return txt;
 }

 /** \brief Genera estructura de ruta Graphviz
 *
 * \return string
 *
 */

 string Nodo_matriz::getRutaGraphviz(){
    //
    string txt = "";

    if(this->arriba != NULL)
        txt.append(this->id).append("->").append(this->arriba->id).append(";\n");

    if(this->abajo != NULL)
        txt.append(this->id).append("->").append(this->abajo->id).append(";\n");

    if(this->derecha != NULL)
        txt.append(this->id).append("->").append(this->derecha->id).append(";\n");

    if(this->izquierda != NULL)
        txt.append(this->id).append("->").append(this->izquierda->id).append(";\n");
    return txt;
 }
