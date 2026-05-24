#include <string>

#ifndef VERTICE_H
#define VERTICE_H
using namespace std;
class Vertice
{
    public:
        Vertice(string);

        string getNome();


    private:
        string nome;
};

#endif