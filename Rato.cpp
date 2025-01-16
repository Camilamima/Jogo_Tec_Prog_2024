#include "Rato.h"
#include "iostream"

using namespace std;
#define CAMIHO 300

Rato::Rato(int id, const char* png) :
	Inimigo(id, png)
{
	setVelocidae(150, 0);
	setCoordenadas(700, 775);
	relogio.restart();
	setCorpo(150, 150);
	distancia_percorrida = 0;
}

Rato::~Rato() {  }

void Rato::calculaDis() {
	if (velocidadeX > 0) {
		distancia_percorrida += velocidadeX * atualizaDelta();
	}
	else {
		distancia_percorrida+=-velocidadeX * atualizaDelta();
	}
}

void Rato::executar() {
	if (verificaVida()) {
		if (distancia_percorrida >= CAMIHO) {

			velocidadeX = -velocidadeX;
			distancia_percorrida = 0;
		}
		calculaDis();
		mover(velocidadeX);
		pGGrafico->desenha(corpo);
	}

}