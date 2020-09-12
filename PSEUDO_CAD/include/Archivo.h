#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        void crarArchivo(string nombre, string ext, string ruta, string txt);
        void crearGrafo(string nombre, string ruta);
        void abrirImg(string nombre, string ruta);

        void generarEstructura(string nombre, string ruta, string txt);
        json leerJSON(string ruta);

    protected:

    private:
};

#endif // ARCHIVO_H
