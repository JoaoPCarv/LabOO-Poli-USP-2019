#include <iostream>
#include "ContaUniversitaria.h"

using namespace std;

int main() {
  ContaUniversitaria *u1 = new ContaUniversitaria(1);
  u1->depositar(100);

  ContaUniversitaria *u2 = new ContaUniversitaria(1);
  u2->depositar(200);

  ContaUniversitaria::setLimiteDeSaque(50);

  if (u1->retirar(70)) {
		cout << "Conta 1 retirou R$70"  << endl;
  } else cout << "Nao foi possivel retirar R$70 da conta 1" << endl;

  if (u2->retirar(70)) {
		cout << "Conta 2 retirou R$70"  << endl;
  } else cout << "Nao foi possivel retirar R$70 da conta 2" << endl;

  cout << endl << "Alterando o limite" << endl;
  u1->setLimiteDeSaque(100);

  if (u1->retirar(70)) {
		cout << "Conta 1 retirou R$70"  << endl;
  } else cout << "Nao foi possivel retirar R$70 da conta 1" << endl;

  if (u2->retirar(70)) {
		cout << "Conta 2 retirou R$70"  << endl;
  } else cout << "Nao foi possivel retirar R$70 da conta 2" << endl;

  return 0;
}
