#ifndef  MODALIDADE_H
#define MODALIDADE_H
#include <iostream>
#include "Equipe.h"

using namespace std;

class Modalidade{

private:
    string nome;
    Equipe** participantes;
    int quantidade;
    Equipe** resultado;
    void setNome(string nome);
    void setParticipantes(Equipe** participantes);
    void setQuantidade(int quantidade);
    Equipe** getResultado();
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    ~Modalidade();
    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();
    void setResultado(Equipe** ordem);
    int getPosicao (Equipe* participante);
    void imprimir();
};

#endif
