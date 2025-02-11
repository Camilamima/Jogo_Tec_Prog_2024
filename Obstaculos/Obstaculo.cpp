#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Entidades {
	namespace Obstaculos {
		Obstaculo::Obstaculo(int id, const char* png) :
			Entidade(id, png),
			atrito(1.0f)
		{
			noChao = 1;
			danoso = false;
			atrapalha = false;
			impede = false;
		}

		Obstaculo::~Obstaculo()
		{
		}

		void Obstaculo::mover(float aux) {
			velocidadeY += static_cast<float>(gravidade);
			if ((corpo.getPosition().y + velocidadeY) >= chao) {
				velocidadeY = chao - corpo.getPosition().y;
			}
			corpo.move(aux, velocidadeY);
			if (corpo.getPosition().y >= chao) {
				noChao = 1;
				velocidadeY = 0;
			}
		}

		void Obstaculo::restaura(Personagens::Heroi* jogador) {
			float velY = jogador->getVelocidadeY();


			jogador->setVelocidae(VX, velY);

		}
	}
}


