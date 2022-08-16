#ifndef EQUIPE_H
#define EQUIPE_H
#include <iostream>

using namespace std;

class Equipe{
private:
    string nome;
public:
    Equipe(string nome);
    virtual ~Equipe();
    virtual string getNome();
    virtual void imprimir();
};


#endif
