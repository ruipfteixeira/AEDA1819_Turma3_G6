

#ifndef SRC_POSTODEVENDA_H_
#define SRC_POSTODEVENDA_H_

#include <string>
#include <vector>
#include "Bilhete.h"

class PostoDeVenda
{
protected:
	string localizacao;
	vector<Bilhete> bilhetes_emitidos;


public:
	PostoDeVenda(string loc);
	virtual ~PostoDeVenda() {};
	vector<Bilhete> getBilhetes();
	virtual void emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano,  string nome = "null", int idade = -1, int CC = -1, string esc = "null");
	void printBilhetes(bool printPeriod);
	int numeroBilhetes();
	int numeroBilhetes(cat_zonas cat);
	int numeroBilhetes(tipo_bilh tip);
	string getLocalizacao();
	void ordenaBilhetes();
};

class MaqAutomatica: public PostoDeVenda
{
public:
	MaqAutomatica(string loc);
	void emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano);

};



#endif /* SRC_POSTODEVENDA_H_ */
