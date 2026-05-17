#include <string>

using namespace std;
#ifndef VERTICIE_H
#define VERTICIE_H

class Verticie {

    public:
        Verticie();
        Verticie(string);

        void setNome(string);
        string getNome();
        
    private:
        string nome;

};

#endif