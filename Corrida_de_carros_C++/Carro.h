#pragma once
#include "includes.h"
#include "Piloto.h"

class Carro
{
	// vel_max nunca vai ser ultrapassada
	// vel nunca < 0
	// O PEDAL E O ACELERADOR NAO PODEM ESTAR OS DOIS A 1
	string marca, modelo; 
	char id; //a - z (s/ valor = ?)
	string id_check = "abcdefghijklmnopqrstuvxyz";
	int vel, vel_max, energia, cap_inicial, cap_max;
	//acel +2ms, t_pedal = 2 e vai decrementando para simular os segundos
	int t_acel, t_travao; // --------- ainda tenho de ver esta implementação
	bool movimento; //0-parado, 1-movimento
	bool acel, travao; // pedal: 1 acel, 0 larga / travao: 1 trava, 0 larga
	bool sinal; // 1-ligado, 0-desligado
	bool danificado; //1-sim 0-nao
	int temp,temp2, trava;

	Piloto *condutor;

	int pX; //posicao na corrida, a partir da linha de partida
	int pY;
	int lugar; //lugar na corrida;
	int lugar_antes;
	bool garagem; //-------------------- se o veiculo esta na garagem (??)

	int tempo = 0;

	static int conta_c;
	static string usado;
public:
	//nenhum carro pode ser criado sem:
	//	- marca, cap_inicial, cap_max, vel_max, danificado, sinal, travao, acel;
	// Construtor / destrutor
	Carro();
	Carro(string, int);
	Carro(int, int, string, string);
	~Carro();

	// Obter/mudar valor das variaveis
	string getMarca() const;
	string getModelo() const;
	char getId() const;
	int getVel() const;
	int getTempo() const;
	int getCap_ini() const;
	int getCap_max() const;
	int getEnergia() const;
	int getT_Acel() const;
	int getT_Travao() const;
	int getLugar() const;
	int getLugarAnterior() const;
	//char* getId_check() const;
	void aumConta_c();
	void dimConta_c();

	// ????
	static int getConta_c();
	//get boools??
	bool getMovimento() const;
	bool getAcel() const;
	bool getTravao() const;
	bool getSinal() const;
	bool getDanificado() const;

	/*int getPontuacao();
	void somaPontuacao(int);
*/
	void setMarca(string);
	void setModelo(string);
	void setId(char);
	void setVel(int);
	void setTempo(int);
	void setCap_max(int);
	void setEnergia(int);
	void setT_Acel(int);
	void setT_Travao(int);
	void setLugar(int);
	void setLugarAnterior(int);
	//---------------------------
	void setMovimento(int);
	void setSinal(int);
	void setDanificado(int);
	//---------------------------
	Piloto* getCondutor() const;
	void setCondutor(Piloto* p);
	string getNomeCondutor() const;

	string getCarroAsString() const;
	int checkPosIgual(vector<Carro*> posicoes);

	// Movimento do carro
	void MantemVel();
	void AceleraCarro(int);
	void largaAcel();
	void TravaCarro(int);
	void largaTravao();
	
	//int procuraCondutor();
	//temporario
	void tiraCondutor();

	int getpX() const;
	int getpY() const;
	void setpX(int);
	void setpY(int);

	int moveCarro(int);

};

