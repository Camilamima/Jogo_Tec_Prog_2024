#pragma once
#include "Lista.h"
#include "../Entidades/Entidade.h"
#include "../Personagens/Yokai.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Obstaculos/Plataforma.h"
#include <vector>
#include <queue>

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidades::Entidade*>* listaEntidades;
		vector<Entidades::Personagens::Yokai*> *chefoes;
		//vector<Entidades::Entidade*> *plataforma_Yokai;
		queue<Entidades::Entidade*>* plataforma_Yokai;
		int pos_Yokai;
		bool zona_Yokai;//zona onde está o Yokai
		int zona_Yokai_num;
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
		void Incluir(Entidades::Entidade* Entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void IncluirSalvamento(Entidades::Entidade* Entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void setGG(Gerenciadores::Gerenciado_Grafico *gg);
		void Include(Entidades::Entidade* Entidade);
		int VerificMortos();//retona a posicao do morto -> se -1 nao tem mortos!
		void MatarEntidade(Entidades::Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc);
		void matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes* gc);
		void encontraZonaYokai(Entidades::Personagens::Heroi* jog);
		vector<Entidades::Entidade*> returnVec();
	};

}