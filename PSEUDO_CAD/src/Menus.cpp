#include "Menus.h"

Menus::Menus()
{
    limpiarVentana();
}

Menus::~Menus()
{
    //dtor
}

void Menus::limpiarVentana(){
    system("cls");
    cin.clear();
}

void Menus::encabezado(){
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

void Menus::menuCargarLibrerias(){
    this->flagMenuCargarLibreria = true;
    this->rutaJsonLib = "";
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



        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagMenuCargarLibreria = false;
        }

    }while(flagMenuCargarLibreria);
}

void Menus::menuReportes(){
    this->flagMenuReportes = true;
    this->opMenu = ' ';
    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%| R E P O R T E S |%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%|  1. Arbol AVL de proyectos                      |%%%|" << endl;
        cout << " |%%%|  2. Arbol Binario de librerias                  |%%%|" << endl;
        cout << " |%%%|  3. Proyectos ordenados por nivel (ASC)         |%%%|" << endl;
        cout << " |%%%|  4. Proyectos ordenados por nivel (DESC)        |%%%|" << endl;
        cout << " |%%%|  5. Seleccionar proyecto                        |%%%|" << endl;
        cout << " |%%%|                                                 |%%%|" << endl;
        cout << " |%%%|  0. Regresar                                    |%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%|  Escoja una opcion  |%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin.get(opMenu);
        switch(opMenu){
            case '1':
                //Reporte AVL de proyectos
                break;
            case '2':
                //Reporte Arbol binario de librerias
                break;
            case '3':
                //Reporte de proyectos ordenados por nivel (ASC)
                break;
            case '4':
                //Reporte de proyectos ordenados por nivel (DESC)
                break;
            case '5':
                //Escoger proyecto para más reportes
                break;
            case '0':
                //Regresar
                flagMenuReportes = false;
                break;
            default:
                flagMenuReportes = true;
                break;
        }
    }while(flagMenuReportes);
}

void Menus::menuPrincipal(){
    this->flagMenuPrincipal = true;
    this->opMenu = ' ';

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
        cout << " |%%%%%%%%%%|  7. Reportes                      |%%%%%%%%%%|" << endl;
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
            case '7':
                //Cargar librerias
                limpiarVentana();
                menuReportes();
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
