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
    system("dot -Tjpeg" + ruta + "\\" + nombre + ".dot -o" + ruta + "\\" + nombre + ".jpeg");
}

void Archivo::abrirImg(string nombre, string ruta){
    system("nohup display" + ruta + "\\" + nombre + ".jpeg &");
}
