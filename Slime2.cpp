#include "Slime2.h"

Slime2::Slime2(int id, const char* png) :
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

Slime2::~Slime2() {
}

void Slime2::mover(float aux) {
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

void Slime2::processaEvento() {

	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		mover(atualizaDelta() * velocidadeX);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		mover(atualizaDelta() * -velocidadeX);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {
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

void Slime2::executar() {
	processaEvento();
	pGGrafico->desenha(corpo);
}

