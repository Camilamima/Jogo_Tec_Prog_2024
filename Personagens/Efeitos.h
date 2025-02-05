#pragma once
#include "../Entidade.h"

namespace Personagens
{
	class Efeito : public Entidade
	{
	private:
		int tam;
		int limite;
		Clock tempo_efeito;
		bool apareceu;

	public:
		Efeito(int id, const char* png = "");
		~Efeito();
		void executar();
		Clock getTempo()const { return tempo_efeito; }
		void resetaTempo();
		void animacao();
		bool getApareceu()const { return apareceu; }
		void setApareceu(bool a) { apareceu = a; }
	};
}
