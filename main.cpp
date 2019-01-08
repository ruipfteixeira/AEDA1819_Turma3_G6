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
#include "Funcionario.h"
#include "BST.h"
#include "Composicao.h"
#include <fstream>
#include <sstream>

vector <PostoDeVenda> postos;
vector <MaqAutomatica> maquinas;
Funcionario funcNotFound(0, "", NULL);
BST<Funcionario> funcionarios(funcNotFound);
priority_queue<Composicao> composicoes;

/**
 * class excecao para inputs invalidos
 */
class OpcaoInvalida{};


/**
 * menu para adicionar um bilhete a um posto
 * @param posto apontador para o posto de venda no qual se esta a tralbalhar
 */
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
		std::cin.ignore();
		getline(std::cin, name);
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
			std::cin.ignore();
			getline(std::cin, esc);
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

}

/**
 * menu para adicionar um bilhete a um maquina
 * @param posto apontador para a maquina na qual se esta a tralbalhar
 */
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


/**
 * menu para operar um posto
 * @param index indice do posto atual no vetor de postos
 * @param postos apontador para o vetor de postos atual
 */
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
				std::cout << "Para ver o número de bilhetes vendidos escreva 'n'." << std::endl;
				std::cout << "Para voltar ao menu anterior escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'b' && option != 'o' && option != 'n' && option != 'v')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida)
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
		case 'n':
		{
			std::cout << "Para contar bilhetes de uma zona especifica escreva 'z'." << std::endl;
			std::cout << "Para contar bilhetes de uma categoria especifica escreva 'c'." << std::endl;
			std::cout << "Para contar todos os bilhetes prima qualquer outra tecla." << std::endl;
			std::cin >> printOpt;
			if(printOpt == 'z')
			{
				cat_zonas zona;
				int tempZona;
				std::cout << "Escreva o número da zona que pretende contar." << std::endl;
				std::cin >> tempZona;
				if(tempZona == 1)
				{
					zona = z1;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 2)
				{
					zona = z2;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 3)
				{
					zona = z3;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 4)
				{
					zona = z4;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else
				{
					std::cout << "Zona inválida." << std::endl;
				}
			}
			else if(printOpt == 'c')
			{
				tipo_bilh tipo;
				int tempTipo;
				std::cout << "Escreva o número respetivo à categoria que pretende contar." << std::endl;
				std::cout << "(único -> 1, diario -> 2, normal -> 3, junior -> 4, senior -> 5, estudante -> 6)" << std::endl;
				std::cin >> tempTipo;
				if(tempTipo == 1)
				{
					tipo = UNIC;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 2)
				{
					tipo = DIAR;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 3)
				{
					tipo = A_NORM;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 4)
				{
					tipo = A_JUN;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 5)
				{
					tipo = A_SEN;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 6)
				{
					tipo = A_ESTUD;
					std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else
				{
					std::cout << "Tipo inválido." << std::endl;
				}
			}
			else
			{
				std::cout << "Foram vendidos " << postos->at(index).numeroBilhetes() << " bilhetes." << std::endl;
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

/**
 * menu para operar uma maquina
 * @param index indice da maquina atual no vetor de maquinas
 * @param maquinas apontador para o vetor de maquinas atual
 */
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
				std::cout << "Para ver o número de bilhetes vendidos escreva 'n'." << std::endl;
				std::cout << "Para voltar ao menu anterior escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'b' && option != 'o' && option != 'n' && option != 'v')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida)
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
		case 'n':
		{
			std::cout << "Para contar bilhetes de uma zona especifica escreva 'z'." << std::endl;
			std::cout << "Para contar bilhetes de uma categoria especifica escreva 'c'." << std::endl;
			std::cout << "Para contar todos os bilhetes prima qualquer outra tecla." << std::endl;
			std::cin >> printOpt;
			if(printOpt == 'z')
			{
				cat_zonas zona;
				int tempZona;
				std::cout << "Escreva o número da zona que pretende contar." << std::endl;
				std::cin >> tempZona;
				if(tempZona == 1)
				{
					zona = z1;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 2)
				{
					zona = z2;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 3)
				{
					zona = z3;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else if(tempZona == 4)
				{
					zona = z4;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(zona) << " bilhetes desta zona." << std::endl;
				}
				else
				{
					std::cout << "Zona inválida." << std::endl;
				}
			}
			else if(printOpt == 'c')
			{
				tipo_bilh tipo;
				int tempTipo;
				std::cout << "Escreva o número respetivo à categoria que pretende contar." << std::endl;
				std::cout << "(único -> 1, diario -> 2)" << std::endl;
				std::cin >> tempTipo;
				if(tempTipo == 1)
				{
					tipo = UNIC;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else if(tempTipo == 2)
				{
					tipo = DIAR;
					std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes(tipo) << " bilhetes deste tipo." << std::endl;
				}
				else
				{
					std::cout << "Tipo inválido." << std::endl;
				}
			}
			else
			{
				std::cout << "Foram vendidos " << maquinas->at(index).numeroBilhetes() << " bilhetes." << std::endl;
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

/**
 * pesquisa um posto ou maquina num vetor de postos ou maquinas, respetivamente
 * @param loc localizacao do posto ou maquina que se deseja procurar
 * @param postos apontador para o vetor no qual se pretende procurar um posto ou maquina
 * @return indice do posto ou maquina desejados no vetor (-1 se nao existir)
 */
template <class T>
int vectorSearchPosto(string loc, vector<T> *postos)
{
	for(unsigned int i = 0; i < postos->size(); i++)
	{
		if(postos->at(i).getLocalizacao() == loc)
		{
			return i;
		}
	}
	return -1;
}

/**
 * menu para adicionar um posto ou maquina ao respetivo vetor
 * @param postos apontador para o vetor de postos atual
 * @param maquinas apontador para o vetor de maquinas atual
 */
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

			catch(OpcaoInvalida)
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

/**
 * menu para procurar um posto ou maquina no respetivo vetor (caso seja encontrado avanca para o menu para operar sobre este)
 * @param postos apontador para o vetor de postos atual
 * @param maquinas apontador para o vetor de maquinas atual
 */
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

			catch(OpcaoInvalida)
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



// Cria um ficheiro com a localizacao e bilhetes de cada posto de venda e de cada maquina. O formato e do tipo:
// . localizacao posto 1
// bilhete 1
// bilhete 2
// (...)
// . localicazao posto 2
// (..)
// %             (usado para separar postos de maquinas uma unica vez)
// . localicazao maquina 1
// bilhete 1
// (...)
//
//
// Tem como input o nome do ficheiro onde guardara a informacao. A informacao do bilhete e toda processada de forma a estar toda contida na string linha.

void ExportSaveFile(string ficheiro){
	string linha;
	ofstream File(ficheiro);

	// postos
	for(unsigned int iP = 0; iP < postos.size(); iP++){
	 	 if(File.is_open()){
	 		 File << postos.at(iP).getLocalizacao();
	 		 File << "\n";
		 }
	 for(unsigned int i1 = 0; i1 < postos.at(iP).getBilhetes().size(); i1++){
		 string zona = (postos.at(iP).getBilhetes().at(i1).getCategoria());
		 string tipo = (postos.at(iP).getBilhetes().at(i1).getTipo());
		 string data = (postos.at(iP).getBilhetes().at(i1).getDataString());
		 string name = (postos.at(iP).getBilhetes().at(i1).getNome());
		 string age = to_string((postos.at(iP).getBilhetes().at(i1).getIdade()));
		 string CCidadao = to_string((postos.at(iP).getBilhetes().at(i1).getCC()));
		 string school = (postos.at(iP).getBilhetes().at(i1).getEscola());
		 linha = zona + "|" + tipo + "|" + data + "|" + name + "|" + age + "|" + CCidadao + "|" + school + "|";
		 zona.clear();tipo.clear();data.clear();name.clear();age.clear();CCidadao.clear();school.clear();
	 	 if(File.is_open()){
	 	 File << linha;
		 File << "\n";
		 }
	 }

	}

	 if(File.is_open()){
		 File << "%";
		 File << "\n";
	 }

 	 // maquinas

 	for(unsigned int iP = 0; iP < maquinas.size(); iP++){
 	 	 if(File.is_open()){
 	 		 File << maquinas.at(iP).getLocalizacao();
 	 		 File << "\n";
 		 }
 	 for(unsigned int i1 = 0; i1 < maquinas.at(iP).getBilhetes().size(); i1++){
 		 string zona = (maquinas.at(iP).getBilhetes().at(i1).getCategoria());
 		 string tipo = (maquinas.at(iP).getBilhetes().at(i1).getTipo());
 		 string data = (maquinas.at(iP).getBilhetes().at(i1).getDataString());
 		 linha = zona + "|" + tipo + "|" + data + "|";
		 zona.clear();tipo.clear();data.clear();

 	 	 if(File.is_open()){
 	 	 File << linha;
 		 File << "\n";
 		 }
 	 }

	}
	File.close();
}



// Le um ficheiro e converte a informacao de localizacao/bilhetes dos postos/maquinas.
// Tem como input o nome do ficheiro de onde le a informacao.
// Descodifica cada um dos passos usados para guardar e cria novos vetores de postos/maquinas.


void ImportSaveFile(string ficheiro){
	string linha;
	string info;
	ifstream File(ficheiro);
	int counter = 0;
	int counterPosto = -1;
	int counterMaquina = -1;

	string location;
	cat_zonas zone;
	tipo_bilh tip;
	string name;
	string esc;
	int Ccidadao;
	int age;
	int day, month, year;
	vector<Bilhete> listabilhetes;

	postos.clear();
	maquinas.clear();
	bool PostoMaquina = true; // true = posto | false = maquina

	if(File.is_open()){
		while(getline(File,linha)){
			bool local = true;
			bool separator = false;
			for(unsigned int c = 0; c < linha.size(); ++c) {
				if (linha[c] == '|') {
					local = false;
				}
				if (linha[c] == '%'){
					local = false;
					PostoMaquina = false;
					separator = true;
				}
			}

			cout << linha << endl;

			if (local && PostoMaquina){
				location = linha;
				postos.push_back(PostoDeVenda(location));
				counterPosto++;
			}

			if (local && (!PostoMaquina)){
				location = linha;
				maquinas.push_back(MaqAutomatica(location));
				counterMaquina++;
			}


			if(PostoMaquina  && (!local) && (!separator)){
			 for(unsigned int i = 0; i < linha.size(); ++i) {
			    if (linha[i] == '|'){
			    	switch (counter){

			    	case 0:{
			    		if(info == "z1"){ zone = z1;}
			    		if(info == "z2"){ zone = z2;}
			    		if(info == "z3"){ zone = z3;}
			    		if(info == "z4"){ zone = z4;}
			    		break;
			    	}

			    	case 1:{
			    		if(info == "unico"){tip = UNIC;}
			    		if(info == "diario"){tip = DIAR;}
			    		if(info == "assinatura_normal"){tip = A_NORM;}
			    		if(info == "assinatura_junior"){tip = A_JUN;}
			    		if(info == "assinatura_senior"){tip = A_SEN;}
			    		if(info == "assinatura_estudante"){tip = A_ESTUD;}
			    		break;
			    	}

			    	case 2:{
			    		string info2;
			    		int counter2 = 0;
			    		for(unsigned int i2 = 0; i2 < info.size(); ++i2) {
			    			if (info[i2] == '/'){

			    				if(counter2 == 0){day = stoi(info2);}
			    				if(counter2 == 1){month = stoi(info2);}

			    				info2.clear();
			    				counter2++;
			    			}
			    			else{
						    	stringstream ss2;
						    	string s2;
						    	char c2 = info[i2];
						    	ss2 << c2;
						    	ss2 >> s2;
						    	info2 = info2 + s2;
			    			}
			    		}
			    		year = stoi(info2);
			    		info2.clear();
			    		break;
			    	}

			    	case 3:{
			    		name = info;
			    		break;
			    	}

			    	case 4:{
			    		age = stoi(info);
			    		break;
			    	}

			    	case 5:{
			    		Ccidadao = stoi(info);
			    		break;
			    	}

			    	case 6:{
			    		esc = info;
			    		break;
			    	}

			    	default: {
			    		break;
			    	}

			    	}

			    	counter++;
			    	info.clear();
			    }

			    else{
			    	stringstream ss;
			    	string s;
			    	char c = linha[i];
			    	ss << c;
			    	ss >> s;
			    	info = info + s;
			    }
			 }
			 postos.at(counterPosto).emiteBilhete(zone,tip,day,month,year,name,age,Ccidadao,esc);
			 counter = 0;
			}


			if((!PostoMaquina)  && (!local) && (!separator)){
			 for(unsigned int i = 0; i < linha.size(); ++i) {
			    if (linha[i] == '|'){
			    	switch (counter){

			    	case 0:{
			    		if(info == "z1"){ zone = z1;}
			    		if(info == "z2"){ zone = z2;}
			    		if(info == "z3"){ zone = z3;}
			    		if(info == "z4"){ zone = z4;}
			    		break;
			    	}

			    	case 1:{
			    		if(info == "unico"){tip = UNIC;}
			    		if(info == "diario"){tip = DIAR;}
			    		break;
			    	}

			    	case 2:{
			    		string info2;
			    		int counter2 = 0;
			    		for(unsigned int i2 = 0; i2 < info.size(); ++i2) {
			    			if (info[i2] == '/'){

			    				if(counter2 == 0){day = stoi(info2);}
			    				if(counter2 == 1){month = stoi(info2);}

			    				info2.clear();
			    				counter2++;
			    			}

			    			else{
						    	stringstream ss2;
						    	string s2;
						    	char c2 = info[i2];
						    	ss2 << c2;
						    	ss2 >> s2;
						    	info2 = info2 + s2;
			    			}
			    		}
			    		year = stoi(info2);
			    		info2.clear();
			    		break;
			    	}

			    	default: {break;}

			    	}

			    	counter++;
			    	info.clear();
			    }

			    else{
			    	stringstream ss;
			    	string s;
			    	char c = linha[i];
			    	ss << c;
			    	ss >> s;
			    	info = info + s;
			    }
			 }
			 maquinas.at(counterMaquina).emiteBilhete(zone,tip,day,month,year);
			 counter = 0;
			}

		}
		File.close();
	}
}

void gereFuncionarios(vector <PostoDeVenda> *postos)
{
	char option;
	bool progress = false, exit = false;
	string nome, loc;
	int index, salario;
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar um funcionario escreva 'a'." << std::endl;
				std::cout << "Para remover um funcionario escreva 'r'." << std::endl;
				std::cout << "Para imprimir a lista de Funcionarios escreva 'p'." << std::endl;
				std::cout << "Para voltar ao menu inicial escreva 'v'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'r' && option != 'p' && option != 'v')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida)
			{
				std::cout << "Inseriu uma opção inválida, por favor tente outra vez." << std::endl;
				progress = false;
			}
		}while(progress == false);
		switch(option)
		{
		case 'a':
		{
			std::cout << "Insira o valor do salario." << std::endl;
			std::cin >> salario;
			std::cout << "Insira o nome do funcionario." << std::endl;
			std::cin.ignore();
			std::getline(std::cin, nome);
			std::cout << "Insira a localização do posto de venda." << std::endl;
			std::getline(std::cin, loc);
			index = vectorSearchPosto(loc, postos);
			if(index == -1)
			{
				std::cout << "Não há postos nesta localizacao." << std::endl;
			}
			else
			{
				funcionarios.insert(Funcionario(salario, nome, &(postos->at(index))));
			}
			break;
		}
		case 'r':
		{
			std::cout << "Insira o valor do salario." << std::endl;
			std::cin >> salario;
			std::cout << "Insira o nome do funcionario." << std::endl;
			std::cin.ignore();
			std::getline(std::cin, nome);
			funcionarios.remove(Funcionario(salario, nome, NULL));
			break;
		}
		case 'p':
		{
			funcionarios.printTree();
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

void gereComposicoes(priority_queue<Composicao> * composicoes)
{
	char option;
		bool progress = false, exit = false;
		int index, id, dias;
		bool avaria;
		char avaria_in;
		do
		{
			do
			{
				try
				{
					std::cout << std::endl << "Escolha uma opção:" << std::endl;
					std::cout << "Para adicionar uma composição escreva 'a'." << std::endl;
					std::cout << "Para remover uma composição escreva 'r'." << std::endl;
					std::cout << "Para imprimir a lista de Composições escreva 'p'." << std::endl;
					std::cout << "Para decrementar o número de dias restantes para a próxima manutenção escreva 'd'." << std::endl;
					std::cout << "Para efetuar uma manutenção da composição no topo da fila escreva 'm'." << std::endl;
					std::cout << "Para voltar ao menu inicial escreva 'v'." << std::endl;
					std::cin >> option;

					if(option != 'a' && option != 'r' && option != 'p' && option != 'd' && option != 'm' && option != 'v')
					{throw OpcaoInvalida();}
					progress = true;
				}

				catch(OpcaoInvalida)
				{
					std::cout << "Inseriu uma opção inválida, por favor tente outra vez." << std::endl;
					progress = false;
				}
			}while(progress == false);
			switch(option)
			{
			case 'a':
			{
				std::cout << "Insira o número identificativo da composição." << std::endl;
				std::cin >> id;
				std::cout << "Insira o número de dias até à próxima manutenção." << std::endl;
				std::cin >> dias;
				std::cout << "Indique se a composição está avariada.('s' caso sim, qualquer outra tecla caso não)" << std::endl;
				std::cin >> avaria_in;
				if(avaria_in == 's')
					avaria = true;
				else
					avaria = false;
				composicoes->push(Composicao(dias, avaria, id));
				break;
			}
			case 'r':
			{
				std::cout << "Insira o número identificativo da composição." << std::endl;
				std::cin >> id;
				vector<Composicao> temp;
				Composicao temp2(0, false, id);
				while(!(composicoes->empty()))
				{
					temp.push_back(composicoes->top());
					composicoes->pop();
				};
				for(int i = 0; i < temp.size(); i++)
				{
					if(temp.at(i) == temp2)
					{
						temp.erase(temp.begin()+i);
						break;
					}
				}
				for(int i = 0; i < temp.size(); i++)
				{
					composicoes->push(temp.at(i));
				}
				break;
			}
			case 'p':
			{
				vector<Composicao> temp;
				while(!(composicoes->empty()))
				{
					temp.push_back(composicoes->top());
					composicoes->pop();
				};
				for(int i = 0; i < temp.size(); i++)
				{
					temp.at(i).print();
					composicoes->push(temp.at(i));
				}
				break;
			}
			case 'd':
			{
				vector<Composicao> temp;
				while(!(composicoes->empty()))
				{
					temp.push_back(composicoes->top());
					composicoes->pop();
				};
				for(int i = 0; i < temp.size(); i++)
				{
					temp.at(i).decDias();
					composicoes->push(temp.at(i));
				}
				break;
			}
			case 'm':
			{
				if((composicoes->top().getAvaria() && composicoes->top().getProxManut() < 10) || (!(composicoes->top().getAvaria()) && composicoes->top().getProxManut() == 0))
				{
					Composicao temp = composicoes->top();
					composicoes->pop();
					temp.efetuaManutencao();
					composicoes->push(temp);
				}
				else
					std::cout << "Manutenção desnecessária." << std::endl;
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
}


/**
 * menu principal, no qual se pode carregar ou guardar um ficheiro e trabalhar na sessao atual
 */
void mainMenu()
{
	char option;
	bool progress = false, exit = false;
	std::cout << "Sistema de Registo de Bilhetes de Metro v(4*10^7).0" << std::endl;

	std::cout << "Para carregar um ficheiro existente escreva 'c'. Para criar um novo escreva 'n'." << std::endl;
	std::cin >> option;

	if(option == 'c'){
		std::cout << "Indique o nome do ficheiro." << std::endl;
		string savefileI;
		cin >> savefileI;
		ImportSaveFile(savefileI);
	}
	do
	{
		do
		{
			try
			{
				std::cout << std::endl << "Escolha uma opção:" << std::endl;
				std::cout << "Para adicionar postos ou maquinas escreva 'a'." << std::endl;
				std::cout << "Para procurar um posto ou maquina escreva 'p'." << std::endl;
				std::cout << "Para gerir funcionários escreva 'f'." << std::endl;
				std::cout << "Para gerir composições escreva 'c'." << std::endl;
				std::cout << "Para guardar a informaçao escreva 'g'." << std::endl;
				std::cout << "Para sair escreva 's'." << std::endl;
				std::cin >> option;

				if(option != 'a' && option != 'p' && option != 'f' && option != 'c' && option != 'g' && option != 's')
				{throw OpcaoInvalida();}
				progress = true;
			}

			catch(OpcaoInvalida)
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
		case 'f':
		{
			gereFuncionarios(&postos);
			break;
		}
		case 'c':
		{
			gereComposicoes(&composicoes);
			break;
		}
		case 'g':{
			std::cout << "Indique o nome do ficheiro." << std::endl;
			string savefileE;
			cin >> savefileE;
			ExportSaveFile(savefileE);
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


