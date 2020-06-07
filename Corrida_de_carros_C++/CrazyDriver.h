#pragma once
#include "Piloto.h"
#include "Carro.h"
#include "includes.h"

class CrazyDriver: public Piloto {
	int arranca = 0;
public:
	CrazyDriver(string t, string n);
	CrazyDriver();
	~CrazyDriver();

	int avancaTempo(int n, int c, vector<Carro*>, Log &) override;
	int verificaPos(vector<Piloto*> pilotos);
	//bool checkPosIgual(Carro c, vector<Carro*> posicoes) override;

	//bool verificaPrimeiro(vector<Piloto*> pilotos);
	//bool verificaUltimo(vector<Piloto*> pilotos);

};

