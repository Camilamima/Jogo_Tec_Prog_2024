#include "SlimeMau.h"
#include <iostream>

using namespace Personagens;
namespace Obstaculos {
	SlimeMau::SlimeMau(int id, const char* png) :
		Obstaculo(id, png)
	{
		pJogador = nullptr;
		setCoordenadas(1200, 800);
		setCorpo(100.0, 100.00);
		atrapalha = true;
		atrito = 0.5f;
		atrasador = VX * atrito;
	}

	SlimeMau::~SlimeMau() {
	}
	

	void SlimeMau::executar() {
		pGGrafico->desenha(corpo);
	}

	void SlimeMau::obstacular(Slime* jogador) {

		float velY = jogador->getVelocidadeY();
		jogador->setVelocidae(atrasador, (float)0.97 * (float) velY);
	}

	json SlimeMau::salvar() const {
		json entidadeJson;

		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["altura"] = corpo.getSize().y;
		entidadeJson["largura"] = corpo.getSize().x;

		return entidadeJson;
	}
}