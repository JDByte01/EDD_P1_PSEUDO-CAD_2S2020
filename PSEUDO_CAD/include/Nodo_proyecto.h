#ifndef NODO_PROYECTO_H
#define NODO_PROYECTO_H


class Nodo_proyecto
{
    public:
        Nodo_proyecto();
        virtual ~Nodo_proyecto();

    protected:

    private:
        int id;
        int altura;

        Nodo_proyecto* izquierda;
        Nodo_proyecto* derecha;
};

#endif // NODO_PROYECTO_H
