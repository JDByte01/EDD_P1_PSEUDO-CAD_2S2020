#include "Matriz_nivel.h"

Matriz_nivel::Matriz_nivel()
{
    //ctor
}

Matriz_nivel::~Matriz_nivel()
{
    //dtor
    delete this->headers;
}

/** \brief agrega un punto en la matriz
 *
 * \param int x
 * \param int y
 * \param string letra
 * \param string color
 * \return void
 *
 */

void Matriz_nivel::agregarPunto(int x, int y, string letra, string color){

}

/** \brief verifica si existe el punto en la matriz
 *
 * \param int x
 * \param int y
 * \return bool, true = existe | false = no existe
 *
 */

 bool Matriz_nivel::existePunto(int x, int y){

 }

 /** \brief Busca el id del objeto en la matriz
  *
  * \param int x
  * \param int y
  * \return int id del objeto
  *
  */

  int Matriz_nivel::getIdPunto(int x, int y){

  }

  /** \brief Obtiene la estructura de la matriz para graficar
   *
   * \param string nombre
   * \return string dot
   *
   */

string Matriz_nivel::getGraphviz(string nombre){

}

/** \brief agregar el punto x en el header
 *
 * \param int x
 * \return void
 *
 */

 void Matriz_nivel::agregarEjeX(int x){

 }

  /** \brief agregar el punto y en el header
   *
   * \param int y
   * \return void
   *
   */

   void Matriz_nivel::agregarEjeY(int y){

   }




