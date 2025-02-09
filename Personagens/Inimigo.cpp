#include "Inimigo.h"


namespace Personagens {
	Inimigo::Inimigo(int id, const char* png) :
		Personagem(id, png)
	{
		nivel_maldade = -1;
	}

	Inimigo::~Inimigo() {

	}

	void Inimigo::mover(float aux) {

		if (!noChao)
		{

			velocidadeY += static_cast<float>(gravidade) * atualizaDelta(relogio);
			if ((corpo.getPosition().y + velocidadeY) >= chao) {
				velocidadeY = chao - corpo.getPosition().y;
			}
			corpo.move(aux, velocidadeY);
			if (corpo.getPosition().y >= chao) {
				noChao = 1;
				velocidadeY = 0;
			}
		}
		else {
			corpo.move(aux, 0);
		}

	}

	void Inimigo::setMaldade(int maldade) {
		nivel_maldade = maldade;
	}

	void Inimigo::ataca(Slime* jog,int lado) {
		if (lado == 2) {
			if (!jog->getAtacado()) {
				jog->operator-=(nivel_maldade*5);
				jog->pular(300);
				jog->setAtacado(1, 0);
			}
		}
		else if (lado == 3) {
			if (!jog->getAtacado()) {
				jog->operator-=(nivel_maldade * 5);
				jog->pular(300);
				jog->setAtacado(1, 1);
			}
		}
	}
}