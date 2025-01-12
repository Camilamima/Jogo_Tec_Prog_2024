#include "SlimeMau.h"
#include <iostream>

SlimeMau::SlimeMau(int id, const char* png) :
	Obstaculo(id, png)
{	
	atrapalha = true;
	pJogador = nullptr;
	atrito = 0.5f;
	setCoordenadas(1200, 800);
	setCorpo(100.0, 100.00);
	atrasador = VX*atrito;

}

SlimeMau::~SlimeMau() {
}

void SlimeMau::executar() {
	pGGrafico->desenha(corpo);
}

void SlimeMau::obstacular(Slime* jogador) {

	float velY = jogador->getVelocidadeY();

	jogador->setVelocidae((atrasador), (velY*atrito));
}
