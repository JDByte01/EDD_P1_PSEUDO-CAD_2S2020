#ifndef LISTA_NIVEL_H
#define LISTA_NIVEL_H

#include <Nodo_nivel.h>

#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

class Lista_nivel
{
    public:
        Lista_nivel();
        virtual ~Lista_nivel();

    protected:

    private:
        int size; //cantidad de niveles en el proyecto

        Nodo_nivel* inicio;
};

#endif // LISTA_NIVEL_H
