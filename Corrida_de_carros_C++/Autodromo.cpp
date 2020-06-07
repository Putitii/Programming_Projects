#include "Autodromo.h"

Autodromo::Autodromo() : comprimento(130)
{
	conta_a++; //aumento aqui por causa do objeto temporario
}
//------------------------------------------------------
Autodromo::Autodromo(const Autodromo &aut) : comprimento(aut.comprimento) {
	nome = aut.nome;
	if (N_carros > 7) {
		N_carros = 7;
	}
	else {
		N_carros = aut.N_carros;
	}
	conta_a++;
	comecou = false;
	cronometro = 0;
}
//------------------------------------------------------
Autodromo::Autodromo(int n, int comp, string nom) : comprimento(comp) {
	if (N_carros > 7) {
		N_carros = 7;
	}
	else {
		N_carros = n;
	}
	nome = nom;
	conta_a++;
	comecou = false;
	cronometro = 0;
}
//------------------------------------------------------
Autodromo::~Autodromo()
{
	if (conta_a > 0) {
		conta_a--;
	}
	//cout << "Destruindo Autodromo " << nome << endl;
}
//------------------------------------------------------
Autodromo& Autodromo::operator=(const Autodromo& temp)
{
	N_carros = temp.N_carros;
	return *this;
}
//------------------------------------------------------
int Autodromo::getN_Carros() const {
	return N_carros;
}
//------------------------------------------------------
int Autodromo::getComprimento() const {
	return comprimento;
}
//------------------------------------------------------
string Autodromo::getNome() const{
	return nome;
}
//------------------------------------------------------
void Autodromo::setN_Carros(int n) {
	N_carros = n;
}
//------------------------------------------------------
void Autodromo::setNome(string nom) {
	nome = nom;
}
//------------------------------------------------------
string Autodromo::getAutoAsString() {
	ostringstream os;
	os << "Nome: " << nome << " / Comprimento: " << comprimento
		<< " / N_carros: " << N_carros;

	return os.str();
}
//------------------------------------------------------
string Autodromo::getConta_aAsString() const {
	stringstream ss;
	ss << getConta_a();
	return ss.str();
}
//------------------------------------------------------
int Autodromo::getConta_a() const {
	return conta_a;
}
//------------------------------------------------------
bool Autodromo::getComecou() const {
	return comecou;
}
//------------------------------------------------------
void Autodromo::setComecou(int n) {
	if (n == 1) {
		comecou = true;
	}
	else
		comecou = false;
}
//------------------------------------------------------
void Autodromo::NovoNome() {
	srand((unsigned int)time(NULL));
	int num = rand() % 100;
	nome = nome + to_string(num);
}

//------------------------------------------------------
void Autodromo::desenhaTempo(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 79);
	Consola::gotoxy(1, 6);
	cout << "  ";
	Consola::gotoxy(1, 6);
	cout << cronometro;
	Consola::gotoxy(5, 6);
	cout << "Corrida " << nome;
}
//------------------------------------------------------
int Autodromo::desenhaPistas(HANDLE hconsola, int posX, int posY, int tam, int N) {
	SetConsoleTextAttribute(hconsola, 139);
	for (int c = 0; c < N; c++) { //asdsad
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < tam; i++) { //asdass
				cout << " ";
			}
			posY += 1;
			Consola::gotoxy(posX, posY);
		}
		posY += 1;
		Consola::gotoxy(posX, posY);
	}
	return posY; //posicao final da pista
}
//------------------------------------------------------
void Autodromo::desenhaCarrosInicial(HANDLE hconsola, int posX, int posY) {
	SetConsoleTextAttribute(hconsola, 79);
	posY += 1;
	Consola::gotoxy(posX, posY);
	pista[0]->setpY(posY); // 1º: 8
	cout << (char)(toupper(pista[0]->getId()));
	Consola::gotoxy(posX + 1, posY);
	cout << pista[0]->getEnergia();

	for (unsigned int i = 1; i < pista.size(); i++) {
		posY += 4;
		pista[i]->setpY(posY);
		Consola::gotoxy(posX, posY);
		cout << (char)(toupper(pista[i]->getId()));

		Consola::gotoxy(posX + 1, posY);
		cout << pista[i]->getEnergia();
	}
}
//------------------------------------------------------
void Autodromo::desenhaDivisorias(HANDLE hconsola, int posX, int posY, int tam, int N) {
	SetConsoleTextAttribute(hconsola, 112);
	posY += 3;
	for (int i = 0; i < N - 1; i++) {
		Consola::gotoxy(posX, posY);
		for (int j = 0; j < tam; j++) {
			cout << " ";
		}
		posY += 4;
	}
}
//------------------------------------------------------
void Autodromo::desenhaCarros(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 79);
	for (unsigned int i = 0; i < pista.size(); i++) {
		Consola::gotoxy(pista[i]->getpX(), pista[i]->getpY());
		cout << (char)(toupper(pista[i]->getId()));
		Consola::gotoxy(pista[i]->getpX() + 1, pista[i]->getpY());
		cout << pista[i]->getEnergia();
	}
}
//------------------------------------------------------

void Autodromo::colocaCarrosPista(vector<Carro*> &carros, vector<Piloto*> &pilotos) {
	unsigned int ind;
	for (int i = 0; i < N_carros; i++) {
		ind = i;
		if (ind < carros.size()) {
			if (carros[i]->getCondutor() != NULL) {
				pista.push_back(carros[i]);
				
				if (pilotos[i]->getTipo() == "rapido") {
					pista_p.push_back(carros[i]->getCondutor());
					
				}
				if (pilotos[i]->getTipo() == "crazy") {
					pista_p.push_back(carros[i]->getCondutor());
				}
			}
		}
	}
	posicoes = pista;
}
//------------------------------------------------------
void Autodromo::colocaCarrosGaragem(vector<Carro*> &carros) {
	unsigned int ind;
	for (int i = 0; i < N_carros; i++) {
		ind = i;
		if (ind < carros.size()) {
			if (carros[i]->getCondutor() != NULL) {
				garagem.push_back(carros[i]);
			}
		}
	}
}
//------------------------------------------------------
void Autodromo::desenhaCarrosGaragem(HANDLE hconsola, int x, int y) {
	int py = y;
	int px = x;
	SetConsoleTextAttribute(hconsola, 79);
	for (unsigned int i = 0; i < garagem.size(); i++) {
		px += 2;
		Consola::gotoxy(px, y);
		if (px > 100) {
			px = x;
			py += 1;
			Consola::gotoxy(x + 2, py);
		}
		cout << (char)(toupper(garagem[i]->getId()));
	}
}
//------------------------------------------------------
void Autodromo::carregaTudo() {
	for (unsigned int i = 0; i < pista.size(); i++) {
		pista[i]->setEnergia(pista[i]->getCap_max());
	}
}
//------------------------------------------------------
void Autodromo::carregaBat(char c, int e) {
	//carregabat <letra> <quant>
	int ind = pesquisaCarroPista(c);
	if (ind != -1) {
		if (pista[ind]->getVel() == 0) {
			if ((pista[ind]->getEnergia() + e) >= pista[ind]->getCap_max()) { //se >= maximo
				pista[ind]->setEnergia(pista[ind]->getCap_max()); //coloca o valor maximo
			}
			else {
				pista[ind]->setEnergia(pista[ind]->getEnergia() + e); //adiciona ao que ja tem
			}
		}
		else {
			cout << "Carro ainda esta em movimento!\n";
		}
		
	}
}
//------------------------------------------------------
void Autodromo::avancarCarros(int i) {
	pista[i]->setpX(pista[i]->getpX() + 1);
}
//------------------------------------------------------
int Autodromo::passaTempo(HANDLE hconsola, int n, Log &log) {
	int fim = 0;
	for (int t = 0; t < n; t++) {
		if (fim == 0) {
			cronometro++;
			for (unsigned int i = 0; i < pista.size(); i++) {
				pista_p[i]->avancaTempo(n, getCronometro(), posicoes, log);
				fim = pista[i]->moveCarro(comprimento);
				if (fim == 1) {
					return fim;
				}
				sortLugares(); //da sort aos carros
				desenhaCarros(hconsola);
			}
			log.adicionaMensagem("----\n");
		}
	}
	return fim;
}
//------------------------------------------------------
int Autodromo::getCronometro() {
	return cronometro;
}
//------------------------------------------------------
bool Autodromo::comp(Carro *c1, Carro *c2) {
	return c1->getpX() < c2->getpX();
}
//------------------------------------------------------
void Autodromo::sortLugares() { //organiza por orderm crescente
	//posicoes = pista;
	sort(posicoes.begin(), posicoes.end(), comp);
	for (unsigned int i = 0; i < posicoes.size(); i++) {
		if (cronometro > 0) {
			posicoes[i]->setLugarAnterior(posicoes[i]->getLugar());
		}
		posicoes[i]->setLugar(posicoes.size() - i);
	}
}
//------------------------------------------------------
void Autodromo::moveCarros() {
	for (unsigned int i = 0; i < pista.size(); i++) {
		pista[i]->moveCarro(comprimento);
	}
}
//------------------------------------------------------
//string Autodromo::imprimeScores() {
//	ostringstream os;
//	os << "Corrida no autodromo " << getNome() << " (" << getComprimento() << " m):\n";
//	for (unsigned int i = posicoes.size(); i-- > 0;) {
//		os << posicoes[i]->getLugar() << ". " << posicoes[i]->getId() << " " << posicoes[i]->getMarca()
//			<< " / " << posicoes[i]->getNomeCondutor() << " (" << posicoes[i]->getCondutor()->getTipo() << ")"
//			<< "- " << posicoes[i]->getEnergia() << "mAh, " << posicoes[i]->getCap_max() << "mAh - "
//			<< posicoes[i]->getpX() - 1 << "m - " << posicoes[i]->getVel() << "m/s\n";
//	}
//	return os.str();
//}
//------------------------------------------------------
vector<Carro*> Autodromo::getVPosicoes() const {
	return posicoes;
}
//------------------------------------------------------
Carro* Autodromo::getCarroPosicao(int i) const{
	return posicoes[i];
}
//------------------------------------------------------
//int Autodromo::getSize() const{
//	return this.size();
//}
//------------------------------------------------------
bool Autodromo::apagaCarroCorrida(char c, DVG &dvg) {
	int ind = pesquisaCarroPosicoes(c);
	int indx = pesquisaCarroPista(c);
	int indz = pesquisaCarroNoCondutor(c);
	if (ind != -1 && indx != -1 && indz != -1) { //se encontrou carro
		dvg.apagaCarro(c);						//retira do dvg
		posicoes.erase(posicoes.begin() + ind); //retira das posicoes
		pista.erase(pista.begin() + indx);		//retira da pista
		pista_p.erase(pista_p.begin() + indz);	//retira da pista_p
		cout << "Carro apagado!\n";
		return true;
	}
	cout << "Carro não existe!\n" << endl;
	return false;
}
//------------------------------------------------------
int Autodromo::pesquisaCarroPosicoes(char c) {
	for (unsigned int j = 0; j < posicoes.size(); j++) {
		if (posicoes[j]->getId() == c) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
int Autodromo::pesquisaCarroPista(char c) {
	for (unsigned int j = 0; j < pista.size(); j++) {
		if (pista[j]->getId() == c) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
int Autodromo::pesquisaCarroNoCondutor(char c) {
	for (unsigned int j = 0; j < pista_p.size(); j++) {
		if (pista_p[j]->getCarro()->getId() == c) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
void Autodromo::somaPontos() {
	for (unsigned int j = 0; j < posicoes.size(); j++) {
		if (pista[j]->getLugar() == 1) {
			cout << "          Carro " << (char)toupper(pista[j]->getId()) << " e o vencedor!\n";
			pista_p[j]->somaPontuacao(10);
		}
		else if (pista[j]->getLugar() == 2) {
			pista_p[j]->somaPontuacao(5);
		}
		else if (pista[j]->getLugar() == 3) {
			pista_p[j]->somaPontuacao(2);
		}
	}
}
//------------------------------------------------------
void Autodromo::resetCarros() {
	for (unsigned int i = 0; i < pista.size(); i++) {
		pista[i]->setVel(0);
		pista[i]->setpX(1);
		pista[i]->largaAcel();
		pista[i]->largaTravao();
	}
	
}
//------------------------------------------------------