

#ifndef SRC_BILHETE_H_
#define SRC_BILHETE_H_

#include <string>
using namespace std;

typedef enum cat_zonas {z1 = 1, z2, z3, z4};
typedef enum tipo_bilh {UNIC, DIAR, A_NORM, A_JUN, A_SEN, A_ESTUD};

class Bilhete
{
protected:
	cat_zonas categoria;
	tipo_bilh tipo;
	string escola;
	string nome;
	int CC, idade;
	//bool validado;

public:
	Bilhete(cat_zonas cat, tipo_bilh tip, string nome = "null", string esc = "null");
	//virtual ~Bilhete() {};
	//bool eValido();
	string getCategoria();
	//virtual int validaBilhete();
	string getTipo();
	double getPreco();
	string getEscola();
	string getNome();
	void printBilhete();
	int getCC();
	int getIdade();
};
/*
class Ocasional: public Bilhete
{
	string tipo;
	int duracao;
	//referencia local emissao?

public:
	Ocasional(string cat, string tipo);
	int validaBilhete();
	int getPreco();

};

class Assinatura: public Bilhete
{
protected:
	string nome;

public:
	Assinatura(string nome, string cat);
	string getNome();
	virtual int getPreco();
	int validaBilhete();

};

class JuniorOuSenior: public Assinatura
{
protected:
	int idade;
	int CC;

public:
	JuniorOuSenior(string nome, string cat, int idade, int CC);
	int getIdade();
	int getCC();
	int getPreco();
};

class Estudante: public JuniorOuSenior
{
protected:
	string escola;

public:
	Estudante(string nome, string cat, int idade, int CC, string escola);
	string getEscola();
};
*/

#endif /* SRC_BILHETE_H_ */
