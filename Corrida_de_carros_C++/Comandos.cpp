#include "Comandos.h"
#include "Consola.h"

void Comando::LeComandosModo2(HANDLE hconsola, string autos, DVG &dvg, Campeonato &camp, Log &log) {
	bool nao_existe, correr = false, terminou = false;
	string linha, comando, args1, args2;
	int argi1, prox = 0;
	char argc1;
	int xfinal = 20;
	Scores scr;

	if (!camp.criaCampeonato(autos)) {
		cout << "Erro ao criar corridas!\n";
		return;
	}
	camp.fazPares(dvg);
	cout << camp.getCorridasAsString();

	Autodromo *atual = new Autodromo(); //faz a primeira corrida
	atual = camp.getCorrida(camp.getIndex());

	vector<Carro *> temp = camp.getVParesC(); //so para a 1a corrida
	atual->colocaCarrosGaragem(temp);

	do {
		Consola::getch();
		SetConsoleTextAttribute(hconsola, 15);
		Consola::clrscr();
		printTituloModo2(hconsola);
		//---------------------------------------------------------------------------------
		// CORRIDAS
		int f = 0;
		if (correr == true) {
			//faz aqui as funcoes da corrida
			camp.desenhaGaragem(hconsola, *atual);
			xfinal = camp.desenhaCorrida(hconsola, *atual, correr);
		}
		//---------------------------------------------------------------------------------
		nao_existe = true;
		SetConsoleTextAttribute(hconsola, 15);
		Consola::gotoxy(1, xfinal + 1);
		cout << "Comando.: ";
		getline(cin, linha);
		cout << "\n";

		stringstream is(linha);
		is >> comando;
		
		for (auto c : comandos2) {
			if (c == comando) {
				nao_existe = false;
				break;
			}
		}
		if (nao_existe) {
			cerr << "comando invalido!\n";
			continue;
		}
		else if (comando == "listacarros") {
			cout << camp.getParesAsString();
		}
		else if (comando == "carregabat" && correr == true) {
			//carregabat <carro> <quant>
			if (is >> argc1 && is >> argi1) {
				atual->carregaBat(argc1, argi1);
			}
			else {
				cerr << "argumentos invalidos!\n";
			}
		}
		else if (comando == "carregatudo" && correr == false) {
			atual->carregaTudo();
		}
		else if (comando == "acidente") {
			//acidente <carro>
			if (correr == true) {
				if (is >> argc1) {
					//funcao acidente
				}
			}
			else {
				cout << "a corrida ainda nao comecou!\n";
			}
		}
		else if (comando == "stop") {
			//stop <piloto>
			if (correr == true) {
				if (is >> args1) {
					//funcao stop
				}
				else {
					cerr << "argumentos invalidos!\n";
				}
			}
			else {
				cout << "corrida ainda nao comecou!\n";
			}	
		}
		else if (comando == "destroi") {
			//destroi <carro>
			if (correr == true) {
				if (is >> argc1) {
					camp.apagaCarroCampeonato(argc1, *atual, dvg);
				}
				else {
					cerr << "argumentos invalidos!\n";
				}
			}
			else {
				cout << "a corrida ainda nao comecou!\n";
			}
		}
		else if (comando == "passatempo") {
			//passatempo <n>
			if (correr == true) {
				if (is >> argi1) {
					atual->setComecou(1);
					if (atual->passaTempo(hconsola, argi1, log) == 1) {
						terminou = true;
						xfinal = camp.desenhaCorrida(hconsola, *atual, correr);
					}
				}
				else {
					cout << "argumentos invalidos!\n";
				}
			}
			else {
				cerr << "corrida ainda nao comecou!\n";
			}
		}
		else if (comando == "log") {
			//funcao log
			if (correr == true) {
				cout << log.getLogAsString();
			}
			else {
				cerr << "corrida ainda nao comecou!\n";
			}
		}
		else if (comando == "corrida") {
			correr = true;
			cout << "a corrida vai comecar!\n";
			vector<Carro*>p_c = camp.getVParesC();
			vector<Piloto*>p_p = camp.getVParesP();

			atual->colocaCarrosPista(p_c, p_p);
			atual->resetCarros();
			atual->carregaTudo();
		}
		else if (comando == "scores") {
			//cout << atual->imprimeScores();
			cout << scr.imprimeScores(*atual);
		}
		if (terminou) {
			atual->somaPontos();
			//atual->colocaCarrosGaragem();
			terminou = false;
			correr = false;
			atual = camp.proxCorrida();
			if (atual == NULL) {
				SetConsoleTextAttribute(hconsola, 79);
				Consola::gotoxy(50, 25);
				cout << "Campeonato Terminou!\n ";
				
				camp.sortScoreFinal();
				scr.imprimeScoresFinais(camp);
				
				delete atual;
				_fim2 = true;
			}
			else {
				SetConsoleTextAttribute(hconsola, 79);
				Consola::gotoxy(50, 25);
				atual->setComecou(0);
				//atual->resetCarros();
				cout << "Corrida Terminou!\n ";
			}
		}
	} while (!_fim2);
}
//------------------------------------------------------
bool Comando::leETrataComando(HANDLE hconsola, DVG &dvg, Campeonato &camp, Log &log) {
	string linha, comando, args1, args2, args3;
	int argi1, argi2;
	char argc1, argc2;
	bool nao_existe;

	do {
		Consola::getch();
		Consola::clrscr();
		printTituloModo1(hconsola);
		Consola::gotoxy(1, 10);
		nao_existe = true;
		SetConsoleTextAttribute(hconsola, 15);
		cout << "Comando: ";
		getline(cin, linha);
		cout << "\n";

		stringstream is(linha);
		is >> comando;
		for (auto c : comandos) {
			if (c == comando) {
				nao_existe = false;
				break;
			}
		}
		if (nao_existe) {
			cerr << "comando invalido!\n";
			continue;
		}
		else if (comando == "carregaP") {
			if (is >> args1) {
				if (args1 == "pilotos.txt") {
					dvg.LeFichPilotos(args1);
				}
				else {
					cerr << "ficheiro invalido!\n";
				}
			}
			else
				cerr << "argumentos invalidos\n";
		}
		else if (comando == "carregaC") {
			if (is >> args1) {
				if (args1 == "carros.txt") {
					dvg.LeFichCarros(args1);
				}
				else {
					cerr << "ficheiro invalido!\n";
				}
			}
			else
				cerr << "argumentos invalidos\n";
		}
		else if (comando == "carregaA") {
			if (is >> args1) {
				if (args1 == "autodromos.txt") {
					camp.LeFichAutodromos(args1);
				}
				else {
					cerr << "ficheiro invalido!\n";
				}
			}
			else
				cerr << "argumentos invalidos\n";
		}
		else if (comando == "cria") {
			if (is >> argc1) {
				if (argc1 == 'c') {
					//capIni CapMax marca modelo
					if (is >> argi1 && is >> argi2 && is >> args1 && is >> args2) {
						dvg.criaCarro(argi1, argi2, args1, args2);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else if (argc1 == 'p') {
					//tipo nome
					if (is >> args1 && is >> args2) {
						dvg.criaPiloto(args1, args2);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else if (argc1 == 'a') {
					if (is >> argi1 && is >> argi2 && is >> args1) {
						camp.criaAutodromo(argi1, argi2, args1);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else {
					cout << "LetraTipo inválido!";
				}
			}
		}
		else if (comando == "apaga") {
			if (is >> argc1) {
				if (argc1 == 'c') {
					if (is >> argc2) {
						dvg.apagaCarro(argc2);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else if (argc1 == 'p') {
					//tipo nome
					if (is >> args1) {
						dvg.apagaPiloto(args1);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else if (argc1 == 'a') {
					if (is >> args1) {
						camp.apagaAutodromo(args1);
					}
					else {
						cerr << "argumentos invalidos!\n";
					}
				}
				else {
					cerr << "LetraTipo inválido!";
				}
			}
		}
		else if (comando == "entranocarro") {
			if (is >> argc1 && is >> args1) {
				dvg.entraNoCarro(argc1, args1);
			}
			else {
				cerr << "argumentos invalidos!\n";
			}
		}
		else if (comando == "saidocarro") {
			if (is >> argc1) {
				dvg.saiDoCarro(argc1);
			}
			else {
				cerr << "argumentos invalidos!\n";
			}
		}
		else if (comando == "lista") {
			dvg.listaInfo(camp);
		}
		else if (comando == "sair") {
			return true;
		}
		//MODO 2
		else if (comando == "campeonato") {
			if (is >> args1) { //tem de ter pelo menos 1
				if (camp.pesquisaAutodromo(args1) != -1 && dvg.contaCarrosParaCamp() > 1) {
					LeComandosModo2(hconsola, linha, dvg, camp, log);
				}
				else {
					cerr << "Nao foi possivel criar campeonato!\n";
				}
			}
		}
	} while (!_fim);
	return true;
}
//------------------------------------------------------
void Comando::limpaComandosModo1(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 15);
	for (int i = 0; i < 25; i++) {
		cout << "                                                                                                     " << "\n";
	}
}
//------------------------------------------------------
void Comando::limpaComandosModo2(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 15);
	for (int i = 0; i < 15; i++) {
		cout << "                                                                                                     " << "\n";
	}
}
//------------------------------------------------------
void Comando::printIntro(HANDLE hconsola) {
	Consola::gotoxy(7, 12);
	SetConsoleTextAttribute(hconsola, 78);
	cout << "                                        ---------------------                                      ";
	Consola::gotoxy(7, 11);
	cout << "                                       | Simulador de Carros |                                     ";
	Consola::gotoxy(7, 12);
	cout << "                                        ---------------------                                      ";
	Consola::gotoxy(7, 13);
	cout << "---------------------------------------------------------------------------------------------------";
	Consola::gotoxy(7, 14);
	cout << "                                                                                                   ";
	Consola::gotoxy(7, 15);
	cout << "                                                                                                   ";
	Consola::gotoxy(7, 16);
	cout << "                                                                                                   ";
	Consola::gotoxy(7, 17);
	cout << "                                  clique numa tecla para continuar                                 ";
	Consola::gotoxy(7, 18);
	cout << "                                                                                                   ";
	SetConsoleTextAttribute(hconsola, 15);
	Consola::getch();
}
//------------------------------------------------------
//funcao ainda n esta funcional
void Comando::imprimeJanela(HANDLE hconsola) {
	int y = 2, x = 1;
	Consola::gotoxy(1, y);
	string Fundo[60][20];
	SetConsoleTextAttribute(hconsola, 2);
	for (int i = 0; i < 60; i++) {

		for (int j = 0; j < 20; j++) {
			Fundo[i][j] = " ";
			Consola::gotoxy(1, y);
			//y++;
			cout << Fundo[i][j];
		}
		//x++;
		//Consola::gotoxy(x,y);
	}

}
//------------------------------------------------------
void Comando::printTituloModo1(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 78);
	cout << "                                                                                        \n";
	cout << "                                 PRE-CAMPEONATO                                         \n";
	cout << "                                                                                        \n";
	SetConsoleTextAttribute(hconsola, 79);
}
//------------------------------------------------------
void Comando::printTituloModo2(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 78);
	cout << "                                                                                        \n";
	cout << "                                   CAMPEONATO                                           \n";
	cout << "                                                                                        \n";
	//cout << "                                   Corrida " << camp.getIndex() << "                                           \n";
	SetConsoleTextAttribute(hconsola, 15);
}
//------------------------------------------------------
void Comando::printFim(HANDLE hconsola) {
	SetConsoleTextAttribute(hconsola, 78);
	Consola::gotoxy(7, 13);
	cout << "                                                                                                   ";
	Consola::gotoxy(7, 14);
	cout << "                                        ---------------------                                      ";
	Consola::gotoxy(7, 15);
	cout << "                                       |     FIM DO JOGO     |                                     ";
	Consola::gotoxy(7, 16);
	cout << "                                        ---------------------                                      ";
	Consola::gotoxy(7, 17);
	cout << "---------------------------------------------------------------------------------------------------";
	Consola::gotoxy(7, 18);
	SetConsoleTextAttribute(hconsola, 15);
	Consola::getch();
}