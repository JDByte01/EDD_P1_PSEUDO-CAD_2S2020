#include <Lista_puntos.h>
#include <Nodo_objeto.h>

#include <iostream>

using namespace std;

/*
 * Author: KByteGt
 * Estructura de Datos
 * 2do Semestre 2020
 */

 //Variables
 bool flagMenuPrincipal = true;
 bool flagMenuCargarLibreria = true;

 char opMenu;

 string rutaJsonLib = "";

 Lista_puntos* puntos;
 Nodo_objeto* objeto;

void limpiarVentana(){
    system("cls");
    cin.clear();
}

void encabezado(){
    cout << " ___________________________________________________________" << endl;
    cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << " |%%%%%%%%%%%%%%%|  P S E U D O  -  C A D  |%%%%%%%%%%%%%%%|" << endl;
    cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
    cout << " |%%%%%%%|  Universidad De San Carlos De Guatemala |%%%%%%%|" << endl;
    cout << " |%%%%%%%|  Estructura de Datos                    |%%%%%%%|" << endl;
    cout << " |%%%%%%%|  Seccion A                              |%%%%%%%|" << endl;
    cout << " |%%%%%%%|  Jose Daniel Lopez Gonzalez             |%%%%%%%|" << endl;
    cout << " |%%%%%%%|  201503836                              |%%%%%%%|" << endl;
    cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
}

//===========================
//  Cargar librerias
//===========================

void menuCargarLibrerias(){
    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%| C A R G A R - L I B R E R I A S |%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  0. Regresar                      |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%|  Ruta del archivo JSON  |%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin >> rutaJsonLib;

        if(rutaJsonLib != "0"){
            cout << " | Ruta ingresada: " << rutaJsonLib << endl;

            system("pause");

            //Test
            objeto = new Nodo_objeto();
            objeto->setIdentificador(1);
            objeto->setNombre("prueba");
            objeto->setLetra("P");
            objeto->setColor("#C4C4C4");



            objeto->insertarPunto(10,10);
            objeto->insertarPunto(10,11);
            objeto->insertarPunto(11,10);
            objeto->insertarPunto(11,11);
            objeto->insertarPunto(12,1);
            objeto->insertarPunto(0,10);
            objeto->insertarPunto(0,1);


            objeto->imprimirNodo();
            objeto->getPuntos()->imprimir();

        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagMenuCargarLibreria = false;
        }

    }while(flagMenuCargarLibreria);
}

void menuPrincipal(){

    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%| M E N U |%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  1. Ver proyectos                 |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  2. Editar proyectos              |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  3. Cargar proyectos              |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  4. Graficar proyectos            |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  5. Guardar proyectos             |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  6. Cargar Librerias              |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|                                   |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  0. Salir                         |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%|  Escoja una opcion  |%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin.get(opMenu);

        switch(opMenu){
            case '1':
                //Ver proyectos
                cout << "Ver Proyectos" << endl;
                limpiarVentana();
                break;
            case '2':
                //Editar proyectos
                limpiarVentana();
                break;
            case '3':
                //Cargar proyectos
                limpiarVentana();
                break;
            case'4':
                //Graficar proyectos
                limpiarVentana();
                break;
            case '5':
                //Guardar proyectos
                limpiarVentana();
                break;
            case '6':
                //Cargar librerias
                limpiarVentana();
                menuCargarLibrerias();
                break;
            case '0':
                flagMenuPrincipal = false;
                //Salir
                break;
            default:
                limpiarVentana();
                break;
        }

    } while(flagMenuPrincipal);
}


//========================
//      Main()
//========================

int main()
{
    encabezado();
    menuPrincipal();
    return 0;

}




