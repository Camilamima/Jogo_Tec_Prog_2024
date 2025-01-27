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
