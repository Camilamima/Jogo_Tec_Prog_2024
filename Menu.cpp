#include "Menu.h"

Menu::Menu(int id,const char* png):
    Ente(id,png)
{
    selec = 0;
	fonte.loadFromFile(FONTES);
	setaTextos();
    seta.setSize(Vector2f(40.0f, 40.0f));
    seta.setTexture(&sprite);
    seta.setPosition(60.0f, 300.0f);
    timer.restart();
}

Menu::~Menu() {
	
}

void Menu::moveSeta() {
    
    if (timer.getElapsedTime().asSeconds() > 0.1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {  // Seta para baixo
            selec++;  // Aumenta o valor de selec
            if (selec > 3) {
                selec = 0;  // Se selec for maior que 5, volta para 0
            }
        }

        // Verifica se a seta para cima foi pressionada
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {  // Seta para cima
            selec--;  // Diminui o valor de selec
            if (selec < 0) {
                selec = 3;  // Se selec for menor que 0, vai para 5
            }
        }

        seta.setPosition(60.0f, 300.0f + ((float)selec * 60.0f));
        timer.restart();
    }
}

void Menu::setaTextos() {
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