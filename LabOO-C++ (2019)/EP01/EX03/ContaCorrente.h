#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

class ContaCorrente {
public:
  ContaCorrente (int numero);
  virtual ~ContaCorrente();
  virtual bool retirar (double valor) = 0;
  virtual void depositar (double valor);
  virtual bool transferirPara (ContaCorrente* destino,
                               double valor);
  virtual double getSaldo();
  int getNumero();
protected:
  double saldo;
private:
  int numero;
};

#endif // CONTACORRENTE_H
