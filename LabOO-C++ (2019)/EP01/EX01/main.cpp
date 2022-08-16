#include <iostream>
#include "ContaCorrente.h"
#include "ContaEspecial.h"

using namespace std;

int main() {
  ContaCorrente* ce = new ContaEspecial (1, 100);

  ce->depositar (100);
  cout << (ce->retirar (150) ? "OK" : "NOK") << endl;

  delete ce;

  return 0;
}
