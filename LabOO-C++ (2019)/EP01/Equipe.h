#ifndef EQUIPE_H
#define EQUIPE_H
#include <iostream>

using namespace std;

class Equipe{
private:
    string nome;
    void setNome(string nome);
public:
    Equipe(string nome);
    ~Equipe();
    string getNome();
    void imprimir();
};

#endif



