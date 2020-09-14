#ifndef ABB_NIVEL_H
#define ABB_NIVEL_H

#include <Matriz_nivel.h>
#include <Nodo_coordenada.h>

#include <ABB_lib.h>


class ABB_nivel : public ABB_lib
{
    public:
        ABB_nivel();
        virtual ~ABB_nivel();
        ABB_nivel(const ABB_nivel& other);

        bool eliminar(int id);

        void generarMatriz(Matriz_nivel* m);

    protected:

    private:

        bool eliminar(Nodo_objeto* raiz, int id);
        void generarMatriz(Matriz_nivel*m, Nodo_objeto* raiz);
};

#endif // ABB_NIVEL_H
