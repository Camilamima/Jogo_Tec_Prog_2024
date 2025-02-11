#pragma once
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {
		class Heroi;
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
			virtual void ataca(Heroi* jog, int lado);
			int getMaldade() const { return nivel_maldade; }
			virtual void animacao(int num, int limite) = 0;
			virtual json salvar() const = 0;
		};
	}
}

