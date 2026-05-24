#include "grafo.h"
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

void Grafo::inserirAresta(Aresta* aresta) {
    //testar insercao de aresta
    if (aresta == nullptr) {
        cout << "Aresta nula nao pode ser inserida." << endl;
        return;
    }

    arestas.push_back(aresta);

    //atualizar matriz de adjacencia
    setVertices();
    setIndiceMatrizVertices();
    montarMatrizAdjacencia();
}

void Grafo::exibirMatrizAdjacencia() {

    if (arestas.empty()){
        cout << "Grafo vazio. Nao ha vertices ou arestas para exibir." << endl;
        return;
    }

    cout << "----MATRIZ DE ADJACENCIA---:" << endl;
    cout << setw(2) << "  ";

    for (Vertice* vertice : vertices) {
        cout << setw(3) << vertice->getNome() << " ";
    }
    cout << endl;

    for (size_t i = 0; i < vertices.size(); i++){
        cout << setw(2) << vertices[i]->getNome() << " ";
        for (size_t j = 0; j< vertices.size(); j++){
            cout << fixed << setprecision(1) << matrizAdjacencia[i][j] << " ";
        }
        cout << endl;
    }

}

void Grafo::exibirGrauVertices() {
    if (arestas.empty()){
        cout << "Grafo vazio. Nao ha vertices ou arestas para exibir." << endl;
        return;
    }

    unordered_map<Vertice*, int> grauVertices = calcularGrauVertices();
    
    cout << "----GRAU DOS VERTICES---:" << endl;
    for (Vertice* vertice : vertices){
        cout << "Vertice " << vertice->getNome() << ": Grau " << grauVertices[vertice] << endl;
    }

}


//Funcoes auxiliares --- MATRIZ DE ADJACENCIA
void Grafo::montarMatrizAdjacencia(){

    size_t numVertices = vertices.size();
    
    //inicializar matriz de adjacencia com 0s
    matrizAdjacencia = vector<vector<float>>(numVertices, vector<float>(numVertices, 0.0));

    //preencher matriz de adjacencia com os custos das arestas
    for (Aresta* aresta : arestas){
        Vertice* verticeOrigem = aresta->getVerticeOrigem();
        Vertice* verticeDestino = aresta->getVerticeDestino();
        float custo = aresta->getCusto();

        int indiceOrigem = indiceVertices[verticeOrigem];
        int indiceDestino = indiceVertices[verticeDestino];

        matrizAdjacencia[indiceOrigem][indiceDestino] = custo;
        matrizAdjacencia [indiceDestino][indiceOrigem] = custo;
    }

}

void Grafo::setVertices(){

    unordered_set<Vertice*> verticesUnicos;
    for (Aresta* aresta : arestas){

        Vertice* verticeOrigem = aresta->getVerticeOrigem();
        Vertice* verticeDestino = aresta->getVerticeDestino();
        verticesUnicos.insert(verticeOrigem);
        verticesUnicos.insert(verticeDestino);
    }
    
    vertices = vector<Vertice*>(verticesUnicos.begin(), verticesUnicos.end());
    
    //ordenar os vertices por nome para garantir ordem na matriz de adjacencia
    sort(vertices.begin(), vertices.end(), [](Vertice* v1, Vertice* v2) {
        return v1->getNome() < v2->getNome();
    });
    //o sort ordena os vertices por nome usando uma funcao lambda que compara os nomes dos vertices.
}

void Grafo::setIndiceMatrizVertices(){
    int indice = 0;
    for (Vertice* vertice : vertices){
        indiceVertices[vertice] = indice;
        indice++;
    }
}
//-----------------------------------------------------------------------------------------------------


//Funcoes auxiliares --- CALCULOS
float Grafo::calcularCustoCaminho(vector<Aresta*> arestas) {
    float custoTotal = 0.0;
    for (Aresta* aresta : arestas) {
        custoTotal += aresta->getCusto();
    }
    return custoTotal;
}

unordered_map<Vertice*, int> Grafo::calcularGrauVertices(){

    unordered_map<Vertice*, int> grauVertices;

    //contando o numero de linhas nao nulas para cada vertice na matriz de adjacencia
    for (size_t i = 0; i < vertices.size(); i++){
        for (size_t j = 0; j < vertices.size(); j++){
            if (matrizAdjacencia[i][j] != 0){
                grauVertices[vertices[i]]++;
            }
        }
    }
    
    return grauVertices;
}

//-----------------------------------------------------------------------------------------------------



