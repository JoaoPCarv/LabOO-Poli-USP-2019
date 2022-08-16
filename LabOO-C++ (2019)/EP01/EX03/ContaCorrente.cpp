#include "ContaCorrente.h"

ContaCorrente::ContaCorrente (int numero) : saldo (0),
															numero (numero) {
}

ContaCorrente::~ContaCorrente() {
}

void ContaCorrente::depositar (double valor) {
  this->saldo += valor;
}

bool ContaCorrente::transferirPara (ContaCorrente* destino,
                                    double valor) {
  if (this->retirar (valor) ) {
    destino->depositar (valor);
    return true;
  }

  return false;
}

double ContaCorrente::getSaldo() {
  return this->saldo;
}

int ContaCorrente::getNumero() {
  return this->numero;
}
