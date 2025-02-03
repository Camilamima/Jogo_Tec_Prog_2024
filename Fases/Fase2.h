#pragma once
#include "Fase.h"
namespace Fases {
	class Fase2 : public Fase
	{
	private:
		int num_obs2;
		static const int numero_projeteis;
		Personagens::Chefao teste2;
		Projetil p1;
		Projetil p2;
		Projetil p3;
		Projetil p4;
		Projetil p5;
		Projetil p6;
		Projetil p7;
		Projetil p8;
		Projetil p9;
		Projetil p10;
	public:
		Fase2();
		~Fase2();
		void inicializa();
		void geraChao();
		void geraInimigos();
		void executar() override;
	};
}

