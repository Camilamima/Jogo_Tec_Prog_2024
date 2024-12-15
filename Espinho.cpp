#include "Espinho.h"

Espinho::Espinho(int id, const char* png) :
	Obstaculo(id, png),
	atrito(0.9998f),
	pJogador(nullptr)
{
	danoso = true;
	setCoordenadas(1500, 775);
	setCorpo(80.0, 80.0);
}

Espinho::~Espinho() {
}

void Espinho::executar() {
	pGGrafico->desenha(corpo);
	obstacular(pJogador, atrito);
}