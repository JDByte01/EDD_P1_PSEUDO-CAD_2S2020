#include "Lista_nivel.h"

Lista_nivel::Lista_nivel()
{
    //ctor
    this->size = 0;
    this->inicio = NULL;
}

Lista_nivel::~Lista_nivel()
{
    this->size = 0;
    this->inicio = NULL;
}

/** \brief Insertar Niveles por JSON
 *
 * \param json j
 * \return void
 *
 */

 void Lista_nivel::cargarJSON(json j){
    //cout << "Niveles: " << j["niveles"].size() << endl;
    Nodo_nivel* n;

    for(int i = 0; i < j["niveles"].size(); i++){
        n = new Nodo_nivel();
        n->cargarJSON(j["niveles"][i]);
        insertarNivel(n);
    }
 }

 /** \brief Insertar un nivel con informacion
  *
  * \param Nodo_nivel n
  * \return void
  *
  */

  void Lista_nivel::insertarNivel(Nodo_nivel* n){
    if(estaVacio()){
        this->inicio = n;
    } else {
        Nodo_nivel* temp = this->inicio;
        while(temp->getSiguiente() != NULL){
            temp = temp->getSiguiente();
        }

        temp->setSiguiente(n);
    }
    this->size++;
  }

  /** \brief insertar un nuevo nivel vacio
   *
   * \param string nombre
   * \return void
   *
   */

void Lista_nivel::nuevoNivel(int nombre){
    Nodo_nivel* n = new Nodo_nivel();
    n->setNombre(nombre);

    insertarNivel(n);
}

/** \brief Eliminar nivel por nombre
 *
 * \param int nombre
 * \return void
 *
 */

 void Lista_nivel::eliminarNivel(int nombre){
    if(!estaVacio()){
        if(this->inicio->getNombre() == nombre){
            this->inicio = this->inicio->getSiguiente();
            this->size--;
        } else {
            Nodo_nivel* temp = this->inicio;
            Nodo_nivel* anterior = this->inicio;

            while(temp->getSiguiente() != NULL && temp->getNombre() != nombre){
                anterior = temp;
                temp = temp->getSiguiente();
            }

            if(temp->getNombre() == nombre){
                anterior->setSiguiente(temp->getSiguiente());
                this->size--;
            }
        }
    }
 }

 /** \brief Buscar nivel por nombre
  *
  * \param string nombre
  * \return Nodo_nivel
  *
  */

 Nodo_nivel* Lista_nivel::buscarNivel(int nombre){
     if(!estaVacio()){
        if(this->inicio->getNombre() == nombre){
            return this->inicio;
        } else {
            Nodo_nivel* temp = this->inicio;

            while(temp->getSiguiente() != NULL && temp->getNombre() != nombre){
                temp = temp->getSiguiente();
            }

            if(temp->getNombre() == nombre){
                return temp;
            } else {
                return NULL;
            }
        }
    } else {
        return NULL;
    }
 }

 /** \brief Imprimir lista de niveles
  *
  * \return void
  *
  */

  void Lista_nivel::imprimir(){
     if(!estaVacio()){
        Nodo_nivel* temp = this->inicio;

        while(temp->getSiguiente() != NULL){
            cout << " | - Nivel: " << to_string(temp->getNombre()) << endl;
            temp = temp->getSiguiente();
        }

        cout << " | - Nivel: " << to_string(temp->getNombre()) << endl;
    }
  }
