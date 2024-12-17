#include "Slime.h"

Slime::Slime(int id, const char* png) :
	Personagem(id, png)
{
	setVelocidae(VX, 0);
	setCoordenadas(875, 775);
	pontos = 0;
	noChao = 1;
	wPress = 0;
	relogio.restart();
	impulso = 600;
	setCorpo(150, 150);
}

Slime::~Slime() {
}

void Slime::mover(float aux) {
	if (!noChao)
	{

		velocidadeY += static_cast<float>(gravidade) * atualizaDelta();
		if ((corpo.getPosition().y + velocidadeY) > 775) {
			velocidadeY = 775 - corpo.getPosition().y;
		}

		if (!wPress && velocidadeY < 0) {

			if (velocidadeY < 0) {
				velocidadeY = 0;
			}

			wPress = 1;

			mover(aux);
		}

		corpo.move(aux, velocidadeY);

		if (corpo.getPosition().y >= 775) {
			noChao = 1;
			velocidadeY = 0;

		}
	}
	else {
		corpo.move(aux, 0);
	}


}

void Slime::processaEvento() {
	/*Event event;
	while (pGGrafico->window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			pGGrafico->window.close();
		}
	}*/

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		mover(atualizaDelta() * velocidadeX);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		mover(atualizaDelta() * -velocidadeX);
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



void Slime::executar() {
	processaEvento();
	pGGrafico->desenha(corpo);
}
