#ifndef COMPETICAO_H
#define COMPETICAO_H
#include <iostream>
#include "Equipe.h"
#include "Tabela.h"


class Competicao{

protected:
    string nome;
    int quantidade;
    Equipe** participantes;
public:
    Competicao(string nome, Equipe** equipes, int quantidade);
    virtual ~Competicao();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    virtual Tabela* getTabela() = 0;
    void imprimir();
};
#endif
