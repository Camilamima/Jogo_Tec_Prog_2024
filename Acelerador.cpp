#include "Acelerador.h"

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

void Acelerador::obstacular(Slime* jogador) {
	float VelX = jogador->getVelocidadeX();
	float VelY = jogador->getVelocidadeY();

	jogador->setVelocidae((VelX * booster), VelY);
}