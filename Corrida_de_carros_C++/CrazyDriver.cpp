#include "CrazyDriver.h"
#include "Log.h"

CrazyDriver::CrazyDriver(string t, string n) : Piloto(t, n)
{
}
//------------------------------------------------------
CrazyDriver::CrazyDriver()
{
}
//------------------------------------------------------
CrazyDriver::~CrazyDriver()
{
}
//------------------------------------------------------
int CrazyDriver::verificaPos(vector<Piloto*> pilotos) {
	return 2; //so para n dar erros xd
}
//------------------------------------------------------
int CrazyDriver::avancaTempo(int t, int cronometro, vector<Carro*> posicoes, Log &log) {
	ostringstream os;
	int num, num2;
	if (cronometro == 1) { //se ja comecou a corrida
		num = (rand() % 5) + 1;
		arranca = num;
	}
	if (carro != NULL) {
		if (carro->getEnergia() > 0) {
			num2 = (rand() % 2) + 1;
			if (arranca <= cronometro) {
				if (arranca == cronometro) { //primeiro arranque
					carro->AceleraCarro(1);
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s para arrancar!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
				else if (carro->checkPosIgual(posicoes) != -1) { //ve se alguem esta na mm posicao que ele
					int ind = carro->checkPosIgual(posicoes);
					if (num2 == 1) { //ou acelera 1 ou 2 para ver se sai do empate
						carro->AceleraCarro(1);
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
							<< " e Carro " << (char)toupper(posicoes[ind]->getId()) << " a lutar pelo lugar!\n";
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s\n";
						log.adicionaMensagem(os.str());
						os.str("");
					}
					else if (num2 == 2) {
						carro->AceleraCarro(2);
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
							<< " e Carro " << (char)toupper(posicoes[ind]->getId()) << " lutam pelo lugar!\n";
						os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 2 m/s\n";
						log.adicionaMensagem(os.str());
						os.str("");
					}
				}
				else if (carro == posicoes[0]) { //se esta em ultimo
					carro->TravaCarro(1);
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " travou por estar em ultimo!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
				else if (carro == posicoes[posicoes.size() - 1] /*&& arranca != cronometro*/) { //se esta em primeiro //turno arranca n conta
					carro->MantemVel();
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
						<< " mantem velocidade " << carro->getVel() << " m/s por estar em primeiro!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
				else if (carro->getLugarAnterior() < carro->getLugar()) {
					carro->AceleraCarro(2);
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 2 m/s depois de perder 1 lugar!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
				else {
					carro->AceleraCarro(1); //esta no meio
					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s para alcancar vitoria!\n";
					log.adicionaMensagem(os.str());
					os.str("");
				}
			}
		}
		else {
			carro->TravaCarro(1);
		}
		return 0;
	}
	else {
		return -1;
	}
}
//------------------------------------------------------

//------------------------------------------------------
//void CrazyDriver::avancaTempo(int t, int cronometro, vector<Carro*> posicoes, Log &log) {
//	ostringstream os;
//	int num, num2, num3;
//	if (cronometro == 1) { //primeiro arranque
//		num = (rand() % 5) + 1;
//		arranca = num;
//	}
//	if (carro->getEnergia() > 0) {
//		if (arranca <= cronometro) {
//			if (arranca == cronometro) {
//				carro->AceleraCarro(1);
//				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s para arrancar!\n";
//				log.adicionaMensagem(os.str());
//				os.str("");
//			}
//			else if (carro == posicoes[0]) { //esta em ultimo
//				if (carro->getpX() == posicoes[posicoes.size() - 1]->getpX() && carro == posicoes[posicoes.size() - 1]) { //se esta na mesma posicao q o primeiro
//					carro->AceleraCarro(1);
//					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
//						<< " e Carro " << (char)toupper(posicoes[posicoes.size() - 1]->getId()) << " a lutar pelo primeiro lugar!\n";
//					log.adicionaMensagem(os.str());
//					os.str("");
//				}
//				else if (cronometro != 1) {
//					carro->TravaCarro(1);
//					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " travou por estar em ultimo!\n";
//					log.adicionaMensagem(os.str());
//					os.str("");
//				}
//			}
//			else if (carro == posicoes[posicoes.size() - 1] && arranca != cronometro) { //esta em primeiro //turno arranca n conta
//				carro->MantemVel();
//				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
//					<< " mantem velocidade " << carro->getVel() << " m/s por estar em primeiro!\n";
//				log.adicionaMensagem(os.str());
//				os.str("");
//			}
//			else if (carro->getpX() == posicoes[posicoes.size() - 1]->getpX() && carro != posicoes[posicoes.size() - 1]) {
//				if (carro->getEnergia() > posicoes[posicoes.size() - 1]->getEnergia()) {
//					carro->AceleraCarro(2);
//					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 2 m/s!\n";
//					log.adicionaMensagem(os.str());
//					os.str("");
//				}
//				else {
//					carro->AceleraCarro(1);
//					os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s!\n";
//					log.adicionaMensagem(os.str());
//					os.str("");
//				}
//				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId())
//					<< " e Carro " << (char)toupper(posicoes[posicoes.size() - 1]->getId()) << " a lutar pelo primeiro lugar!\n";
//				log.adicionaMensagem(os.str());
//				os.str("");
//			}
//			else if (carro->getLugarAnterior() < carro->getLugar()) {
//				carro->AceleraCarro(2);
//				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 2 m/s depois de perder 1 lugar!\n";
//				log.adicionaMensagem(os.str());
//				os.str("");
//			}
//			else {
//				carro->AceleraCarro(1); //esta no meio
//				os << "turno " << cronometro << ": " << "Carro " << (char)toupper(carro->getId()) << " acelerou 1 m/s para alcançar vitoria!\n";
//				log.adicionaMensagem(os.str());
//				os.str("");
//			}
//		}
//	}
//	else {
//		carro->TravaCarro(1);
//	}
//}