#pragma once
#include "Fase.h"
namespace Fases {
	class Fase2 : public Fase
	{
	private:
		int num_obs2;
	public:
		Fase2();
		~Fase2();
		void inicializa();
		void geraChao();
		void geraInimigos();
	};
}

