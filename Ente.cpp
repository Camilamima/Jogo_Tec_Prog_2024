#include "Ente.h"


Ente::Ente(int x, const char* png):
	id(x)
{
	sprite.loadFromFile(png);
	pgenGrafico = NULL;
}

Ente::~Ente() {
	pgenGrafico = NULL;
}

void Ente::setGerenciador(Gerenciado_Grafico* g) {
	pgenGrafico = g;
}

