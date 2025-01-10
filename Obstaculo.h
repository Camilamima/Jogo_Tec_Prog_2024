#pragma once
#include "Entidade.h"
#include "Slime.h"
#include "Slime2.h"

namespace Entidades {

	namespace Obstaculos {
		class Obstaculo : public Entidade
		{
		protected:
			bool danoso;
			float atrito;
			Slime* pJogador;
			Slime2* pJogador2;

		public:
			Obstaculo(int id, const char* png);
			~Obstaculo();
			virtual void executar() = 0;
			virtual void obstacular(Slime* jogador, Slime2* jogador2) = 0;
		};

	}//namespace Obstaculos

}//namespace Entidades
