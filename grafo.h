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
        vector<Vertice*> getVertices(); 
        void exibirMatrizAdjacencia(); //funcao 1
        void exibirGrauVertices(); //funcao 2
        void exibirGrafoAcessivel(); //funcao 3
        void exibirCaminhoMaisCurto(Vertice*, Vertice*); //funcao 4
        void exibirOrdemDecrescenteCentralidade(); //funcao 5

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

        //---FUNCOES AUXILIARES CAMINHO MAIS CURTO---
        //funcao para executar o algoritmo de Dijkstra e retornar os predecessores de cada vertice no caminho mais curto
        //recebe o vertice de origem e um mapa para armazenar as distancias minimas de cada vertice a origem
        unordered_map<Vertice*, vector<Vertice*>>dijkstra(Vertice*, unordered_map<Vertice*, float>&);

        //funcao para reconstruir os caminhos mais curtos a partir do mapa de predecessores gerado pelo Dijkstra
        //recebe o vertice de destino, o mapa de predecessores, um vetor para armazenar o caminho atual e um vetor para armazenar todos os caminhos minimos encontrados
        void reconstruirCaminhos(Vertice*, Vertice* , unordered_map<Vertice*, vector<Vertice*>>&, vector<Vertice*>&, vector<vector<Vertice*>>&);

        //funcao para obter os caminhos mais curtos entre a origem e o destino, chamando o Dijkstra e a funcao de reconstruir caminhos
        //recebe o vertice de origem e destino e retorna um vetor de vetores, onde cada vetor interno representa um caminho minimo encontrado
        vector<vector<Vertice*>> obterCaminhosMinimos(Vertice*, Vertice*);

        //---FUNCOES AUXILIARES CALCULOS---
        float calcularCustoCaminho(vector<Aresta*>);
        unordered_map<Vertice*, int> calcularGrauVertices();
};

#endif