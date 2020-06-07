#include "includes.h"
#include "Campeonato.h"
#include "DVG.h"
#include "Log.h"
#include "Scores.h"

//temos de fazer os comandos todos do modo 1, exceto o savedgv, loaddgv, deldgv
//so temos de fazer os comandos campeonato <>, e passtempo <> PARA META 1

class Comando {
	std::vector<std::string> comandos = { "carregaP", "carregaC", "carregaA"
		, "cria", "apaga", "entranocarro", "saidocarro","sair", "lista"
		, "savedgv", "loaddgv", "deldgv", "campeonato" };

	std::vector<std::string> comandos2 = { "listacarros","scores", "carregabat", "carregatudo"
		, "corrida", "acidente", "stop", "destroi","passatempo","log" };

	bool _fim, _fim2;
public:
	bool leETrataComando(HANDLE hconsola, DVG &dvg, Campeonato &camp, Log &log);
	void LeComandosModo2(HANDLE hconsola, string, DVG&, Campeonato&, Log &log);
	void limpaComandosModo1(HANDLE hconsola);
	void limpaComandosModo2(HANDLE hconsola);
	void imprimeJanela(HANDLE hconsola);
	void printIntro(HANDLE hconsola);
	void printTituloModo1(HANDLE hconsola);
	void printTituloModo2(HANDLE hconsola);
	void printFim(HANDLE hconsola);
};
