#pragma once
#include "Personagem.h"
#include <algorithm>

#define VX 500

namespace Entidades {

	namespace Personagens {

		class Slime2 : public Personagem
		{
		private:
			int pontos;
			bool noChao;
			bool wPress;
			float impulso;
		public:
			Slime2(int id, const char* png = "gato2.png");
			~Slime2();
			void mover(float aux);
			void executar();
			void processaEvento();

		};

	}//namespace Personagens

}//namespace Entidades