
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


void PostoDeVenda::ImportSaveFile(string ficheiro){
	string linha;
	string info;
	ifstream File(ficheiro);
	int counter = 0;

	cat_zonas zone;
	tipo_bilh tip;
	string name;
	string esc;
	int Ccidadao;
	int age;
	int day, month, year;

	if(File.is_open()){
		while(getline(File,linha)){
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
			    		if(info == "assinatura normal"){tip = A_NORM;}
			    		if(info == "assinatura junior"){tip = A_JUN;}
			    		if(info == "assinatura senior"){tip = A_SEN;}
			    		if(info == "assinatura estudante"){tip = A_ESTUD;}
			    		break;
			    	}

			    	case 2:{
			    		string info2;
			    		int counter2;
			    		for(unsigned int i2 = 0; i2 < info.size(); ++i2) {
			    			if (info[i] == '|'){

			    				if(counter2 == 0){day = stoi(info2);}
			    				if(counter2 == 1){month = stoi(info2);}

			    				info2.clear();
			    				counter2++;
			    			}

			    			else{
						    	stringstream ss2;
						    	string s2;
						    	char c2 = info[i];
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

			emiteBilhete(zone,tip,day,month,year,name,age,Ccidadao,esc);
		}
		File.close();
	}








}


void PostoDeVenda::ExportSaveFile(string ficheiro){
	string linha;
	ofstream File(ficheiro);

	for(unsigned int i1 = 0; i1 < bilhetes_emitidos.size(); i1++){
		string zona = (bilhetes_emitidos.at(i1).getCategoria());
		string tipo = (bilhetes_emitidos.at(i1).getTipo());
		string data = (bilhetes_emitidos.at(i1).getDataString());
		string name = (bilhetes_emitidos.at(i1).getNome());
		string age = to_string((bilhetes_emitidos.at(i1).getIdade()));
		string CCidadao = to_string((bilhetes_emitidos.at(i1).getCC()));
		string school = (bilhetes_emitidos.at(i1).getEscola());
		linha = zona + "|" + tipo + "|" + data + "|" + name + "|" + age + "|" + CCidadao + "|" + school + "|";

		if(File.is_open()){
		File << linha;
		File << "\n";
		}
	}
	File.close();
}









