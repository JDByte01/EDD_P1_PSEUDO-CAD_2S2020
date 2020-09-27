#include "Lista_proyectos.h"

Lista_proyectos::Lista_proyectos()
{
    //Constructor
    this->inicio = NULL;
    this->fin = NULL;
}

Lista_proyectos::~Lista_proyectos()
{
    if(this->inicio != NULL){
         Nodo_lista* temp = this->inicio;
        Nodo_lista* auxiliar;

        while(temp->getSiguiente() != NULL){
            auxiliar = temp;
            temp = temp->getSiguiente();
            delete auxiliar;
        }
        delete temp;
    }

    this->inicio = NULL;
    this->fin = NULL;
}

/** \brief Insertar de forma ordenada
 *
 * \param int id
 * \param string nombre
 * \param int niveles
 * \return void
 *
 */
void Lista_proyectos::insertar(int id, string nombre, int niveles){
    Nodo_lista* n = new Nodo_lista(id, nombre, niveles);



    if(this->inicio != NULL){
        if(this->inicio->getNiveles() > niveles){
            this->inicio->setAnterior(n);
            n->setSiguiente(this->inicio);
            //n->getSiguiente()->setAnterior(n);
            this->inicio = n;
        } else {
            Nodo_lista* temp = this->inicio;
            Nodo_lista* aux = this->inicio;
            while(temp->getSiguiente() != NULL && temp->getNiveles() <= niveles){
                aux = temp;
                temp = temp->getSiguiente();
            }

            if(temp->getNiveles() > niveles){
                n->setAnterior(aux);
                aux->setSiguiente(n);
                n->setSiguiente(temp);
                temp->setAnterior(n);
            } else {
                temp->setSiguiente(n);
                n->setAnterior(temp);

                this->fin = n;
            }
        }
    } else {
        this->inicio = n;
        this->fin = n;
    }
 }

 /** \brief Imprimir lista ordenada AZ
  *
  * \return void
  *
  */

void Lista_proyectos::imprimirAZ(){
    Nodo_lista* temp = this->inicio;
    while(temp->getSiguiente() != NULL){
        temp->imprimir();
        temp = temp->getSiguiente();
    }
    temp->imprimir();
}

/** \brief Imprimir lista ordenada ZA
  *
  * \return void
  *
  */

void Lista_proyectos::imprimirZA(){
Nodo_lista* temp = this->fin;
    while(temp->getAnterior() != NULL){
        temp->imprimir();
        temp = temp->getAnterior();
    }
    temp->imprimir();
}

