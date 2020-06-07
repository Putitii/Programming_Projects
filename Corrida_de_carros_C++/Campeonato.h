#pragma once
#include "includes.h"
//#include "Autodromo.h"
#include "DVG.h"

class DVG;
class Autodromo;

class Campeonato
{
	vector<Carro *> pares_c; //????
	vector<Piloto *> pares_p; //????
	vector<Autodromo*> autodromos;
	vector<Autodromo*> corridas; //vetor dos autodromos mas ordenado
	vector<Carro*> garagem;
	vector<string> log;
	int index; //numero da corrida que ja vai
public:
	Campeonato();
	~Campeonato();

	vector<Autodromo*> getAutodromos();
	Autodromo* getAutodromo(int i);
	Autodromo* getCorrida(int i);
	string getAutodromosAsString();

	bool apagaAutodromo(string n);
	void criaAutodromo(int n, int comp, string nome);
	void LeFichAutodromos(string);
	int pesquisaAutodromo(string n);

	void fazPares(const DVG &dvg);

	string getCorridasAsString();
	string getParesAsString();
	int getIndex() const;
	void setIndex(int i);

	string listaCorridas();
	bool criaCampeonato(string cmd);

	int desenhaCorrida(HANDLE hconsola, Autodromo &aut, bool);
	void desenhaGaragem(HANDLE hconsola, Autodromo &atual);
	//void carregaBat(char c, int e);

	Autodromo* proxCorrida();
	vector<Carro*> getVParesC();
	vector<Piloto*> getVParesP();
	Carro* getParC(int i) const;	
	Piloto* getParP(int i) const;

	bool apagaCarroCampeonato(char c, Autodromo &aut, DVG &dvg);

	//void guardaPontos(Autodromo &aut);
	void colocaCarrosGaragem(Autodromo &aut);

	void sortScoreFinal();
	static bool comp(Piloto* p1, Piloto* p2);

	int pesquisaCNosPares(char c);
};

