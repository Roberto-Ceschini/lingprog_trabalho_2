#include "Vertice.h"

#ifndef ARESTA_H
#define ARESTA_H
class Aresta {

    public:
        Aresta (Vertice*, Vertice*, float=1.0);

        Vertice* getVerticeOrigem();
        Vertice* getVerticeDestino();
        float getCusto();


    private:
        Vertice *verticeOrigem;
        Vertice *verticeDestino;
        float custo;

};

#endif