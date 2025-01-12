#include "Slime.h"
#include <iostream>

using namespace std;

Slime::Slime(int id, const char* png) :
	Personagem(id, png)
{
	chao = 800;
	setVelocidae(500, 0);
	setCoordenadas(875, 800);
	pontos = 0;
	noChao = 1;
	moviX = 1;
	moviY = 1;
	wPress = 0;
	relogio.restart();
	impulso = 600;
	setCorpo(100, 100);
}

Slime::~Slime() {
}

void Slime::mover(float aux) {


	if (!noChao)
	{

		velocidadeY += static_cast<float>(gravidade) * atualizaDelta();
		if ((corpo.getPosition().y + velocidadeY) >= chao) {
			velocidadeY = chao - corpo.getPosition().y;
		}

		if (!wPress && velocidadeY < 0) {

			if (velocidadeY < 0) {
				velocidadeY = 0;
			}

			wPress = 1;

			mover(aux);
		}

		corpo.move(aux, velocidadeY);

		if (corpo.getPosition().y >= chao) {
			noChao = 1;
			velocidadeY = 0;
		}
	}
	else {
		corpo.move(aux, 0);
	}


}

void Slime::processaEvento() {

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		if (moviX == 1) {
			mover(atualizaDelta() * velocidadeX);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		if (moviY == 1) {
			mover(atualizaDelta() * -velocidadeX);
		}
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::W)) {

		if (noChao) {
			velocidadeY = -impulso * atualizaDelta();
			noChao = 0;
			wPress = 1;
		}
		mover(0);
	}
	else {
		wPress = 0;
		mover(0);
	}
}



void Slime::executar(){
	if (corpo.getPosition().y >= chao) {
		noChao = 1;
		velocidadeY = 0;
	}
	processaEvento();
	pGGrafico->desenha(corpo);
	//cout << chao << endl;
	//cout << corpo.getPosition().y << endl;
	//cout << noChao << endl;

}



