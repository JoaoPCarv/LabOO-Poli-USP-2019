#ifndef MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include "Equipe.h"
#include "TabelaComOrdem.h"

class Modalidade{


private:
    string nome;
    bool jaResultado;
    int quantidade;
    Equipe** participantes;
    TabelaComOrdem* tabela;
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    virtual ~Modalidade();
    virtual string getNome();
    virtual Equipe** getEquipes();
    virtual int getQuantidadeDeEquipes();
    virtual void setResultado(Equipe** ordem);
    virtual bool temResultado();
    virtual TabelaComOrdem* getTabela();
    virtual void imprimir();






};

#endif
