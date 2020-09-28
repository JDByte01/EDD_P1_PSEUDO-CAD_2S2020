#include "AVL_proyectos.h"

AVL_proyectos::AVL_proyectos()
{
    //Constructor
    this->raiz = NULL;
    this->lista = new Lista_proyectos();
}

AVL_proyectos::~AVL_proyectos()
{
    //dtor
    delete this->raiz;
    delete this->lista;
}

/** \brief Obtiene la altura del nodo
 *
 * \param Nodo_proyecto n
 * \return int altura
 *
 */

int AVL_proyectos::altura(Nodo_proyecto* n){
    if(n != NULL){
        return n->getAltura();
    } else {
        return 0;
    }
}

   /**
     *          y
     *        /   \
     *       x     y
     *      / \   / \
     *     t1 t2 t3 t4
     */

Nodo_proyecto* AVL_proyectos::rotarDerecha(Nodo_proyecto* y){
    Nodo_proyecto* x = y->getIzquierda();
    Nodo_proyecto* t2 = x->getDerecha();

    //Rotación
    x->setDerecha(y);
    y->setIzquierda(t2);

    //Actualizar alturas
    y->setAltura(maximo(altura(y->getIzquierda()),  altura(y->getDerecha())) +1);
    x->setAltura(maximo(altura(x->getIzquierda()),  altura(x->getDerecha())) +1);

    return x;
}

Nodo_proyecto* AVL_proyectos::rotarIzquierda(Nodo_proyecto* x){
    Nodo_proyecto* y = x->getDerecha();
    Nodo_proyecto* t2 = y->getIzquierda();

    //Rotación
    y->setIzquierda(x);
    x->setDerecha(t2);

    //Actualizar alturas
    x->setAltura(maximo(altura(x->getIzquierda()),  altura(x->getDerecha())) +1);
    y->setAltura(maximo(altura(y->getIzquierda()),  altura(y->getDerecha())) +1);

    return y;
}

int AVL_proyectos::getBalance(Nodo_proyecto* n){
    if(n != NULL){
        return altura(n->getIzquierda()) - altura(n->getDerecha());
    } else {
        return 0;
    }
}

/** \brief Metodo de insertar
 *
 * \param
 * \return
 *
 */

 void AVL_proyectos::insertar(Nodo_proyecto* n){
    this->raiz = insertar(this->raiz, n);
 }

 void AVL_proyectos::insertar(string proyecto){
    Nodo_proyecto* n = new Nodo_proyecto();
    n->setNombre(proyecto);

    this->raiz = insertar(this->raiz, n);
 }

 Nodo_proyecto* AVL_proyectos::insertar(Nodo_proyecto* raiz, Nodo_proyecto* n){
     //1- Inserción normal
    if(raiz == NULL){
        return (n);
    }

    if(n->getId() < raiz->getId()){
        raiz->setIzquierda(insertar(raiz->getIzquierda(), n));
    } else if(n->getId() > raiz->getId()){
        raiz->setDerecha(insertar(raiz->getDerecha(), n));
    } else {
        return raiz;
    }

    //2- Actualizar altura del padre
    raiz->setAltura(1+ maximo(altura(raiz->getIzquierda()), altura(raiz->getDerecha())));

    //3- Obtener el factor de balance
    int balance = getBalance(raiz);

    //caso: Izquierda Izquierda
    if(balance > 1 && n->getId() < raiz->getId()){
        return rotarDerecha(raiz);
    }

    //caso: Derecha Derecha
    if(balance < -1 && n->getId() > raiz->getId()){
        return rotarIzquierda(raiz);
    }

    //caso: Izquierda Derecha
    if(balance > 1 && n->getId() > raiz->getId()){
        raiz->setIzquierda(rotarIzquierda(raiz->getIzquierda()));
        return rotarDerecha(raiz);
    }

    //caso: Derecha Izquierda
    if(balance < -1 && n->getId() < raiz->getId()){
        raiz->setDerecha(rotarDerecha(raiz->getDerecha()));
        return rotarIzquierda(raiz);
    }

    //Retornar el raiz puntero
    return raiz;
 }

 /** \brief Eliminar nodo del AVL
  *
  * \param
  * \return
  *
  */

  Nodo_proyecto* AVL_proyectos::valorMinimo(Nodo_proyecto* n){
    Nodo_proyecto* actual = n;

    //Bajar hasta encontrar la hoja mas a la izquierda
    while(actual->getIzquierda() != NULL){
        actual = actual->getIzquierda();
    }

    return actual;
  }

  bool AVL_proyectos::eliminar(int id){
    if(this->raiz != NULL){
        if(eliminar(this->raiz, id) != NULL){
            return true;
        } else{
            return false;
        }
    } else {
        return false;
    }
  }

  Nodo_proyecto* AVL_proyectos::eliminar(Nodo_proyecto* raiz, int id){
    //1- Eliminación normal
    if(raiz == NULL){
        return raiz;
    }

    //Busqueda
    if(id < raiz->getId()){
        //Si el Id es menor que el ID de la raiz
        raiz->setIzquierda(eliminar(raiz->getIzquierda(), id));
    }else if(id > raiz->getId()){
        //El Id es mayor que el Id de la raiz
        raiz->setDerecha(eliminar(raiz->getDerecha(),id));
    } else {
        //Nodo igual, eliminar
        //Nodo con un hijo o sin hijos
        if((raiz->getIzquierda() == NULL) || (raiz->getDerecha() == NULL)){
            Nodo_proyecto* temp = NULL;
            if(temp == raiz->getIzquierda()){
                temp = raiz->getDerecha();
            } else {
                temp = raiz->getIzquierda();
            }

            //Ningun hijo
            if(temp == NULL){
                temp = raiz;
                raiz = NULL;
            } else {
                raiz = temp;
            }
        } else {
            //Nodo con dos hijos
            Nodo_proyecto* temp = valorMinimo(raiz->getDerecha());

            raiz->setNombre(temp->getNombre());
            raiz->setNiveles(temp->getNiveles());

            //eliminar
            raiz->setDerecha(eliminar(raiz->getDerecha(), temp->getId()));
        }
    }

    //Si el árbol solo tiene un nodo retornar
    if(raiz == NULL){
        return raiz;
    }

    //2- Actualizar altura del nodo actual
    raiz->setAltura(maximo(altura(raiz->getIzquierda()), altura(raiz->getDerecha())) +1);

    //3- Obtener el factor de balance del nodo
    int balance = getBalance(raiz);

    //caso: Izquierda Izquierda
    if(balance > 1 && getBalance(raiz->getIzquierda()) >= 0){
        return rotarDerecha(raiz);
    }
    //caso: Izquierda Derecha
    if(balance > 1 && getBalance(raiz->getIzquierda()) < 0){
        raiz->setIzquierda(rotarIzquierda(raiz->getIzquierda()));
        return rotarDerecha(raiz);
    }
    //caso: Derecha Derecha
    if(balance < -1 && getBalance(raiz->getDerecha()) <= 0){
        return rotarIzquierda(raiz);
    }
    //caso: Derecha Izquierda
    if(balance < -1 && getBalance(raiz->getDerecha()) > 0){
        raiz->setDerecha(rotarDerecha(raiz->getDerecha()));
        return rotarIzquierda(raiz);
    }

    return raiz;
  }

  /** \brief Método de busqueda
   *
   * \param
   * \return
   *
   */

Nodo_proyecto* AVL_proyectos::buscar(int id){
    if(this->raiz != NULL){
        return buscar(this->raiz, id);
    } else {
        return NULL;
    }
}

Nodo_proyecto* AVL_proyectos::buscar(Nodo_proyecto* raiz, int id){
    Nodo_proyecto* temp = NULL;

    while(raiz != NULL){
        if(id < raiz->getId()){
            raiz = raiz->getIzquierda();
        } else if(id > raiz->getId()){
            raiz = raiz->getDerecha();
        } else {
            temp = raiz;
            return temp;
        }

        temp = buscar(raiz, id);
    }

    return temp;
}

/** \brief Imprimir AVL en consola
 *
 * \param
 * \return
 *
 */

void AVL_proyectos::imprimir(){
    if(this->raiz != NULL)
        imprimir(this->raiz);
    else
        cout << " |%%%| **AVL vacio" << endl;
}

void AVL_proyectos::imprimir(Nodo_proyecto* n){
    if(n != NULL){
        imprimir(n->getIzquierda());
        n->imprimir();
        imprimir(n->getDerecha());
    }
}

/** \brief Lista ordenada
 *
 * \param
 * \return
 *
 */

 void AVL_proyectos::imprimirListaAZ(){
    this->lista->imprimirAZ();
 }

  void AVL_proyectos::imprimirListaZA(){
    this->lista->imprimirZA();
 }

 void AVL_proyectos::llenarLista(){
    //Limpiar la lista
    delete this->lista;
    llenarLista(this->raiz);
 }

 void AVL_proyectos::llenarLista(Nodo_proyecto* n){
    if(n != NULL){
        llenarLista(n->getIzquierda());
        this->lista->insertar(n->getId(), n->getNombre(), n->sizeNiveles());
        llenarLista(n->getDerecha());
    }
 }

 /** \brief Cargar archivo JSON
  *
  * \param json j
  * \return void
  *
  */

void AVL_proyectos::cargarJSON(json j){
     Nodo_proyecto* n;

     cout << "Total de proyectos " << j["proyectos"].size() << endl;

    for(int i = 0; i < j["proyectos"].size(); i++){
        n = new Nodo_proyecto();
        //cout << "Nombre: " << j["proyectos"][i]["nombre"] << endl;
        n->setNombre(j["proyectos"][i]["nombre"]);
        //cout << "Niveles: " << j["proyectos"][i] << endl;
        n->cargarJSON(j["proyectos"][i]);
        insertar(n);
    }
}

/** \brief Generar grafo Graphviz
 *
 * \param string nombre
 * \return string dot
 *
 */

string AVL_proyectos::getGraphviz(string nombre){
    string g = "digraph G {\nnode [shape = oval ];\nlabel = \".: AVL - "+nombre+" :.\";\n";
    if(raiz != NULL){
        g.append(this->raiz->getGraphviz());
    }

    g.append("}");
    return g;

}

