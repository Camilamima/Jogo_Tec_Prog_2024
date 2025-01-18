#include "SlimeMau.h"
#include <iostream>

SlimeMau::SlimeMau(int id, const char* png) :
	Obstaculo(id, png)
{	
	pJogador = nullptr;
	setCoordenadas(1200, 820);
	setCorpo(80.0, 80.00);
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
	std::cout << "Velocidade X: " << jogador->getVelocidadeX() << std::endl;
	jogador->setVelocidae(atrasador, velY*atrito);
}