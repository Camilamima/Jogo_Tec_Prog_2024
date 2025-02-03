#include "Rato.h"
#include "iostream"


using namespace std;
#define CAMIHO 300
namespace Personagens {
	Rato::Rato(int id, const char* png) :
		Inimigo(id, png)
	{
		setVelocidae(150, 0);
		relogio.restart();
		setCorpo(100, 100);
		distancia_percorrida = 0;
		setMaldade(1);
	}

	Rato::~Rato() {  }

	void Rato::calculaDis() {
		if (velocidadeX > 0) {
			distancia_percorrida += velocidadeX * atualizaDelta();
		}
		else {
			distancia_percorrida += -velocidadeX * atualizaDelta();
		}
	}

	void Rato::executar() {
		if (verificaVida()) {
			if (distancia_percorrida >= CAMIHO) {

				velocidadeX = -velocidadeX;
				distancia_percorrida = 0;
			}
			calculaDis();
			if (!noChao) {
				mover(0);
			}
			if (velocidadeX > 0 && moviD) {
				mover(velocidadeX * atualizaDelta());
			}
			else if (velocidadeX < 0 && moviE) {
				mover(velocidadeX * atualizaDelta());
			}

			pGGrafico->desenha(corpo);
		}

	}
}