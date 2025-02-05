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
		int getEspinhos() const {
			return num_espinhos;
		}
		void setEspinhos(int e) {
			num_espinhos = e;
		}
		void obstacular(Personagens::Slime* jogador);
		virtual json salvar() const;
	};
}
