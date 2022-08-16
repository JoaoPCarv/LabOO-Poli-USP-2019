#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade){

this->nome = nome;
this->participantes = participantes;
this->quantidade = quantidade;
this->tabela = new TabelaComOrdem(this->participantes, this->getQuantidadeDeEquipes());
this->jaResultado = false;

};

Modalidade::~Modalidade(){};

string Modalidade::getNome(){

return this->nome;

};

Equipe** Modalidade::getEquipes(){

return this->participantes;

};

int Modalidade::getQuantidadeDeEquipes(){

return this->quantidade;

};

void Modalidade::setResultado(Equipe** ordem){

this->tabela->setResultado(ordem);
this->jaResultado = true;

};

bool Modalidade::temResultado(){

return this->jaResultado;

};

TabelaComOrdem* Modalidade::getTabela(){

return this->tabela;

};

void Modalidade::imprimir(){

cout << "Modalidade: " << this->getNome() << endl;
this->getTabela()->imprimir();

};



