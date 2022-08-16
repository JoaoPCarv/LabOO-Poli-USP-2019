#include "TabelaComPontos.h"
#include <stdexcept>

using namespace std;

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade) : Tabela(participantes, quantidade){

    this->pontuacao = new int[quantidade];
    this->mapa = new int[quantidade];

    for(int i = 0; i < quantidade; i++)
        this->pontuacao[i] = 0;

    this->jaPontuado = new bool[quantidade];

    for(int i = 0; i < quantidade; i++)
        this->jaPontuado[i] = false;

};

TabelaComPontos::~TabelaComPontos() {};

void TabelaComPontos::pontuar(Equipe* participante, int pontos){

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++)
    {

        if(this->participantes[i] == participante)
        {

            this->pontuacao[i] += pontos;
            this->jaPontuado[i] = true;
            return;
        };
    };

    throw new invalid_argument("Equipe nao existente");


};

int TabelaComPontos::getPosicao(Equipe* participante){

    int pos = Tabela::getPosicao(participante);

    if(this->jaPontuado[pos] == false)
        throw new logic_error("Equipe ainda nao pontuada");

    int retorno = 1;

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++)
        if(pos != i && this->pontuacao[i] > this->pontuacao[pos])
            retorno ++;

    return retorno;

};

Equipe** TabelaComPontos::getEquipesEmOrdem(){


    for(int i  = 0; i < this->getQuantidadeDeEquipes(); i++)
        if(this->jaPontuado[i] == false)
            throw new logic_error("Ainda ha equipes sem pontos");

    Equipe** ordem = new Equipe*[this->getQuantidadeDeEquipes()];

    for(int k = 0; k < this->getQuantidadeDeEquipes(); k++)
        ordem[k] = NULL;

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++)
    {
        int pos = 0;

        for(int j = 0; j < this->getQuantidadeDeEquipes(); j++) if(i!= j && this->pontuacao[i] < this->pontuacao[j]) pos++;

        this->mapa[i] = pos+1;

        bool jaColocado = false;

        while(!jaColocado)
        {
            if(ordem[pos] == NULL)
            {
                ordem[pos] = this->participantes[i];
                jaColocado = true;
            };

            pos++;
        };
    };
    return ordem;
};

int TabelaComPontos::getPontos(Equipe* participante){

    for(int i = 0; i < this->getQuantidadeDeEquipes(); i++) if(this->participantes[i] == participante) return this->pontuacao[i];

    throw new invalid_argument("Equipe nao participante");

};

void TabelaComPontos::imprimir(){

    for(int i  = 0; i < this->getQuantidadeDeEquipes(); i++)
        if(this->jaPontuado[i] == false)
        {
            Tabela::imprimir();
            return;
        };

    Equipe** ordem = this->getEquipesEmOrdem();

    for(int i  = 0; i < this->getQuantidadeDeEquipes(); i++)
    {
        for(int j  = 0; i < this->getQuantidadeDeEquipes(); j++)
        {
            if(ordem[i] == this->participantes[j])
            {
                cout << '\t' << this->mapa[j] << "o " << ordem[i]->getNome() << " (" << this->pontuacao[j] << " pontos)" << endl;
                break;
            };
        };
    };
};
