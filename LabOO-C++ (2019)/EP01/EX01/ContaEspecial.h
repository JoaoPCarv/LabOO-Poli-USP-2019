#ifndef CONTAESPECIAL_H
#define CONTAESPECIAL_H

#include "ContaCorrente.h"

class ContaEspecial : public ContaCorrente {
public:
  ContaEspecial (int numero, double limite);
  virtual ~ContaEspecial();
  bool retirar (double valor);
  virtual double getLimite();
private:
  double limite;
};

#endif // CONTAESPECIAL_H
