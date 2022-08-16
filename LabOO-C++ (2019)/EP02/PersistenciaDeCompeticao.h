#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H
#include "Competicao.h"

class PersistenciaDeCompeticao{

public:
    PersistenciaDeCompeticao();
    virtual ~PersistenciaDeCompeticao();
    Competicao* carregar(string arquivo);
    void salvar(string arquivo, Competicao* c);
};

#endif
