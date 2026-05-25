#include <iostream>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"

void menu(Grafo& grafo){

    int opcao = 0;

    while (opcao != 6){

        cout << endl;
        cout << "========== MENU ==========" << endl;
        cout << "1. Imprimir matriz de adjacencia" << endl;
        cout << "2. Imprimir grau dos vertices" << endl;
        cout << "3. Verificar se o grafo e conexo" << endl;
        cout << "4. Imprimir caminho mais curto entre dois vertices" << endl;
        cout << "5. Imprimir ordem de centralidade dos vertices" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opcao: ";

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

            case 4: {

                string nomeOrigem;
                string nomeDestino;

                Vertice* origem = nullptr;
                Vertice* destino = nullptr;

                cout << endl;
                cout << "Vertices disponiveis: [ ";

                for (Vertice* vertice : grafo.getVertices()){
                    cout << vertice->getNome() << " ";
                }

                cout << "]" << endl;

                // ORIGEM
                while (origem == nullptr){

                    cout << "Digite o vertice de origem: ";
                    cin >> nomeOrigem;

                    for (Vertice* vertice : grafo.getVertices()){

                        if (vertice->getNome() == nomeOrigem){
                            origem = vertice;
                            break;
                        }
                    }

                    if (origem == nullptr){
                        cout << "Vertice de origem nao encontrado." << endl;
                    }
                }

                // DESTINO
                while (destino == nullptr){

                    cout << "Digite o vertice de destino: ";
                    cin >> nomeDestino;

                    for (Vertice* vertice : grafo.getVertices()){

                        if (vertice->getNome() == nomeDestino){
                            destino = vertice;
                            break;
                        }
                    }

                    if (destino == nullptr){
                        cout << "Vertice de destino nao encontrado." << endl;
                    }
                }

                grafo.exibirCaminhoMaisCurto(origem, destino);

                break;
            }

            case 5:
                grafo.exibirOrdemDecrescenteCentralidade();
                break;

            case 6:
                cout << "Encerrando programa..." << endl;
                break;

            default:
                cout << "Opcao invalida." << endl;
                break;
        }
    }
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
    Aresta a5 = Aresta(&v1, &v4, 4.5);

    Grafo grafo;
    grafo.inserirAresta(&a1);
    grafo.inserirAresta(&a2);
    grafo.inserirAresta(&a3);
    grafo.inserirAresta(&a4);
    grafo.inserirAresta(&a5);
    menu(grafo);

    return 0;
}