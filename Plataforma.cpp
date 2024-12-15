#include "Plataforma.h"

Plataforma::Plataforma(int id, const char* png) :
	Obstaculo(id, png),
	atrito(0.99998f),
	pJogador(nullptr)
{
	atrapalha = false;
	setCoordenadas(0, 860);
	setCorpo(1800.0, 40.0);
}
Plataforma::~Plataforma() {
}

void Plataforma::executar() {
	pGGrafico->desenha(corpo);
	obstacular(getpJogador(), atrito);
}

