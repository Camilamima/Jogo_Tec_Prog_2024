#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace Personagens;
using namespace Obstaculos;

Obstaculo::Obstaculo(int id,const char* png) : 
Entidade(id, png), 
atrito(1.0f)
{
	danoso = false;
	atrapalha = false;
	impede = false;
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::restaura(Slime* jogador) {
	float velY = jogador->getVelocidadeY();


	jogador->setVelocidae(VX, velY);
	
}
