
#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

#include <string>
#include "PostoDeVenda.h"
using namespace std;

class Funcionario
{
private:
	int salario;
	string nome;
	PostoDeVenda* localDeTrabalho;

public:
	Funcionario(int salario, string nome, PostoDeVenda* LDT);
	int getSalario();
	string getNome();
	PostoDeVenda* getLocalDeTrabalho();
	void setSalario(int newSalario);
	void setLocalDeTrabalho(PostoDeVenda* newLDT);
	bool operator< (const Funcionario & right) const;
	bool operator== (const Funcionario & right) const;

	friend ostream & operator<<(ostream & o, const Funcionario & f);
};

ostream & operator<<(ostream & o, const Funcionario & f);

#endif
