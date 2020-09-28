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
        //Nodo Hoja

        if(raiz->getIzquierda() == NULL && raiz->getDerecha() == NULL){
            raiz = NULL;
        } else if(raiz->getIzquierda() != NULL && raiz->getDerecha() == NULL){
            raiz = raiz->getIzquierda();
        } else if(raiz->getIzquierda() == NULL && raiz->getDerecha() != NULL){
            raiz = raiz->getDerecha();
        } else {
            raiz = raiz->getIzquierda();
        }
        return true;
    }
  }

  /** \brief Genera la matriz a base de sus nodos
   *
   * \param Matriz_nivel m
   * \return void
   *
   */

  void ABB_nivel::generarMatriz(Matriz_nivel* m){
    //Limpiar la matriz por referencia
    m->getHeaders()->setDerecha(NULL);
    m->getHeaders()->setAbajo(NULL);

    //Agregar cada punto de cada nodo en la matriz
     if(estaVacio()){
       cout << " | -> ABB vacio..." << endl;
    } else {
        cout << " |-> Generando Matriz..." << endl;
        generarMatriz(m,this->getRaiz());
    }
  }

  void ABB_nivel::generarMatriz(Matriz_nivel* m, Nodo_objeto* raiz){

    if(raiz->getIzquierda() != NULL)
        generarMatriz(m,raiz->getIzquierda());

    //Leer cada punto he insertar
    cout << "Insertando punto " << raiz->getNombre() << endl;
    Nodo_coordenada* n = raiz->getInicioPunto();

    if(n != NULL){
        while(n->getSiguiente() != NULL){
            cout << "(x,y) " << to_string(n->getX()) << ", " << to_string(n->getY()) << endl;
            m->agregarPunto(n->getX(),n->getY(),raiz->getLetra(),raiz->getColor(),raiz->getIdentificador());
            n = n->getSiguiente();
        }
        cout << "(x,y) " << to_string(n->getX()) << ", " << to_string(n->getY()) << endl;
        m->agregarPunto(n->getX(),n->getY(),raiz->getLetra(),raiz->getColor(),raiz->getIdentificador());
    } else {
        cout << "Lista vacia" << endl;
    }



    if(raiz->getDerecha() != NULL)
        generarMatriz(m,raiz->getDerecha());
  }

