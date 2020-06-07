#include "Scores.h"

Scores::Scores()
{
}
//------------------------------------------------------
Scores::~Scores()
{
}
//------------------------------------------------------
string Scores::imprimeScores(const Autodromo &aut) {
	ostringstream os;
	os << "Corrida no autodromo " << aut.getNome() << " (" << aut.getComprimento() << " m):\n";
	for (unsigned int i = aut.getVPosicoes().size(); i-- > 0;) {
		os << aut.getCarroPosicao(i)->getLugar() << ". " << aut.getCarroPosicao(i)->getId() << " " << aut.getCarroPosicao(i)->getMarca()
			<< " / " << aut.getCarroPosicao(i)->getNomeCondutor() << " (" << aut.getCarroPosicao(i)->getCondutor()->getTipo() << ")"
			<< "- " << aut.getCarroPosicao(i)->getEnergia() << "mAh, " << aut.getCarroPosicao(i)->getCap_max() << "mAh - "
			<< aut.getCarroPosicao(i)->getpX() - 1 << "m - " << aut.getCarroPosicao(i)->getVel() << "m/s\n";
	}
	return os.str();
}
//------------------------------------------------------
void Scores::imprimeScoresFinais(Campeonato camp) {
	ostringstream os;
	Consola::gotoxy(50, 25);
	cout << "Pontuacao final do campeonato: ";
	Consola::gotoxy(50, 26);
	cout << "------------------------------";
	Consola::gotoxy(50, 27);
	for (unsigned int i = 0; i < camp.getVParesP().size(); i++) {
		cout << i + 1 << ": " << camp.getParP(i)->getNome() << "(" 
			<< camp.getParP(i)->getCarro()->getId() << ")"<< " " << camp.getParP(i)->getPontuacao() << " pontos";
		Consola::gotoxy(50, 28 + i);
	}
}
//------------------------------------------------------
