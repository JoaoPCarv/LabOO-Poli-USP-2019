#include "Modalidade.h"
#include "Equipe.h"
#include <iostream>

using namespace std;

void Modalidade::setNome(string nome){

this->nome = nome;

};

void Modalidade::setParticipantes(Equipe** participantes){

this->participantes = participantes;

};

void Modalidade::setQuantidade(int quantidade){

this->quantidade = quantidade;

};

Equipe** Modalidade::getResultado(){

return this->resultado;

};

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade){
this->setNome(nome);
this->setParticipantes(participantes);
this->setQuantidade(quantidade);
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

this->resultado = ordem;


};


int Modalidade::getPosicao(Equipe* participante){


if (this->getResultado() == NULL) return -1;

for (int i  = 0; i < this->getQuantidadeDeEquipes(); i++){

    if(this->getResultado()[i] == participante) return i;

};

return -1;

};

void Modalidade::imprimir(){

if (this->getResultado() == NULL) {

    cout << "Modalidade: " << this->getNome() << endl;
    cout << "Participantes: " << endl;

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){
       cout << "\t" << this->getEquipes()[i]->getNome() << endl;
    };

} else {

    cout << "Modalidade: " << this->getNome() << endl;
    cout << "Resultado: " << endl;

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){
        cout << "\t" << i + 1 << "o " << this->getResultado()[i]->getNome() << endl;
    };
};


};
