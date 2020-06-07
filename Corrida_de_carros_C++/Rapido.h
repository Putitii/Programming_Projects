#pragma once
#include "Piloto.h"
#include "Carro.h"
#include "includes.h"

class Rapido :	public Piloto {
public:
	Rapido(string t, string n);
	Rapido();
	virtual ~Rapido();

	int avancaTempo(int n, int c, vector<Carro*> carros, Log &log) override;
};

