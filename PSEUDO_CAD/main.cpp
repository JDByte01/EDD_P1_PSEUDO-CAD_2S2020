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
    //Probar matiz dispersa
}

int main(){
    //Menus* m = new Menus();
    //m->encabezado();
    //m->menuPrincipal();

    test();
    //testJSON();

    return 0;

}




