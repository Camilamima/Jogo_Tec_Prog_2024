#include "Plataforma.h"

Plataforma::Plataforma(int id, const char* png) :
	Obstaculo(id, png),
	atrapalha(false),
	atrito(0.93f)
{
	setCoordenadas(2, 860);
	setCorpo(1730.0, 40.0);
}
Plataforma::~Plataforma() {
}

void Plataforma::executar() {
	pGGrafico->desenha(corpo);
}
void Plataforma::obstacular(Slime* jogador) {
	if (atrapalha == true) {
		float velX = jogador->getVelocidadeX();
		float velY = jogador->getVelocidadeY();

		jogador->setVelocidae((velX * atrito), velY);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			restaura(jogador);
		}
	}
}
void Plataforma::restaura(Slime* jogador) {
	float velY = jogador->getVelocidadeY();

	jogador->setVelocidae(VX, velY);
}
