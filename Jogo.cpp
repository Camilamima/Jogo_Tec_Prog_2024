#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Jogo::Jogo():
Slime1(-1),
ratinho(-1),
//plat(-1),
plat2(-1),
plat3(-1),
esp(-1),
obst_facil(-1),
gerent(),
gerentC()
{	
	ratinho.setGerenciador(&gerent);
    Slime1.setGerenciador(&gerent);
	//plat.setGerenciador(&gerent);
	esp.setGerenciador(&gerent);
	obst_facil.setGerenciador(&gerent);
	plat2.setGerenciador(&gerent);
	plat3.setGerenciador(&gerent);

	//mudar de local
	//plat.geraPlataforma(40, 1800, 0, 860);
	plat2.geraPlataforma(40, 1200, 0, 700);
	plat3.geraPlataforma(40, 500, 600, 300);

	//provisórioss
	gerentC.setJogadores(&Slime1, nullptr);
	//gerentC.includeObstaculo(&plat);
	gerentC.includeObstaculo(&plat2);
	gerentC.includeObstaculo(&plat3);

}

Jogo::~Jogo(){
}

void Jogo::executar(){

	
	plat2.setpJogador(&Slime1);
	//plat.setpJogador(&Slime1);
	esp.setpJogador(&Slime1);
	obst_facil.setpJogador(&Slime1);
	plat3.setpJogador(&Slime1);



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

		gerentC.executar();
		ratinho.executar();
		//plat.executar();
		plat2.executar();
		plat3.executar();
		Slime1.executar();
		esp.executar();
		obst_facil.executar();
		

		gerent.mostrar();
		
    }
	
}