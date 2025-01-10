#pragma once
#include "Obstaculo.h"

namespace Entidades {

	namespace Obstaculos {

		class SlimeMau : public Obstaculo {
		private:
			float atrasador;
		public:
			SlimeMau(int id, const char* png = "slimemau.png");
			~SlimeMau();
			void setpJogador(Personagens::Slime* jogador) { pJogador = jogador; }
			void setpJogador2(Personagens::Slime2* jogador2) { pJogador2 = jogador2; }
			Personagens::Slime* getpJogador1() { return pJogador; }
			Personagens::Slime2* getpJogador2() { return pJogador2; }
			void executar();
			void obstacular(Personagens::Slime* jogador, Personagens::Slime2* jogador2);
		};

	}//namespace Obstaculos

}//namespace Entidades