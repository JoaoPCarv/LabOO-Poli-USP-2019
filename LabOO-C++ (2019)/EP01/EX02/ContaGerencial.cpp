#include "ContaGerencial.h"
#include <string>

using namespace std;

ContaGerencial::ContaGerencial (int idGerente, string data) :
	  ContaCorrente (9990), ContaInvestimento (9991) {
	this->idGerente = idGerente;
	this->data = data;
}

double ContaGerencial::getSaldoTotal() {
	return getSaldoCC() + getSaldoCI();
}

int ContaGerencial::getIdGerente() {
	return idGerente;
}


ContaGerencial::~ContaGerencial() {
}
