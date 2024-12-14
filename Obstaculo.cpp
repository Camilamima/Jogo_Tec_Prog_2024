#include "Obstaculo.h"
#include <iostream>

Obstaculo::Obstaculo(int id,const char* png) : Entidade(id, png)
{
	danoso = false;
}

Obstaculo::~Obstaculo()
{
}
void Obstaculo::obstacular(Slime* jogador, float atrito)
{
	//if (danoso)
	//{
	//	if()
	//	jogador->operator--();
	//	std::cout << "Vidas: " << jogador->getVidas() << std::endl;

	//}
	//else
	//{
		float velX = jogador->getVelocidadeX();
		float velY = jogador->getVelocidadeY();

		jogador->setVelocidae((velX * atrito), velY);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			float velY = jogador->getVelocidadeY();

			jogador->setVelocidae(VX, velY);
		}
	//}
}