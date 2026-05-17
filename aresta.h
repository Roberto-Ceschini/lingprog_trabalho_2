#include "verticie.h"

using namespace std;

#ifndef ARESTA_H
#define ARESTA_H

class Aresta {

    public:
        Aresta (float, Verticie*, Verticie*);

        float getPeso();
        Verticie* getVertice1();
        Verticie* getVertice2();

    private:
        float peso;
        Verticie *vertice1;
        Verticie *vertice2;

};
#endif