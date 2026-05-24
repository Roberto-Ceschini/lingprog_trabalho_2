#include "aresta.h"
#include <iostream>

Aresta::Aresta(Vertice* verticeOrigem, Vertice* verticeDestino, float custo)  {

         if (custo <= 0){
            cout << "Aresta invalida: custo deve ser positivo. Normalizando custo 1.0" << endl;
            custo = 1.0;
        }

        if (verticeDestino == verticeOrigem){
            cout << "Aresta invalida: vertice de origem e destino sao iguais." << endl;
            custo = 0.0;
        }

        this->verticeOrigem = verticeOrigem;
        this->verticeDestino = verticeDestino;
        this->custo = custo;
    }

Vertice* Aresta::getVerticeOrigem() {
    return this->verticeOrigem;
}

Vertice* Aresta::getVerticeDestino() {
    return this->verticeDestino;
}

float Aresta::getCusto() {
    return this->custo;
}