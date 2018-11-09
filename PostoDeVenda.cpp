
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

MaqAutomatica::MaqAutomatica(string loc): localizacao(loc){}

void MaqAutomatica::emiteBilhete(cat_zonas cat, tipo_bilh tip)
{
	bilhetes_emitidos.push_back(Bilhete(cat, tip));
}
