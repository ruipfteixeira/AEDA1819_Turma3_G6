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



void addBilhetePosto(PostoDeVenda *posto) {
	cat_zonas zone;
	string zona;
	tipo_bilh tip;
	string tip0;
	string tip1;
	string name;
	string esc;
	int Ccidadao;
	int age;
	int dia, mes, ano;

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "  Para comprar bilhete único, escreva 1           " << std::endl;
	std::cout << "  Para comprar bilhete diario, escreva 2          " << std::endl;
	std::cout << "  Para comprar assinatura, escreva 3              " << std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> tip0;
	std::cout << std::endl << std::endl;

	if (tip0 == "1") { tip = UNIC;}
	if (tip0 == "2") { tip = DIAR;}
	if (tip0 == "3") {
		std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
		std::cout << "          Escolha uma assinatura:           "	<< std::endl;
		std::cout << "     Normal, Junior, Senior, Estudante      " << std::endl;
		std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
		std::cin >> tip1;

		if (tip1 == "Normal"){ tip = A_NORM;}
		if (tip1 == "Junior"){ tip = A_JUN;}
		if (tip1 == "Senior"){ tip = A_SEN;}
		if (tip1 == "Estudante"){ tip = A_ESTUD;}
	}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "             Escolha uma zona:              "	<< std::endl;
	std::cout << "               1 , 2 , 3 , 4                "	<< std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> zona;
	std::cout << std::endl << std::endl;

	if (zona == "1") { zone = z1;}
	if (zona == "2") { zone = z2;}
	if (zona == "3") { zone = z3;}
	if (zona == "4") { zone = z4;}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "         Indique a data de compra:          "	<< std::endl;
	std::cout << "                DD MM AAAA                  "	<< std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> dia >> mes >> ano;
	std::cout << std::endl << std::endl;

	if(tip0 == "3")
	{

		std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
		std::cout << "             Indique o seu Nome             "	<< std::endl;
		std::cout << "                                            "	<< std::endl;
		std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
		std::cin >> name;
		std::cout << std::endl << std::endl;

		if (tip1 != "Normal"){
			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
			std::cout << "       Indique o seu Cartao de Cidadao      "	<< std::endl;
			std::cout << "                                            "	<< std::endl;
			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
			std::cin >> Ccidadao;
			std::cout << std::endl << std::endl;

			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
			std::cout << "             Indique a sua Idade            "	<< std::endl;
			std::cout << "                                            "	<< std::endl;
			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
			std::cin >> age;
			std::cout << std::endl << std::endl;

		if (tip1 == "Estudante") {
			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
			std::cout << "            Indique a sua Escola            "	<< std::endl;
			std::cout << "                                            "	<< std::endl;
			std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
			std::cin >> esc;
			std::cout << std::endl << std::endl;
			posto->emiteBilhete(zone, tip, dia, mes, ano, name, age, Ccidadao, esc);
			}
		else
			posto->emiteBilhete(zone, tip, dia, mes, ano, name, age, Ccidadao);
		}
		else
			posto->emiteBilhete(zone, tip, dia, mes, ano, name);
	}
	else
		posto->emiteBilhete(zone, tip, dia, mes, ano);

	// Vetor de Bilhetes  |add|  Bilhete(zone, tip, name, esc, Ccidadao, age);
}


void addBilheteMaq(MaqAutomatica *maquina) {
	cat_zonas zone;
	string zona;
	tipo_bilh tip;
	string tip0;
	int dia, mes, ano;

	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "  Para comprar bilhete único, escreva 1           " << std::endl;
	std::cout << "  Para comprar bilhete diario, escreva 2          " << std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> tip0;
	std::cout << std::endl << std::endl;

	if (tip0 == "1") { tip = UNIC;}
	if (tip0 == "2") { tip = DIAR;}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "             Escolha uma zona:              "	<< std::endl;
	std::cout << "               1 , 2 , 3 , 4                "	<< std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> zona;
	std::cout << std::endl << std::endl;

	if (zona == "1") { zone = z1;}
	if (zona == "2") { zone = z2;}
	if (zona == "3") { zone = z3;}
	if (zona == "4") { zone = z4;}

	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl;
	std::cout << "         Indique a data de compra:          "	<< std::endl;
	std::cout << "                DD MM AAAA                  "	<< std::endl;
	std::cout << ">>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<" << std::endl << std::endl;
	std::cin >> dia >> mes >> ano;
	std::cout << std::endl << std::endl;


	maquina->emiteBilhete(zone, tip, dia, mes, ano);

	// Vetor de Bilhetes  |add|  Bilhete(zone, tip, name, esc, Ccidadao, age);
}



void operaPosto(int index, vector<PostoDeVenda> *postos)
{
	char option, printOpt;
	bool progress = false, exit = false, printPeriod = false;
	string localizacao;
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar um bilhete escreva 'a'." << std::endl;
				std::cout << "Para ver os bilhetes vendidos escreva 'b'." << std::endl;
				std::cout << "Para ordenar or bilhetes vendidos escreva 'o'." << std::endl;
				std::cout << "Para voltar ao menu anterior escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'b' && option != 'o' && option != 'v')
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
			addBilhetePosto(&(postos->at(index)));
			break;
		}
		case 'b':
		{
			std::cout << "Para imprimir bilhetes de um certo periodo escreva 'p'." << std::endl;
			std::cout << "Para imprimir todos os bilhetes prima qualquer outra tecla." << std::endl;
			std::cin >> printOpt;
			if(printOpt == 'p')
				printPeriod = true;
			else
				printPeriod = false;

			postos->at(index).printBilhetes(printPeriod);
			break;
		}
		case 'o':
		{
			postos->at(index).ordenaBilhetes();
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

void operaMaquina(int index, vector<MaqAutomatica> *maquinas)
{
	char option, printOpt;
	bool progress = false, exit = false, printPeriod = false;
	string localizacao;
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar um bilhete escreva 'a'." << std::endl;
				std::cout << "Para ver os bilhetes vendidos escreva 'b'." << std::endl;
				std::cout << "Para ordenar or bilhetes vendidos escreva 'o'." << std::endl;
				std::cout << "Para voltar ao menu anterior escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'b' && option != 'o' && option != 'v')
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
			addBilheteMaq(&(maquinas->at(index)));
			break;
		}
		case 'b':
		{
			std::cout << "Para imprimir bilhetes de um certo periodo escreva 'p'." << std::endl;
			std::cout << "Para imprimir todos os bilhetes prima qualquer outra tecla." << std::endl;
			std::cin >> printOpt;
			if(printOpt == 'p')
				printPeriod = true;
			else
				printPeriod = false;

			maquinas->at(index).printBilhetes(printPeriod);
			break;
		}
		case 'o':
		{
			maquinas->at(index).ordenaBilhetes();
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

template <class T>
int vectorSearchPosto(string loc, vector<T> *postos)
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
			std::cin.ignore();
			std::getline(std::cin, localizacao);
			postos->push_back(PostoDeVenda(localizacao));
			break;
		}
		case 'm':
		{
			std::cout << "insira a localizacao da maquina automatica." << std::endl;
			std::cin.ignore();
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
			std::cin.ignore();
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
			std::cin.ignore();
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


