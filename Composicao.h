
#ifndef SRC_COMPOSICAO_H_
#define SRC_COMPOSICAO_H_


class Composicao
{
private:
	int diasProxManut;
	bool avariado;
	int id_composicao;

public:
	Composicao(int dias, bool avaria, int id);
	int getProxManut() const;
	bool getAvaria() const;
	int getId() const;
	void decDias();
	void setAvaria();
	void efetuaManutencao();
	bool operator< (const Composicao & right) const;
	bool operator== (const Composicao & right) const;
	void print();
};

#endif
