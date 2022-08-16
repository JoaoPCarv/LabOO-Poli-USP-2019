
#include <iostream>
#include <string>

#include "ContaCorrente.h"
#include "ContaInvestimento.h"
#include "ContaGerencial.h"

using namespace std;

int main() {
  cout << "Teste da Conta Corrente" << endl;
  ContaCorrente *cc = new ContaCorrente(1);
  cc->depositarCC (1000);
  cout << (cc->retirarCC (150) ? "OK" : "NOK") << endl;
  cout << "Saldo da Conta Corrente numero " <<
       cc->getNumeroCC() << " = " << cc->getSaldoCC() << endl;

  cout << "Teste da Conta Investimento" << endl;
  ContaInvestimento *ci = new ContaInvestimento(2);
  ci->depositarCI(4000);
  cout << (ci->retirarCI(150) ? "Ok" : "NOK") << endl;
  cout << "Saldo da Conta Investimento numero " <<
       ci->getNumeroCI() << " = " << ci->getSaldoCI() << endl;

  cout << "Teste da Conta Gerencial" << endl;
  ContaGerencial *cg = new ContaGerencial(21, "01/10/2018");

  cg->depositarCC (1000);
  cout << (cg->retirarCC(150) ? "Ok" : "NOK") << endl;
  cout << "Saldo da Conta Corrente numero " <<
       cg->getNumeroCC() << " = " << cg->getSaldoCC() << endl;

  cg->depositarCI(4000);
  cout << (cg->retirarCI(150) ? "Ok" : "NOK") << endl;
  cout << "Saldo da Conta Investimento numero " <<
       cg->getNumeroCI() << " = " << cg->getSaldoCI() << endl;

  cout << "Saldo Total = " << cg->getSaldoTotal() << endl;

  return 0;
}
