#include "Nodo_proyecto.h"

Nodo_proyecto::Nodo_proyecto()
{
    //Constructor
    this->id = 0;
    this->altura = 1;
    this->nombre = "";
    this->niveles = new Lista_nivel();
    this->izquierda = NULL;
    this->derecha = NULL;

}

Nodo_proyecto::Nodo_proyecto(string nombre, Lista_nivel* l){

    //Constructor
    this->altura = 1;
    this->nombre = nombre;
    this->niveles = l;
    this->izquierda = NULL;
    this->derecha = NULL;

    setID(nombre);

}

Nodo_proyecto::~Nodo_proyecto()
{
    //dtor
    delete this->niveles;
}

/** \brief Obtiene el total de niveles en la lista
 *
 * \return int niveles
 *
 */
 int Nodo_proyecto::sizeNiveles(){
    if(this->niveles != NULL)
        return this->niveles->getSize();
    else
        return 0;
 }

 /** \brief Genera el id del nodo AVL
  *
  * \param string nombre
  * \return void
  *
  */
  void Nodo_proyecto::setID(string nombre){
    this->id = 0;
    for(int i = 0; i < nombre.length(); i++){
        this->id += (int)nombre[i];
    }
  }

  /** \brief Obtiene el segmento de Graphviz equivalente al nodo
   *
   * \return string dot
   *
   */

string Nodo_proyecto::getGraphviz(){
    g = "";
    g.append("n").append(to_string(this->id)).append(" [label = \"").append(this->nombre).append(" N(").append(to_string(this->sizeNiveles())).append(")\"];\n");

    if(this->izquierda != NULL)
        g.append(this->izquierda->getGraphviz()).append(" n").append(to_string(this->id)).append(" -> n").append(to_string(this->izquierda->getId())).append(";\n");

    if(this->derecha != NULL)
        g.append(this->derecha->getGraphviz()).append(" n").append(to_string(this->id)).append(" -> n").append(to_string(this->derecha->getId())).append(";\n");
    return g;
}

  /** \brief Obtiene el segmento de JSON equivalente al nodo
   *
   * \return string JSON
   *
   */

string Nodo_proyecto::getJSON(){
    return "";
}

/** \brief Carga la información de un archivo JSON
 *
 * \param json j
 * \return  void
 *
 */

void Nodo_proyecto::cargarJSON(json j){
    this->setNombre(j["nombre"]);
    cout << j["nombre"] << endl;
    this->niveles->cargarJSON(j["niveles"]);

    cout << " | Archivo JSON leido exitosamente!" << endl;
    cout << " | Niveles: " << j["niveles"].size() << endl;
}

/** \brief Imprime los datos del nodo proyecto
 *
 * \return void
 *
 */

void Nodo_proyecto::imprimir(){
    cout << " | (" << to_string(this->id) << ") " << this->nombre << endl;
    cout << " | -> Niveles: " << to_string(this->sizeNiveles()) << endl;
    //this->niveles->imprimir();
}

