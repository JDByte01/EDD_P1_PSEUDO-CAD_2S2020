#ifndef NODO_MATRIZ_H
#define NODO_MATRIZ_H


class Nodo_matriz
{
    public:
        Nodo_matriz();
        virtual ~Nodo_matriz();
         //Get
        string getLetra(){ return this->letra; }
        string getColor(){ return this->color; }
        int getX(){ return this->x; }
        int getY(){ return this->y; }
        Nodo_matriz* getArriba(){ return this->arriba; }
        Nodo_matriz* getAbajo(){ return this->abajo; }
        Nodo_matriz* getDerecha(){ return this->derecha; }
        Nodo_matriz* getIzquierda(){ return this->izquierda; }
        //Set
        void setLetra(string letra)

        //Otros
        string getNodoGraphviz();
        string getRutaGraphviz();

    protected:

    private:
        string letra;
        string color;
        int x;
        int y;

        Nodo_matriz* arriba;
        Nodo_matriz* abajo;
        Nodo_matriz* derecha;
        Nodo_matriz* izquierda;


};

#endif // NODO_MATRIZ_H
