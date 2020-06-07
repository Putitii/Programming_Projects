#include "DVG.h"

DVG::DVG()
{
}
//------------------------------------------------------
DVG::~DVG()
{
	//cout << "Destruindo DVG" << endl;
	for (auto el : vetor_carros) {
		delete el;
	}
	for (auto elem : vetor_pilotos) {
		delete elem;
	}
}
//------------------------------------------------------
int DVG::getNCarros() const{
	return n_carros;
}
//------------------------------------------------------	
int DVG::getNPilotos() const{
	return n_pilotos;
}
//------------------------------------------------------
void DVG::setNCarros(int n) {
	n_carros = n;
}
//------------------------------------------------------
void DVG::setNPilotos(int n){
	n_pilotos = n;
}
//------------------------------------------------------
Carro* DVG::getCarro(int i) const{
	return vetor_carros[i];
}
//------------------------------------------------------
Piloto* DVG::getPiloto(int i) const{
	return vetor_pilotos[i];
}
//------------------------------------------------------
vector<Carro *> DVG::getVCarros()  const{
	return vetor_carros;
}
//------------------------------------------------------
vector<Piloto *> DVG::getVPilotos() const{
	return vetor_pilotos;
}
//------------------------------------------------------
//comando carregaC
void DVG::LeFichCarros(string fich) {
	ifstream ficheiro(fich);
	string linha, marca, modelo;
	int capIni, capMax;

	if (ficheiro) {
		while (getline(ficheiro, linha)) {
			istringstream i(linha);
			if (i >> capIni && i >> capMax && i >> marca && i >> modelo) {
				//teste print: cout << capIni << " " << capMax << " " << marca << " " << modelo << endl;
				vetor_carros.push_back(new Carro(capIni, capMax, marca, modelo));
			}
			else {
				cerr << "leitura ficheiro invalida!\n";
			}
		}
		ficheiro.close();
	}
	else {
		cerr << "erro ao abrir ficheiro "<< fich << endl;
	}
}
//------------------------------------------------------
//comando carregaP
void DVG::LeFichPilotos(string fich) {
	ifstream ficheiro(fich);
	string tipo, nome, linha;

	if (ficheiro) {
		while (getline(ficheiro, linha)) {
			istringstream i(linha);
			if (i >> tipo && i >> nome) {
				Piloto *tp = new Piloto(); //temporario para aceder a variavel static
				
				if (vetor_pilotos.size() == 0) { //se nao encontrou nome igual
					if (tipo == "crazy") {
						CrazyDriver *temp = new CrazyDriver(tipo, nome);
						temp->NovoNome();
						vetor_pilotos.push_back(temp);
						delete tp;
					}
					else if (tipo == "rapido") {
						Rapido *temp = new Rapido(tipo, nome);
						temp->NovoNome();
						vetor_pilotos.push_back(temp);
						delete tp;
					}
				}
				else if (pesquisaPiloto(nome) == -1) { //nao encontrou
					if (tipo == "crazy") {
						CrazyDriver *temp = new CrazyDriver(tipo, nome);
						vetor_pilotos.push_back(temp);
						delete tp;

					}
					else if (tipo == "rapido") {
						Rapido *temp = new Rapido(tipo, nome);
						vetor_pilotos.push_back(temp);
						delete tp;

					}
				}
				else if (pesquisaPiloto(nome) != -1) { //se encontrou
					if (tipo == "crazy") {
						CrazyDriver *temp = new CrazyDriver(tipo, nome);
						vetor_pilotos.push_back(temp);
						delete tp;
					}
					else if (tipo == "rapido") {
						Rapido *temp = new Rapido(tipo, nome);
						vetor_pilotos.push_back(temp);
						delete tp;
					}
				}
			}
			else {
				cerr << "leitura ficheiro invalida!\n";
			}
		}	
		ficheiro.close();
	}
	else {
		cerr << "erro ao abrir ficheiro " << fich << endl;
	}
}
//------------------------------------------------------
void DVG::criaCarro(int capi, int capmax, string mar, string mod) {
	//cap_ini, cap_max, marca, modelo
	Carro *temp = new Carro(capi, capmax, mar, mod);
	vetor_carros.push_back(temp);
}
//------------------------------------------------------
void DVG::criaPiloto(string tipo, string nome) {
	//tipo, nome
	Piloto *tp = new Piloto(); //temporario para aceder a variavel static

	if (vetor_pilotos.size() == 0) { //se nao encontrou nome igual
		if (tipo == "crazy") {
			CrazyDriver *temp = new CrazyDriver(tipo, nome);
			vetor_pilotos.push_back(temp);
		}
		else if (tipo == "rapido") {
			Rapido *temp = new Rapido(tipo, nome);
			vetor_pilotos.push_back(temp);
		}
		delete tp;
	}
	else if (pesquisaPiloto(nome) == -1) { //nao encontrou
		if (tipo == "crazy") {
			CrazyDriver *temp = new CrazyDriver(tipo, nome);
			vetor_pilotos.push_back(temp);
		}
		else if (tipo == "rapido") {
			Rapido *temp = new Rapido(tipo, nome);
			vetor_pilotos.push_back(temp);
		}
		delete tp;
	}
	else if (pesquisaPiloto(nome) != -1) {
		if (tipo == "crazy") {
			CrazyDriver *temp = new CrazyDriver(tipo, nome);
			temp->NovoNome();
			vetor_pilotos.push_back(temp);
		}
		else if (tipo == "rapido") {
			Rapido *temp = new Rapido(tipo, nome);
			temp->NovoNome();
			vetor_pilotos.push_back(temp);
		}
		delete tp;
	}
}
//------------------------------------------------------
bool DVG::apagaCarro(char c) {
	int ind = pesquisaCarro(c);
	if (ind != -1) { //se encontrou carro
		saiDoCarro(c);
		delete vetor_carros[ind];
		vetor_carros.erase(vetor_carros.begin() + ind);
		vetor_carros[ind]->dimConta_c();
		return true;
	}
	cout << "Carro não existe!\n" << endl;
	return false;
}
//------------------------------------------------------
bool DVG::apagaPiloto(string n) {
	int ind = pesquisaPiloto(n);
	if (ind != -1) { //se encontrou carro
		delete vetor_pilotos[ind];
		vetor_pilotos.erase(vetor_pilotos.begin() + ind);
		vetor_pilotos[ind]->dimConta_p();
		return true;
	}
	cout << "Piloto não existe!\n" << endl;
	return false;
}
//------------------------------------------------------
bool DVG::entraNoCarro(char c, string n) {
	//entranocarro <letraCarro> <nomePiloto>
	int car = pesquisaCarro(c);
	int p = pesquisaPiloto(n);

	if (car != -1 && vetor_carros[car]->getDanificado() == false) { //ve se carro existe e n esta danificado
		if (p != -1) {
			if (!encontrouPilotoNoCarro(n)) { //ve se o piloto ja esta num carro
				//se nao
				vetor_carros[car]->setCondutor(getPiloto(p)); //liga piloto carro
				vetor_pilotos[p]->setCarro(getCarro(car));
				return true;
			}
			else {
				cout << "Piloto ja esta noutro carro!" << endl;
				return false;
			}
		}
		else {
			cerr << "piloto nao existe!\n";
			return false;
		}
	}		
	else {
		cout << "Carro nao existe!\n";
		return false;
	}
	return true;
}
//------------------------------------------------------
bool DVG::saiDoCarro(char c) {
	//saidocarro <letraCarro>
	int car = pesquisaCarro(c); //se carro existe
	string n = vetor_carros[car]->getNomeCondutor();
	int pil = pesquisaPiloto(n);

	if (car != -1) { //ve se carro existe
		if (vetor_carros[car]->getCondutor() != nullptr) {
			vetor_carros[car]->setCondutor(0);
			vetor_pilotos[pil]->setCarro(0);
		}
		else {
			cerr << "Carro esta vazio!\n";
		}
	}
	else {
		cout << "Carro nao existe!\n";
		return false;
	}
	return true;
}
//------------------------------------------------------
bool DVG::encontrouPilotoNoCarro(string no) const{ //se o piloto conduz algum carro
	for (unsigned int i = 0; i < vetor_carros.size(); i++) {
		if (vetor_carros[i]->getNomeCondutor() == no)
			return true; //existe condutor num carro
	}
	return false;
}
//------------------------------------------------------
int DVG::pesquisaCarro(char c) {
	for (unsigned int j = 0; j < vetor_carros.size(); j++) {
		if (vetor_carros[j]->getId() == c) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
int DVG::pesquisaPiloto(string n) const{
	for (unsigned int j = 0; j < vetor_pilotos.size(); j++) {
		if (vetor_pilotos[j]->getNome() == n) {
			return j;
		}
	}
	return -1;
}
//------------------------------------------------------
void DVG::listaInfo(Campeonato camp) {
	cout << "\n\nListagem de Entidades:" << endl;
	cout << "---------------------------" << endl;
	cout << "Carros:" << endl;
	if (vetor_carros.size() > 0) {
		cout << GetVCarrosAsString();
		cout << endl;
	}
	else {
		cout << "Nao existem carros!" << endl;
	}
	cout << "--------------------------------" << endl;
	cout << "Pilotos: " << endl;
	if (vetor_pilotos.size() > 0) {
		cout << GetVPilotosAsString();
		cout << endl;
	}
	else {
		cout << "Nao existem pilotos!" << endl;
	}
	cout << "--------------------------------" << endl;
	cout << "Autodromos: " << endl;
		if (camp.getAutodromos().size() > 0) {
			cout << camp.getAutodromosAsString();
			cout << endl;
		}
		else {
			cout << "Nao existem autodromos!" << endl;
		}
		
	}
//------------------------------------------------------
string DVG::GetVCarrosAsString() const{
	ostringstream os; 
	for (unsigned int i = 0; i < vetor_carros.size(); i++) {
		os << vetor_carros[i]->getCarroAsString();
	}
	return os.str();
}
//------------------------------------------------------
string DVG::GetVPilotosAsString() const {
	ostringstream os;
	for (unsigned int i = 0; i < vetor_pilotos.size(); i++) {
		os << vetor_pilotos[i]->getPilotoAsString();
	}
	return os.str();
}
//------------------------------------------------------

//------------------------------------------------------
void DVG::desenhaCarrosGaragem(HANDLE hconsola) {
	Consola::gotoxy(80, 1);
	int y = 1;
	for (unsigned int i = 0; i < vetor_carros.size(); i++) {
		if (i % 2 == 1) {
			SetConsoleTextAttribute(hconsola, 95);
			Consola::gotoxy(80, 1 + y);

			if (vetor_carros[i]->getCondutor() != NULL) {
				cout << (char)(toupper(vetor_carros[i]->getId()));
			}
			else {
				cout << vetor_carros[i]->getId();
			}
		}
		else {
			SetConsoleTextAttribute(hconsola, 63);
			Consola::gotoxy(80, 1 + y);
		}
		y++;
	}
}
//------------------------------------------------------
int DVG::contaCarrosParaCamp() {
	int conta = 0;
	for (unsigned int i = 0; i < vetor_carros.size(); i++) {
		if (vetor_carros[i]->getCondutor() != NULL) {
			conta++;
		}
	}
	return conta;
}
//------------------------------------------------------








