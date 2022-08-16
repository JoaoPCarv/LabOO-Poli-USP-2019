#ifndef TABELA_H
#define TABELA_H
#include "Equipe.h"
#include <iostream>

using namespace std;

class Tabela{
private:
    Equipe** participantes;
    int quantidade;
    int pontuacao[];
    void setParticipantes(Equipe** participantes);
    void setQuantidade(int quantidade);
    Equipe** getParticipantes();
    int getQuantidade();
    int procurarParticipante(Equipe* participante);
public:
    Tabela(Equipe** participantes, int quantidade);
    ~Tabela();
    void pontuar (Equipe* participante, int pontos);
    int getPontos (Equipe* participante);
    int getPosicao (Equipe* participante);
    void imprimir();
};

#endif
