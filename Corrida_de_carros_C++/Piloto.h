#pragma once
#include "includes.h"
#include "Log.h"

// o piloto e o utilizador (comandos) tem acesso as variaveis do carro
// um piloto esta dentro de um carro
//so pode conduzir um unico carro

class Carro;

class Piloto
{
	int pontuacao;
	string nome; //nome unico, se ja houver damos um nome novo ao piloto
	string tipo; //por agora vou fazer assim
	//bool dentro;//1- dentro do carro, 0- nao tem carro
	static int conta_p;
protected:
	Carro* carro;
	bool trava;
	int lugar;
	bool acelera;
public:
	//nome (nunca muda)
	Piloto();
	Piloto(string, string);
	~Piloto();

	string getNome() const;
	string getTipo() const;
	void setTipo(string);
	void setNome(string);

	string getPilotoAsString() const;
	string getConta_pAsString() const;

	Carro* getCarro() const;
	void setCarro(Carro* p);

	int getConta_p() const;
	void aumConta_p();
	void dimConta_p();

	void NovoNome();

	virtual int avancaTempo(int t, int, vector<Carro*>, Log &);
	virtual int verificaPos(vector<Piloto*> pilotos);
	
	void somaPontuacao(int p);
	int getPontuacao();
};

