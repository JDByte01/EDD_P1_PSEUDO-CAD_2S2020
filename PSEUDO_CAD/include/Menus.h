#ifndef MENUS_H
#define MENUS_H
#include <Nodo_objeto.h>
#include <nlohmann/json.hpp>
#include <Archivo.h>
#include <ABB_Lib.h>
#include <Matriz_nivel.h>
#include <Nodo_matriz.h>
#include <ABB_nivel.h>
#include <Nodo_nivel.h>
#include <Lista_nivel.h>
#include <Nodo_proyecto.h>
#include <AVL_proyectos.h>
#include <Nodo_lista.h>
#include <Lista_proyectos.h>

#include <iostream>

using namespace std;
using json = nlohmann::json;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

//Ruta Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/
class Menus
{
    public:
        Menus();
        virtual ~Menus();

        void limpiarVentana();
        void encabezado();
        void menuCargarLibrerias();
        void menuCargarProyecto();
        void menuNuevoProyecto();
        void menuVerProyectos();
        void menuEditarProyecto();

        void menuEditar(Nodo_proyecto* n);
        void agregarNivel(Nodo_proyecto* n);
        void eliminarNivel(Nodo_proyecto* n);
        void eliminarProyecto(int id);
        void cargarJsonNivel(Nodo_proyecto* n);

        void menuReportes();
        void menuPrincipal();


    private:
        //Flags
        bool flagMenuCargarLibreria = true;
        bool flagMenuCargarProyecto = true;
        bool flagEditarProyecto = true;
        bool flagNuevoProyecto = true;
        bool flagMenuPrincipal = true;
        bool flagMenuReportes = true;
        bool flagVerProyecto = true;
        bool flagMenuEditar = true;
        bool flagAgregarNivel = true;
        bool flagEliminarNivel = true;


        //Auxiliares
        char opMenu;
        string rutaJsonLib;
        string rutaJsonPry;
        string nombreProyecto;
        int idNivel;
        int idPry;

        //Estructuras
        Archivo* archivo;
        ABB_lib* librerias;
        AVL_proyectos* proyectos;


        //Test
        Nodo_objeto* objeto;

};

#endif // MENUS_H
