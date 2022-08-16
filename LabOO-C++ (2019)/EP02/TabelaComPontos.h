#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H
#include <iostream>
#include "Tabela.h"

class TabelaComPontos : public Tabela{

 public:
    TabelaComPontos(Equipe** participantes, int quantidade);
    virtual ~TabelaComPontos();
    int getPontos (Equipe* participante);
    void pontuar (Equipe* participante, int pontos);
    virtual int getPosicao (Equipe* participante);
    virtual Equipe** getEquipesEmOrdem();
    virtual void imprimir();
 private:
    int *pontuacao;
    int *mapa;
    bool *jaPontuado;

};


#endif
