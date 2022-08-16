#ifndef CONTAUNIVERSITARIA_H
#define CONTAUNIVERSITARIA_H

#include "ContaCorrente.h"

class ContaUniversitaria : public ContaCorrente {
public:
  ContaUniversitaria (int numero);
  virtual ~ContaUniversitaria();
  bool retirar (double valor);
  static double getLimiteDeSaque();
  static void setLimiteDeSaque (double limite);
private:
  static double limiteDeSaque;
};

#endif // CONTAUNIVERSITARIA_H
