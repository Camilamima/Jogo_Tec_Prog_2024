#include "Rio.h"
#include <iostream>

namespace Entidades {
	namespace Obstaculos {
		Rio::Rio(int id, const char* png) :
			Obstaculo(id, png)
		{
			setCoordenadas(1200, 800);
			setCorpo(100.0, 100.00);
			atrapalha = true;
			atrito = 0.5f;
			atrasador = VX * atrito;
		}

		Rio::~Rio() {
		}


		void Rio::executar() {
			pGGrafico->desenha(corpo);
			if (!noChao) {
				mover(0);
			}
		}

		void Rio::obstacular(Entidades::Personagens::Personagem* jogador, int i) {

			float velY = jogador->getVelocidadeY();
			jogador->setVelocidae(atrasador, (float)0.97 * (float)velY);
		}

		json Rio::salvar() const {
			json entidadeJson;

			entidadeJson["id"] = id;
			entidadeJson["x"] = corpo.getPosition().x;
			entidadeJson["y"] = corpo.getPosition().y;
			entidadeJson["altura"] = corpo.getSize().y;
			entidadeJson["largura"] = corpo.getSize().x;

			return entidadeJson;
		}
	}
}