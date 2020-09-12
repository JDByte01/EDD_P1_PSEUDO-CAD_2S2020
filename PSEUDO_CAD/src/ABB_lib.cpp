#include "ABB_lib.h"

/*
 * ARBOL BINARIO DE BUSQUEDA
 */

ABB_lib::ABB_lib()
{
    this->raiz = NULL;
}

ABB_lib::~ABB_lib()
{
    //Eliminar árbol
    delete this->raiz;
}

/*
 *  METODOS MISELANEOS
 */

 bool ABB_lib::estaVacio(){
    return this->raiz == NULL;
 }

/*
 * METODO DE INSERTAR
 */

 void ABB_lib::insertar(Nodo_objeto* n){
    //Insertar método principal
    if(estaVacio()){
        //El árbol está vacio
        this->raiz = n;
        this->objetos++;
    } else {
        insertar(this->raiz, n);
    }
 }

 void ABB_lib::insertar(Nodo_objeto* raiz, Nodo_objeto* n){
    //Insertar método recursivo
    if(n->getIdentificador() < raiz->getIdentificador()){
        //tomar nodo izquierda
        if(raiz->getIzquierda() != NULL){
            //Tomar izquirda
            insertar(raiz->getIzquierda(), n);
        } else {
            //Insertar en el nodo izquierda
            raiz->setIzquierda(n);
            this->objetos++;
        }
    } else if(n->getIdentificador() > raiz->getIdentificador()){
        //Tomar nodo derecha
        if(raiz->getDerecha() != NULL){
            //Tomar derecha
            insertar(raiz->getDerecha(), n);
        } else {
            //Insertar en el nodo derecha
            raiz->setDerecha(n);
            this->objetos++;
        }
    } else {
        cout << " | ** ERROR: ya existe el objeto con id " << n->getIdentificador() << endl;
    }
 }

 /*
  * METODO EXISTE
  * PARAMETROS INT ID
  */

    bool ABB_lib::existe(int id){
    if(estaVacio()){
        return false;
    } else {
        return existe(this->raiz, id);
    }
  }

  bool ABB_lib::existe(Nodo_objeto* raiz, int id){
    if(id < raiz->getIdentificador()){
        //Tomar izquierda
        if(raiz->getIzquierda() != NULL){
            return existe(raiz->getIzquierda(), id);
        } else{
            return false;
        }
    } else if(id > raiz->getIdentificador()){
        //Tomar derecha
        if(raiz->getDerecha() != NULL){
            return existe(raiz->getDerecha(), id);
        } else {
            return false;
        }
    } else {
        return true;
    }
  }

  /*
  * METODO ENCONTRAR
  * PARAMETROS INT ID
  */

  Nodo_objeto* ABB_lib::encontrar(int id){
    if(estaVacio()){
        return NULL;
    } else {
        return encontrar(this->raiz, id);
    }
  }

  Nodo_objeto* ABB_lib::encontrar(Nodo_objeto* raiz, int id){
    if(id < raiz->getIdentificador()){
        //Tomar Izquierda
        if(raiz->getIzquierda() != NULL){
            return encontrar(raiz->getIzquierda(), id);
        } else {
            return NULL;
        }
    } else if(id > raiz->getIdentificador()){
        //Tomar Derecja
        if(raiz->getDerecha() != NULL){
            return encontrar(raiz->getDerecha(), id);
        } else {
            return NULL;
        }
    } else {
        return raiz;
    }
  }

  /*
  * METODO ELIMINAR
  * PARAMETROS INT ID
  */

  bool ABB_lib::eliminar(int id){
    if(estaVacio()){
        return false;
    } else {
        return eliminar(this->raiz, id);
    }
  }

  bool ABB_lib::eliminar(Nodo_objeto* raiz, int id){
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


        return true;
    }
  }

 /*
  * METODO IMPRIMIR EN CONSOLA ARBOL BINARIO DE BUSQUEDA
  */

  void ABB_lib::imprimir(){
    if(estaVacio()){
       cout << " | -> ABB vacio..." << endl;
    } else {
        cout << " |%%%| Librerias disponibles |%%%|" << endl;
        imprimir(this->raiz);
    }
  }

  void ABB_lib::imprimir(Nodo_objeto* raiz){

    if(raiz->getIzquierda() != NULL)
        imprimir(raiz->getIzquierda());

    raiz->imprimirNodo();

    if(raiz->getDerecha() != NULL)
        imprimir(raiz->getDerecha());

  }

   /*
  * METODO GET GRAPHVIZ
  */

  string ABB_lib::getGraphviz(string nombre){
    //Obtener arbol en graphviz
    g_nodes = "";

    g_nodes += graphviz(this->raiz, "");
    return graphIn + g_initA + nombre + g_initB + g_node + g_nodes + "}";
  }

  string ABB_lib::graphviz(Nodo_objeto* raiz, string txt){
    if(raiz->getIzquierda() != NULL)
        txt = graphviz(raiz->getIzquierda(), txt);

    txt += raiz->getNodoGraphviz();

    if(raiz->getDerecha() != NULL)
        txt = graphviz(raiz->getDerecha(), txt);

    return txt;
  }

  /** \brief Cargar datos de estructura JSON
   *
   * \param json Objeto JSON
   * \return
   *
   */

void ABB_lib::cargarJSON(json lib){
    Nodo_objeto* ob;

    for(int i = 0; i < lib["Libreria"].size(); i++){
        ob = new Nodo_objeto();
        ob->setIdentificador(lib["Libreria"][i]["identificador"]);
        ob->setNombre(lib["Libreria"][i]["nombre"]);
        ob->setLetra(lib["Libreria"][i]["letra"]);
        ob->setColor(lib["Libreria"][i]["color"]);

        for(int j = 0; j < lib["Libreria"][i]["puntos"].size(); j++){
             ob->insertarPunto(lib["Libreria"][i]["puntos"][j]["x"],lib["Libreria"][i]["puntos"][j]["y"]);
        }

        this->insertar(ob);
    }

    cout << " | Archivo JSON leido exitosamente!" << endl;
    cout << " | Objetos leidos: " << lib["Libreria"].size() << endl;
    //cout << to_string(i) <<" -> [" << lib["Libreria"][i]["identificador"] << "] " << lib["Libreria"][i]["nombre"]<< endl;
}

