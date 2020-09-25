#include "Matriz_nivel.h"

Matriz_nivel::Matriz_nivel()
{
    //ctor
    this->headers = new Nodo_matriz("M","",0,0,-1);
    this->dot = "";
    this->dotN = "";
    this->dotR = "";
    this->dotI = "";
    this->x = 0;
    this->y = 0;
}

Matriz_nivel::~Matriz_nivel()
{
    //dtor
    Nodo_matriz* temp;

    temp = this->headers;

    //Recorrer el eje x
    while(temp->getDerecha() != NULL){
        temp = temp->getDerecha();
        delete temp->getAbajo();
    }
    delete temp->getAbajo();

    temp = this->headers;

    //Recorrer el eje y
    while(temp->getAbajo() != NULL){
        temp = temp->getAbajo();
        delete temp->getDerecha();
    }
    delete temp->getDerecha();

    delete headers->getDerecha();
    delete headers->getAbajo();
}

/** \brief agrega un punto en la matriz
 *
 * \param int x
 * \param int y
 * \param string letra
 * \param string color
 * \return void
 *
 */

void Matriz_nivel::agregarPunto(int x, int y, string letra, string color, int id){
    ///Agregar punto en el eje X
    agregarEjeX(x);
    ///Agregar punto en el eje Y
    agregarEjeY(y);

    ///Agregar punto
    Nodo_matriz* temp;
    Nodo_matriz* punto = new Nodo_matriz(letra,color,x,y,id);

    ///Insertar en el eje x
    temp = this->headers;

    //Recorrer el eje x hasta encontrar la x
    while(temp->getDerecha() != NULL && temp->getDerecha()->getX() <= x){
        temp = temp->getDerecha();
    }

    if(temp->getX() == x){
        if(temp->getAbajo() == NULL){
            //No hay punto
            temp->setAbajo(punto);
            punto->setArriba(temp);

        } else {
            //Existe un punto
            //Recorrer puntos del eje x en y
            while(temp->getAbajo() != NULL && temp->getAbajo()->getY() < y){
                temp = temp->getAbajo();
            }

            ///Caso1: insertar al final de la lista
            if(temp->getAbajo() == NULL && temp->getY() != y){
                temp->setAbajo(punto);
                punto->setArriba(temp);
            ///Caso2: insertar entre la lista
            } else if(temp->getAbajo() != NULL && temp->getAbajo()->getY() != y){
                Nodo_matriz* aux = temp->getAbajo();
                temp->setAbajo(punto);
                punto->setArriba(temp);
                punto->setAbajo(aux);
                aux->setArriba(punto);
            ///Caso3: ya existe un nodo
            } else {
                cout << " | -- Ya existe un punto en la posicion y: " << to_string(y) << endl;
            }
        }
    }

    ///***********************************************************************
    /**Insertar Y**/
    temp = this->headers;

    ///Recorrer eje y hasta encontrar y
    while(temp->getAbajo() != NULL && temp->getAbajo()->getY() <= y){
        temp = temp->getAbajo();
    }

    if(temp->getY() == y){
        ///No hay punto
        if(temp->getDerecha() == NULL){
            temp->setDerecha(punto);
            punto->setIzquierda(temp);
        } else {
            ///Recorrer x en el eje y
            while(temp->getDerecha() != NULL && temp->getDerecha()->getX() < x){
                temp = temp->getDerecha();
            }

            ///Caso1: insertar al inicio
            if(temp->getDerecha() == NULL && temp->getX() != x){
                temp->setDerecha(punto);
                punto->setIzquierda(temp);
            ///Caso2: insertar entre la lista
            } else if(temp->getDerecha() != NULL && temp->getDerecha()->getX() != x){
                Nodo_matriz* aux = temp->getDerecha();
                temp->setDerecha(punto);
                punto->setIzquierda(temp);
                punto->setDerecha(aux);
                aux->setIzquierda(punto);
            ///Caso3: ya existe un nodo
            } else {
                cout << " | -- Ya existe un punto en la posicion x: " << to_string(x) << endl;
            }
        }
    }

}

/** \brief verifica si existe el punto en la matriz
 *
 * \param int x
 * \param int y
 * \return bool, true = existe | false = no existe
 *
 */

 bool Matriz_nivel::existePunto(int x, int y){
    Nodo_matriz* temp = this->headers;

     //Recorrer el eje x hasta encontrar la x
    while(temp->getDerecha() != NULL && temp->getDerecha()->getX() <= x){
        temp = temp->getDerecha();
    }

    ///Validar x = x
    if(temp->getX() == x){
        if(temp->getAbajo() == NULL){
            ///No hay punto y
            return false;
        } else {
            //Existe un o mas puntos
            //Recorrer puntos del eje x en y
            while(temp->getAbajo() != NULL && temp->getAbajo()->getY() <= y){
                temp = temp->getAbajo();
            }

            ///Verificar si y existe
            if(temp->getY() == y){
                return true;
            } else {
                return false;
            }
        }
    } else {
        ///No existe el encabezado x
        return false;
    }
 }

 /** \brief Busca el id del objeto en la matriz
  *
  * \param int x
  * \param int y
  * \return int id del objeto
  *
  */

  int Matriz_nivel::getIdPunto(int x, int y){
    Nodo_matriz* temp = this->headers;

    ///Recorrer el eje x hasta encontrar la x
    while(temp->getDerecha() != NULL && temp->getDerecha()->getX() <= x){
        temp = temp->getDerecha();
    }

    ///Validar x = x
    if(temp->getX() == x){
        if(temp->getAbajo() == NULL){
            ///No hay punto y
            return -1;
        } else {
            //Existe un o mas puntos
            //Recorrer puntos del eje x en y
            while(temp->getAbajo() != NULL && temp->getAbajo()->getY() <= y){
                temp = temp->getAbajo();
            }

            ///Verificar si y existe
            if(temp->getY() == y){
                return temp->getId();
            } else {
                return -1;
            }
        }
    } else {
        ///No existe el encabezado x
        return -1;
    }
  }

  /** \brief Obtiene la estructura de la matriz para graficar
   *
   * \param string nombre
   * \return string dot
   *
   */

string Matriz_nivel::getGraphviz(string nombre){

    dotN = "";
    dotR = "";
    dotI = "";

    dot = "digraph Sparce_Matrix {\nnode [shape=box]\nedge [dir=none]\nNM00[ label = \"N\", width = 0.4, height = 0.4, group = 0, shape = Msquare];\n";
    dot.append("label = \"").append(nombre).append("\";\n");

    Nodo_matriz* temp;
    Nodo_matriz* aux;

    temp = this->headers;

     /**Obtener Nodos**/
    while(temp->getDerecha() != NULL){
        aux = temp;
        while(aux->getAbajo() != NULL){
            if(aux != this->headers)
                dotN.append(aux->getNodoGraphviz());
            aux = aux->getAbajo();
        }
        dotN.append(aux->getNodoGraphviz());

        temp = temp->getDerecha();
    }

    while(temp->getAbajo() != NULL){
        if(temp != this->headers)
            dotN.append(temp->getNodoGraphviz());
        temp = temp->getAbajo();
    }
    dotN.append(temp->getNodoGraphviz());


    /**Obtener Rutas**/
    temp = this->headers;
    while(temp->getAbajo() != NULL){
        aux = temp;
        dotI.append("{ rank = same; ");
        while(aux->getDerecha() != NULL){
            dotI.append(aux->getIdNodo()).append(";");
            dotR.append(aux->getRutaGraphviz());

            aux = aux->getDerecha();
        }
        dotI.append(aux->getIdNodo()).append(";}\n");
        dotR.append(aux->getRutaGraphviz());

        temp = temp->getAbajo();
    }


    dotI.append("{ rank = same; ");
    while(temp->getDerecha() != NULL){
        dotI.append(temp->getIdNodo()).append(";");
        dotR.append(temp->getRutaGraphviz());

        temp = temp->getDerecha();
    }
    dotI.append(temp->getIdNodo()).append(";}\n");
    dotR.append(temp->getRutaGraphviz());

    dot.append(dotN).append(dotI).append(dotR).append("\n}");

    return dot;
}

/** \brief agregar el punto x en el header
 *
 * \param int x
 * \return void
 *
 */

 void Matriz_nivel::agregarEjeX(int x){

    Nodo_matriz* temp = this->headers;

    //Crear nodo
    Nodo_matriz* nodo = new Nodo_matriz("X","",x,0,-1);

    if(temp->getDerecha() == NULL){
        //El eje Y esta vacio
        temp->setDerecha(nodo);
        nodo->setIzquierda(temp);
    } else{
        //Recorrer el eje Y
        while(temp->getDerecha() != NULL && temp->getDerecha()->getX() < x){
            temp = temp->getDerecha();
        }

        //Validar
        if(temp->getDerecha() == NULL && temp->getX() != x){
            //Agregar al final del eje Y
            temp->setDerecha(nodo);
            nodo->setIzquierda(temp);
            this->x = x; //Agregar al valor de x;
        } else if(temp->getDerecha() != NULL && temp->getDerecha()->getX() != x){
            //Agregar entre el eje Y
            Nodo_matriz* aux = temp->getDerecha();
            temp->setDerecha(nodo);
            nodo->setIzquierda(temp);
            nodo->setDerecha(aux);
            aux->setIzquierda(nodo);
        } else {
            //Existe, no agregar solo liberar nodo
            delete nodo;
        }
    }
 }

  /** \brief agregar el punto y en el header
   *
   * \param int y
   * \return void
   *
   */

void Matriz_nivel::agregarEjeY(int y){
    Nodo_matriz* temp = this->headers;

    //Crear nodo
    Nodo_matriz* nodo = new Nodo_matriz("Y","",0,y,-1);

    if(temp->getAbajo() == NULL){
        //El eje Y esta vacio
        temp->setAbajo(nodo);
        nodo->setArriba(temp);
    } else{
        //Recorrer el eje Y
        while(temp->getAbajo() != NULL && temp->getAbajo()->getY() < y){
            temp = temp->getAbajo();
        }

        //Validar
        if(temp->getAbajo() == NULL && temp->getY() != y){
            //Agregar al final del eje Y
            temp->setAbajo(nodo);
            nodo->setArriba(temp);
            this->y = y;
        } else if(temp->getAbajo() != NULL && temp->getAbajo()->getY() != y){
            //Agregar entre el eje Y
            Nodo_matriz* aux = temp->getAbajo();
            temp->setAbajo(nodo);
            nodo->setArriba(temp);
            nodo->setAbajo(aux);
            aux->setArriba(nodo);
        } else {
            //Existe, no agregar solo liberar nodo
            delete nodo;
        }
    }
}



