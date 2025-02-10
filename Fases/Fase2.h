#pragma once
#include "Fase.h"
namespace Fases {
	class Fase2 : public Fase
	{
	private:
		int num_obs2;
		int num_chefoes;
		int num_projeteis;
	public:
		Fase2();
		Fase2(const json& dados, Gerenciadores::Gerenciado_Grafico* gC);
		~Fase2();
		//Fase2(const json& dados, Gerenciadores::Gerenciado_Grafico* gC);
		void inicializa();
		void setPontos(int ponto1, int ponto2) {
			Slime1.setPonto(ponto1);
			Slime2.setPonto(ponto2);
		}
		void geraChao();
		void geraInimigos();
		void geraChefao();
		void geraProjeteis();
		//void executar() override;
	};
}

