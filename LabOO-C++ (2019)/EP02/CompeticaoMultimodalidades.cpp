#include "CompeticaoMultimodalidades.h"
#include "TabelaComPontos.h"
#include <stdexcept>
#include <vector>
#include <iterator>

using namespace std;

vector<int>* CompeticaoMultimodalidades::pontos = NULL;

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade) : Competicao(nome, equipes, quantidade){

this->modalidades = new list<Modalidade*>();

this->modalidadesAdicionadas = 0;

this->jaModalidades = false;

CompeticaoMultimodalidades::setPontuacao(new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1}));

};

CompeticaoMultimodalidades::~CompeticaoMultimodalidades(){};

void CompeticaoMultimodalidades::adicionar(Modalidade* m){

list<Modalidade*>::iterator i = this->modalidades->begin();

while(i != this->modalidades->end()){

     if(*i == m) throw new invalid_argument("Modalidade ja adicionada");

    i++;
};

this->jaModalidades = true;
this->modalidadesAdicionadas++;
this->modalidades->push_back(m);

};

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades(){

return this->modalidades;

};

Tabela* CompeticaoMultimodalidades::getTabela(){

if(!this->jaModalidades) throw new invalid_argument("Ainda nao foram adicionadas modalidades");

TabelaComPontos* retorno = new TabelaComPontos(this->participantes, this->quantidade);

list<Modalidade*>::iterator i = this->modalidades->begin();

while(i != this->modalidades->end()){

if((*i)->temResultado()){

  TabelaComOrdem* t = (*i)->getTabela();
  Equipe** ordem = t->getEquipesEmOrdem();

  for(int j = 0; j < t->getQuantidadeDeEquipes(); j++){

  retorno->pontuar(ordem[j], CompeticaoMultimodalidades::getPontoPorPosicao(j+1));

    };
 };
 i++;
};

return retorno;

};

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos){

if(pontos->size() < 3) throw new invalid_argument("Tamanho menor do que o necessario");

CompeticaoMultimodalidades::pontos = pontos;

};

int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao){

if(CompeticaoMultimodalidades::pontos->at(posicao - 1) != NULL) return CompeticaoMultimodalidades::pontos->at(posicao - 1);

return 0;


};

void CompeticaoMultimodalidades::imprimir(){

Competicao::imprimir();

this->getTabela()->imprimir();


};
