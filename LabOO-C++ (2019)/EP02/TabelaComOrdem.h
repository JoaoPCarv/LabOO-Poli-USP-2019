#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H
#include <iostream>
#include "Tabela.h"

class TabelaComOrdem : public Tabela{

public:
    TabelaComOrdem(Equipe** participantes, int quantidade);
    virtual ~TabelaComOrdem();
    void setResultado (Equipe** ordem);
    virtual int getPosicao (Equipe* participante);
    virtual Equipe** getEquipesEmOrdem();
    virtual void imprimir();


private:
    Equipe** resultado;
};


#endif
