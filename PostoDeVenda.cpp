
#include <iostream>
#include "PostoDeVenda.h"

PostoDeVenda::PostoDeVenda(string loc): localizacao(loc)
{}

vector<Bilhete> PostoDeVenda::getBilhetes()
{
	return bilhetes_emitidos;
}

void PostoDeVenda::emiteBilhete(cat_zonas cat, tipo_bilh tip, string nome = "null", string esc = "null")
{
	bilhetes_emitidos.push_back(Bilhete(cat, tip, nome, esc));
}

void PostoDeVenda::printBilhetes()
{
	if(bilhetes_emitidos.size() == 0)
	{
		std::cout << "Este posto não emitiu bilhetes." << std::endl;
	}
	else
	{
		for(size_t i = 0; i < bilhetes_emitidos.size(); i++)
		{
			bilhetes_emitidos.at(i).printBilhete();
		}
	}
}

int PostoDeVenda::numeroBilhetes()
{
	return bilhetes_emitidos.size();
}

int PostoDeVenda::numeroBilhetes(cat_zonas cat)
{
	if(bilhetes_emitidos.size() == 0)
	{
		std::cout << "Este posto não emitiu bilhetes." << std::endl;
		return 0;
	}
	else
	{
		string categoria;
		int count = 0;
		switch (cat)
			{
			case z1:
			{
				categoria = "z1";
				break;
			}
			case z2:
			{
				categoria = "z2";
				break;
			}
			case z3:
			{
				categoria = "z3";
				break;
			}
			case z4:
			{
				categoria = "z4";
				break;
			}
			default:
			{
				categoria = "invalid";
				break;
			}
			}
		for(size_t i = 0; i < bilhetes_emitidos.size(); i++)
		{
			if(bilhetes_emitidos.at(i).getCategoria() ==categoria)
			{count++;}
		}
		return count;
	}

}

int PostoDeVenda::numeroBilhetes(tipo_bilh tip)
{
	if(bilhetes_emitidos.size() == 0)
		{
			std::cout << "Este posto não emitiu bilhetes." << std::endl;
			return 0;
		}
		else
		{
			string tipo;
			int count = 0;
			switch (tip)
				{
				case UNIC:
				{
					tipo = "unico";
					break;
				}
				case DIAR:
				{
					tipo = "diario";
					break;
				}
				case A_NORM:
				{
					tipo = "assinatura normal";
					break;
				}
				case A_JUN:
				{
					tipo = "assinatura junior";
					break;
				}
				case A_SEN:
				{
					tipo = "assinatura senior";
					break;
				}
				case A_ESTUD:
				{
					tipo = "assinatura estudante";
					break;
				}
				default:
				{
					tipo = "tipo invalido";
					break;
				}
				}
			for(size_t i = 0; i < bilhetes_emitidos.size(); i++)
			{
				if(bilhetes_emitidos.at(i).getTipo() == tipo)
				{count++}
			}
			return count;
		}
}

MaqAutomatica::MaqAutomatica(string loc): localizacao(loc){}

void MaqAutomatica::emiteBilhete(cat_zonas cat, tipo_bilh tip)
{
	bilhetes_emitidos.push_back(Bilhete(cat, tip));
}

string PostoDeVenda::getLocalizacao()
{
	return localizacao;
}

