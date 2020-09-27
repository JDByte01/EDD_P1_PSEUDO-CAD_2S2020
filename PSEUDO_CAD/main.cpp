#include <Lista_puntos.h>
#include <Nodo_objeto.h>
#include <Menus.h>

//Test
#include <ABB_Lib.h>
#include <Nodo_objeto.h>
#include <Matriz_nivel.h>
#include <Nodo_matriz.h>
#include <ABB_nivel.h>
#include <Nodo_nivel.h>
#include <Lista_nivel.h>
#include <Nodo_proyecto.h>
#include <AVL_proyectos.h>
#include <Nodo_lista.h>
#include <Lista_proyectos.h>

//Archivos
#include <Archivo.h>

//Libreria para JSON
#include <nlohmann/json.hpp>

#include <iostream>
#include <fstream>

using namespace std;
using json=nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

void testJSON(){
    string archivo = "./prueba.json";
    ifstream reader(archivo);
    json j;
    reader>>j;
    reader.close();

    cout << j.size() << endl;
    cout << j["personas"].size() << endl;

    for(int i = 0; i < j["personas"].size(); i++){
        cout << j["personas"][i]["nombre"] << endl;
    }

    //int i = 0;
    //while(j["personas"][i] != "null"){
    //    cout << j["personas"][i]["nombre"] << endl;
    //    i++;
    //}

}
void testAVL(){
    Archivo* archivo = new Archivo();
    string ruta = "C:/Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/Niveles.json";
    string ruta2 = "C:/Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/Proyectos.json";

    cout << "Test AVL" << endl;

    AVL_proyectos* proyectos = new AVL_proyectos();
    //proyectos->cargarJSON(archivo->leerJSON(ruta2));

    //Creando Nodo Proyecto
    Nodo_proyecto* np1 = new Nodo_proyecto();
    np1->setNombre("Proyecto 1");

    Lista_nivel* ln = new Lista_nivel();
    ln->cargarJSON(archivo->leerJSON(ruta));
    np1->setNiveles(ln);

    Nodo_proyecto* np2 = new Nodo_proyecto();
    np2->setNombre("EDD 21");

    Nodo_proyecto* np3 = new Nodo_proyecto();
    np3->setNombre("COMPI 2");

    Nodo_proyecto* np4 = new Nodo_proyecto();
    np4->setNombre("ARQUI 1");

    Nodo_proyecto* np5 = new Nodo_proyecto();
    np5->setNombre("Final Final");

    Nodo_proyecto* np6 = new Nodo_proyecto();
    np6->setNombre("Final Final2");

    Nodo_proyecto* np7 = new Nodo_proyecto();
    np7->setNombre("Final Final Final");

    Nodo_proyecto* np8 = new Nodo_proyecto();
    np8->setNombre("Final1");

    Nodo_proyecto* np9 = new Nodo_proyecto();
    np9->setNombre("Final23");

    Nodo_proyecto* np10 = new Nodo_proyecto();
    np10->setNombre("Final F");


    proyectos->insertar(np1);
    proyectos->insertar(np2);
    proyectos->insertar(np3);
    proyectos->insertar(np4);
    proyectos->insertar(np5);
    proyectos->insertar(np6);
    proyectos->insertar(np7);
    proyectos->insertar(np8);
    proyectos->insertar(np9);
    proyectos->insertar(np10);

    cout << "AVL proyectos" << endl;
    proyectos->imprimir();

    proyectos->eliminar(539);
    //cout << "AVL proyectos" << endl;
    //proyectos->imprimir();

    cout << " Imprimir lista AZ" << endl;
    proyectos->llenarLista();
    proyectos->imprimirListaAZ();

    cout << proyectos->getGraphviz("PSEUDO-CAD") << endl;

/*
    system("pause");

    //Lista ordenada de proyectos
    Lista_proyectos* lp = new Lista_proyectos();

    lp->insertar(125, "Py1 ", 10);
    lp->insertar(120, "Py2 ", 2);
    lp->insertar(112, "Py3 ", 6);
    lp->insertar(123, "Py4 ", 3);
    lp->insertar(156, "Py5 ", 2);
    lp->insertar(80, "Py6 ", 8);

    cout << " Imprimir lista AZ" << endl;
    lp->imprimirAZ();

    cout << " Imprimir lista ZA" << endl;
    lp->imprimirZA();
*/
}

void testListaNivel(){
    Archivo* archivo = new Archivo();
    string ruta = "C:/Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/Niveles.json";

    Lista_nivel* ln = new Lista_nivel();

    ln->cargarJSON(archivo->leerJSON(ruta));
    cout << " | Lista de niveles" << endl;
    ln->imprimir();

    /*
    Nodo_nivel* level1 = new Nodo_nivel();
    if(archivo->existe(ruta)){
        //Existe el archivo
        json j = archivo->leerJSON(ruta);
        level1->cargarJSON(j["niveles"][0]);
    } else {
        //No existe el archivo
        cout << " |> **ERROR: Ruta incorrecta..." << endl;
    }

    cout << "Paredes totales = " << to_string(level1->getParedes()) << endl;

    cout << "Dot...\n" << endl;

    level1->mostrarNivel();
    */
}
void test(){
    //Probar matiz dispersa


    Matriz_nivel* nivel1 = new Matriz_nivel();


    cout << "insertando puntos" << endl;

    for(int x = 1; x < 10; x++){
        for(int y = 15; y < 30; y ++){
            nivel1->agregarPunto(x,y,"P","#49787F",1);
            y++;
        }
    }

    nivel1->agregarPunto(4,5,"JD","#17E0FF",4);
    nivel1->agregarPunto(4,6,"JD","#17E0FF",4);
    nivel1->agregarPunto(3,6,"JD","#17E0FF",4);

    cout << "existe x=3, y=6 " << nivel1->existePunto(3,6) << endl;
    cout << "existe x=2, y=1 " << nivel1->existePunto(2,1) << endl;

    cout << "id punto 3,6 " << to_string(nivel1->getIdPunto(3,6)) << endl;
    cout << "id punto 2,1 " << to_string(nivel1->getIdPunto(2,1)) << endl;

    //cout << nivel1->getGraphviz("Nivel 1") << endl;

    //Probando ABB_Nivel

    ABB_nivel* abb_n1 = new ABB_nivel();

    Nodo_objeto* n1 = new Nodo_objeto();
    Nodo_objeto* n2 = new Nodo_objeto();

    Lista_puntos* l1 = new Lista_puntos();
    l1->insertar(1,1);
    l1->insertar(1,2);
    l1->insertar(2,1);
    l1->insertar(1,3);
    l1->insertar(3,1);

    l1->insertar(6,1);
    l1->insertar(7,1);

    l1->insertar(1,6);
    l1->insertar(1,7);

    n1->setIdentificador(-2);
    n1->setNombre("Pared");
    n1->setLetra("P");
    n1->setColor("#C4C4C4");
    n1->setPuntos(l1);

    Lista_puntos* l2 = new Lista_puntos();
    l2->insertar(1,4);
    l2->insertar(1,5);
    l2->insertar(4,1);
    l2->insertar(5,1);

    n2->setIdentificador(-3);
    n2->setNombre("Ventana");
    n2->setLetra("V");
    n2->setColor("#F4C4DA");
    n2->setPuntos(l2);

    abb_n1->insertar(n1);
    abb_n1->insertar(n2);

    abb_n1->generarMatriz(nivel1);

    //cout << nivel1->getGraphviz("Nivel 1") << endl;

    //cout << nivel1->getGraphviz() << endl;
    //cout << nivel1->getGraphviz() << endl;
}

int main(){
    Menus* m = new Menus();
    m->encabezado();
    m->menuPrincipal();

    //testAVL();
    //testListaNivel();
    //test();
    //testJSON();

    return 0;

}




