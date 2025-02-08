#include "Menu.h"
#include "Fases/Fase.h"

Menu::Menu(int id,const char* png):
    Ente(id,png)
{
    pfase = nullptr;
    continuar = 0;
    menu = 1;
    fase = -1;
    selec = 0;
	fonte.loadFromFile(FONTES);
	setaTextos1();
    seta.setSize(Vector2f(40.0f, 40.0f));
    seta.setTexture(&sprite);
    seta.setPosition(60.0f, 300.0f);
    timer.restart();
}

Menu::~Menu() {
	
}

void Menu::setFase(Fases::Fase* f) {
    pfase = f;
    pfase->setMenu(this);
    menu = 4;
}

void Menu::comandos() {

    int i = (int)nomes.size()-1;
    
    if (timer.getElapsedTime().asSeconds() > 0.15) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { 
            selec++;  
            if (selec > i) {
                selec = 0; 
            }
        }

        // Verifica se a seta para cima foi pressionada
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {  
            selec--;  
            if (selec < 0) {
                selec = i;  
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
        
            if (menu == 1) {
                if (selec == i) {
                    setaTextos2();
                    selec = 0;
                    menu =2;
                }
                else if (selec == 0) {
                    fase = 1;
                    setaTextos3();
                    selec = 0;
                    menu = 3;
                }
                else if (selec == 2) {
                    continuar = 1;
                }
                else {
                    continuar = 1;
                }
            }
            else if (menu == 2) {
                if (selec == 0) {
                    setaTextos3();
                    fase = 1;
                    selec = 0;
                    menu = 3;
                    continuar = 0;
                }
                else if(selec==1){
                    fase = 2;
                    setaTextos3();
                    selec = 0;
                    menu = 3;
                    continuar = 0;
                }
            }
            else if (menu == 3) {
                continuar = 1;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            if (menu !=4) {
                menu = 1;
                setaTextos1();
            }
        }

        seta.setPosition(60.0f, 300.0f + ((float)selec * 60.0f));
        timer.restart();
    }
}

void Menu::setaTextos1() {
    nomes.clear(); // Limpa o vetor nomes
    textos.clear();
    nomes.push_back("Novo Jogo");
    nomes.push_back("Recuperar Jogo");
    nomes.push_back("LeaderBoard");
    nomes.push_back("Selecionar Fase");

    textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

    for (int i = 0; i < nomes.size(); i++) {
        textos[i].setFont(fonte);
        textos[i].setString(nomes[i]);
        textos[i].setCharacterSize(50);
        textos[i].setFillColor(sf::Color::White);
        textos[i].setPosition(100, 300 + i * 60);
    }
}

void Menu::setaTextos3() {
    nomes.clear(); // Limpa o vetor nomes
    textos.clear();
    nomes.push_back("1 Jogador");
    nomes.push_back("2 Jogadores");

    textos.resize(nomes.size());

    for (int i = 0; i < nomes.size(); i++) {
        textos[i].setFont(fonte);
        textos[i].setString(nomes[i]);
        textos[i].setCharacterSize(50);
        textos[i].setFillColor(sf::Color::White);
        textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
    }
}

void Menu::setaPause() {

    nomes.clear(); // Limpa o vetor nomes
    textos.clear();
    nomes.push_back("Salvar");
    nomes.push_back("Sair do jogo");
    nomes.push_back("Voltar ao jogo");
    textos.resize(nomes.size());

    for (int i = 0; i < nomes.size(); i++) {
        textos[i].setFont(fonte);
        textos[i].setString(nomes[i]);
        textos[i].setCharacterSize(50);
        textos[i].setFillColor(sf::Color::White);
        textos[i].setPosition(100.0f, 300.0f + (float)i * 60.0f);
    }

}

void Menu::setaTextos2() {
    nomes.clear(); // Limpa o vetor nomes
    textos.clear();
    nomes.push_back("Floresta");
    nomes.push_back("Caverna");

    textos.resize(nomes.size());

    for (int i = 0; i < nomes.size(); i++) {
        textos[i].setFont(fonte);
        textos[i].setString(nomes[i]);
        textos[i].setCharacterSize(50);
        textos[i].setFillColor(sf::Color::White);
        textos[i].setPosition(100.0f, 300.0f+ (float)i * 60.0f);
    }
}

void Menu::Pause() {
    int i = (int)nomes.size() - 1;

    for (int i = 0; i < textos.size(); i++) {
        pGGrafico->window.draw(textos[i]);
    }

    pGGrafico->desenha(seta);
    pGGrafico->window.display();
    pGGrafico->clear();

    if (timer.getElapsedTime().asSeconds() > 0.5) {

            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            selec++;
            if (selec > i) {
                selec = 0;
            }
            seta.setPosition(60.0f, 300.0f + ((float)selec * 60.0f));
            timer.restart();
        }

        // Verifica se a seta para cima foi pressionada
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            selec--;
            if (selec < 0) {
                selec = i;
            }
            seta.setPosition(60.0f, 300.0f + ((float)selec * 60.0f));
            timer.restart();
        }

        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (selec == 0) {
                pfase->salvaFase();
            }
            else if(selec ==1){
                pGGrafico->window.close();
            }
            else {
                pfase->setPause(false);
            }
        }


    }
}



void Menu::executar() {

    for (int i = 0; i < textos.size(); i++) {
        pGGrafico->window.draw(textos[i]);
    }

    pGGrafico->desenha(seta);
    pGGrafico->window.display();
    pGGrafico->clear();
    comandos();
    if (continuar == 1) {
        setaPause();

    }

}