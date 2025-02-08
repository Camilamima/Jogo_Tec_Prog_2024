#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> 
#include "Fase.h"
#include"../Menu.h"



using namespace sf;
using namespace std;

namespace Fases {
	Fase::Fase() :
		num_fase(-1),
		Slime1(1),
		Slime2(2),
		listaEntidades(),
		gerent(NULL),
		gerentC(),
		num_facil(-1),
		chao(3),
		ladoE(3),
		tamanho_fase(14400),
		tamanho_zona(1800),
		zona_atual(0),
		qnt_jogadores(-1),
		Pause(0)
	{
		pMenu = nullptr;
		gerent = nullptr;
	}

	Fase::~Fase() {
		limpaVec();
	}

	void Fase::limpaVec() {
     localizacao_obs.clear();
	}

	const bool Fase::checaLocaliza(float x,int ver) const {
		if (ver == 1) {
			for (int i = 0; i < localizacao_obs.size(); i++) {
				if (localizacao_obs[i] == x) {
					return 1;
				}
			}
		}
		else
		{
			for (int i = 0; i < localizacao_obs.size(); i++) {
				if (localizacao_obs[i] >= x-3  && localizacao_obs[i]<=x+400+3) {
					return 1;
				}
			}
		}
		return 0;
	}

	float Fase::checaZona() {

		if (gerentC.getJogador2() == nullptr) {
			int xJog1;
			xJog1 = (int)Slime1.getCorpo().getPosition().x;
			xJog1 = xJog1 + (int)Slime1.getCorpo().getSize().x / 2;

			zona_atual = (xJog1 / tamanho_zona);

			return (float)(zona_atual * tamanho_zona);
		}
		else {
			int xJog1, xJog2;
			xJog1 = (int)Slime1.getCorpo().getPosition().x;
			xJog1 = xJog1 + (int)Slime1.getCorpo().getSize().x / 2;
			xJog2 = (int)Slime2.getCorpo().getPosition().x;
			xJog2 = xJog2 + (int)Slime1.getCorpo().getSize().x / 2;

			zona_atual = (xJog1 / tamanho_zona);

			if (xJog2 / tamanho_zona < zona_atual) {
				zona_atual = xJog2 / tamanho_zona;
			}

			return (float)zona_atual * tamanho_zona;

		}


	}


	void Fase::geraEspinho() {
		int quantidade;
		int numeros[144] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		quantidade = (int)((rand() % 10) + 10);
		int posicao = 0;
		for (int k = quantidade; k > 0; k--) {
			posicao = (rand() % 142) + 1;
			while (numeros[posicao] != 0 || checaLocaliza((float)posicao * 100,1) ||
				(posicao < 143 && (numeros[posicao + 1] == 1 || numeros[posicao - 1] == 1)) ||
				(posicao < 142 && (numeros[posicao + 1] == 1 && numeros[posicao + 2] == 1)) ||
				(posicao > 1 && (numeros[posicao - 1] == 1 && numeros[posicao - 2] == 1) ||
				posicao%1800==0 )   
				) {
				posicao = (rand() % 142) + 1;
			}
			numeros[posicao] = 1;
		}

		//tamanho fase: 14400, 1400/144=100 cada espinho
		for (int i = 0; i < 144; i++) {
			if (numeros[i] != 0 && i > 3) {
				Obstaculos::Espinho* p = new Obstaculos::Espinho(9);
				p->setCoordenadas((float)i * 100, 700);
				p->setCorpo(100, 70);
				listaEntidades.Incluir(p, &gerentC);
			}

		}
	}



	void Fase::geraPlataformaFase(){
		if (num_fase == 1) {
			float lugar = 0;
			int tipo = 0;
			int plataforma = 0;
			time_t tempo;
			srand((unsigned)time(&tempo));

			for (float zona = 0; zona <= 7; zona++) {
				lugar = static_cast<float>((((rand() % 16) + 1) * 100) + (zona * 1800));
				tipo = (rand() % 4) + 1;
				TipoPlataforma(tipo, lugar);

			}
		}
		else if (num_fase == 2) {
			float lugar = 0;
			int tipo = 0;
			int plataforma = 0;
			time_t tempo;
			srand((unsigned)time(&tempo));

			for (float zona = 0; zona < 3; zona++) {
				lugar = static_cast<float>((((rand() % 16) + 1) * 100) + (zona * 1800));
				tipo = (rand() % 4) + 1;
				TipoPlataforma(tipo, lugar);
			}	

			//==== teste ===//
			lugar = static_cast<float>((((rand() % 10) + 1) * 50) + (1 * 1800));
			tipo = (rand() % 4) + 1;
			TipoPlataforma(tipo, lugar);
			//==============//
		}
	}

	void Fase::TipoPlataforma(int tipo,float x){

		if (tipo == 1) {//a em formato L invertido
			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3,"assets/pedra_tiles.png");
			p->geraPlataforma(300, 200, x, 560);
			
			listaEntidades.Incluir(p, &gerentC);
			Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/tronco.png");
			p2->geraPlataforma(100, 600, x + 10, 460);
			listaEntidades.Incluir(p2, &gerentC);
			localizacao_obs.push_back((int)x);
			localizacao_obs.push_back((int)x+100);
		}
		else if (tipo == 2) {
			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/planta.png");
			p->geraPlataforma(150, 100, x, 610);
			listaEntidades.Incluir(p, &gerentC);
			localizacao_obs.push_back((int)x);
		}
		else if (tipo == 3) {
			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/pedra_tiles.png");
			p->geraPlataforma(200, 300, x, 560);
			listaEntidades.Incluir(p, &gerentC);
			Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/tronco.png");
			p2->geraPlataforma(100, 200, x+200, 460);
			listaEntidades.Incluir(p2, &gerentC);
			localizacao_obs.push_back((int)x);
			localizacao_obs.push_back((int)x+100);
			localizacao_obs.push_back((int)x+200);
		}
		else if (tipo == 4) {
			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/tronco2.png");
			p->geraPlataforma(200, 100, x, 560);
			listaEntidades.Incluir(p, &gerentC);
			Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/folhas_3x.png");
			p2->geraPlataforma(100, 400, x - 50, 520);
			listaEntidades.Incluir(p2, &gerentC);
			localizacao_obs.push_back((int)x);
		}
	}

	void Fase::executar() {
		qnt_jogadores = 1;
		bool apareceu1 = false;
		bool apareceu2 = false;
		int cont1 = 0;
		int cont2 = 0;
		bool morreu = false;
		bool morreu2 = false;
		int pos_morto = -1;

		if (gerentC.getJogador2() != nullptr)
			qnt_jogadores = 2;

			gerent->arrumaCamera(checaZona());

			gerent->clear();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				Pause = true;
				pMenu->restartTime();
				while (Pause) {
					pMenu->Pause();
				}

			}
			gerent->desenha();
			listaEntidades.Percorrer(&gerentC);

			pos_morto = listaEntidades.VerificMortos();

			if (pos_morto != -1) {
				listaEntidades.matarEntidadePos(pos_morto, &gerentC);
			}

			
			if (Slime1.getVidas() <= 0 && apareceu1 == false) {
				Slime1.setMorrendo(true);
				if (Slime1.getCont() % 8 == 0) {
					morreu = Slime1.animacaoMorte(cont1, 10);
					cont1++;
					if (morreu == true) {
						cout << "Jogador 1 morreu!" << endl;
						listaEntidades.MatarEntidade(&Slime1, &gerentC);
						qnt_jogadores--;
						apareceu1 = true;
					}
				}
			}

			if (gerentC.getJogador2() != nullptr && apareceu2 == false) {
				if (Slime2.getVidas() <= 0) {
					cout << "Jogador 2 morreu!" << endl;
					listaEntidades.MatarEntidade(&Slime2, &gerentC);
					qnt_jogadores--;
					apareceu2 = true;
				}
			}

			if (qnt_jogadores == 0) {
				if (Slime1.getVidas() <= 0) {
					cout << "Fim de jogo!" << endl;
					gerent->window.close();
				}
			}
			gerent->mostrar();
			
		
	}

	void Fase::salvaFase() {
		vector<Entidade*> vec = listaEntidades.returnVec();

		json jsonData;//Json pra juntar tudo
		int i;
		jsonData["Fase"] = num_fase;
		jsonData["zona"] = zona_atual;
		jsonData["jogadores"] = qnt_jogadores;

		jsonData["entidades"] = json::array();
		for (i = 0; i < vec.size(); i++) {
			if (vec[i] != nullptr) {
				jsonData["entidades"].push_back(vec[i]->salvar());
			}
		}

		std::ofstream outFile("Save/fase.json");
		outFile << jsonData.dump(4);  // "4" para indentação legível
		outFile.close();  // Fecha o arquivo

		std::cout << "Fase salva com sucesso!" << std::endl;

	}
}