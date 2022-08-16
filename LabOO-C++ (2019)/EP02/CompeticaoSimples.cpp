#include "CompeticaoSimples.h"

using namespace std;


CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m) : Competicao(nome, equipes, quantidade){

this->modalidade = m;

};

CompeticaoSimples::~CompeticaoSimples(){};

Modalidade* CompeticaoSimples::getModalidade(){

return this->modalidade;

};

Tabela* CompeticaoSimples::getTabela(){

return this->getModalidade()->getTabela();

};

void CompeticaoSimples::imprimir(){

Competicao::imprimir();

this->getTabela()->imprimir();

};
