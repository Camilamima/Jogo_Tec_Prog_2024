#include "Plataforma.h"

Entidades::Obstaculos::Plataforma::Plataforma(int id, const char* png) :
		Obstaculo(id, png), x(0), y(860)
	{
		pJogador = nullptr;
		pJogador2 = nullptr;
		atrito = 1.0f;
		setCoordenadas(x, y);
		setCorpo(1800.0, 40.0);
	}
Entidades::Obstaculos::Plataforma::~Plataforma() {
	}

	void Entidades::Obstaculos::Plataforma::executar() {
		pGGrafico->desenha(corpo);
		obstacular(getpJogador1(), getpJogador2());

	}

	void Entidades::Obstaculos::Plataforma::obstacular(Personagens::Slime* jogador, Personagens::Slime2* jogador2) {

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

					jogador->setVelocidae((velX * atrito), velY);
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

					jogador->setVelocidae((velX * atrito), velY);
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

					jogador2->setVelocidae((velX * atrito), velY);
				}
			}
			else
			{
				float velY = jogador2->getVelocidadeY();
				jogador2->setVelocidae(VX, velY);
			}
		}
	}
