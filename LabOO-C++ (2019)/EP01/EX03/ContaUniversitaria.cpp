#include "ContaUniversitaria.h"

double ContaUniversitaria::limiteDeSaque = 0;

ContaUniversitaria::ContaUniversitaria (int numero) :
  ContaCorrente (numero) {
}

ContaUniversitaria::~ContaUniversitaria() {
}

bool ContaUniversitaria::retirar (double valor) {
  if (valor <= ContaUniversitaria::limiteDeSaque
      && saldo >= valor) {
    saldo -= valor;
    return true;
  }

  return false;
}

double ContaUniversitaria::getLimiteDeSaque() {
  return ContaUniversitaria::limiteDeSaque;
}

void ContaUniversitaria::setLimiteDeSaque (double limite) {
  ContaUniversitaria::limiteDeSaque = limite;
}
