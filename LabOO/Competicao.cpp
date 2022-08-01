#include "Competicao.h"
#include <stdexcept>

Competicao::Competicao(string nome, Equipe** equipes, int quantidade){

this->nome = nome;
this->participantes = equipes;
this->quantidade = quantidade;

};

Competicao::~Competicao(){};

string Competicao::getNome(){

return this->nome;

};

Equipe** Competicao::getEquipes(){

return this->participantes;

};

int Competicao::getQuantidadeDeEquipes(){

return this->quantidade;

};

void Competicao::imprimir(){

cout << this->getNome() << endl;

};
