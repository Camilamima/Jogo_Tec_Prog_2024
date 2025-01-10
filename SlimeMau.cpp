#include "SlimeMau.h"

Entidades::Obstaculos::SlimeMau::SlimeMau(int id, const char* png) :
		Obstaculo(id, png)
	{
		pJogador = nullptr;
		setCoordenadas(1200, 775);
		setCorpo(80.0, 80.00);
		atrasador = atrito * 0.91;
	}

Entidades::Obstaculos::SlimeMau::~SlimeMau() {
	}

	void Entidades::Obstaculos::SlimeMau::executar() {
		pGGrafico->desenha(corpo);
		obstacular(pJogador, pJogador2);
	}

	void Entidades::Obstaculos::SlimeMau::obstacular(Personagens::Slime* jogador, Personagens::Slime2* jogador2) {

		RectangleShape teste1;
		teste1 = jogador->getCorpo();

		Vector2f pos;
		pos.x = corpo.getPosition().x + corpo.getSize().x;
		pos.y = corpo.getPosition().y + corpo.getSize().y;

		if (jogador2 == nullptr) {//só tem 1 jogador
			if ((teste1.getPosition().x <= pos.x) && (teste1.getPosition().x >= corpo.getPosition().x))
			{
				if ((teste1.getPosition().y <= pos.y) && (teste1.getPosition().y >= corpo.getPosition().y))
				{
					float velX = jogador->getVelocidadeX();
					float velY = jogador->getVelocidadeY();

					jogador->setVelocidae((velX * atrasador), velY);
				}
			}
			else
			{
				float velY = jogador->getVelocidadeY();
				jogador->setVelocidae(VX, velY);
			}
		}

		else {//tem 2 jogadores
			RectangleShape teste2;
			teste2 = jogador2->getCorpo();

			/*Jogador 1*/
			if ((teste1.getPosition().x <= pos.x) && (teste1.getPosition().x >= corpo.getPosition().x))
			{
				if ((teste1.getPosition().y <= pos.y) && (teste1.getPosition().y >= corpo.getPosition().y))
				{
					float velX = jogador->getVelocidadeX();
					float velY = jogador->getVelocidadeY();

					jogador->setVelocidae((velX * atrasador), velY);
				}
			}
			else
			{
				float velY = jogador->getVelocidadeY();
				jogador->setVelocidae(VX, velY);
			}

			/*Jogador 2*/
			if ((teste2.getPosition().x <= pos.x) && (teste2.getPosition().x >= corpo.getPosition().x))
			{
				if ((teste2.getPosition().y <= pos.y) && (teste2.getPosition().y >= corpo.getPosition().y))
				{
					float velX = jogador2->getVelocidadeX();
					float velY = jogador2->getVelocidadeY();

					jogador2->setVelocidae((velX * atrasador), velY);
				}
			}
			else
			{
				float velY = jogador2->getVelocidadeY();
				jogador2->setVelocidae(VX, velY);
			}
		}
	}