#include "Archivo.h"

Archivo::Archivo()
{
    //ctor
}

Archivo::~Archivo()
{
    //dtor
}


void Archivo::crarArchivo(string nombre, string ext, string ruta, string txt){
    //Crar archivo
    ofstream fs(ruta + "\\" + nombre + "." + ext);

    fs << txt << endl;
    fs.close();
}

void Archivo::crearGrafo(string nombre, string ruta){
    system(("dot -Tjpeg" + ruta + "\\" + nombre + ".dot -o" + ruta + "\\" + nombre + ".jpeg").c_str());
}

void Archivo::abrirImg(string nombre, string ruta){
    system(("nohup display" + ruta + "\\" + nombre + ".jpeg &").c_str());
}


/** \brief Generar grafica de estructuras
 *
 * \param string nombre del archivo
 * \param string ruta, carpeta
 * \param string txt, contenido del archivo
 * \return
 *
 */

void Archivo::generarEstructura(string nombre, string ruta, string txt){
    //Crear archivo
    string archivo = ruta + "//" + nombre;

    cout << "Generando archivo .dot" << endl;

    ofstream fs(archivo + ".dot");
    fs << txt << endl;
    fs.close();

    cout << "Compilando dot a JPEG" << endl;

    system(("dot -Tjpeg " + archivo + ".dot -o " + archivo + ".jpeg").c_str());

    cout << "Abriendo imagen...." << endl;

    //system(("nohup display " + archivo + ".jpeg &").c_str());
    system(("display " + ruta + "\\" + nombre + " &").c_str());
}

/** \brief Leer archivo JSON
 *
 * \param string ruta del archivo JSON
 * \return JSON
 *
 */

json Archivo::leerJSON(string ruta){
    //Leer archivo
    ifstream r(ruta);
    json j;
    r >> j;
    r.close();

    return j;
}
