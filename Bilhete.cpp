
#include <iostream>
#include <vector>
#include "Bilhete.h"


Bilhete::Bilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano, string nome, int idade, int, string esc)
{
	categoria = cat;
	tipo = tip;
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
	this->nome = nome;
	this->idade = idade;
	this->CC = CC;
	escola = esc;
}


string Bilhete::getCategoria()
{
	string cat;
	switch (categoria)
	{
	case z1:
	{
		cat = "z1";
		break;
	}
	case z2:
	{
		cat = "z2";
		break;
	}
	case z3:
	{
		cat = "z3";
		break;
	}
	case z4:
	{
		cat = "z4";
		break;
	}
	default:
	{
		cat = "invalid";
		break;
	}
	}
	return cat;
}

string Bilhete::getTipo()
{
	string tip;
	switch (tipo)
	{
	case UNIC:
	{
		tip = "unico";
		break;
	}
	case DIAR:
	{
		tip = "diario";
		break;
	}
	case A_NORM:
	{
		tip = "assinatura normal";
		break;
	}
	case A_JUN:
	{
		tip = "assinatura junior";
		break;
	}
	case A_SEN:
	{
		tip = "assinatura senior";
		break;
	}
	case A_ESTUD:
	{
		tip = "assinatura estudante";
		break;
	}
	default:
	{
		tip = "tipo invalido";
		break;
	}
	}
	return tip;
}

double Bilhete::getPreco()
{
	double preco;
	switch (tipo)
	{
	case UNIC:
	{
		preco = categoria;
		break;
	}
	case DIAR:
	{
		preco = categoria * 3;
		break;
	}
	case A_NORM:
	{
		preco = categoria * 10;
		break;
	}
	case A_JUN:

	case A_SEN:

	case A_ESTUD:
	{
		preco = categoria * 10 * 0.75;
		break;
	}
	default:
	{
		preco = -1;
		break;
	}
	}
	return preco;
}

string Bilhete::getEscola()
{
	return escola;
}

string Bilhete::getNome()
{
	return nome;
}

void Bilhete::printBilhete()
{
	std::cout << "categoria: " << this->getCategoria() << std::endl;
	std::cout << "tipo: " << this->getTipo() << std::endl;
	std::cout << "data: " << dia << "/" << mes << "/" << ano << std::endl;
	if(tipo >= A_NORM)
	{
		std::cout << "nome: " << nome << std::endl;
		if(tipo >= A_JUN)
		{
			std::cout << "idade: " << idade << std::endl;
			std::cout << "CC: " << CC << std::endl;
			if(tipo == A_ESTUD)
			{
				std::cout << "escola: " << escola << std::endl;
			}
		}
	}
	std::cout << "preço: " << this->getPreco() << "€" << std::endl;
}

int Bilhete::getCC()
{
	return CC;
}

int Bilhete::getIdade()
{
	return idade;
}

vector<int> Bilhete::getData()
{
	vector<int> data;
	data[0] = dia;
	data[1] = mes;
	data[2] = ano;
	return data;
}

bool Bilhete::operator< (const Bilhete & c) const
{
	if(ano < c.ano)
		return true;
	else if(ano > c.ano)
		return false;
	else
	{
		if(mes < c.mes)
			return true;
		else if(mes > c.mes)
			return false;
		else
		{
			if(dia < c.dia)
				return true;
			else if(dia > c.dia)
				return false;
			else
			{
				if(tipo <  c.tipo)
					return true;
				else if(tipo > c.tipo)
					return false;
				else
				{
					if(categoria < c.categoria)
						return true;
					else
						return false;
				}
			}
		}
	}
}

bool Bilhete::operator> (const Bilhete & c) const
{
	if(ano > c.ano)
		return true;
	else if(ano < c.ano)
		return false;
	else
	{
		if(mes > c.mes)
			return true;
		else if(mes < c.mes)
			return false;
		else
		{
			if(dia > c.dia)
				return true;
			else if(dia < c.dia)
				return false;
			else
			{
				if(tipo >  c.tipo)
					return true;
				else if(tipo < c.tipo)
					return false;
				else
				{
					if(categoria > c.categoria)
						return true;
					else
						return false;
				}
			}
		}
	}
}

