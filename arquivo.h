#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <fstream>
#include <vector>
#include <unordered_map>

#include "aresta.h"
#include "vertice.h"

using namespace std;

class Arquivo {

    public:
        void abrirArquivo(string);
        void fecharArquivo();
        bool verificarArquivo();
        vector<Aresta*> lerArestas();

    private:
        fstream arquivo;
};

#endif