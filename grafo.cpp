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

void Grafo::exibirGrafoAcessivel() {
    if (arestas.empty()){
        cout << "Grafo vazio. Nao ha vertices ou arestas para exibir." << endl;
        return;
    }

    cout << "----GRAFO ACESSIVEL---:" << endl;
    if (isAcessivel()){
        cout << "O grafo e acessivel. Todos os vertices estao conectados." << endl;
    } else {
        cout << "O grafo nao e acessivel. Existem vertices isolados ou desconectados." << endl;
    }

    cout << endl;
    exibirMatrizAdjacencia();
}

void Grafo::exibirCaminhoMaisCurto(Vertice* verticeOrigem, Vertice* verticeDestino) {
    //implementar algoritmo de Dijkstra para encontrar o caminho mais curto entre verticeOrigem e verticeDestino
    //utilizar a matriz de adjacencia para obter os custos das arestas
    //imprimir o caminho encontrado e seu custo total

    
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

//Funcoes auxiliares --- DFS
vector<Vertice*> Grafo::obterVizinhos(Vertice* vertice) {

    vector<Vertice*> vizinhos;

    int indiceVertice = indiceVertices[vertice];

    for (size_t j = 0; j < vertices.size(); j++){
        if (matrizAdjacencia[indiceVertice][j] != 0){
            vizinhos.push_back(vertices[j]);
        }
    }
    return vizinhos;
}

void Grafo::dfs(Vertice* vertice, unordered_map<Vertice*, bool>& visitados) {
    //marca o vertice como visitado
    visitados[vertice] = true;

    vector<Vertice*> vizinhos = obterVizinhos(vertice);

    for (Vertice* vizinho : vizinhos) {
        // se ainda nao foi visitado, continua a DFS
        if (!visitados[vizinho]) {
            dfs(vizinho, visitados);
        }
    }
}

bool Grafo::isAcessivel(){
 
    unordered_map<Vertice*, bool> visitados;
    
    for (Vertice* vertice : vertices) {
        visitados[vertice] = false;
    }

    Vertice* partida = vertices[0];

    dfs(partida, visitados);

    for (Vertice* vertice : vertices) {
        if (!visitados[vertice]) {
            return false; // achou alguem isolado
        }
    }

    return true; // todos foram visitados
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



