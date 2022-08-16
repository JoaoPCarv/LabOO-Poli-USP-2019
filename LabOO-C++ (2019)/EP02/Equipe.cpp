#include "Equipe.h"
#include <iostream>

using namespace std;

Equipe::Equipe(string nome){

this->nome = nome;

};

Equipe::~Equipe(){};

string Equipe::getNome(){

return this->nome;

}

void Equipe::imprimir(){

cout << "Equipe " << this->getNome() << endl;

};
