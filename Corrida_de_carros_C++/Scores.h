#pragma once
#include "Autodromo.h"
#include "includes.h"

class Scores
{
public:
	Scores();
	~Scores();

	string imprimeScores(const Autodromo &);
	void imprimeScoresFinais(Campeonato );
};

