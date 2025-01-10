#include "Fase1.h"
#include <iostream>

Fase1::Fase1() :
	Slime1(10),
	Slime2(10),
	ratinho(-1),
	plat(-1),
	esp(-1),
	obst_facil(-1),
	gerent()
{
	ratinho.setGerenciador(&gerent);
	Slime1.setGerenciador(&gerent);
	Slime2.setGerenciador(&gerent);
	plat.setGerenciador(&gerent);
	esp.setGerenciador(&gerent);
	obst_facil.setGerenciador(&gerent);

}

Fase1::~Fase1() {
}

void Fase1::executar() {

	int num_jogadores = 0;

	std::cout << "1 para 1 jogador 2 para 2 jogadores!" << std::endl;

	std::cin >> num_jogadores;

	if (num_jogadores == 1)
		std::cout << "Selecionado 1 jogador!" << std::endl;
	else
		std::cout << "Selecionado 2 jogadores!" << std::endl;



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

		if (num_jogadores == 1) {
			gerent.clear();

			plat.setpJogador(&Slime1);
			plat.setpJogador2(nullptr);
			esp.setpJogador(&Slime1);
			esp.setpJogador2(nullptr);
			obst_facil.setpJogador(&Slime1);
			obst_facil.setpJogador2(nullptr);

			ratinho.executar();
			plat.executar();
			Slime1.executar();
			esp.executar();
			obst_facil.executar();

			gerent.mostrar();
		}
		else if (num_jogadores == 2) {
			gerent.clear();


			plat.setpJogador(&Slime1);
			plat.setpJogador2(&Slime2);
			esp.setpJogador(&Slime1);
			esp.setpJogador2(&Slime2);
			obst_facil.setpJogador(&Slime1);
			obst_facil.setpJogador2(&Slime2);

			ratinho.executar();
			plat.executar();
			Slime1.executar();
			Slime2.executar();
			esp.executar();
			obst_facil.executar();


			gerent.mostrar();
		}

	}

}