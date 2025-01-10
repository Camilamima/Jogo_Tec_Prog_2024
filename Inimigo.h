#pragma once
#include "Personagem.h"

namespace Entidades {

	namespace Personagens {

		class Inimigo : public Personagem
		{
		protected:
			int nivel_maldade;
		public:
			Inimigo(int id, const char* png);
			~Inimigo();
			virtual void executar() = 0;
			void mover(float aux);
			void setMaldade(int maldade);
		};

	}//namespace Personagens

}//namespace Entidades