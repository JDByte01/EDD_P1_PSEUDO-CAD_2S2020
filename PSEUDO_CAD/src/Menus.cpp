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
            flagMenuCargarProyecto = false;
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

void Menus::menuEditarProyecto(){
    this->flagEditarProyecto = true;
    this->idPry = 0;

    do {
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%|  E D I T A T    P  R  O  Y  E  C  T  O  |%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%| 0. Regresar" << endl;
        proyectos->imprimir();
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%|  Ingresar Id del proyecto a editar              |%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin >> idPry;

        if(idPry != 0){
            cout << " |%%%| Proyecto (" << to_string(idPry) << ") seleccionado" << endl;
            Nodo_proyecto* temp = proyectos->buscar(idPry);

            if(temp != NULL){
                menuEditar(temp);
            } else {
                cout << " |%%%| **Proyecto no existe" << endl;
            }

            //Regresar a menu principal
            system("pause");
            flagVerProyecto = false;
        } else {
            //Regresar al ménu principal
            limpiarVentana();
            flagEditarProyecto = false;
        }
    }while(flagEditarProyecto);
}

void Menus::menuEditar(Nodo_proyecto* n){
    this->flagMenuEditar = true;

    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|    M E N U  -  P R O Y E C T O    |%%%%%%%%1%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  1. Agregar nivel                 |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  2. Editar nivel                  |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  3. Eliminar nivel                |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  4. Eliminar proyecto             |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  5. Cargar JSON                   |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|                                   |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  0. Regresar                      |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%|  Escoja una opcion  |%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin.get(opMenu);

        switch(opMenu){
            case '1':
                //Agregar Nivel al proyecto
                agregarNivel(n);
                limpiarVentana();
                break;
            case '2':
                //Editar Nivel
                break;
            case '3':
                //Eliminar Nivel
                eliminarNivel(n);
                limpiarVentana();
                break;
            case '4':
                //Eliminar proyecto
                eliminarProyecto(n->getId());
                limpiarVentana();
                break;
            case '5':
                //Cargar JSON
                cargarJsonNivel(n);
                limpiarVentana();
                break;
            case '0':
                //Regresar
                flagEditarProyecto = false;
                break;
            default:
                limpiarVentana();
                break;
        }
    } while(flagEditarProyecto);
}

void Menus::agregarNivel(Nodo_proyecto*n ){
    this->flagAgregarNivel = true;
    this->opMenu = '0';

    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  Agregar un nivel al proyecto     |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  1. Confirmar, 0. Cancelar        |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin.get(opMenu);

        if(opMenu != '0'){
            if(opMenu == '1'){
                n->agregarNivel(n->sizeNiveles() +1);

                cout << " |%%%|-> Nivel agregado con exito..." << endl;

                system("pause");
                flagAgregarNivel = false;
            } else {
                cout << " |%%%| **Error: caracter invalido" << endl;
            }

        } else {
            flagAgregarNivel = false;
        }

    } while(flagAgregarNivel);
}

void Menus::eliminarNivel(Nodo_proyecto* n){
    this->flagEliminarNivel = true;
    this->idNivel = 0;

    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%|       E L I M I N A R   N I V E L       |%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%| 0. Regresar" << endl;
        n->imprimirNiveles();
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%|  Ingresar el numero del nivel a eliminar        |%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin >> idNivel;

        if(idNivel != 0){
            //if(isdigit(idNivel)){
                n->eliminarNivel(idNivel);

                system("pause");
                flagEliminarNivel = false;
            //} else {
             //   cout << " |%%%| **Error: caracter invalido" << endl;
            //}
        } else {
            //Regresar
            flagEliminarNivel = false;
        }
    } while(flagEliminarNivel);
}

void Menus::eliminarProyecto(int id){
    this->flagEliminarNivel = true;
    this->opMenu == '0';
    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%|    E L I M I N A R   P R O Y E C T O    |%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%|     1. Confirmar, 0. Cancelar           |%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |> ";
        cin.get(opMenu);

        if(opMenu == '1'){
            //Eliminar proyecto
            if(proyectos->eliminar(id)){
                cout << " |%%%|-> Proyecto eliminado con exito" << endl;
                this->flagEditarProyecto = false;
            } else {
                cout << " |%%%|-> No se pudo eliminar el proyecto" << endl;
            }
            flagEliminarNivel = false;
            system("pause");
        } else if(opMenu == '0'){
            flagEliminarNivel = false;
        }

    } while(flagEliminarNivel);

}

void Menus::cargarJsonNivel(Nodo_proyecto* n){
    this->flagMenuCargarLibreria = true;
    this->rutaJsonLib = "";
    do{
        cout << " ___________________________________________________________" << endl;
        cout << " |%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%%|   C A R G A R - N I V E L E S   |%%%%%%%%%%%|" << endl;
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
                n->cargarJSON(archivo->leerJSON(rutaJsonLib));

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
                    proyectos->llenarLista();
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
                    proyectos->llenarLista();
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
        cout << " |%%%%%%%%%%|  4. Guardar proyectos             |%%%%%%%%%%|" << endl;
        cout << " |%%%%%%%%%%|  5. Crear nuevo proyecto          |%%%%%%%%%%|" << endl;
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
                limpiarVentana();
                menuVerProyectos();
                break;
            case '2':
                //Editar proyectos
                limpiarVentana();
                menuEditarProyecto();
                break;
            case '3':
                //Cargar proyectos
                limpiarVentana();
                menuCargarProyecto();
                break;
            case '4':
                //Guardar proyectos
                limpiarVentana();
                break;
            case '5':
                //Crear Nuevo Proyecto
                limpiarVentana();
                menuNuevoProyecto();
                break;
            case '6':
                //Cargar librerias
                limpiarVentana();
                menuCargarLibrerias();
                break;
            case '7':
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
