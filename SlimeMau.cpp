#include "SlimeMau.h"

SlimeMau:: SlimeMau(int id, const char* png) : Obstaculo(id, png),
atrito(0.5f),
pJogador(nullptr)
{
	atrapalha = true;
	setCoordenadas(1200, 775);
	setCorpo(80.0, 80.0);
}

SlimeMau::~SlimeMau() {
}

void SlimeMau::executar() {
	pGGrafico->desenha(corpo);
	obstacular(pJogador, atrito);
}