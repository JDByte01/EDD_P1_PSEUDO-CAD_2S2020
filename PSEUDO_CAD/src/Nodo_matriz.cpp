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

Nodo_matriz::Nodo_matriz(string letra, string color, int x, int y, int id){
    //Insertar nodo
    this->letra = "";
    this->color = "";
    this->x = 0;
    this->y = 0;
    this->id = id;

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

/** \brief Genera el id del nodo
 *
 * \param String l
 * \param int x
 * \param int y
 * \return void
 *
 */

string Nodo_matriz::getIdNodo(){
    return "N".append(this->letra).append(to_string(this->x)).append(to_string(this->y));
}

/** \brief Genera estructura de nodo Graphviz
 *
 * \return string
 *
 */

 string Nodo_matriz::getNodoGraphviz(){
    //
    string txt = "";

    ///N85 [label = "L", width = 0.4, group = 8, shape = circle, style = filled, color = "#A0F4CF"];
    if(x > 0 && y > 0)
        txt.append(this->getIdNodo()).append(" [label = \"").append(this->letra).append("\", width = 0.4, shape = circle, style = filled, group = ").append(to_string(this->x)).append(", color = ").append(this->color).append("];\n");

    /// Y5  [label = "5", width = 0.4, height = 0.4, style = filled, group = 0 ];
    if(x == 0)
        txt.append(this->getIdNodo()).append(" [label = \"").append(to_string(this->y)).append(", width = 0.4, height = 0.4, group = 0];\n");

    /// X20 [label = "20", width = 0.4, height = 0.4, group = 20 ];
    if(y == 0)
        txt.append(this->getIdNodo()).append(" [label = \"").append(to_string(this->x)).append(", width = 0.4, height = 0.4, group = ").append(to_string(this->x)).append("];\n");

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

    //if(this->arriba != NULL)
        //txt.append(this->id).append("->").append(this->arriba->id).append(";\n");

    if(this->abajo != NULL)
        txt.append(this->getIdNodo()).append("->").append(this->abajo->id).append(";\n");

    if(this->derecha != NULL)
        txt.append(this->getIdNodo()).append("->").append(this->derecha->id).append(";\n");

    //if(this->izquierda != NULL)
        //txt.append(this->id).append("->").append(this->izquierda->id).append(";\n");
    return txt;
 }
