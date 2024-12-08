#include "Ente.h"


Ente::Ente(){
	gGrafico = NULL;
}

Ente::~Ente() {
	gGrafico = NULL;

}

void Ente::setGerenciador(Gerenciado_Grafico* g) {
	gGrafico = g;
}