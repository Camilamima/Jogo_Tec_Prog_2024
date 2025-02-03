#pragma once
#include "../Personagens/Slime.h"
#include <stdio.h>
#include "../Obstaculos/Plataforma.h"
#include "../Obstaculos/Espinho.h"
#include "../Obstaculos/SlimeMau.h"
#include "../Obstaculos/Acelerador.h"
#include "../Personagens/Rato.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Listas/ListaEntidades.h"
#include "../Projetil.h"
#include "../Personagens/Chefao.h"
#include "../Personagens/Efeitos.h"
#include "../Personagens/Cachorro.h"

namespace Fases {
	class Fase1 {

	private:
		int tamanho_fase;
		int tamanho_zona;
		int zona_atual;
		Gerenciadores::Gerenciador_Colisoes gerentC;
		Gerenciadores::Gerenciado_Grafico gerent;
		Personagens::Slime Slime1;
		Personagens::Slime Slime2;
		Obstaculos::Plataforma chao;
		Obstaculos::Plataforma ladoE;
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
		Personagens::Efeito teletransporte;
		Personagens::Cachorro teste;
		static const int numero_projeteis;

		/*Plataforma plat2;
		Plataforma plat3;
		Espinho esp;
		SlimeMau obst_facil;
		Acelerador booster;
		Rato ratinho;*/
		Listas::ListaEntidade listaEntidades;

	public:
		Fase1();
		~Fase1();
		float checaZona();
		void executar();
		void geraChao();
		void geraEspinho();
	};
}
