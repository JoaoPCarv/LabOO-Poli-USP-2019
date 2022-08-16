#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include <string>

using namespace std;

class ContaCorrente {
public:
  ContaCorrente (int numero);
  virtual ~ContaCorrente();

  bool retirarCC(double valor);
  void depositarCC(double valor);
  double getSaldoCC();
  int getNumeroCC();
protected:
  double saldoCC;
  int numeroCC;
};

#endif // CONTACORRENTE_H


