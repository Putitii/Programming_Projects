#include "DVG.h"
#include "Comandos.h"
#include "Jogo.h"
#include "Log.h"
using namespace std;

int Carro::conta_c = 0;
int Piloto::conta_p = 0;
int Autodromo::conta_a = 0;
string Carro::usado = "";

int main()
{
	bool fim = false;
	DVG dvg;
	Campeonato camp;
	Comando cd;
	Log log;
	HANDLE hconsola = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)time(NULL));

	Consola::setScreenSize(40, 150);
	cd.printIntro(hconsola);
	Consola::setBackgroundColor(0);
	Consola::clrscr();
	
	do {
		fim = cd.leETrataComando(hconsola, dvg, camp, log);
	} while(!fim);

	Consola::clrscr();
	cd.printFim(hconsola);

	return 0;
}
