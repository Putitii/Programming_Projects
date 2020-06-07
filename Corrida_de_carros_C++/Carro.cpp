#include "Carro.h"

Carro::Carro() {
	//conta_c++; //aumento aqui por causa do objeto temporario
}
//------------------------------------------------------
//ainda tenho de ver isto //falta tmb a energia
Carro::Carro(string marca = "modelo base", int vel_max = 30) {
	unsigned int i;
	int j = 0;
	conta_c++;
	for (i = 0; i < id_check.length(); i++) {
		if (id_check[i] != usado[j]) {
			id = id_check[i];
			usado.append(1, id_check[i]);
			break;
		}
		else {
			j++;
		}
	}
	if (i == id_check.length() - 1) {
		id = '?';
	}
	pX = 1;
	pY = 8;
	energia = 0;
	condutor = nullptr;
	lugar = 0;
	lugar_antes = 0;
}
//------------------------------------------------------
Carro::Carro(int capIni, int capMax, string ma, string model)
{
	unsigned int i = 0;
	int j = 0;
	conta_c++;
	for (i = 0; i < id_check.length(); i++) {
		if (id_check[i] != usado[j]) {
			id = id_check[i];
			usado.append(1, id_check[i]);
			break;
		}
		else {
			j++;
		}
	}
	if (i == id_check.length() - 1) {
		id = '?';
	}
	cap_inicial = capIni;
	cap_max = capMax;
	modelo = model;
	marca = ma;
	condutor = nullptr;
	energia = 0;
	pX = 1;
	pY = 8;
	lugar = 0;
	lugar_antes = 0;
}
//------------------------------------------------------
Carro::~Carro()
{
	/*if (conta_c > 0) {
		conta_c--;
	}*/
	//cout << "Destruindo carro " << id << endl;

}
//------------------------------------------------------
string Carro::getMarca() const {
	return marca;
}
//------------------------------------------------------
int Carro::getTempo() const {
	return tempo;
}
//------------------------------------------------------
string Carro::getModelo() const {
	return modelo;
}
//------------------------------------------------------
char Carro::getId() const {
	return id;
}
//------------------------------------------------------
int Carro::getVel() const {
	return vel;
}
//------------------------------------------------------
int Carro::getCap_ini() const {
	return cap_inicial;
}
//------------------------------------------------------
int Carro::getEnergia() const {
	return energia;
}
//------------------------------------------------------
int Carro::getCap_max() const{
	return cap_max;
}
//------------------------------------------------------
int Carro::getT_Acel() const {
	return t_acel;
}
//------------------------------------------------------
int Carro::getT_Travao() const {
	return t_travao;
}
//------------------------------------------------------
/*char* Carro::getId_check() const{
	return id_check;
}*/
//------------------------------------------------------
//get boools??
bool Carro::getMovimento() const {
	return movimento;
}
//------------------------------------------------------
bool Carro::getAcel() const {
	return acel;
}
//------------------------------------------------------
bool Carro::getTravao() const {
	return travao;
}
//------------------------------------------------------
bool Carro::getSinal() const {
	return sinal;
}
//------------------------------------------------------
bool Carro::getDanificado() const {
	return danificado;
}
//------------------------------------------------------
void Carro::setMarca(string s) {
	marca = s;
}
//------------------------------------------------------
void Carro::setModelo(string s) {
	modelo = s;
}
//------------------------------------------------------
//nao tenho a certeza deste tbh
void Carro::setId(char c) {
	id = c;
}
//------------------------------------------------------
void Carro::setVel(int v) {
	vel = v;
}
//------------------------------------------------------
void Carro::setTempo(int t) {
	tempo = t;
}
//------------------------------------------------------
void Carro::setEnergia(int e) {
	energia = e;
}
//------------------------------------------------------
void Carro::setCap_max(int m) {
	cap_max = m;
}
//------------------------------------------------------
void Carro::setT_Acel(int n) {
	t_acel = n;
}
//------------------------------------------------------
void Carro::setT_Travao(int n) {
	t_travao = n;
}
//------------------------------------------------------
//void Carro::setDanificado()
//set/get bools???
void Carro::setMovimento(int i){
	if (i == 1) {
		movimento = true;
	}
	else {
		movimento = false;
	}
}
//------------------------------------------------------
void Carro::setSinal(int i) {
	if (i == 1) {
		sinal = true;
	}
	else {
		sinal = false;
	}
}
//------------------------------------------------------
void Carro::setDanificado(int i) {
	if (i == 1) {
		danificado = true;
	}
	else {
		danificado = false;
	}
}
//------------------------------------------------------
void Carro::setLugar(int l) {
	lugar = l;
}
//------------------------------------------------------
void Carro::setLugarAnterior(int l) {
	lugar_antes = l;
}
//------------------------------------------------------
int Carro::getConta_c()
{
	return conta_c;
}
//------------------------------------------------------
void Carro::dimConta_c() {
	conta_c--;
}
//------------------------------------------------------
void Carro::aumConta_c() {
	conta_c++;
}
//------------------------------------------------------
void Carro::setCondutor(Piloto* p) {
	condutor = p;
}
//------------------------------------------------------
Piloto* Carro::getCondutor() const{
	return condutor;
}
//------------------------------------------------------
int Carro::getLugarAnterior() const {
	return lugar_antes;
}
//------------------------------------------------------
string Carro::getNomeCondutor() const{
	if (condutor == NULL) {
		return "vazio";
	}
	else {
		return condutor->getNome();
	}
}
//------------------------------------------------------
int Carro::getLugar() const {
	return lugar;
}
//------------------------------------------------------
void Carro::tiraCondutor() {
	condutor->setNome(NULL);
}
//------------------------------------------------------
string Carro::getCarroAsString() const{
	ostringstream os;
	os << "Id: " << id << " / Carro: " << marca << " " << modelo
		<< " / Energia: " << energia << " / " << "Condutor: ";
	if (condutor != NULL) {
		os << condutor->getNome();
		os << " (" << condutor->getTipo() << ")";
	}
	else {
		os << "--";
	}
	os << " / CapIni: " << cap_inicial << " / CapMax : " << cap_max << endl;
	
	return os.str();
}
//------------------------------------------------------

//------------------------------------------------------
void Carro::MantemVel() {
	acel = false;
	travao = false;
}
//------------------------------------------------------
void Carro::AceleraCarro(int i) {
	acel = true; //esta a acelerar
	travao = false;
	temp += i;
}
//------------------------------------------------------
void Carro::largaAcel() {
	acel = false;
}
//------------------------------------------------------
void Carro::TravaCarro(int i) {
	acel = false;
	travao = true;
	temp = 0;
	temp2 += i;
}
//------------------------------------------------------
void Carro::largaTravao() {
	travao = false;
}
//------------------------------------------------------
int Carro::getpX() const {
	return pX;
}
//------------------------------------------------------
int Carro::getpY() const {
	return pY;
}
//------------------------------------------------------
void Carro::setpX(int x) {
	pX = x;
}
//------------------------------------------------------
void Carro::setpY(int y) {
	pY = y;
}
//------------------------------------------------------
int Carro::moveCarro(int comprimento) {
	if (energia - 1 >= 0) {
		if (acel == true && travao == false) {
			temp--;
			vel++;
			pX = pX + vel;
			if (pX >= comprimento) {
				return 1;
			}
			energia--;
		}
		else if (travao == true && acel == false) {
			if (vel != 0) {
				temp = 0;
				if (temp2 > 0) {
					temp2--;
					vel--;
					pX = pX + vel;
					if (vel > 0) {
						vel--;
					}
					if (pX >= comprimento) {
						return 1;
					}
					energia--;
				}
				else if (temp2 == 0) {
					vel--;
					pX = pX + vel;
					if (pX >= comprimento) {
						return 1;
					}
					energia--;
				}
			}
		}
		else if (acel == false && travao == false && vel != 0) {
			pX = pX + vel;
			if (pX >= comprimento) {
				return 1;
			}
			energia--;
		}
	}
	else {
		if (vel > 0) {
			pX = pX + vel;
			vel--;
		}
	}
	return 0;
}
//------------------------------------------------------
int Carro::checkPosIgual(vector<Carro*> posicoes) {
	for (unsigned int i = 0; i < posicoes.size(); i++) {
		if (getpX() == posicoes[i]->getpX() && this!=posicoes[i]) {
			return i;
		}
	}
	return -1;
}