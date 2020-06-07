#pragma once
#include "includes.h"
#include "Carro.h"
#include "Campeonato.h"

class Campeonato;
class DVG;

class Autodromo
{
	//ainda tenho de ver como quero isto, se quero
	//  pista cpp ou nao, ou junto tudo
	int N_carros, cronometro;
	const int comprimento;
	string nome;
	static int conta_a;
	bool comecou;

	vector<Carro *> garagem; 
	vector<Carro *> pista; //carros da pista
	vector<Piloto *> pista_p;
	vector<Carro *> posicoes;
public:
	Autodromo();
	Autodromo(int n, int comp, string nom);
	Autodromo(const Autodromo &aut);
	~Autodromo();

	Autodromo& operator=(const Autodromo& temp);

	bool getComecou() const;
	int getN_Carros() const;
	int getComprimento() const;
	string getNome() const;
	int getConta_a() const;
	vector<Carro*> getVPosicoes() const;
	Carro* getCarroPosicao(int) const;

	void setN_Carros(int n);
	void setComecou(int n);
	//void setComprimento(int c);
	void setNome(string nom);
	void NovoNome();

	string getConta_aAsString() const;
	string getAutoAsString();
	//string imprimeScores();

	int desenhaPistas(HANDLE hconsola, int posX, int posY, int tam, int N);
	void desenhaDivisorias(HANDLE hconsola, int posX, int posY, int tam, int N);
	void desenhaCarros(HANDLE hconsola);
	void desenhaTempo(HANDLE hconsola);

	void desenhaCarrosInicial(HANDLE hconsola, int posX, int posY);
	void carregaTudo();
	void colocaCarrosPista(vector<Carro*>&, vector<Piloto*>&);

	void avancarCarros(int);
	int passaTempo(HANDLE hconsola, int n, Log &);

	int getCronometro();

	static bool comp(Carro *c1, Carro *c2);
	void sortLugares();
	void moveCarros();

	void colocaCarrosGaragem(vector<Carro*> &carros);
	void desenhaCarrosGaragem(HANDLE hconsola, int, int);

	void somaPontos();
	void resetCarros();
	void carregaBat(char c, int e);

	bool apagaCarroCorrida(char c, DVG &);
	int pesquisaCarroPosicoes(char c);
	int pesquisaCarroPista(char c);
	int pesquisaCarroNoCondutor(char c);
	//bool saiDoCarro(char c);
};

