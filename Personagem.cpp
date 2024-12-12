#include "Personagem.h"


Personagem::Personagem(int id, const char* png) :
	Entidade(id, png)
{
	velocidadeX = 0;
	velocidadeY = 0;
	vidas = -1;
}

Personagem::~Personagem() {
	vidas = -1;
}

void Personagem::setVidas(int vid) {
	vidas = vid;
}

void Personagem::setVelocidae(float vX, float vY) {
	velocidadeX = vX;
	velocidadeY = vY;
}


const float Personagem::gravidade = 7;