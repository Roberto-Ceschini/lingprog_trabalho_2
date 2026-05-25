#include <iostream>
#include "vertice.h"
#include "aresta.h"
#include "grafo.h"
#include "arquivo.h"

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


int main(){

    //inicializar grafo a partir do arquivo
    Arquivo arquivo;
    Grafo grafo;
    vector<Aresta*> arestas;

    arquivo.abrirArquivo("arestas");

    if (!arquivo.verificarArquivo()){
        cout << "Erro ao abrir arquivo."<< endl;
        return 1;
    }

    arestas = arquivo.lerArestas();
    arquivo.fecharArquivo();

    for (Aresta* aresta : arestas){
        grafo.inserirAresta(aresta);
    }

    menu(grafo);

    return 0;
}