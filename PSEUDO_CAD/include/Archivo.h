#ifndef ARCHIVO_H
#define ARCHIVO_H


class Archivo
{
    public:
        Archivo();
        virtual ~Archivo();

        void crarArchivo(string nombre, string ext, string ruta, string txt);
        void crearGrafo(string nombre, string ruta);
        void abrirImg(string nombre, string ruta);

    protected:

    private:
};

#endif // ARCHIVO_H
