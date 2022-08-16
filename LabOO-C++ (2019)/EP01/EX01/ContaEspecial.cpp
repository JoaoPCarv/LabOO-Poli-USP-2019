#include "ContaEspecial.h"

ContaEspecial::ContaEspecial (int numero,
															double limite) : ContaCorrente (numero), limite (limite) {

}

ContaEspecial::~ContaEspecial() {
}

double ContaEspecial::getLimite() {
	return limite;
}

bool ContaEspecial::retirar (double valor) {
	if (valor <= limite + saldo) {
		saldo -= valor;
		return true;
	}

	return false;
}
