#pragma once
#include "Lista.h"
#include "../Entidade.h"
#include "../Personagens/Chefao.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Obstaculos/Plataforma.h"
#include <vector>
#include <queue>

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidade*>* listaEntidades;
		vector<Personagens::Chefao*> *chefoes;
		//vector<Entidade*> *plataforma_chefao;
		queue<Entidade*>* plataforma_chefao;
		int pos_chefao;
		bool zona_chefao;//zona onde está o chefao
		int zona_chefao_num;
	public:
		ListaEntidade();
		~ListaEntidade();

		const bool chefeNulo() const {
			if (!chefoes) return true;

			for (const auto& chefe : *chefoes) {
				if (chefe != nullptr) {
					return false; 
				}
			}
			return true; 
		}
		void Percorrer(Gerenciadores::Gerenciador_Colisoes* gc);
		void Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void IncluirSalvamento(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void setGG(Gerenciadores::Gerenciado_Grafico *gg);
		void Include(Entidade* entidade);
		void MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc);
		int VerificMortos();//retona a posicao do morto -> se -1 nao tem mortos!
		void matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes* gc);
		void encontraZonaChefao(Personagens::Slime* jog);
		vector<Entidade*> returnVec();
	};

}