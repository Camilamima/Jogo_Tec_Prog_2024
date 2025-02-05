#include "Acelerador.h"
namespace Obstaculos {
	Acelerador::Acelerador(int id, const char* png) : Obstaculo(id, png)
	{
		timer = 0;
		booster = 3.5;
		acelera = true;
		setCoordenadas(750, 400);
		setCorpo(207.0, 100.0);
	}

	Acelerador::~Acelerador()
	{
	}

	void Acelerador::executar()
	{
		pGGrafico->desenha(corpo);
		timer++;
	}

	void Acelerador::obstacular(Personagens::Slime* jogador) {
		float VelX = jogador->getVelocidadeX();
		float VelY = jogador->getVelocidadeY();

		jogador->setVelocidae((VelX * booster), VelY);
	}

	json Acelerador::salvar() const {
		json entidadeJson;

		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["danoso"] = danoso;
		entidadeJson["impede"] = impede;
		entidadeJson["acelera"] = acelera;
		entidadeJson["atrito"] = atrito;
		entidadeJson["booster"] = booster;
		entidadeJson["timer"] = timer;
		entidadeJson["altura"] = corpo.getSize().y;
		entidadeJson["largura"] = corpo.getSize().x;
		return entidadeJson;
	}
}