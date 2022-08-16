
#include "ContaInvestimento.h"
#include <string>

using namespace std;

ContaInvestimento::ContaInvestimento (int numero) {
  this->numeroCI = numero;
  this->saldoCI = 0;
}

ContaInvestimento::~ContaInvestimento() {
}

bool ContaInvestimento::retirarCI (double valor) {
  if (valor <= saldoCI) {
    saldoCI -= valor;
    return true;
  }

  return false;
}

void ContaInvestimento::depositarCI (double valor) {
  this->saldoCI += valor;
}

double ContaInvestimento::getSaldoCI() {
  return saldoCI;
}

int ContaInvestimento::getNumeroCI() {
  return numeroCI;
}

