
#include <iostream>
#include "Bilhete.h"

Bilhete::Bilhete(cat_zonas cat, tipo_bilh tip, string nome = "null", string esc = "null")
{
	categoria = cat;
	tipo = tip;
	this->nome = nome;
	escola = esc;
}
/*
bool Bilhete::eValido()
{
	return validado;
}
*/

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

/*
virtual int Bilhete::validaBilhete()
{
	validado = true;
	return 0;
}

Ocasional::Ocasional(string cat, string tipo): Bilhete(cat)
{
	this->tipo = tipo;
	if(tipo == "unico")
		duracao = 2;
	if(tipo == "diario")
		duracao = 24;
}

int Ocasional::validaBilhete()
{
	validado = true;
	return duracao;
}

int Ocasional::getPreco()
{
	int preco = 0;
	//definir preço consoante categoria e tipo
	return preco;
}

Assinatura::Assinatura(string nome, string cat): Bilhete(cat)
{
	this->nome = nome;
}

string Assinatura::getNome()
{
	return nome;
}

int Assinatura::validaBilhete()
{
	validado = true;
	return 0; //a alterar
}

virtual int Assinatura::getPreco()
{
	int preco = 0;
	//definir preço consoante categoria
	return preco;
}

JuniorOuSenior::JuniorOuSenior(string nome, string cat, int idade, int CC): Assinatura(nome, cat)
{
	this->idade = idade;
	this->CC = CC;
}

int JuniorOuSenior::getIdade()
{
	return idade;
}

int JuniorOuSenior::getCC()
{
	return CC;
}

int JuniorOuSenior::getPreco()
{
	int preco = 0;
	//definir preço consoante categoria
	preco = preco * 0.75;
	return preco;
}

Estudante::Estudante(string nome, string cat, int idade, int CC, string escola): JuniorOuSenior(nome, cat, idade, CC)
{
	this->escola = escola;
}

string Estudante::getEscola()
{
	return escola;
}
*/
