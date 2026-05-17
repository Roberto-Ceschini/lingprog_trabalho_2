#include "aresta.h"
#include <vector>

using namespace std;

#ifndef CAMINHO_H
#define CAMINHO_H

class Caminho {

    public:
        void setAresta(Aresta *);
        float calcularCusto();
        void imprimirCaminho();

    private:
        vector<Aresta *> arestas;
        bool verificarInsercao(Aresta *);

};
#endif