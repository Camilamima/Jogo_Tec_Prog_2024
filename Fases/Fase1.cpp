#include "Fase1.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Fases {
	/*ratinho(4),
		plat(3),
		plat2(3),
		plat3(3),
		esp(3),
		booster(3),
		obst_facil(3)*/
	Fase1::Fase1() :
		Slime1(1),
		Slime2(2),
		listaEntidades(),
		gerent(),
		gerentC(),
		chao(3),
		ladoE(3),
		tamanho_fase(7200),
		tamanho_zona(1800),
		zona_atual(0)
	{
		geraChao();
		geraEspinho();

		/*==== setando numero de jogadores ====*/
		int num_jogadores;

		cout << "Para 1 jogador tecle 1" << endl;
		cout << "Para 2 jogadores tecle 2" << endl;
		//cin >> num_jogadores;
		num_jogadores = 1;

		if (num_jogadores == 1) {
			cout << " Selecionado 1 jogador! " << endl;
			gerentC.setJogadores(&Slime1, nullptr);
			listaEntidades.Incluir(&Slime1, &gerentC);
		}
		if (num_jogadores == 2) {
			cout << " Selecionado 2 jogadores! " << endl;
			gerentC.setJogadores(&Slime1, &Slime2);
			listaEntidades.Incluir(&Slime1, &gerentC);
			listaEntidades.Incluir(&Slime2, &gerentC);
		}
		if (num_jogadores != 1 && num_jogadores != 2) {
			cout << "Numero invalido de jogadores!" << endl;
			cout << "Selecionado 1 jogador!" << endl;
			gerentC.setJogadores(&Slime1, nullptr);
			listaEntidades.Incluir(&Slime1, &gerentC);
		}

		/*==== incluindo na lista ent e na de colisoes ====*/
		listaEntidades.Incluir(&chao, &gerentC);
		listaEntidades.Incluir(&ladoE, &gerentC);
		/*listaEntidades.Incluir(&ratinho, &gerentC);
		listaEntidades.Incluir(&plat, &gerentC);
		listaEntidades.Incluir(&plat2, &gerentC);
		listaEntidades.Incluir(&plat3, &gerentC);
		listaEntidades.Incluir(&esp, &gerentC);
		listaEntidades.Incluir(&obst_facil, &gerentC);
		listaEntidades.Incluir(&booster, &gerentC);*/

		/*==== setando o gerenciador grafico ====*/
		listaEntidades.setGG(&gerent);

		/*==== gerando plataforma ====*/
		ladoE.geraPlataforma(900, 40, 0, 0);
		chao.geraPlataforma(40, (float)tamanho_fase, 0, 900);
		/*plat.geraPlataforma(100, 100, 400, 600);
		plat2.geraPlataforma(200, 300, 300, 700);
		plat3.geraPlataforma(40, 500, 600, 500);*/

	}

	Fase1::~Fase1() {
	}

	void Fase1::executar() {
		int qnt_jogadores = 1;
		bool apareceu1 = false;
		bool apareceu2 = false;
		if (gerentC.getJogador2() != nullptr)
			qnt_jogadores = 2;

		while (gerent.estaAberta()) {
			sf::Event event;
			while (gerent.window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					gerent.window.close();
				}
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Escape) {
						gerent.window.close();
					}
				}
			}
			gerent.arrumaCamera(checaZona());

			gerent.clear();
			listaEntidades.Percorrer(&gerentC);//executar de td

			if (Slime1.getVidas() <= 0 && apareceu1 == false) {
				cout << "Jogador 1 morreu!" << endl;
				listaEntidades.MatarEntidade(&Slime1, &gerentC);
				qnt_jogadores--;
				apareceu1 = true;
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
					break;
				}
			}
			gerent.mostrar();
		}
	}
	float Fase1::checaZona() {

		if (gerentC.getJogador2() == nullptr) {
			int xJog1;
			xJog1 = (int)Slime1.getCorpo().getPosition().x;
			xJog1 = xJog1 + (int)Slime1.getCorpo().getSize().x / 2;

			zona_atual = (xJog1 / tamanho_zona);

			return (float)zona_atual * tamanho_zona;
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


	void Fase1::geraEspinho() {
		int quantidade;
		int numeros[72] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		quantidade = (int)((rand() % 13) + 3);

		for (int k = quantidade; k > 0; k--) {
			int posicao = (rand() % 70) + 1;
			while (numeros[posicao] != 0) {
				posicao = (rand() % 70) + 1;
			}
			numeros[posicao] = 1;
		}

		//tamanho fase: 7200, 7200/72=100 cada espinho
		for (int i = 0; i < 72; i++) {
			if (numeros[i] != 0 && i > 3) {
				Obstaculos::Espinho* p = new Obstaculos::Espinho(3);
				p->setCoordenadas(i * 100, 700);
				p->setCorpo(100, 100);
				listaEntidades.Incluir(p, &gerentC);
			}

		}
	}

	void Fase1::geraChao() {
		int quantidade;
		int numeros[36] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		quantidade = (int)((rand() % 13) + 3);

		for (int k = quantidade; k > 0; k--) {
			int posicao = (rand() % 34) + 1;
			while (numeros[posicao] != 0) {
				posicao = (rand() % 34) + 1;
			}
			numeros[posicao] = 1;
		}

		//tamanho fase: 7200, 7200/36=200 cada bloco
		for (int i = 0; i < 36; i++) {
			if (i == 0 || numeros[i] == 0) {
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3);
				p->geraPlataforma(100, 200, i * 200, 800);
				listaEntidades.Incluir(p, &gerentC);
			}
			else {
				Obstaculos::SlimeMau* M = new Obstaculos::SlimeMau(3);
				M->setCoordenadas(i * 200, 800);
				M->setCorpo(200, 100);
				listaEntidades.Incluir(M, &gerentC);
			}
		}
	}
}