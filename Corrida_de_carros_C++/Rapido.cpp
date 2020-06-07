#include "Rapido.h"

Rapido::Rapido(string t, string n) : Piloto(t, n) {

}
//------------------------------------------------------
Rapido::Rapido()
{
}
//------------------------------------------------------
Rapido::~Rapido()
{
}
//------------------------------------------------------
int Rapido::avancaTempo(int t, int cronometro, vector<Carro*> carros, Log &log) {
	ostringstream os;
	int num2;
	if (carro != NULL) {
		if (carro->getEnergia() > 0) {
			if (cronometro == 1) {
				carro->AceleraCarro(1);
				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s para arrancar!\n";
				log.adicionaMensagem(os.str());
				os.str("");
			}
			else {
				//em caso de empate
				if (carro->checkPosIgual(carros) != -1) { //ve se alguem esta na mm posicao que ele
					int ind = carro->checkPosIgual(carros);

					num2 = (rand() % 2) + 1;
					if (num2 == 1) { //ou acelera 1 ou 2 para ver se sai do empate
						carro->AceleraCarro(1);
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
							<< " e Carro " << (char)toupper(carros[ind]->getId()) << " a lutar pelo lugar!\n";
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s\n";
						log.adicionaMensagem(os.str());
						os.str("");
					}
					else if(num2 == 2) {
						carro->AceleraCarro(2);
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
							<< " e Carro " << (char)toupper(carros[ind]->getId()) << " a lutar pelo lugar!\n";
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 2 m/s\n";
						log.adicionaMensagem(os.str());
						os.str("");
					}
				}
				else if (carro->getEnergia() > 0 && carro->getEnergia() > (carro->getCap_max() / 2)) {
					carro->AceleraCarro(1);
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
				else if (cronometro % 3 == 0) {
					carro->AceleraCarro(1);
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s depois de 3 segundos!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}	
				else {
					carro->MantemVel();
				}
			}
		}
		else {
			carro->TravaCarro(1);
			os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " ficou sem energia!\n";
			log.adicionaMensagem(os.str());
			os.str("");
		}
	}
	else {
		return -1;
	}
	return 0;
}
//------------------------------------------------------
//------------------------------------------------------
//------------------------------------------------------
