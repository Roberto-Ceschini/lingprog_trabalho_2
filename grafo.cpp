#include "grafo.h"
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <limits>

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

unordered_map<Vertice*, vector<Vertice*>> Grafo::dijkstra (Vertice* origem, unordered_map<Vertice*, float>& distancias){

    unordered_map<Vertice*, bool> visitados;
    unordered_map<Vertice*, vector<Vertice*>> anteriores;

    // inicializacao
    for (Vertice* vertice : vertices){

        distancias[vertice] =
            numeric_limits<float>::infinity();

        visitados[vertice] = false;
    }

    distancias[origem] = 0;

    // dijkstra
    for (size_t i = 0; i < vertices.size(); i++){

        Vertice* atual = nullptr;

        float menorDistancia =
            numeric_limits<float>::infinity();

        // procurar menor nao visitado
        for (Vertice* vertice : vertices){

            if (!visitados[vertice] && distancias[vertice] < menorDistancia){

                menorDistancia = distancias[vertice];
                atual = vertice;
            }
        }

        if (atual == nullptr){
            break;
        }

        visitados[atual] = true;

        vector<Vertice*> vizinhos =obterVizinhos(atual);

        for (Vertice* vizinho : vizinhos){

            int indiceAtual = indiceVertices[atual];
            int indiceVizinho = indiceVertices[vizinho];
            float custo =matrizAdjacencia[indiceAtual][indiceVizinho];
            float novaDistancia = distancias[atual] + custo;

            // caminho melhor
            if (novaDistancia < distancias[vizinho]){

                distancias[vizinho] = novaDistancia;

                anteriores[vizinho].clear();

                anteriores[vizinho].push_back(atual);
            }

            // caminho empatado
            else if (novaDistancia == distancias[vizinho]){
                anteriores[vizinho]
                    .push_back(atual);
            }
        }
    }

    return anteriores;
}

void Grafo::reconstruirCaminhos(Vertice* atual, Vertice* origem, unordered_map<Vertice*, vector<Vertice*>>& anteriores, vector<Vertice*>& caminhoAtual, 
    vector<vector<Vertice*>>& caminhos){

    caminhoAtual.push_back(atual);

    // chegou na origem
    if (atual == origem){

        vector<Vertice*> caminhoCompleto = caminhoAtual;

        reverse(caminhoCompleto.begin(), caminhoCompleto.end()
        );

        caminhos.push_back(caminhoCompleto);
    }

    else{

        for (Vertice* anterior : anteriores[atual]){

            reconstruirCaminhos(anterior, origem, anteriores, caminhoAtual, caminhos);
        }
    }

    caminhoAtual.pop_back();
}

vector<vector<Vertice*>>Grafo::obterCaminhosMinimos(Vertice* origem, Vertice* destino){

    unordered_map<Vertice*, float> distancias;
    unordered_map<Vertice*, vector<Vertice*>> anteriores = dijkstra(origem, distancias);
    vector<vector<Vertice*>> caminhos;

    // nao existe caminho
    if (distancias[destino] == numeric_limits<float>::infinity()){
        return caminhos;
    }
    vector<Vertice*> caminhoAtual;

    reconstruirCaminhos(destino, origem, anteriores, caminhoAtual, caminhos);

    return caminhos;
}

void Grafo::exibirCaminhoMaisCurto(Vertice* origem, Vertice* destino){

    vector<vector<Vertice*>> caminhos = obterCaminhosMinimos(origem, destino);

    if (caminhos.empty()){

        cout << "Nao existe caminho." << endl;
        return;
    }

    cout << "-MENORES CAMINHOS-"<< endl;

    for (size_t i = 0; i < caminhos.size(); i++){

        cout << "Caminho "<< i + 1 << ": ";

        for (size_t j = 0; j < caminhos[i].size(); j++){

            cout<< caminhos[i][j]->getNome();

            if (j != caminhos[i].size() - 1){
                cout << " -> ";
            }
        }

        float custo = calcularCustoVertices(caminhos[i]);
        cout << " | custo total = "<< fixed << setprecision(1) << custo << endl;
    }
}

void Grafo::exibirOrdemDecrescenteCentralidade(){

    unordered_map<Vertice*, float> centralidade;

    //inicializar centralidade
    for (Vertice* vertice : vertices){
        centralidade[vertice] = 0.0;
    }

    //percorrer todos os pares
    for (Vertice* origem : vertices){
        for (Vertice* destino : vertices){
            //ignorar mesmo vertice
            if (origem == destino){
                continue;
            }

            vector<vector<Vertice *>> caminhos = obterCaminhosMinimos(origem, destino);

            //quantidade total de menores caminhos
            int totalCaminhos = caminhos.size();

            if (totalCaminhos == 0){
                continue;
            }

            // contar intermediarios
            for (vector<Vertice*> caminho : caminhos){

                //ignorar origem e destino
                for (size_t i = 1; i < caminho.size() - 1; i++){

                    Vertice* intermediario = caminho[i];

                    centralidade[intermediario]+= 1.0 / totalCaminhos;
                }
            }
        }
    }

    //converter para vetor para ordenar
    vector<pair<Vertice*, float>>ranking;

    for (auto item : centralidade){
        ranking.push_back(item);
    }

    //ordenar do menor para menor
    sort(ranking.begin(),ranking.end(), [](pair<Vertice*, float> a, pair<Vertice*, float> b){
        return a.second < b.second;
        }
    );

    // exibir
    cout << endl;
    cout << "----ORDEM DE CENTRALIDADE----"<< endl;

    for (auto item : ranking){

        cout << item.first->getNome() << " -> " << fixed << setprecision(2)<< item.second << endl;
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
float Grafo::calcularCustoVertices(vector<Vertice*> caminho){

    float custoTotal = 0.0;

    for (size_t i = 0;i < caminho.size() - 1;i++){
        Vertice* origem = caminho[i];
        Vertice* destino = caminho[i + 1];
        int indiceOrigem = indiceVertices[origem];
        int indiceDestino =indiceVertices[destino];

        custoTotal += matrizAdjacencia[indiceOrigem][indiceDestino];

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

vector<Vertice*> Grafo::getVertices() {
    return vertices;
}

