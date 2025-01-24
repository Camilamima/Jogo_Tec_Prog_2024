#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Jogo::Jogo():
Slime1(1),
Slime2(2),
listaEntidades(),
ratinho(4),
doguinho(4),
plat(3),
plat2(3),
plat3(3),
//esp(3),
//obst_facil(3),
gerent(),
gerentC()
{	
	int num_jogadores;

	cout << "Para 1 jogador tecle 1" << endl;
	cout << "Para 2 jogadores tecle 2" << endl;
	//cin >> num_jogadores;
	num_jogadores = 2;
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

	//incluindo na lista ent e na de colisoes
	listaEntidades.Incluir(&ratinho, &gerentC);
	listaEntidades.Incluir(&plat, &gerentC);
	listaEntidades.Incluir(&plat2, &gerentC);
	listaEntidades.Incluir(&plat3, &gerentC);
	//listaEntidades.Incluir(&esp, &gerentC);
	//listaEntidades.Incluir(&obst_facil, &gerentC);
	listaEntidades.Incluir(&doguinho, &gerentC);

	listaEntidades.setGG(&gerent); //setando gg

	//mudar de local
	plat.geraPlataforma(100, 100, 400, 100);
	plat2.geraPlataforma(100, 100, 300, 800);
	plat3.geraPlataforma(40, 500, 600, 600);

}

Jogo::~Jogo(){
}

void Jogo::executar(){

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

		gerent.mostrar();
    }
}