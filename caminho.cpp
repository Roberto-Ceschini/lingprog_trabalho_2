#include "caminho.h"
#include <iostream>

void Caminho::setAresta(Aresta *aresta) {
    if (verificarInsercao(aresta)) {
        arestas.push_back(aresta);
    }
}

bool Caminho::verificarInsercao(Aresta *aresta) {
    if (arestas.empty()) {
        return true;
    }

    Aresta *ultimaAresta = arestas.back();
    Verticie *vertice2 = ultimaAresta->getVertice2();

    if (aresta->getVertice1() == vertice2) {
        return true;
    }

    return false;
}

void Caminho::imprimirCaminho() {
   for (Aresta *aresta : arestas) {
        Verticie *verticie1 = aresta->getVertice1();
        Verticie *verticie2 = aresta->getVertice2();

        cout << verticie1->getNome() << " -(" << aresta->getPeso() << ")-> " << verticie2->getNome() << endl;
   }

   cout << "Custo total: " << calcularCusto() << endl;
}

 float Caminho::calcularCusto(){

    float custoTotal = 0;

    for (Aresta *aresta : arestas){
        custoTotal += aresta->getPeso();
    }

    return custoTotal;
}

