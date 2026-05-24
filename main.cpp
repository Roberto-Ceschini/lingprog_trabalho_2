#include <iostream>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

void menu(){
    cout << "Menu:" << endl;
    cout << "1. Imprimir matriz de adjacencia" << endl;
    cout << "2. Imprimir grau dos vertices" << endl;
    cout << "3. Verificar se o grafo e conexo" << endl;
    cout << "4. Imprimir caminho mais curto entre dois vertices" << endl;
    cout << "5. Imprimir ordem de centralidade dos verices" << endl;
}

int main (){

    Vertice v1 = Vertice("A");
    Vertice v2 = Vertice("B");
    Vertice v3 = Vertice("C");
    Vertice v4 = Vertice("D");

    Aresta a1 = Aresta(&v1, &v2, 2.2);
    Aresta a2 = Aresta(&v2, &v3, 1.0);
    Aresta a3 = Aresta(&v3, &v4, 3.1);
    Aresta a4 = Aresta(&v3, &v3, 1.2);

    Grafo grafo;
    grafo.inserirAresta(&a1);
    //grafo.inserirAresta(&a2);
    grafo.inserirAresta(&a3);
    grafo.inserirAresta(&a4);

    menu();
    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            grafo.exibirMatrizAdjacencia();
            break;
        case 2:
            grafo.exibirGrauVertices();
            break;
        case 3:
            grafo.exibirGrafoAcessivel();
            break;

        default:
            cout << "Opcao invalida." << endl;
            break;
    }

    return 0;
}