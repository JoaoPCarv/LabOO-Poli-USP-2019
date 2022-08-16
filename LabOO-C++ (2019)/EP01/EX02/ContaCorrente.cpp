
#include "ContaCorrente.h"
#include <string>

using namespace std;

ContaCorrente::ContaCorrente (int numero) {
  this->numeroCC = numero;
  this->saldoCC = 0;
}

ContaCorrente::~ContaCorrente() {
}

bool ContaCorrente::retirarCC (double valor) {
  if (valor <= saldoCC) {
    saldoCC -= valor;
    return true;
  }

  return false;
}

void ContaCorrente::depositarCC (double valor) {
  this->saldoCC += valor;
}

double ContaCorrente::getSaldoCC() {
  return saldoCC;
}

int ContaCorrente::getNumeroCC() {
  return numeroCC;
}
