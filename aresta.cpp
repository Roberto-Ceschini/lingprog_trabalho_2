#include "aresta.h"

Aresta::Aresta(Vertice* verticeOrigem, Vertice* verticeDestino, float custo) 
    : verticeOrigem(verticeOrigem), verticeDestino(verticeDestino), custo(custo) {}

Vertice* Aresta::getVerticeOrigem() {
    return this->verticeOrigem;
}

Vertice* Aresta::getVerticeDestino() {
    return this->verticeDestino;
}

float Aresta::getCusto() {
    return this->custo;
}