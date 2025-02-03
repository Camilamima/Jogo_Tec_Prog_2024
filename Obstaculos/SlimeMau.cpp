#include "SlimeMau.h"
#include <iostream>
using namespace Obstaculos;
using namespace Personagens;

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
	jogador->setVelocidae(atrasador, 0.97*velY);
}