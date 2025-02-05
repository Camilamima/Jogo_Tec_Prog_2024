#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
using namespace Fases;
Jogo::Jogo()
{
    fase = 1;
    fase1 = nullptr;
    fase2 = nullptr;
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{   
    fase1 = new Fase1; 
    fase1->setGerenciador(&gerent);
    fase1->inicializa();

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

                bool i = fase1->checaFinal();

                if (fase1->checaFinal()) {

                    fase = 2;
                    gerent.clear();
                    fase2ini = 0;
                    delete fase1;
                    fase1 = nullptr;
                }
                else {

                    if (fase1->getJogadores() == 0) {
                        cout << "Fim de jogo!" << endl;
                        gerent.window.close();
                        break;
                    }
                    fase1->executar();
                }
            }
            else if (fase == 2) {
                if (fase2ini == 0) {
                    fase2 = new Fase2;
                    fase2->setGerenciador(&gerent);
                    fase2->inicializa();
                    fase2ini = 1;

                }
                else if (fase1->getJogadores() == 0) {
                    gerent.window.close();
                    cout << "Fim de jogo!" << endl;
                    break;
                }
                fase2->executar();
            }


        }
}