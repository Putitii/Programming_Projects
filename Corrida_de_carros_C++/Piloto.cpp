#include "Piloto.h"

Piloto::Piloto()
{
	//conta_p++; //aumento aqui por causa do objeto temporario
	carro = nullptr;
}
//------------------------------------------------------
Piloto::Piloto(string t, string nom) {
	tipo = t;
	nome = nom;
	conta_p++;
	carro = nullptr;
}
//------------------------------------------------------
Piloto::~Piloto()
{
	/*if (conta_p > 0) {
		conta_p--;
	}*/
	//cout << "Destruindo piloto "<< nome << endl;
}
//------------------------------------------------------
string Piloto::getNome() const{
	if (nome.empty()) {
		return "vazio";
	}
	else {
		return nome;
	}
}
//------------------------------------------------------
void Piloto::setNome(string nom) {
	nome = nom;
}
//------------------------------------------------------
/*
void Piloto::setCarro(Carro* car) {
	carro = car;
}
*/
//------------------------------------------------------
int Piloto::getConta_p() const{
	return conta_p;
}
//------------------------------------------------------
void Piloto::aumConta_p()
{
	conta_p++;
}
//------------------------------------------------------
void Piloto::dimConta_p() {
	conta_p--;
}
//------------------------------------------------------
string Piloto::getPilotoAsString() const{
		ostringstream os;
		os << "Nome: " << nome << " / Tipo: " << tipo << endl;
		return os.str();
	}
//------------------------------------------------------
string Piloto::getConta_pAsString() const {
	stringstream ss;
	ss << getConta_p();
	return ss.str();
}
//------------------------------------------------------
void Piloto::NovoNome() {
	srand((unsigned int)time(NULL));
	int num = rand() % 100;
	nome = nome + to_string(num);
}
//------------------------------------------------------
Carro* Piloto::getCarro() const{
	return carro;
}
//------------------------------------------------------
void Piloto::setCarro(Carro* c) {
	carro = c;
}
//------------------------------------------------------
string Piloto::getTipo() const {
	return tipo;
}
//------------------------------------------------------
void Piloto::setTipo(string t) {
	tipo = t;
}
//------------------------------------------------------
//int Piloto::getTempo() const {
//	return tempo;
//}
////------------------------------------------------------
//void Piloto::setTempo(int t) {
//	tempo = t;
//}
//------------------------------------------------------
int Piloto::avancaTempo(int t, int c, vector<Carro*> carros, Log &) {
	return 1;
}
//------------------------------------------------------
//bool Piloto::checkPosIgual(Carro c) {
//	
//}
//------------------------------------------------------
int Piloto::verificaPos(vector<Piloto*> pilotos) {
	return 2; //lol
}
//------------------------------------------------------
//bool Piloto::ComparaPosicao(Piloto *p1, Piloto *p2) {
//	return p1->getCarro()->getpX() > p2->getCarro()->getpX();
//}
//------------------------------------------------------
void Piloto::somaPontuacao(int p) {
	pontuacao += p;
}
//------------------------------------------------------
int Piloto::getPontuacao() {
	return pontuacao;
}
//------------------------------------------------------
//------------------------------------------------------