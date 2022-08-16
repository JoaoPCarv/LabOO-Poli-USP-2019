#ifndef CONTAINVESTIMENTO_H
#define CONTAINVESTIMENTO_H

#include <string>
#include "ContaCorrente.h"

using namespace std;

class ContaInvestimento {
public:
  ContaInvestimento(int numero);
  virtual ~ContaInvestimento();

  bool retirarCI(double valor);
  void depositarCI(double valor);
  double getSaldoCI();
  int getNumeroCI();
protected:
  double saldoCI;
  int numeroCI;
};

#endif // ContaInvestimento_H



