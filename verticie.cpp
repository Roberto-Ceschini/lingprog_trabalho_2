#include "verticie.h"

Verticie::Verticie() {
    setNome("N/A");
}

Verticie::Verticie(string _nome) {
    setNome(_nome);
}

void Verticie::setNome(string _nome) {
    nome = _nome;
}

string Verticie::getNome() {
    return nome;
}