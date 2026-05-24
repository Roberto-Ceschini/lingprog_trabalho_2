#include <vector>
#include "Aresta.h"
#include <unordered_set>
#include <unordered_map>
#ifndef GRAFO_H
#define GRAFO_H

using namespace std;

class Grafo{

    public:
        
        void inserirAresta(Aresta*);
        void exibirMatrizAdjacencia(); //funcao 1
        void exibirGrauVertices(); //funcao 2
        void exibirGrafoAcessivel(); //funcao 3
        void exibirCaminhoMaisCurto(Vertice*, Vertice*); //funcao 4

    private:
        vector<Aresta*> arestas;
        vector<vector<float>> matrizAdjacencia; //matriz de adjacencia do grafo

        //---ATRIBUTOS AUXILIARES MATRIZ DE ADJACENCIA---
        vector <Vertice*> vertices;
        unordered_map<Vertice*, int> indiceVertices; //mapa para associar cada vertice a um indice na matriz de adjacencia

        //---FUNCOES AUXILIARES MATRIZ DE ADJACENCIA---
        void montarMatrizAdjacencia(); //funcao para montar a matriz de adjacencia a partir dos vertices e arestas do grafo
        void setVertices(); //funcao para extrair os vertices unicos do grafo a partir das arestas e armazenar no conjunto vertices
        void setIndiceMatrizVertices(); //funcao para associar cada vertice um indice na matriz de adjacencia

        //---FUNCOES AUXILIARES GRAFO ACESSIVEL ---
        vector<Vertice*> obterVizinhos(Vertice* vertice);
        void dfs(Vertice*, unordered_map<Vertice*, bool>&);
        bool isAcessivel(); //funcao para verificar se o grafo e acessivel por DFS

        //---FUNCOES AUXILIARES CALCULOS---
        float calcularCustoCaminho(vector<Aresta*>);
        unordered_map<Vertice*, int> calcularGrauVertices();
};

#endif