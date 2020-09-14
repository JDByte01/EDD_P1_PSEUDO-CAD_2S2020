#ifndef ABB_NIVEL_H
#define ABB_NIVEL_H

#include <ABB_lib.h>


class ABB_nivel : public ABB_lib
{
    public:
        ABB_nivel();
        virtual ~ABB_nivel();
        ABB_nivel(const ABB_nivel& other);

        bool eliminar(int id);

        void cargarJSON_Nivel(json lib);

    protected:

    private:

        bool eliminar(Nodo_objeto* raiz, int id);
};

#endif // ABB_NIVEL_H
