#include "Espinho.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>

Entidades::Obstaculos::Espinho::Espinho(int id, const char* png) :
		Obstaculo(id, png)
	{
		pJogador = nullptr;
		pJogador2 = nullptr;
		atrito = 1.0f;
		danoso = true;
		setCoordenadas(1500, 775);
		setCorpo(80.0, 80.0);

		time_t tempo;//usei isso da prova de POO s73 1 sem23 do prof Simão

		srand((unsigned)time(&tempo));//isso tbm
		num_espinhos = (int)(rand() % 10);//isso tbm

	}

Entidades::Obstaculos::Espinho::~Espinho() {
	}

	void Entidades::Obstaculos::Espinho::executar() {
		pGGrafico->desenha(corpo);
		obstacular(pJogador, pJogador2);
	}

	void Entidades::Obstaculos::Espinho::obstacular(Personagens::Slime* jogador, Personagens::Slime2* jogador2) {

		RectangleShape teste;
		teste = jogador->getCorpo();

		Vector2f pos;
		pos.x = corpo.getPosition().x + corpo.getSize().x;
		pos.y = corpo.getPosition().y + corpo.getSize().y;


		/* 1 jogador */
		if (jogador2 == nullptr) {
			if ((teste.getPosition().x <= pos.x) && (teste.getPosition().x >= corpo.getPosition().x))
			{

				if ((teste.getPosition().y <= pos.y) && (teste.getPosition().y >= corpo.getPosition().y))
				{
					if (danoso)
					{
						std::cout << "Num do espinho: " << num_espinhos << std::endl;
						std::cout << "Vidas antes jog 1: " << jogador->getVidas() << std::endl;
						jogador->operator*=(num_espinhos);
						std::cout << "Vidas depois jog 1: " << jogador->getVidas() << std::endl;
					}
				}
			}
		}

		/* 2 jogadores */
		else {

			RectangleShape teste2;
			teste2 = jogador2->getCorpo();

			//Testando a pos do jogador 1
			if ((teste.getPosition().x <= pos.x) && (teste.getPosition().x >= corpo.getPosition().x))
			{

				if ((teste.getPosition().y <= pos.y) && (teste.getPosition().y >= corpo.getPosition().y))
				{
					if (danoso)
					{
						std::cout << "Num do espinho: " << num_espinhos << std::endl;
						std::cout << "Vidas antes jog 1: " << jogador->getVidas() << std::endl;
						jogador->operator*=(num_espinhos);
						std::cout << "Vidas depois jog 1: " << jogador->getVidas() << std::endl;
					}
				}
			}

			//Testando a pos do jogador 2
			if ((teste2.getPosition().x <= pos.x) && (teste2.getPosition().x >= corpo.getPosition().x))
			{

				if ((teste2.getPosition().y <= pos.y) && (teste2.getPosition().y >= corpo.getPosition().y))
				{
					if (danoso)
					{
						std::cout << "Num do espinho: " << num_espinhos << std::endl;
						std::cout << "Vidas antes jog 2: " << jogador2->getVidas() << std::endl;
						jogador2->operator*=(num_espinhos);
						std::cout << "Vidas depois jog 2: " << jogador2->getVidas() << std::endl;
					}
				}
			}
		}
	}