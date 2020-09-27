#include "Menus.h"


//Ruta Users/JOSED/source/repos/EDD_P1_PSEUDO-CAD_2S2020/entradas/
Menus::Menus()
{
    //Estructuras
    archivo = new Archivo();
    librerias = new ABB_lib();
    proyectos = new AVL_proyectos();

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
        cout << " |> C:/ ";
        cin >> rutaJsonLib;

        if(rutaJsonLib != "0"){
            rutaJsonLib = "C:/" + rutaJsonLib;
            cout << " | Ruta ingresada: " << rutaJsonLib << endl;

            if(archivo->existe(rutaJsonLib)){
                //Existe el archivo
                librerias->cargarJSON(archivo->leerJSON(rutaJsonLib));

                //Regresar a menu principal
                system("pause");
                flagMenuCargarLibreria = false;
            } else {
                //No existe el archivo
                cout << " |> **ERROR: Ruta incorrecta..." << endl;
            }
        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagMenuCargarLibreria = false;
        }

    }while(flagMenuCargarLibreria);
}

void Menus::menuCargarProyecto(){
    this->flagMenuCargarProyecto = true;
    this->rutaJsonPry = "";
    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%| C A R G A R  -  P R O Y E C T O |%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  0. Regresar                      |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%|  Ruta del archivo JSON  |%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> C:/ ";
        cin >> rutaJsonPry;

        if(rutaJsonPry != "0"){
            rutaJsonPry = "C:/" + rutaJsonPry;
            cout << " | Ruta ingresada: " << rutaJsonPry << endl;

            if(archivo->existe(rutaJsonPry)){
                //Existe el archivo
                proyectos->cargarJSON(archivo->leerJSON(rutaJsonPry));

                //Regresar a menu principal
                system("pause");
                flagMenuCargarProyecto = false;
            } else {
                //No existe el archivo
                cout << " |> **ERROR: Ruta incorrecta..." << endl;
            }
        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagMenuCargarLibreria = false;
        }

    }while(flagMenuCargarProyecto);
}

void Menus::menuNuevoProyecto(){
    this->flagNuevoProyecto = true;
    this->nombreProyecto = "";
    do {
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%|  N U E V O  -  P R O Y E C T O  |%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  0. Regresar                      |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  Nombre del nuevo proyecto        |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin >> nombreProyecto;

        if(nombreProyecto != "0"){
            //Crear un nuevo proyecto
            proyectos->insertar(nombreProyecto);
            cout << " |-> Proyecto creado con exito!" << endl;

            //Regresar a menu principal
            system("pause");
            flagNuevoProyecto = false;
        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagNuevoProyecto = false;
        }
    } while(flagNuevoProyecto);
}

void Menus::menuVerProyectos(){
    this->flagVerProyecto = true;
    this->idPry = 0;

    do {
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  V  E  R - P  R  O  Y  E  C  T  O |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%| 0. Regresar" << endl;
        proyectos->imprimir();
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%|  Ingresar Id del proyecto a ver                 |%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin >> idPry;

        if(idPry != 0){
            cout << " |%%%| Proyecto (" << to_string(idPry) << ") seleccionado" << endl;
            Nodo_proyecto* temp = proyectos->buscar(idPry);

            if(temp != NULL){
                temp->generarNiveles();
            } else {
                cout << " |%%%| **Proyecto no existe" << endl;
            }

            //Regresar a menu principal
            system("pause");
            flagVerProyecto = false;
        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagVerProyecto = false;
        }
    }while(flagVerProyecto);
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
                if(!proyectos->estaVacio()){
                    archivo->generarEstructura("AVL_Proyectos", proyectos->getGraphviz("Proyectos"));
                } else {
                    cout << " | AVL - Proyectos esta vacio..." << endl;
                }

                system("pause");
                flagMenuReportes = false;
                break;
            case '2':
                //Reporte Arbol binario de librerias
                if(!librerias->estaVacio()){
                    archivo->generarEstructura("ABB_Librerias", librerias->getGraphviz("Librerias"));
                } else {
                    cout << " | ABB - Librerias esta vacio..." << endl;
                }

                system("pause");
                flagMenuReportes = false;
                break;
            case '3':
                //Reporte de proyectos ordenados por nivel (ASC)
                if(!proyectos->estaVacio()){
                    proyectos->imprimirListaAZ();
                } else {
                    cout << " | AVL - Proyectos esta vacio..." << endl;
                }

                system("pause");
                flagMenuReportes = false;
                break;
            case '4':
                //Reporte de proyectos ordenados por nivel (DESC)
                if(!proyectos->estaVacio()){
                    proyectos->imprimirListaZA();
                } else {
                    cout << " | AVL - Proyectos esta vacio..." << endl;
                }

                system("pause");
                flagMenuReportes = false;
                break;
            case '5':
                //Escoger proyecto para más reportes
                break;
            case '0':
                //Regresar
                flagMenuReportes = false;
                break;
            default:
                limpiarVentana();
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
        cout << " |%%%%%%%%%%|  6. Crear nuevo proyecto          |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  7. Cargar Librerias              |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  8. Reportes                      |%%%%%%%%%%|" << endl;
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
                limpiarVentana();
                menuVerProyectos();
                break;
            case '2':
                //Editar proyectos
                limpiarVentana();
                break;
            case '3':
                //Cargar proyectos
                limpiarVentana();
                menuCargarProyecto();
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
                //Crear Nuevo Proyecto
                limpiarVentana();
                menuNuevoProyecto();
                break;
            case '7':
                //Cargar librerias
                limpiarVentana();
                menuCargarLibrerias();
                break;
            case '8':
                //Reportes
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
