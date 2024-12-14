#include "Jogo.h"
#include <SFML/Graphics.hpp>

using namespace sf;

Jogo::Jogo():
Slime1(-1),
plat(-1),
gerent()
{
    Slime1.setGerenciador(&gerent);
	plat.setGerenciador(&gerent);
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

		plat.executar();
		Slime1.executar();
		//plat.obstacular(&Slime1);

		gerent.mostrar();
		
    }
	
}