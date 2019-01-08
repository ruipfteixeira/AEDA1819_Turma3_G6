
#include <iostream>
#include "Funcionario.h"


Funcionario::Funcionario(int salario, string nome, PostoDeVenda* LDT)
{
	this->salario = salario;
	this->nome = nome;
	localDeTrabalho = LDT;
}

int Funcionario::getSalario()
{
	return salario;
}
string Funcionario::getNome()
{
	return nome;
}
PostoDeVenda* Funcionario::getLocalDeTrabalho()
{
	return localDeTrabalho;
}
void Funcionario::setSalario(int newSalario)
{
	salario = newSalario;
}
void Funcionario::setLocalDeTrabalho(PostoDeVenda* newLDT)
{
	localDeTrabalho = newLDT;
}

bool Funcionario::operator< (const Funcionario & right) const
{
	if(salario < right.salario)
		return true;
	else if(salario == right.salario)
	{
		if(nome < right.nome)
			return true;
	}
	return false;
}

bool Funcionario::operator== (const Funcionario & right) const
{
	if(salario == right.salario && nome == right.nome)
		return true;
	else
		return false;
}

ostream & operator<<(ostream & o, const Funcionario & f)
{
o << f.nome << '/' << f.salario << '/' << f.localDeTrabalho->getLocalizacao();
return o;
}
