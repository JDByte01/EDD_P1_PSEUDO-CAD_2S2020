#include "Nodo_nivel.h"

Nodo_nivel::Nodo_nivel()
{
    //ctor
    this->nombre = "";
    this->objetos = 0;
    this->paredes = 0;
    this->ventanas = 0;
    this->siguiente = NULL;
    this->arbol = new ABB_nivel();
    this->matriz = new Matriz_nivel();
}

Nodo_nivel::~Nodo_nivel()
{
    //dtor
    this->arbol->setRaiz(NULL);
    this->matriz->getHeaders()->setDerecha(NULL);
    this->matriz->getHeaders()->setAbajo(NULL);
    this->siguiente = NULL;
    this->nombre = "";
    this->objetos = 0;
    this->paredes = 0;
    this->ventanas = 0;
}

/** \brief Cargar objetos dentro del JSON
 *
 * \param json j
 * \return void
 *
 */

 void Nodo_nivel::cargarJSON(json j){

 }

 /** \brief Agregar objeto al arbol ABB
  *
  * \param Nodo_objeto n
  * \return void
  *
  */

void Nodo_nivel::addObjeto(Nodo_objeto* n){

}

/** \brief Agregar pared al arbol ABB
 *
 * \param Nodo_objeto n
 * \return void
 *
 */

 void Nodo_nivel::addPared(Nodo_objeto* n){

 }

 /** \brief Agregar ventana al arbol ABB
  *
  * \param Nodo_objeto n
  * \return void
  *
  */

void Nodo_nivel::addVentana(Nodo_objeto* n){

}

/** \brief Generar dot de la matriz por medio del ABB
 *
 * \return void
 *
 */

 void Nodo_nivel::mostrarNivel(){

 }




