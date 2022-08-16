#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H
#include <iostream>
#include <list>
#include <vector>
#include "Competicao.h"
#include "Modalidade.h"


class CompeticaoMultimodalidades : public Competicao{

private:
    list<Modalidade*>* modalidades;
    static vector<int>* pontos;
    bool jaModalidades;
    int modalidadesAdicionadas;
public:
    CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
    virtual ~CompeticaoMultimodalidades();
    void adicionar(Modalidade* m);
    list<Modalidade*>* getModalidades();
    static void setPontuacao(vector<int>* pontos);
    static int getPontoPorPosicao(int posicao);
    Tabela* getTabela();
    void imprimir();
};




#endif
