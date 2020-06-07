#pragma once
#include "includes.h"
#include "Piloto.h"
#include "Carro.h"
#include "Autodromo.h"
#include "Rapido.h"
#include "CrazyDriver.h"

class Campeonato;

class DVG
{
	vector<Piloto *> vetor_pilotos;
	vector<Carro *> vetor_carros;
	int n_carros;
	int n_pilotos;
public:
	DVG();
	~DVG();

	int getNCarros() const;
	int getNPilotos() const;
	void setNCarros(int n);
	void setNPilotos(int n);

	//vector<Piloto> acrescentaPilotos();
	//vector<Carro> acrescentaCarros();
	void LeFichPilotos(string);
	void LeFichCarros(string);

	//-------
	int contaCarrosParaCamp();

	Carro* getCarro(int i) const;
	Piloto* getPiloto(int i) const;

	vector<Carro *> getVCarros() const;
	vector<Piloto *> getVPilotos() const;
	
	void criaPiloto(string t, string n);
	void criaCarro(int capi, int capmax, string mar, string mod);

	bool apagaCarro(char c);
	bool apagaPiloto(string n);

	bool entraNoCarro(char, string);
	bool saiDoCarro(char c);

	//void setCondutor(Piloto*);
	//void setCarro(Carro& car, Piloto& piloto);

	bool encontrouPilotoNoCarro(string no) const;
	int pesquisaCarro(char c);
	int pesquisaPiloto(string n) const;
	int procuraCondutor(string no);

	void listaInfo(Campeonato);
	string GetVCarrosAsString() const;
	string GetVPilotosAsString() const;

	void carregaBat(char c, int e);
	//void carregaTudo();

	void desenhaCarrosGaragem(HANDLE hconsola);
};

