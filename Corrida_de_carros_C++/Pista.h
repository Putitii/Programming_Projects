#pragma once
#include "includes.h"

// e a pista que avanca o TEMPO NA CORRIDA (se ja come�ou) e avisa os carros que o tempo avancou
// permite terminar a corrida
// mostra classificacoes (obter)

class Pista
{
	int comprimento; // distancia entre a linha de partida e chegada
	bool comeca; //se come�ou a corrida ou nao (??)
public:
	Pista();
	~Pista();
};

