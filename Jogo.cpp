#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Jogo::Jogo():
Slime1(1),
listaEntidades(),
ratinho(4),
plat(3),
plat2(3),
plat3(3),
esp(3),
obst_facil(3),
gerent(),
gerentC()
{	

	gerentC.setJogadores(&Slime1, nullptr);
	
	//incluindo na lista ent e na de colisoes
	listaEntidades.Incluir(&Slime1, &gerentC);
	listaEntidades.Incluir(&ratinho, &gerentC);
	listaEntidades.Incluir(&plat, &gerentC);
	listaEntidades.Incluir(&plat2, &gerentC);
	listaEntidades.Incluir(&plat3, &gerentC);
	listaEntidades.Incluir(&esp, &gerentC);
	listaEntidades.Incluir(&obst_facil, &gerentC);

	listaEntidades.setGG(&gerent); //setando gg

	//mudar de local
	plat.geraPlataforma(100, 100, 400, 600);
	plat2.geraPlataforma(200, 300, 300, 700);
	plat3.geraPlataforma(40, 500, 600, 500);

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