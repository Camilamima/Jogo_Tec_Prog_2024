#pragma once
#include "Obstaculo.h"
using namespace Personagens;

namespace Obstaculos {
	class Espinho : public Obstaculo {
	private:
		int num_espinhos;
		int timer;
	public:
		Espinho(int id, const char* png ="assets/espinho.png");
		~Espinho();
		Personagens::Slime* getpJogador() { return pJogador; }
		void executar();
		void obstacular(Personagens::Slime* jogador);
	};
}
