/*
 * main.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: PC
 */
#include <iostream>
#include <vector>
#include <string>
#include "PostoDeVenda.h"

class OpcaoInvalida{};


void operaPosto(int index, vector<PostoDeVenda> *postos)
{

}

void operaMaquina(int index, vector<MaqAutomatica> *maquinas)
{

}

template <class T>
int vectorSearchPosto(string loc, const vector<T> *postos)
{
	for(int i = 0; i < postos->size(); i++)
	{
		if(postos->at(i).getLocalizacao() == loc)
		{
			return i;
		}
	}
	return -1;
}

void adicionaPostos(vector <PostoDeVenda> *postos, vector <MaqAutomatica> *maquinas)
{
	char option;
	bool progress = false, exit = false;
	string localizacao;
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar um posto de venda escreva 'p'." << std::endl;
				std::cout << "Para adicionar uma maquina automatica escreva 'm'." << std::endl;
				std::cout << "Para voltar ao menu inicial escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'p' && option != 'm' && option != 'v')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida *)
			{
				std::cout << "Inseriu uma opção inválida, por favor tente outra vez." << std::endl;
				progress = false;
			}
		}while(progress == false);
		switch(option)
		{
		case 'p':
		{
			std::cout << "Insira a localização do posto de venda." << std::endl;
			std::getline(std::cin, localizacao);
			postos->push_back(PostoDeVenda(localizacao));
			break;
		}
		case 'm':
		{
			std::cout << "insira a localizacao da maquina automatica." << std::endl;
			std::getline(std::cin, localizacao);
			maquinas->push_back(MaqAutomatica(localizacao));
			break;
		}
		case 'v':
		{
			exit = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}while(exit == false);

}

void procuraPosto(vector <PostoDeVenda> *postos, vector <MaqAutomatica> *maquinas)
{
	char option;
	bool progress = false, exit = false;
	string localizacao;
	int index;
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para procurar um posto de venda escreva 'p'." << std::endl;
				std::cout << "Para procurar uma maquina automatica escreva 'm'." << std::endl;
				std::cout << "Para voltar ao menu inicial escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'p' && option != 'm' && option != 'v')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida *)
			{
				std::cout << "Inseriu uma opção inválida, por favor tente outra vez." << std::endl;
				progress = false;
			}
		}while(progress == false);
		switch(option)
		{
		case 'p':
		{
			std::cout << "Insira a localização do posto de venda." << std::endl;
			std::getline(std::cin, localizacao);
			index = vectorSearchPosto(localizacao, postos);
			if(index == -1)
			{
				std::cout << "Não há postos nesta localizacao." << std::endl;
			}
			else
			{
				operaPosto(index, postos);
			}
			break;
		}
		case 'm':
		{
			std::cout << "insira a localizacao da maquina automatica." << std::endl;
			std::getline(std::cin, localizacao);
			index = vectorSearchPosto(localizacao, maquinas);
			if(index == -1)
			{
				std::cout << "Não há postos nesta localizacao." << std::endl;
			}
			else
			{
				operaMaquina(index, maquinas);
			}
			break;
		}
		case 'v':
		{
			exit = true;
			break;
		}
		default:
		{
			break;
		}
		}
	}while(exit == false);
}


void mainMenu()
{
	char option;
	bool progress = false, exit = false;
	vector <PostoDeVenda> postos;
	vector <MaqAutomatica> maquinas;
	std::cout << "Sistema de Registo de Bilhetes de Metro v1.0" << std::endl;
	/*sistema de carregamento de ficheiros
	std::cout << "Para carregar um ficheiro existente escreva 'c'. Para criar um novo escreva 'n'." << std::endl;
	std::cin >> option;
	*/
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar postos ou maquinas escreva 'a'." << std::endl;
				std::cout << "Para procurar um posto ou maquina escreva 'p'." << std::endl;
				std::cout << "Para sair escreva 's'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'p' && option != 's')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida *)
			{
				std::cout << "Inseriu uma opção inválida, por favor tente outra vez." << std::endl;
				progress = false;
			}

		}while(progress == false);
		switch(option)
		{
		case 'a':
		{
			adicionaPostos(&postos, &maquinas);
			break;
		}
		case 'p':
		{
			procuraPosto(&postos, &maquinas);
			break;
		}
		case 's':
		{
			exit = true;
			break;
		}
		default:
		{
			break;
		}
		}

	}while(exit == false);
	/*sistema para guardar para um ficheiro*/
}



int main()
{
	mainMenu();
	return 0;
}


