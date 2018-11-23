

#ifndef SRC_BILHETE_H_
#define SRC_BILHETE_H_

#include <string>
using namespace std;

typedef enum cat_zonas {z1 = 1, z2, z3, z4};
typedef enum tipo_bilh {UNIC = 1, DIAR, A_NORM, A_JUN, A_SEN, A_ESTUD};

class Bilhete
{
protected:
	cat_zonas categoria;
	tipo_bilh tipo;
	string escola;
	string nome;
	int CC, idade;
	int dia, mes, ano;

public:
	Bilhete(cat_zonas cat, tipo_bilh tip, int dia, int mes, int ano,  string nome = "null", int idade = -1, int CC = -1, string esc = "null");
	//virtual ~Bilhete() {};
	string getCategoria();
	string getTipo();
	double getPreco();
	string getEscola();
	string getNome();
	void printBilhete();
	int getCC();
	int getIdade();
	vector<int> getData();
	string getDataString();
	bool operator< (const Bilhete & c) const;
	bool operator> (const Bilhete & c) const;

};


#endif /* SRC_BILHETE_H_ */
