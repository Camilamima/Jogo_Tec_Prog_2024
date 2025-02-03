#pragma once
#include <stdio.h>
#include <vector>
#include <set>
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
	class Fase {
	protected:
		int qnt_jogadores;
		const int tamanho_fase;
		const int tamanho_zona;
		int zona_atual;
		int num_facil;
		vector <int> localizacao_obs;
		Gerenciadores::Gerenciador_Colisoes gerentC;
		Gerenciadores::Gerenciado_Grafico *gerent;
		Personagens::Slime Slime1;
		Personagens::Slime Slime2;
		Obstaculos::Plataforma chao;
		Obstaculos::Plataforma ladoE;
		Listas::ListaEntidade listaEntidades;

	public:
		Fase();
		~Fase();
		int getJogadores() {
			return qnt_jogadores;
		}
		void setGerenciador(Gerenciadores::Gerenciado_Grafico* g) { gerent = g; }
		virtual void inicializa() = 0;
		void limpaVec();
		const bool checaLocaliza(float x,int ver) const;
		float checaZona();
		void geraEspinho();
		virtual void geraChao()=0;
		bool const checaFinal() const {
			if (zona_atual >= 8) {
				return 1;
			}
			
			return 0;
		}
		virtual void geraInimigos()=0;
		void geraPlataformaFase();
		void TipoPlataforma(int tipo,float x);
		virtual void executar();
	};
}
