#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>  
using namespace sf;
using namespace std;
using json = nlohmann::json;

Jogo::Jogo():
    Texto(),
    menu(-1)
{
    menu.setGerenciador(&gerent);
    fase = 1;
    Floresta_Profunda = nullptr;
    Caverna_Obscura = nullptr;
}

Jogo::~Jogo()
{
    if (Floresta_Profunda != nullptr) {
        delete Floresta_Profunda;
        Floresta_Profunda = nullptr;
    }
    if (Caverna_Obscura != nullptr) {
        delete Caverna_Obscura;
        Caverna_Obscura = nullptr;
    }
}

void Jogo::setaTextos(int text) {
    limpaTextos();
    if (text == 1) {
        nomes.push_back("Saindo da Floresta Profunda");
        nomes.push_back("Entrando na Caverna Obscura");

        textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(14600.0f, 300.0f + (float)i * 60.0f);
        }
    }
    else if (text == 2) {
        nomes.push_back("Fim de jogo");

        textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

        for (int i = 0; i < nomes.size(); i++) {
            textos[i].setFont(fonte);
            textos[i].setString(nomes[i]);
            textos[i].setCharacterSize(50);
            textos[i].setFillColor(sf::Color::White);
            textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
        }
    }

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

            Floresta_Profunda = new Fases::Floresta_Profunda(dados, &gerent);
            menu.setFase(Floresta_Profunda);
        }
        else if (fase == 2) {
            Caverna_Obscura = new Fases::Caverna_Obscura(dados, &gerent);
            gerent.BackGFloresta(2);
            menu.setFase(Caverna_Obscura);
        }
}

void Jogo::executar2() {
    int iniciou = 0;
    int opc = -1;
    int qualMenu = -1;
    bool iniciarFase = false;
    bool Caverna_Obscuraini = 0;
    int jogadores = 0;
    int ponto1 = 0;
    int ponto2 = 0;

    sf::Event event;
    while (gerent.estaAberta()) {
        while (gerent.window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                gerent.window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F4) {
                    gerent.window.close();
                }
            }
            if (event.key.code == sf::Keyboard::F1) {
                // Chama a função para salvar o jogo
                if (fase == 1)
                    Floresta_Profunda->salvaFase();
                else if (fase == 2)
                    Caverna_Obscura->salvaFase();
            }
        }

        if (!iniciarFase) {
            if (!menu.getContinuar()) {
                menu.executar();
            }
            else {
                gerent.BackGFloresta(3);
                opc = menu.getSelect();
                qualMenu = menu.getMenu();

                if (qualMenu == 3) {
                    if (opc == 0) {
                        jogadores = 1;
                    }
                    else if (opc == 1) {

                        jogadores = 2;
                    }
                    fase = menu.getFase();

                    if (fase == 1) {
                        Floresta_Profunda = new Fases::Floresta_Profunda;
                        Floresta_Profunda->setJogadores(jogadores);
                        Floresta_Profunda->setGerenciador(&gerent);
                        gerent.BackGFloresta(1);
                        Floresta_Profunda->inicializa();
                        iniciarFase = true;
                        menu.setFase(Floresta_Profunda);
                        fase = 1;
                        gerent.clear();
                    }
                    else if (fase == 2) {
                        Caverna_Obscura = new Fases::Caverna_Obscura;
                        Caverna_Obscura->setJogadores(jogadores);
                        Caverna_Obscura->setGerenciador(&gerent);
                        gerent.BackGFloresta(2);
                        Caverna_Obscura->inicializa();
                        menu.setFase(Caverna_Obscura);
                        iniciarFase = true;
                        gerent.clear();
                        Caverna_Obscuraini = 1;
                    }
                }
                else if (qualMenu == 1) {
                    if (opc == 1) {
                        lerFase();
                        iniciarFase = true;
                        gerent.clear();
                        if (fase == 2){
                            Caverna_Obscuraini = 1;
                        }
                    }
                }

            }
        }
        else {
            if (fase == 1) {


                if (Floresta_Profunda->checaFinal()) {

                    fase = 2;
                    gerent.clear();
                    Caverna_Obscuraini = 0;
                    jogadores = Floresta_Profunda->getJogadores();
                    ponto1 = Floresta_Profunda->getPontos(1);
                    ponto2 = Floresta_Profunda->getPontos(2);
                    delete Floresta_Profunda;
                    Floresta_Profunda = nullptr;
                    Clock t;
                    t.restart();
                    int x = -1;
                    setaTextos(1);
                    while (x == -1) {
                        gerent.clear();
                        desenhaTexto(&gerent); // Certifique-se de chamar a função correta para desenhar os textos
                        gerent.window.display(); // Atualiza a tela

                        if (t.getElapsedTime().asSeconds() > 3) {
                            x = 0;
                        }
                    }

                }
                else{

                    Floresta_Profunda->executar();
                }
            }
            else if (fase == 2) {
                if (Caverna_Obscuraini == 0) {
                    Caverna_Obscura = new Fases::Caverna_Obscura;
                    Caverna_Obscura->setJogadores(jogadores);
                    Caverna_Obscura->setGerenciador(&gerent);
                    Caverna_Obscura->inicializa();
                    Caverna_Obscura->setPontos(ponto1, ponto2);
                    gerent.BackGFloresta(2);
                    menu.setFase(Caverna_Obscura);
                    Caverna_Obscuraini = 1;

                }
                Caverna_Obscura->executar();
 
            }
        }

    }

}

