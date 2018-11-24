

#ifndef SRC_POSTODEVENDA_H_
#define SRC_POSTODEVENDA_H_

#include <string>
#include <vector>
#include "Bilhete.h"

/**
 * class PostoDeVenda
 * inclui localizacao do posto e um vetor de bilhetes emitidos.
 */
class PostoDeVenda
{
protected:

	string localizacao; /**< localizacao do posto de venda */
	vector<Bilhete> bilhetes_emitidos; /**< bilhetes emitidos pelo posto de venda */


public:
	/**
	 * construtor da classe PostoDeVenda
	 * @param loc localizacao do posto
	 */
	PostoDeVenda(string loc);
	/**
	 * destrutor da classe PostoDeVenda
	 */
	virtual ~PostoDeVenda() {};
	/**
	 * funcao que retorna os bilhetes emitidos pelo posto
	 * @return vetor de bilhetes emitidos
	 */
	vector<Bilhete> getBilhetes();
	/**
	 * funcao que cria um bilhete e o coloca no vetor de bilhetes
	 * @param cat zona do bilhete
	 * @param tip tipo do bilhete
	 * @param dia dia de emissao do bilhete
	 * @param mes mes de emissao do bilhete
	 * @param ano ano de emissao do bilhete
	 * @param nome nome do comprador do bilhete (apenas para assinaturas)
	 * @param idade idade do comprador do bilhete (apenas para assinaturas junior, senior e estudante)
	 * @param CC numero do cartao de cidadao do comprador do bilhete (apenas para assinaturas junior, senior e estudante)
	 * @param esc escola do comprador do bilhete (apenas para assinaturas estudante)
	 */
	virtual void emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano,  string nome = "null", int idade = -1, int CC = -1, string esc = "null");
	/**
	 * imprime os bilhetes do posto
	 * @param printPeriod false para imprimir todos os bilhetes, true para imprimir apenas um certo periodo de tempo (segunda forma não funcional)
	 */
	void printBilhetes(bool printPeriod);
	/**
	 * retorna o numero total de bilhetes emitidos por este posto
	 * @return numero de bilhetes emitidos
	 */
	int numeroBilhetes();
	/**
	 * retorna o numero de bilhetes de uma zona emitidos por este posto
	 * @param cat zona cujos bilhetes serão contados
	 * @return numero de bilhetes da zona escolhida emitidos
	 */
	int numeroBilhetes(cat_zonas cat);
	/**
	 * retorna o numero de bilhetes de um tipo emitidos por este posto
	 * @param tip tipo cujos bilhetes serão contados
	 * @return numero de bilhetes do tipo escolhido emitidos
	 */
	int numeroBilhetes(tipo_bilh tip);
	/**
	 * retorna a localizacao do posto
	 * @return localizacao do posto
	 */
	string getLocalizacao();
	/**
	 * ordena o vetor de bilhetes emitidos do posto por ordem cronologica
	 */
	void ordenaBilhetes();
};

/**
 * class MaqAutomatica
 * versao simplificada de PostoDeVenda que nao emite bilhetes assinatura
 */

class MaqAutomatica: public PostoDeVenda
{
public:
	/**
	 * construtor da class MaqAutomatica
	 * @param loc localizacao da maquina
	 */
	MaqAutomatica(string loc);
	/**
	 * funcao que cria um bilhete e o coloca no vetor de bilhetes
	 * @param cat zona do bilhete
	 * @param tip tipo do bilhete
	 * @param dia dia de emissao do bilhete
	 * @param mes mes de emissao do bilhete
	 * @param ano ano de emissao do bilhete
	 */
	void emiteBilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano);

};



#endif /* SRC_POSTODEVENDA_H_ */
