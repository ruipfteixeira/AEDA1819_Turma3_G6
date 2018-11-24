
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PostoDeVenda.h"
#include <string>
#include <sstream>

PostoDeVenda::PostoDeVenda(string loc): localizacao(loc)
{}

vector<Bilhete> PostoDeVenda::getBilhetes()
{
	return bilhetes_emitidos;
}

void PostoDeVenda::emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano,  string nome, int idade, int CC, string esc)
{
	bilhetes_emitidos.push_back(Bilhete(cat, tip, dia, mes, ano, nome, idade, CC, esc));
}

void PostoDeVenda::printBilhetes(bool printPeriod)
{
	if(bilhetes_emitidos.size() == 0)
	{
		std::cout << "Este posto não emitiu bilhetes." << std::endl;
	}
	else
	{
		if(!printPeriod)
		{
			for(size_t i = 0; i < bilhetes_emitidos.size(); i++)
			{
				bilhetes_emitidos.at(i).printBilhete();
				std::cout << std::endl;
			}
		}
		else
		{
			vector<int> dataBilh = {0, 0, 0}, data1 = {0, 0, 0}, data2 = {0, 0, 0};
			std::cout << "Insira duas datas no formato 'DD MM AAAA'" << std::endl;
			std::cin >> data1.at(0) >> data1.at(1) >> data1.at(2);
			std::cin >> data2.at(0) >> data2.at(1) >> data2.at(2);
			std::cout << data1.at(0) << " " << data1.at(1) << " " << data1.at(2) << " " << data1.at(0) << " " << data2.at(1) << " " << data2.at(2) << std::endl;
			for(size_t i = 0; i < bilhetes_emitidos.size(); i++)
			{
				dataBilh = bilhetes_emitidos.at(i).getData();

				if(dataBilh.at(2) > data1.at(2) && dataBilh.at(2) < data2.at(2))
				{
					bilhetes_emitidos.at(i).printBilhete();
					std::cout << std::endl;
				}
				else if(dataBilh.at(2) == data1.at(2))
				{
					if(dataBilh.at(1) > data1.at(1))
					{
						bilhetes_emitidos.at(i).printBilhete();
						std::cout << std::endl;
					}
					else if(dataBilh.at(1) == data1.at(1))
					{
						if(dataBilh.at(0) >= data1.at(0))
						{
							bilhetes_emitidos.at(i).printBilhete();
							std::cout << std::endl;
						}
					}
				}
				else if(dataBilh.at(2) == data2.at(2))
				{
					if(dataBilh.at(1) < data2.at(1))
					{
						bilhetes_emitidos.at(i).printBilhete();
						std::cout << std::endl;
					}
					else if(dataBilh.at(1) == data2.at(1))
					{
						if(dataBilh.at(0) <= data2.at(0))
						{
							bilhetes_emitidos.at(i).printBilhete();
							std::cout << std::endl;
						}
					}
				}
			}
			std::cout << "end of loop" << std::endl;

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
				{count++;}
			}
			return count;
		}
}

MaqAutomatica::MaqAutomatica(string loc): PostoDeVenda::PostoDeVenda(loc) {}

void MaqAutomatica::emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano)
{
	bilhetes_emitidos.push_back(Bilhete(cat, tip, dia, mes, ano));
}

string PostoDeVenda::getLocalizacao()
{
	return localizacao;
}

void PostoDeVenda::ordenaBilhetes()
{
	sort(bilhetes_emitidos.begin(), bilhetes_emitidos.end());
}
















