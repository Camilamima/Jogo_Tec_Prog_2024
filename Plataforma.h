#pragma once
#include "Obstaculo.h"
#include "Slime.h"
#include "Slime2.h"

namespace Entidades {

	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:

			float x;
			float y;

		public:
			Plataforma(int id, const char* png = "plataforma.png");
			~Plataforma();
			void setpJogador(Personagens::Slime* jogador) { pJogador = jogador; }
			void setpJogador2(Personagens::Slime2* jogador2) { pJogador2 = jogador2; }
			Personagens::Slime* getpJogador1() { return pJogador; }
			Personagens::Slime2* getpJogador2() { return pJogador2; }

			void executar();
			void obstacular(Personagens::Slime* jogador, Personagens::Slime2* jogador2);
		};

	}//namespace Obstaculos

}//namespace Entidades