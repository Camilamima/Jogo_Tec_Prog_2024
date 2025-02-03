#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Jogo::Jogo()
{
    fase = 1;
    fase1.setGerenciador(&gerent);
    fase2.setGerenciador(&gerent);
    fase1.inicializa();
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{       
    bool fase2ini = 0;
        while (gerent.estaAberta()) {  // O loop principal fica aqui!
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
            if (fase == 1) {

                if (fase1.checaFinal()) {
                    fase = 2;
                    gerent.clear();
                    fase2ini = 0;
                }
                else {
                    fase1.executar();
                }
            }
            else if (fase == 2) {
                if (fase2ini == 0) {
                    fase2.inicializa();
                    fase2ini = 1;
                }
                fase2.executar();
            }


        }
}