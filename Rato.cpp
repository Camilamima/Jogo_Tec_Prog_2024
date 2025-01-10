#include "Rato.h"

#define CAMIHO 300

Entidades::Rato::Rato(int id, const char* png) :
	Inimigo(id, png)
{
	setVelocidae(150, 0);
	setCoordenadas(700, 775);
	relogio.restart();
	setCorpo(150, 150);
	distancia_percorrida = 0;
}

Entidades::Rato::~Rato() {  }

void Entidades::Rato::calculaDis() {
	if (velocidadeX > 0) {
		distancia_percorrida += velocidadeX * atualizaDelta();
	}
	else {
		distancia_percorrida+=-velocidadeX * atualizaDelta();
	}
}

void Entidades::Rato::executar() {

	if (distancia_percorrida >= CAMIHO) {

		velocidadeX = -velocidadeX;
		distancia_percorrida = 0;
	}
	calculaDis();
	mover(velocidadeX);
	pGGrafico->desenha(corpo);
}