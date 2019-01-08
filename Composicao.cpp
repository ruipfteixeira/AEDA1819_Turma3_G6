
#include <iostream>
#include "Composicao.h"

Composicao::Composicao(int dias, bool avaria, int id)
{
	diasProxManut = dias;
	avariado = avaria;
	id_composicao = id;
}

int Composicao::getProxManut() const
{
	return diasProxManut;
}

bool Composicao::getAvaria() const
{
	return avariado;
}

int Composicao::getId() const
{
	return id_composicao;
}

void Composicao::decDias()
{
	if(diasProxManut > 0)
		diasProxManut--;
	else
		std::cout << "Manutenção necessária na composição " << id_composicao << std::endl;
}

void Composicao::setAvaria()
{
	avariado = true;
}

void Composicao::efetuaManutencao()
{
	diasProxManut = 60;
	avariado = false;
}

bool Composicao::operator <(const Composicao & right) const
{
	if(diasProxManut > right.diasProxManut)
		return true;
	else
		return false;
}

bool Composicao::operator== (const Composicao & right) const
{
	if(id_composicao == right.id_composicao)
		return true;
	else
		return false;
}

void Composicao::print()
{
	std::cout << "Composição " << id_composicao;
	if(avariado)
		std::cout << ", Avariado";
	else
		std::cout << ", Não avariado";
	std::cout << ", " << diasProxManut << " dias até próxima manutenção." << std::endl;
}
