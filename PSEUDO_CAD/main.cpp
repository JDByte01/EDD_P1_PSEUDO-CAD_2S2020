#include <Lista_puntos.h>
#include <Nodo_objeto.h>
#include <Menus.h>

//Test
#include <ABB_Lib.h>
#include <Nodo_objeto.h>

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
void test(){
    string ruta = "../entradas/entrada_lib3.json";
    json lib;

    Archivo* archivo = new Archivo();
    ABB_lib* libreria = new ABB_lib();
    Nodo_objeto* ob;

    lib = archivo->leerJSON(ruta);

    cout << "Archivo Json leido, objetos: " << lib["Libreria"].size() << endl;

    for(int i = 0; i < lib["Libreria"].size(); i++){
        ob = new Nodo_objeto();
        ob->setIdentificador(lib["Libreria"][i]["identificador"]);
        ob->setNombre(lib["Libreria"][i]["nombre"]);
        ob->setLetra(lib["Libreria"][i]["letra"]);
        ob->setColor(lib["Libreria"][i]["color"]);

        cout << "Puntos: " << lib["Libreria"][i]["puntos"].size() << endl;

        for(int j = 0; j < lib["Libreria"][i]["puntos"].size(); j++){
             ob->insertarPunto(lib["Libreria"][i]["puntos"][j]["x"],lib["Libreria"][i]["puntos"][j]["y"]);
        }

        libreria->insertar(ob);

        cout << to_string(i) <<" -> [" << lib["Libreria"][i]["identificador"] << "] " << lib["Libreria"][i]["nombre"]<< endl;
    }
    system("pause");
    libreria->imprimir();
    system("pause");
    archivo->generarEstructura("ABB_libreria","./archivos",libreria->getGraphviz("Libreria"));
    /*

    Nodo_objeto* ob1 = new Nodo_objeto();
    Nodo_objeto* ob2 = new Nodo_objeto();
    Nodo_objeto* ob3 = new Nodo_objeto();
    Nodo_objeto* ob4 = new Nodo_objeto();
    Nodo_objeto* ob5 = new Nodo_objeto();
    Nodo_objeto* ob6 = new Nodo_objeto();

    ob1->setIdentificador(15);
    ob1->setNombre("Puerta");
    ob1->setLetra("P");
    ob1->setColor("#C4C3C5");

    ob2->setIdentificador(3);
    ob2->setNombre("Ventana");
    ob2->setLetra("V");
    ob2->setColor("#D4C3F5");

    ob3->setIdentificador(9);
    ob3->setNombre("Mesa");
    ob3->setLetra("M");
    ob3->setColor("#C4CFF4");

    ob4->setIdentificador(18);
    ob4->setNombre("Carro");
    ob4->setLetra("C");
    ob4->setColor("#C4C4C4");

    ob6->setIdentificador(10);
    ob6->setNombre("Computadora");
    ob6->setLetra("PC");
    ob6->setColor("#C3DFC5");

    ob5->setIdentificador(1);
    ob5->setNombre("Puerta Doble");
    ob5->setLetra("PD");
    ob5->setColor("#C4C3C5");

    libreria->insertar(ob1);
    libreria->insertar(ob2);
    libreria->insertar(ob3);
    libreria->insertar(ob4);
    libreria->insertar(ob5);
    libreria->insertar(ob6);

    libreria->imprimir();

    cout << libreria->existe(9) << endl; //True = 1, False = 0
    cout << libreria->existe(1) << endl; //True = 1, False = 0

    Nodo_objeto* temp = libreria->encontrar(9);
    if(temp != NULL){
        temp->imprimirNodo();
        temp->setNombre("Mesa Temp"); //Modifica el objeto original
    }

    libreria->imprimir();

    cout << libreria->getGraphviz("Libreria") << endl;


    //Crear archivo .dot

    Archivo* archivo = new Archivo();
    archivo->generarEstructura("ABB_libreria","./archivos",libreria->getGraphviz("Libreria"));
    */
}

int main(){
    //Menus* m = new Menus();
    //m->encabezado();
    //m->menuPrincipal();

    test();
    //testJSON();

    return 0;

}




