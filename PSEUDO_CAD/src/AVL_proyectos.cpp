#include "AVL_proyectos.h"

AVL_proyectos::AVL_proyectos()
{
    //Constructor
    this->raiz = NULL;
    this->lista = NULL;
}

AVL_proyectos::~AVL_proyectos()
{
    //dtor
    delete this->raiz;
    delete this->lista;
}
