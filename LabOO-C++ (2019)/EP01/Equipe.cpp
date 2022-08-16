#include "Equipe.h"
#include <iostream>


using namespace std;


void Equipe::setNome(string nome){

this->nome = nome;


};
Equipe::Equipe(string nome){

    this->setNome(nome);

};

Equipe::~Equipe(){};

string Equipe::getNome(){

return this->nome;

};

void Equipe::imprimir(){


cout << this->getNome() << endl;


};





