#include "TabelaComOrdem.h"
#include <stdexcept>

using namespace std;

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade){};

TabelaComOrdem::~TabelaComOrdem(){};

void TabelaComOrdem::setResultado(Equipe** ordem){

this->resultado = ordem;

};

int TabelaComOrdem::getPosicao(Equipe* participante){

Tabela::getPosicao(participante);

if(this->resultado == NULL) throw new logic_error("Resultado ainda nao definido");

for(int i = 0; i <this->getQuantidadeDeEquipes(); i++){

    if(this->resultado[i] == participante) return i+1;

};

};

Equipe** TabelaComOrdem::getEquipesEmOrdem(){

return this->resultado;

};

void TabelaComOrdem::imprimir(){

if(this->resultado == NULL) Tabela::imprimir();

  else{
    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++){

        cout << '\t' << i+1 << "o " << this->resultado[i]->getNome() << endl;
    };
  };

};


