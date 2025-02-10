#include "Ente.h"


Ente::Ente(int x, const char* png):
	id(x)
{
	this->png = png;
	sprite.loadFromFile(png);
	pGGrafico = NULL;
}
Ente::Ente() {
	id = 30;
	png = "";
	pGGrafico = NULL;
}

Ente::~Ente() {
	pGGrafico = NULL;
}

void Ente::setGerenciador(Gerenciadores::Gerenciado_Grafico* g) {
	pGGrafico = g;
}

