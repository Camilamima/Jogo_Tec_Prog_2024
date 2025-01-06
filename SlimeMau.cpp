#include "SlimeMau.h"

SlimeMau:: SlimeMau(int id, const char* png) : 
Obstaculo(id, png)
{
	pJogador = nullptr;
	atrito = 0.4f;//atributo de obstaculo
	atrapalha = true;//atributo de obstaculo
	setCoordenadas(1200, 775);
	setCorpo(80.0, 80.00);
}

SlimeMau::~SlimeMau() {
}

void SlimeMau::executar() {
	pGGrafico->desenha(corpo);
	obstacular(pJogador);
}