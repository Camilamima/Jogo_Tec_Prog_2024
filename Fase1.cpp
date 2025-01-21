#include "Fase1.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;
Fase1::Fase1() :
	Slime1(1),
	Slime2(2),
	listaEntidades(),
	ratinho(4),
	plat(3),
	plat2(3),
	plat3(3),
	esp(3),
	booster(3),
	obst_facil(3),
	gerent(),
	gerentC()
{

	/*==== setando numero de jogadores ====*/
	int num_jogadores;

	cout << "Para 1 jogador tecle 1" << endl;
	cout << "Para 2 jogadores tecle 2" << endl;
	cin >> num_jogadores;

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
	listaEntidades.Incluir(&ratinho, &gerentC);
	listaEntidades.Incluir(&plat, &gerentC);
	listaEntidades.Incluir(&plat2, &gerentC);
	listaEntidades.Incluir(&plat3, &gerentC);
	listaEntidades.Incluir(&esp, &gerentC);
	listaEntidades.Incluir(&obst_facil, &gerentC);
	listaEntidades.Incluir(&booster, &gerentC);

	/*==== setando o gerenciador grafico ====*/
	listaEntidades.setGG(&gerent);

	/*==== gerando plataforma ====*/
	plat.geraPlataforma(100, 100, 400, 600);
	plat2.geraPlataforma(200, 300, 300, 700);
	plat3.geraPlataforma(40, 500, 600, 500);

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
		gerent.clear();

		listaEntidades.Percorrer(&gerentC);//executar de td
		
		if (Slime1.getVidas() <= 0 && apareceu1 == false) {
			cout << "Jogador 1 morreu!" << endl;
			listaEntidades.MatarEntidade(&Slime1, &gerentC);
			qnt_jogadores --;
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