#include "Efeitos.h"
#include <iostream>

namespace Personagens {

	Efeito::Efeito(int id, const char* png):
		Entidade(id, png)
	{
		setCoordenadas(6960, 450);//coord inicial do Yokai
		setCorpo(250, 250);
		setSoCorpo(250, 250);
		limite = 16;
		tam = 0;
		tempo_efeito.restart();
		apareceu = false;
	}

	Efeito::~Efeito(){
	}

	void Efeito::resetaTempo() {
		tempo_efeito.restart();
	}

	void Efeito::executar(){

		pGGrafico->desenha(corpo);

	}

	void Efeito::animacao() {

		apareceu = true;
		sprite.loadFromFile("assets/efeito/teletransporte.png");
		corpo.setTexture(&sprite);
		corpo.setTextureRect(IntRect(250 * tam, 0, 250, 250));
		tam++;

		if (tam == limite) {
			tam = 0;
			apareceu = false;
		}
	}
}