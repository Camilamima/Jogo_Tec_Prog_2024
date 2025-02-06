#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>  
using namespace sf;
using namespace std;
using namespace Fases;
using json = nlohmann::json;

Jogo::Jogo():
    menu(-1)
{
    menu.setGerenciador(&gerent);
    fase = 1;
    fase1 = nullptr;
    fase2 = nullptr;
}

Jogo::~Jogo()
{

}

void Jogo::lerFase(){
        std::string nomeArquivo = "Save/fase.json";  // Caminho fixo
        std::ifstream arquivo(nomeArquivo);

        if (!arquivo) {
            std::cerr << "Erro ao abrir o arquivo JSON: " << nomeArquivo << std::endl;
            return;
        }
        else {
			cout << "Arquivo aberto com sucesso!" << std::endl;
        }

       json dados;
        arquivo >> dados;

		fase=dados["Fase"];
        if (fase == 1) {

            fase1 = new Fase1(dados, &gerent);
        }
        else if (fase == 2) {
            cout << "ainda ser implementado" << endl;
        }
}

void Jogo::executar2() {

    sf::Event event;
    while (gerent.estaAberta()) {
        while (gerent.window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                gerent.window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    gerent.window.close();
                }
            }

            menu.executar();
        }
        menu.executar();
    }

}

void Jogo::executar()
{
    
        int resp;
        cout << "você deseja carregar o jogo salvo? 1 para sim 2 para não" << endl;
        cin >> resp;
        if (resp == 1) {
            lerFase();

        }
        else {
            fase1 = new Fase1;
            fase1->setGerenciador(&gerent);
            fase1->inicializa();
        }

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
                if (event.key.code == sf::Keyboard::F1) {
                    // Chama a função para salvar o jogo
                    if (fase == 1)
                        fase1->salvaFase();
                    else if (fase == 2)
                        fase2->salvaFase();
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

                    fase1->executar();
                    /*if (fase1->getJogadores() == 0) {
                        cout << "Fim de jogo!" << endl;
                        gerent.window.close();
                        break;
                    }*/
                }
            }
            else if (fase == 2) {
                if (fase2ini == 0) {
                    fase2 = new Fase2;
                    fase2->setGerenciador(&gerent);
                    fase2->inicializa();
                    fase2ini = 1;

                }
                fase2->executar();
                /*if (fase2->getJogadores() == 0) {
                    gerent.window.close();
                    cout << "Fim de jogo!" << endl;
                    break;
                }*/
            }


        }

}