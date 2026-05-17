#include "aresta.h"

Aresta::Aresta(float _peso, Verticie* _vertice1, Verticie* _vertice2) : peso(_peso), vertice1(_vertice1), vertice2(_vertice2) {}

float Aresta::getPeso() {
    return peso;
}

Verticie* Aresta::getVertice1() {
    return vertice1;
}

Verticie* Aresta::getVertice2() {
    return vertice2;
}

