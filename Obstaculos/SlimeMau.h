#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class SlimeMau : public Obstaculo {
	private:
		float atrasador;
	public:
		SlimeMau(int id, const char* png = "assets/slimemau.png");
		~SlimeMau();
		Personagens::Slime* getpJogador() { return pJogador; }
		void executar();
		void obstacular(Personagens::Slime* jogador);
	};
}