#include "arquivo.h"

#include <iostream>
#include <sstream>

using namespace std;

void Arquivo::abrirArquivo(string nome){
    arquivo.open(nome + ".txt", ios::in);
}

void Arquivo::fecharArquivo(){
    arquivo.close();
}

bool Arquivo::verificarArquivo(){
    return arquivo.is_open();
}

vector<Aresta*> Arquivo::lerArestas(){

    vector<Aresta*> arestas;
    unordered_map<string, Vertice*> vertices;
    string linha;

    while (getline(arquivo, linha)){

        if (linha.empty()){
            continue;
        }

        stringstream ss(linha);
        string nomeOrigem;
        string nomeDestino;
        float custo;

        ss >> nomeOrigem >> nomeDestino >> custo;

        //criar vertice origem se nao existir
        if (vertices.find(nomeOrigem) == vertices.end()){

            vertices[nomeOrigem] = new Vertice(nomeOrigem);
        }

        // criar vertice destino se nao existir
        if (vertices.find(nomeDestino) == vertices.end()){

            vertices[nomeDestino] =
                new Vertice(nomeDestino);
        }

        Vertice* origem = vertices[nomeOrigem];
        Vertice* destino = vertices[nomeDestino];

        Aresta* aresta = new Aresta(origem, destino, custo);

        arestas.push_back(aresta);
    }

    return arestas;
}