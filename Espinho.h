#pragma once

#include "Obstaculo.h"

namespace Entidades {

	namespace Obstaculos {
		class Espinho : public Obstaculo {
		private:
			int num_espinhos;
		public:
			Espinho(int id, const char* png = "espinho.png");
			~Espinho();
			void setpJogador(Slime* jogador) { pJogador = jogador; }
			void setpJogador2(Slime2* jogador2) { pJogador2 = jogador2; }
			Slime* getpJogador() { return pJogador; }
			Slime2* getpJogador2() { return pJogador2; }
			void executar();
			void obstacular(Slime* jogador, Slime2* jogador2);
		};

	}//namespace Obstaculos

}//namespace Entidades