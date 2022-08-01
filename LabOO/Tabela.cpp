#include "Tabela.h"
#include <iostream>
#include <stdexcept>
#include <stdio.h>

using namespace std;

Tabela::Tabela(Equipe** participantes, int quantidade){

if(quantidade < 2) throw new invalid_argument("Menos de duas equipes");
this->quantidade = quantidade;
this->participantes = participantes;


};

Tabela::~Tabela(){};

int Tabela::getQuantidadeDeEquipes(){

return this->quantidade;

};

int Tabela::getPosicao(Equipe* participante){

int retorno = this->getQuantidadeDeEquipes();

for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){

    if(this->participantes[i] == participante) {

            return i;
    }
}
if(retorno == this->getQuantidadeDeEquipes()) throw new invalid_argument("Equipe nao participante");

};

void Tabela::imprimir(){

for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){

  cout << '\t' << this->participantes[i]->getNome() << endl;

};
};
