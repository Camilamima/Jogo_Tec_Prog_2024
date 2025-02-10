#pragma once
#include "Personagem.h"


namespace Personagens {
	class Slime;
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
		void ataca(Slime* jog1,int lado);
		int getMaldade() const{ return nivel_maldade; }
		virtual void animacao(int num, int limite) = 0;
		virtual json salvar() const = 0;
	};
}

