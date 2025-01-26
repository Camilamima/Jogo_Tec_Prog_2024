#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Obstaculo::Obstaculo(int id,const char* png) : 
Entidade(id, png), 
atrito(1.0f),
pJogador(nullptr)
{
	danoso = false;
	atrapalha = false;
	impede = false;
	acelera = true;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::restaura(Slime* jogador) {
	float velY = jogador->getVelocidadeY();

	jogador->setVelocidae(VX, velY);

}
