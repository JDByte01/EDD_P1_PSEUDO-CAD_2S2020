#include <Lista_puntos.h>
#include <Nodo_objeto.h>
#include <Menus.h>

//Test
#include <ABB_Lib.h>
#include <Nodo_objeto.h>
#include <Matriz_nivel.h>
#include <Nodo_matriz.h>

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
    //Probar matiz dispersa
    string ruta = "C:/Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/Niveles.json";

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
}

int main(){
    //Menus* m = new Menus();
    //m->encabezado();
    //m->menuPrincipal();

    test();
    //testJSON();

    return 0;

}




