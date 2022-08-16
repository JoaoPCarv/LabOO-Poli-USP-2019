#ifndef COMPETICAO_H
#define COMPETICAO_H
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include <iostream>

class Competicao{
private:
    string nome;
    int quantidade;
    int maximoDeModalidades;
    int quantidadeAtualMod = 0;
    Equipe** equipes;
    Modalidade** modalidades;
    Tabela** tabela;
    void setNome(string nome);
    void setQuantidade(int quantidade);
    void setMaximoDeModalidades(int maximoDeModalidades);
    void incrementaAtualMod();
    void setEquipes(Equipe** equipes);
    int getMaximoDeModalidades();
public:
    Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades);
    ~Competicao();
    string getNome();
    Equipe** getEquipes();
   int getQuantidadeDeEquipes();
   bool adicionar(Modalidade* m);
   Modalidade** getModalidades();
   int getQuantidadeDeModalidades();
   Tabela* getTabela();
   void imprimir();
};

#endif
