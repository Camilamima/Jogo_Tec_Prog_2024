#pragma once
#include <stdio.h>
#include <vector>
#include <set>
#include "../Personagens/Slime.h"
#include "../Obstaculos/Plataforma.h"
#include "../Obstaculos/Espinho.h"
#include "../Obstaculos/SlimeMau.h"
#include "../Personagens/Rato.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Listas/ListaEntidades.h"
#include "../Projetil.h"
#include "../Personagens/Chefao.h"
#include "../Personagens/Efeitos.h"
#include "../Personagens/Cachorro.h"
#include <nlohmann/json.hpp>
#include "../Texto.h"
using json = nlohmann::json;

class Menu;

namespace Fases {
	class Fase:public Ente, public Texto{
	protected:
		int num_fase;
		int qnt_jogadores;
		int qnt_jogadores_ini;
		const int tamanho_fase;
		const int tamanho_zona;
		int zona_atual;
		int num_facil;
		bool Pause;
		Menu* pMenu;
		vector <int> localizacao_obs;
		Gerenciadores::Gerenciador_Colisoes gerentC;
		Personagens::Slime Slime1;
		Personagens::Slime Slime2;
		Obstaculos::Plataforma chao;
		Obstaculos::Plataforma ladoE;
		Listas::ListaEntidade listaEntidades;

	public:
		Fase();
		~Fase();
		int getJogadores() const {
			return qnt_jogadores;
		}
		int getZona()const {
			return zona_atual;
		}

		void setPause(const bool i) {
			Pause = i;
		}
		void setJogadores(const int i) {
			qnt_jogadores = i;
		}
		void setMenu(Menu* m) {
			pMenu = m;
		}
		virtual void inicializa() = 0;
		void limpaVec();
		const bool checaLocaliza(float x, int ver) const;
		float checaZona();
		void geraEspinho();
		virtual void geraChao() = 0;
		bool const checaFinal() const {
			if (zona_atual >= 8) {
				return 1;
			}

			return 0;
		}
		virtual void geraInimigos() = 0;
		void geraPlataformaFase();
		void TipoPlataforma(int tipo, float x);
		virtual void executar();
		void salvaFase();
		void setaTextos(int text);
		void digitarNome();
	};
}
