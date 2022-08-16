#ifndef CONTAGERENCIAL_H
#define CONTAGERENCIAL_H

#include "ContaCorrente.h"
#include "ContaInvestimento.h"

#include <string>

class ContaGerencial : public ContaCorrente, public ContaInvestimento {
public:
  ContaGerencial(int idGerente, string data);
  virtual ~ContaGerencial();
  double getSaldoTotal();
  int getIdGerente();

private:
  int idGerente;
  string data;
};

#endif // CONTAGERENCIAL_H


