#pragma once
#include "Fase.h"
namespace Fases {
	class Caverna_Obscura : public Fase
	{
	private:
		int num_obs2;//
		int num_chefoes;//
		int num_projeteis;//
	public:
		Caverna_Obscura();//
		Caverna_Obscura(const json& dados);//
		~Caverna_Obscura();//
		//Caverna_Obscura(const json& dados, Gerenciadores::Gerenciado_Grafico* gC);
		void inicializa();//
		void geraEspinho();//
		void setPontos(int ponto1, int ponto2) {
			Heroi1.setPonto(ponto1);
			Heroi2.setPonto(ponto2);
		}//
		void geraChao();//
		void geraInimigos();//
		void geraYokai();//
		void geraProjeteis();//
		//void executar() override;
	};
}

