#ifndef TABELA_H
#define TABELA_H
#include <iostream>
#include "Equipe.h"

using namespace std;

class Tabela{

protected:
    Equipe** participantes;
    int quantidade;
public:
    Tabela(Equipe** participantes, int quantidade);
    virtual ~Tabela();
    virtual int getPosicao (Equipe* participante);
    virtual Equipe** getEquipesEmOrdem() = 0;
    virtual int getQuantidadeDeEquipes();
    virtual void imprimir();
};

#endif
