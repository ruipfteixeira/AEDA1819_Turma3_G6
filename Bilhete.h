

#ifndef SRC_BILHETE_H_
#define SRC_BILHETE_H_

#include <string>
using namespace std;
/**
 * enum que define as zonas possiveis para os bilhetes
 */
typedef enum cat_zonas {z1 = 1, z2, z3, z4};
/**
 * enum que define os tipos de bilhetes
 */
typedef enum tipo_bilh {UNIC = 1, DIAR, A_NORM, A_JUN, A_SEN, A_ESTUD};

/**
 * class Bilhete
 * representa um bilhete de metro emitido, independentemente do tipo e zona
 */
class Bilhete
{
protected:

	cat_zonas categoria; /**< zona para a qual o bilhete foi comprado */
	tipo_bilh tipo; /**< tipo do bilhete */
	string escola; /**< escola do assinante ( "null" se o bilhete nao for do tipo assinatura estudante) */
	string nome; /**< nome do assinante ("null" se o bilhete nao for de um tipo assinatura) */
	int CC;  /**< numero do CC do assinante (-1 se o bilhete nao for assinatura junior, senior ou estudante) */
	int idade; /**< idade do assinante (-1 se o bilhete nao for assinatura junior, senior ou estudante) */
	int dia /**< dia de emissao do bilhete */
		,mes /**< mes de emissao do bilhete */
		,ano; /**< ano de emissao do bilhete */

public:
	/**
	 * construtor da class Bilhete
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
	Bilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano,  string nome = "null", int idade = -1, int CC = -1, string esc = "null");
	/**
	 * retorna a zona do bilhete
	 * @return zona do bilhete
	 */
	string getCategoria();
	/**
	 * retorna o tipo do bilhete
	 * @return tipo do bilhete
	 */
	string getTipo();
	/**
	 * retorna o preco do bilhete
	 * @return preco do bilhete
	 */
	double getPreco();
	/**
	 * retorna a escola do comprador do bilhete
	 * @return escola do comprador do bilhete
	 */
	string getEscola();
	/**
	 * retorna o nome do comprador do bilhete
	 * @return nome do comprador do bilhete
	 */
	string getNome();
	/**
	 * imprime no ecra todos os atributos do bilhete
	 */
	void printBilhete();
	/**
	 * retorna o numero do CC do comprador do bilhete
	 * @return numero do CC do comprador do bilhete
	 */
	 int getCC();
	/**
	 * retorna a idade do comprador do bilhete
	 * @return idade do comprador do bilhete
	 */
	int getIdade();
	/**
	 * retorna a data de emissao do bilhete
	 * @return vector que contem a data de emissao do bilhete na forma {DD,MM,AAAA}
	 */
	vector<int> getData();
	/**
	 * retorna true se o argumento da esquerda for menor cronologicamente que o da direita
	 */
	bool operator< (const Bilhete & c) const;
	/**
	 * retorna true se o argumento da esquerda for maior cronologicamente que o da direita
	 */
	bool operator> (const Bilhete & c) const;

};


#endif /* SRC_BILHETE_H_ */
