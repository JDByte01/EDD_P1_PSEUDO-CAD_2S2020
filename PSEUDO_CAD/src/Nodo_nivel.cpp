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

/** \brief Cargar objetos dentro del JSON por nivel
 *
 * \param json j
 * \return void
 *
 */

 void Nodo_nivel::cargarJSON(json j){

    this->setNombre(to_string(j["nivel"]));

    this->cargarParedesJSON(j["paredes"]);
    this->cargarVentanasJSON(j["ventanas"]);
    this->cargarObjetosJSON(j["objetos"]);

    cout << " | Archivo JSON leido exitosamente!" << endl;
    cout << " | Nivel: " << this->getNombre() << " cargado..." <<endl;
 }

 /** \brief Agregar objeto al arbol ABB
  *
  * \param Nodo_objeto n
  * \return void
  *
  */

void Nodo_nivel::cargarObjetosJSON(json j){

    Nodo_objeto* ob;

    for(int i = 0; i < j.size(); i++){
        ob = new Nodo_objeto();
        ob->setIdentificador(j[i]["identificador"]);
        ob->setNombre(j[i]["nombre"]);
        ob->setLetra(j[i]["letra"]);
        ob->setColor(j[i]["color"]);

        for(int k = 0; k < j[i]["puntos"].size(); k++){
             ob->insertarPunto(j[i]["puntos"][k]["x"],j[i]["puntos"][k]["y"]);
        }

        this->arbol->insertar(ob);
    }

    cout << " | Objetos encontrados: "<< j.size() << endl;

}

/** \brief Agregar pared al arbol ABB
 *
 * \param Nodo_objeto n
 * \return void
 *
 */

 void Nodo_nivel::cargarParedesJSON(json j){
    Nodo_objeto* ob;

    for(int i = 0; i < j.size(); i++){
        ob = new Nodo_objeto();
        ob->setIdentificador((-2)*10-i);
        ob->setNombre("Pared");
        ob->setLetra("P");
        ob->setColor(j[i]["color"]);

        //cout << " | Pared [" << to_string(i) << "]" << endl;
        //cout << " | - Inicio (" << j[i]["inicio"][0] << ", " << j[i]["inicio"][1] << ")" << endl;
        //cout << " | - Final (" << j[i]["final"][0] << ", " << j[i]["final"][1] << ")" << endl;


        for(int x = j[i]["inicio"][0]; x <= j[i]["final"][0]; x++){
            for(int y = j[i]["inicio"][1]; y <= j[i]["final"][1]; y++){
                ob->insertarPunto((x+1),(y+1));
                //cout << " | --- Insertando putno (" << to_string(x+1) << ", " << to_string(y+1) << ")" << endl;
            }
        }

        this->arbol->insertar(ob);

        //Incrementar la variable paredes
        this->paredes++;

    }

    cout << " | Paredes encontradas: "<< j.size() << endl;
 }

 /** \brief Agregar ventana al arbol ABB
  *
  * \param Nodo_objeto n
  * \return void
  *
  */

void Nodo_nivel::cargarVentanasJSON(json j){
    Nodo_objeto* ob;

    for(int i = 0; i < j.size(); i++){
        ob = new Nodo_objeto();
        ob->setIdentificador((-3)*10-i);
        ob->setNombre("Ventana");
        ob->setLetra("V");
        ob->setColor(j[i]["color"]);

        cout << " | Ventana [" << to_string(i) << "]" << endl;
        cout << " | - Inicio (" << j[i]["inicio"][0] << ", " << j[i]["inicio"][1] << ")" << endl;
        cout << " | - Final (" << j[i]["final"][0] << ", " << j[i]["final"][1] << ")" << endl;


        for(int x = j[i]["inicio"][0]; x <= j[i]["final"][0]; x++){
            for(int y = j[i]["inicio"][1]; y <= j[i]["final"][1]; y++){
                ob->insertarPunto((x+1),(y+1));
                cout << " | --- Insertando putno (" << to_string(x+1) << ", " << to_string(y+1) << ")" << endl;
            }
        }

        this->arbol->insertar(ob);

        //Incrementar la variable paredes
        this->paredes++;

    }

    cout << " | Ventanas encontradas: "<< j.size() << endl;
}

/** \brief Generar dot de la matriz por medio del ABB
 *
 * \return void
 *
 */

 void Nodo_nivel::mostrarNivel(){
    this->arbol->generarMatriz(this->matriz);
    cout << this->matriz->getGraphviz("Nivel 1") << endl;
 }




