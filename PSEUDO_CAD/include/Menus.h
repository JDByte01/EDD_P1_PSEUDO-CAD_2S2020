#ifndef MENUS_H
#define MENUS_H
#include <Nodo_objeto.h>

#include <iostream>

using namespace std;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */


class Menus
{
    public:
        Menus();
        virtual ~Menus();


        void limpiarVentana();
        void encabezado();
        void menuCargarLibrerias();
        void menuReportes();
        void menuPrincipal();


    private:
        //Flags
        bool flagMenuCargarLibreria = true;
        bool flagMenuPrincipal = true;
        bool flagMenuReportes = true;

        //Auxiliares
        char opMenu;
        string rutaJsonLib;

        //Estructuras


        //Test
        Nodo_objeto* objeto;

};

#endif // MENUS_H
