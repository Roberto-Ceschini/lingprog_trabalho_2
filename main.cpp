#include <iostream>
#include "verticie.h"
#include "aresta.h"
#include "caminho.h"

int main() {
    Verticie verticeA("A");
    Verticie verticeB("B");
    Verticie verticeC("C");

    Aresta arestaAB(1.5, &verticeA, &verticeB);
    Aresta arestaBC(2.0, &verticeB, &verticeC);
    Aresta arestaAC(2.5, &verticeA, &verticeC);

    Caminho caminho;
    caminho.setAresta(&arestaAB);
    caminho.setAresta(&arestaBC);
    caminho.setAresta(&arestaAC); // Esta aresta não será adicionada ao caminho

    caminho.imprimirCaminho();

    return 0;
}