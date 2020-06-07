#include "Campeonato.h"

Campeonato::Campeonato()
{
	index = 0;
}
//------------------------------------------------------
Campeonato::~Campeonato()
{
}
//------------------------------------------------------
void Campeonato::LeFichAutodromos(string fich) {
	//carregaA <fich>
	ifstream ficheiro(fich);
	string nome, linha;
	int N, comp;

	if (ficheiro) {
		while (getline(ficheiro, linha)) {
			istringstream i(linha);
			if (i >> N && i >> comp && i >> nome) {
				Autodromo *tp = new Autodromo(); //temporario para aceder a variavel static

				if (comp > 130) {
					comp = 130;
				}
				if (autodromos.size() == 0) { //se nao encontrou nome igual
					Autodromo *temp = new Autodromo(N, comp, nome);
					autodromos.push_back(temp);
					delete tp;
				}
				else if (pesquisaAutodromo(nome) == -1) { //nao encontrou
					Autodromo *temp = new Autodromo(N, comp, nome);
					autodromos.push_back(temp);
					delete tp;
				}
				else if (pesquisaAutodromo(nome) != -1) {
					string nm = nome + tp->getConta_aAsString();
					Autodromo *temp = new Autodromo(N, comp, nm);
					autodromos.push_back(temp);
					delete tp;
				}
			}
		}
		ficheiro.close();
	}
}
//------------------------------------------------------
vector<Autodromo*> Campeonato::getAutodromos() {
	return autodromos;
}
//------------------------------------------------------
Carro* Campeonato::getParC(int i) const {
	return pares_c[i];
}
//------------------------------------------------------
Piloto* Campeonato::getParP(int i) const {
	return pares_p[i];
}
//------------------------------------------------------
bool Campeonato::apagaAutodromo(string n) {
	int ind = pesquisaAutodromo(n);
	if(ind != -1) {
		if (autodromos[ind]->getNome() == n){
			delete autodromos[ind];
			autodromos.erase(autodromos.begin() + ind);
			return true;
		}
	}
	else {
		cerr << "autodromo nao existe!\n";
	}
	return false;
}
//------------------------------------------------------
void Campeonato::criaAutodromo(int n, int comp, string nome) {
	//cria <letraTipo> <dados do objeto>    // N, comprimento, nome
	Autodromo *tp = new Autodromo();

	if (comp > 130) {
		comp = 130;
	}

	if (autodromos.size() == 0) { //se nao encontrou nome igual
		Autodromo *temp = new Autodromo(n, comp, nome);
		autodromos.push_back(temp);
		delete tp;
	}
	else if (pesquisaAutodromo(nome) == -1) { //nao encontrou
		Autodromo *temp = new Autodromo(n, comp, nome);
		autodromos.push_back(temp);
		delete tp;
	}
	else if (pesquisaAutodromo(nome) != -1) {
		Autodromo *temp = new Autodromo(n, comp, nome);
		temp->NovoNome();
		autodromos.push_back(temp);
		delete tp;
	}
}
//------------------------------------------------------
int Campeonato::getIndex() const {
	return index;
}
//------------------------------------------------------
void Campeonato::setIndex(int i) {
	index = i;
}
//------------------------------------------------------
int Campeonato::pesquisaAutodromo(string n) {
	for (unsigned int j = 0; j < autodromos.size(); j++) {
		if (autodromos[j]->getNome() == n) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
Autodromo* Campeonato::getAutodromo(int i) {
	return autodromos[i];
}
//------------------------------------------------------
Autodromo* Campeonato::getCorrida(int i) {
	return corridas[i];
}
//------------------------------------------------------
string Campeonato::getAutodromosAsString() {
	ostringstream os;
	for (unsigned int i = 0; i < autodromos.size(); i++) {
		os << autodromos[i]->getAutoAsString() << endl;
	}

	return os.str();
}
//------------------------------------------------------
bool Campeonato::criaCampeonato(string autos) {
	string n;
	int ind;
	istringstream s(autos);
	s >> n; //tira o comando campeonato
	while (s >> n) {
		ind = pesquisaAutodromo(n);
		if (ind != -1) { //se encontrou
			corridas.push_back(autodromos[ind]);
		}
		else {
			cerr << "Autodromo: " << n << " nao existe!\n";
		}
	}
	if (getAutodromos().size() > 0) {
		return true;
	}
	else {
		cout << "Nao existem autodromos" << endl;
		return false;
	}
}
//------------------------------------------------------
// TEMPORARIO TALVEZ SO PARA TESTAR O CRIAR DO CAMPEONATO
string Campeonato::getCorridasAsString() {
	ostringstream os;
	for (unsigned int i = 0; i < corridas.size(); i++) {
		os << "---- Campeonato ----\n";
		os << "Corrida" << i + 1 << " " <<
			corridas[i]->getNome() << " " <<
			corridas[i]->getN_Carros() << " " <<
			corridas[i]->getComprimento() << endl;
	}
	return os.str();
}
//------------------------------------------------------
string Campeonato::listaCorridas() {
	ostringstream os;
	return os.str();
}
//------------------------------------------------------
void Campeonato::fazPares(const DVG &dvg) {
	for (unsigned int i = 0; i < dvg.getVCarros().size(); i++) {
		if (dvg.getCarro(i)->getCondutor() != NULL) { //se tem condutor
			pares_c.push_back(dvg.getCarro(i));
			pares_p.push_back(dvg.getCarro(i)->getCondutor());
		}
	}
}
//------------------------------------------------------
string Campeonato::getParesAsString() {
	ostringstream os;
	os << "----Carros----\n";
	for (unsigned int i = 0; i < pares_c.size(); i++) {
		os << pares_c[i]->getCarroAsString();
	}
	os << "\n----Pilotos----\n";
	for (unsigned int j = 0; j < pares_p.size(); j++) {
		os << pares_p[j]->getPilotoAsString();
	}
	os << "\n";
	return os.str();
}
//------------------------------------------------------
Autodromo* Campeonato::proxCorrida() {
	unsigned int i = index;
	if (corridas.size() > 1 && i < (corridas.size() - 1)) {
		index++;
		return corridas[index];
	}
	else {
		return NULL;
	}
}
//------------------------------------------------------
vector<Carro*> Campeonato::getVParesC(){
	return pares_c;
}
//------------------------------------------------------
vector<Piloto*> Campeonato::getVParesP(){
	return pares_p;
}
//------------------------------------------------------
int Campeonato::desenhaCorrida(HANDLE hconsola, Autodromo &aut, bool correr) {
	int posX = 1, posY = 8;
	Consola::gotoxy(posX, posY - 2);
	aut.desenhaTempo(hconsola);
	Consola::gotoxy(posX, posY);
	int xfinal = aut.desenhaPistas(hconsola, posX, posY, aut.getComprimento(), aut.getN_Carros());
	Consola::gotoxy(posX, posY);
	aut.desenhaDivisorias(hconsola, posX, posY, aut.getComprimento(), aut.getN_Carros());
	Consola::gotoxy(posX, posY);
	if (aut.getComecou() == false && correr == true) {
		aut.desenhaCarrosInicial(hconsola, posX, posY);
	}
	else {
		aut.desenhaCarros(hconsola);
	}
	return xfinal;
}
//------------------------------------------------------
void Campeonato::desenhaGaragem(HANDLE hconsola, Autodromo &aut) {
	SetConsoleTextAttribute(hconsola, 32);
	Consola::gotoxy(90, 1);
	cout << "           ";
	Consola::gotoxy(90, 2);
	cout << "           ";
	Consola::gotoxy(90, 1);
	aut.desenhaCarrosGaragem(hconsola, 90 - 2, 1);
}
//-------------------------------------------------------
//void Campeonato::guardaPontos(Autodromo &aut) {
//	for (unsigned int i = 0; i < pares_c.size(); i++) {
//		aut.SomaPontos();
//	}
//}
//-------------------------------------------------------
void Campeonato::colocaCarrosGaragem(Autodromo &aut) {

}
//-------------------------------------------------------
bool Campeonato::apagaCarroCampeonato(char c,Autodromo &aut, DVG &dvg) {
	int ind = pesquisaCNosPares(c);
	bool encontrou = aut.apagaCarroCorrida(c, dvg);
	if (encontrou) {
		pares_c.erase(pares_c.begin() + ind);
		return true;
	}
	return false;
}
//-------------------------------------------------------
int Campeonato::pesquisaCNosPares(char c) {
	for (unsigned int j = 0; j < pares_c.size(); j++) {
		if (pares_c[j]->getId() == c) {
			return j;
		}
	}
	return -1;
}
//-------------------------------------------------------
bool Campeonato::comp(Piloto* p1, Piloto* p2) {
	return p1->getPontuacao() > p2->getPontuacao();
}
//------------------------------------------------------
void Campeonato::sortScoreFinal() {
	sort(pares_p.begin(), pares_p.end(), comp);
}
//-------------------------------------------------------

//-------------------------------------------------------