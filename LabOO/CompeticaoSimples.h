#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H
#include <iostream>
#include "Competicao.h"
#include "Modalidade.h"

class CompeticaoSimples : public Competicao{

private:
    Modalidade* modalidade;
public:
    CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
    virtual ~CompeticaoSimples();
    Modalidade* getModalidade();
    Tabela* getTabela();
    void imprimir();
};

#endif
