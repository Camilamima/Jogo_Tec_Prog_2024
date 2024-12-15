#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Obstaculo::Obstaculo(int id,const char* png) : Entidade(id, png)
{
	danoso = false;
	atrapalha = false;
}

Obstaculo::~Obstaculo()
{
}
void Obstaculo::obstacular(Slime* jogador, float atrito)
{
	RectangleShape teste;
	Vector2f pos;
	pos.x = corpo.getPosition().x + corpo.getSize().x;
	pos.y = corpo.getPosition().y + corpo.getSize().y;
	teste = jogador->getCorpo();
	if ((teste.getPosition().x <= pos.x) && (teste.getPosition().x >= corpo.getPosition().x)) 
	{

		if ((teste.getPosition().y <= pos.y) && (teste.getPosition().y >= corpo.getPosition().y))
		{
			if (atrapalha)
			{
				float velX = jogador->getVelocidadeX();
				float velY = jogador->getVelocidadeY();

				jogador->setVelocidae((velX * atrito), velY);

			}
			if (danoso)
			{
				jogador->operator--();
				std::cout << "Vidas: " << jogador->getVidas() << std::endl;
			}
		}
	}
	else
	{ 
		float velY = jogador->getVelocidadeY();

		jogador->setVelocidae(VX, velY);
	}
}