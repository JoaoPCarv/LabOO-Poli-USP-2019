#include "Tabela.h"
#include "Equipe.h"
#include <iostream>

using namespace std;

void Tabela::setParticipantes(Equipe** participantes){

this->participantes = participantes;

};

void Tabela::setQuantidade(int quantidade){

this->quantidade = quantidade;

};

Equipe** Tabela::getParticipantes(){

return this->participantes;

};

int Tabela::getQuantidade(){

return this->quantidade;

}

Tabela::Tabela(Equipe** participantes, int quantidade){

this->setParticipantes(participantes);
this->setQuantidade(quantidade);


for(int i = 0; i < this->getQuantidade(); i++){

    this->pontuacao[i] = 0;

};

};

Tabela::~Tabela(){};

int Tabela::procurarParticipante(Equipe* participante){

for(int i = 0; i < this->getQuantidade(); i++){

    if(this->getParticipantes()[i] == participante) return i;

};

return -1;

};

void Tabela::pontuar(Equipe* participante, int pontos){

int posicao = this->procurarParticipante(participante);

if(posicao != -1) this->pontuacao[posicao] += pontos;

return;

};

int Tabela::getPontos(Equipe* participante){

int posicao = this->procurarParticipante(participante);

if(posicao == -1) return posicao;

return this->pontuacao[posicao];

};

int Tabela::getPosicao(Equipe* participante){

int posicao = this->procurarParticipante(participante);

if(posicao == -1) return posicao;

int pontos = this->pontuacao[posicao];
int retorno = 1;

for (int i = 0; i < this->getQuantidade(); i++){

if(i != posicao && pontos < this->pontuacao[i]) retorno++;

};

return retorno;

};

void Tabela::imprimir(){


for(int i  = 0; i < this->getQuantidade(); i++){

    cout << "\t" << this->getParticipantes()[i]->getNome() << "  " << this->getPontos(this->getParticipantes()[i]) << "  (" << this->getPosicao(this->getParticipantes()[i]) << "o)" << endl;

};

}
