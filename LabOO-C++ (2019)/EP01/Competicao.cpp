#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include <iostream>

void Competicao::setNome(string nome){

this->nome = nome;

};

void Competicao::setQuantidade(int quantidade){

this->quantidade = quantidade;

};

void Competicao::setMaximoDeModalidades(int maximoDeModalidades){

this->maximoDeModalidades = maximoDeModalidades;

};

void Competicao::incrementaAtualMod(){

this->quantidadeAtualMod++;

};

void Competicao::setEquipes(Equipe** equipes){

this->equipes = equipes;

};

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades){

this->setNome(nome);
this->setEquipes(equipes);
this->setQuantidade(quantidade);
this->setMaximoDeModalidades(maximoDeModalidades);
this->modalidades = new Modalidade* [maximoDeModalidades];

};

Competicao::~Competicao(){

delete[] this->modalidades;

};

string Competicao::getNome(){

return this->nome;

};

Equipe** Competicao::getEquipes(){

return this->equipes;

};

int Competicao::getMaximoDeModalidades(){

return this->maximoDeModalidades;

};

int Competicao::getQuantidadeDeEquipes(){

return this->quantidade;

};

bool Competicao::adicionar(Modalidade* m){

if(this->getQuantidadeDeModalidades() == this->getMaximoDeModalidades()) return false;

this->getModalidades()[this->getQuantidadeDeModalidades()] = m;

this->incrementaAtualMod();

return true;

};

Modalidade** Competicao::getModalidades(){

return this->modalidades;

};

int Competicao::getQuantidadeDeModalidades(){

return this->quantidadeAtualMod;

};

Tabela* Competicao::getTabela(){

Tabela *t = new Tabela(this->getEquipes(), this->getQuantidadeDeEquipes());

for(int i = 0; i < this->getQuantidadeDeModalidades(); i++){

    Modalidade *m = this->getModalidades()[i];

    for (int j = 0; j < this->getQuantidadeDeEquipes(); j++){

    for(int k = 0; k < m->getQuantidadeDeEquipes(); k++){

    if(this->getEquipes()[j] == m->getEquipes()[k]){

        if(m->getPosicao(m->getEquipes()[k]) != -1){

        if(m->getPosicao(m->getEquipes()[k]) == 0) t->pontuar(m->getEquipes()[k], 13);

        else if(m->getPosicao(m->getEquipes()[k]) == 1) t->pontuar(m->getEquipes()[k], 10);

        else if(m->getPosicao(m->getEquipes()[k]) == 2) t->pontuar(m->getEquipes()[k], 8);

        else if(m->getPosicao(m->getEquipes()[k]) == 3) t->pontuar(m->getEquipes()[k], 7);

        else if(m->getPosicao(m->getEquipes()[k]) == 4) t->pontuar(m->getEquipes()[k], 5);

        else if(m->getPosicao(m->getEquipes()[k]) == 5) t->pontuar(m->getEquipes()[k], 4);

        else if(m->getPosicao(m->getEquipes()[k]) == 6) t->pontuar(m->getEquipes()[k], 3);

        else if(m->getPosicao(m->getEquipes()[k]) == 7) t->pontuar(m->getEquipes()[k], 2);

        else if(m->getPosicao(m->getEquipes()[k]) == 8) t->pontuar(m->getEquipes()[k], 1);

        else if(m->getPosicao(m->getEquipes()[k]) >= 9) t->pontuar(m->getEquipes()[k], 0);

    };
     break;
    };
    };
};

};

return t;

};

void Competicao::imprimir(){

cout << this->getNome() << endl;
this->getTabela()->imprimir();

};
