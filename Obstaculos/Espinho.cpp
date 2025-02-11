#include "Espinho.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>
using namespace std;
using namespace Personagens;

namespace Obstaculos {
	Espinho::Espinho(int id, const char* png) :
		Obstaculo(id, png)
	{
		atrito = 1.0f;
		danoso = true;
		setCoordenadas(1500, 800);
		setCorpo(78.0, 100.0);
		timer = 0;

		time_t tempo;//usei isso da prova de POO s73 1 sem23 do prof Simão

		srand((unsigned)time(&tempo));//isso tbm
		num_espinhos = (int)(rand() % 10);//isso tbm

		if (num_espinhos <= 0) {
			num_espinhos = 1;
		}

		if (num_espinhos >= 6) {
			num_espinhos = 5;
		}

	}

	Espinho::~Espinho() {
	}

	void Espinho::executar() {
		pGGrafico->desenha(corpo);
		if (!noChao) {
			mover();
		}
	}

	void Espinho::obstacular(Personagem* jogador,int i) {


		if (timer % 50 == 0) {
			jogador->animacao(4, 1);
			jogador->operator-=(num_espinhos);
			std::cout << "Vidas depois: " << jogador->getVidas() << std::endl;
		}
		timer++;
	}

	json Espinho::salvar() const {

		json entidadeJson;
		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["num_espinhos"]= num_espinhos;

		return entidadeJson;

	}
}
