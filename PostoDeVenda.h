

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
	virtual ~PostoDeVenda();
	vector<Bilhete> getBilhetes();
	virtual void emiteBilhete(cat_zonas cat, tipo_bilh tip, string nome = "null", string esc = "null");
	void printBilhetes();
	int numeroBilhetes();
	int numeroBilhetes(cat_zonas cat);
	int numeroBilhetes(tipo_bilh tip);
};

class MaqAutomatica: public PostoDeVenda
{
public:
	MaqAutomatica(string loc);
	void emiteBilhete(cat_zonas cat, tipo_bilh tip);

};



#endif /* SRC_POSTODEVENDA_H_ */
