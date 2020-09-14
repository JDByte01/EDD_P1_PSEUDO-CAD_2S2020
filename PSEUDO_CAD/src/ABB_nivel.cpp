#include "ABB_nivel.h"

ABB_nivel::ABB_nivel()
{
    //ctor
}

ABB_nivel::~ABB_nivel()
{
    //dtor
}

ABB_nivel::ABB_nivel(const ABB_nivel& other)
{
    //copy ctor
}


/*
  * METODO ELIMINAR
  * PARAMETROS INT ID
  */

  bool ABB_nivel::eliminar(int id){
    if(estaVacio()){
        return false;
    } else {
        return eliminar(this->getRaiz(), id);
    }
  }

  bool ABB_nivel::eliminar(Nodo_objeto* raiz, int id){
    if(id < raiz->getIdentificador()){
        //Tomar izquirda
        if(raiz->getIzquierda() != NULL){
            eliminar(raiz->getIzquierda(), id);
        } else {
            return false;
        }
    } else if(id > raiz->getIdentificador()){
        //Tomar Derecha
        if(raiz->getDerecha() != NULL){
            eliminar(raiz->getDerecha(), id);
        } else {
            return true;
        }
    } else {
        //Encontrado
        //Eliminar nodo y reordenar


        // Código aqui....

        ///Caso1: El nodo raiz es un nodo hoja
        if(raiz->getIzquierda() == NULL && raiz->getDerecha() == NULL){
            if(this->getRaiz() == raiz){
                this->setRaiz(NULL);
            } else if(true){
            }

        ///Caso2: El nodo no es un nodo hoja
        } else {

        }

        return true;
    }
  }

  /** \brief Lee JSON e inserta en el ABB y en la Matris
   *
   * \param JSON lib
   * \return void
   *
   */

   void ABB_nivel::cargarJSON_Nivel(json lib){

   }

