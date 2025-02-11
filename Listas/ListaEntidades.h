#pragma once
#include "Lista.h"
#include "../Entidade.h"
#include "../Personagens/Yokai.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include "../Obstaculos/Plataforma.h"
#include <vector>
#include <queue>

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidade*>* listaEntidades;
		vector<Personagens::Yokai*> *chefoes;
		//vector<Entidade*> *plataforma_Yokai;
		queue<Entidade*>* plataforma_Yokai;
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
		void Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void IncluirSalvamento(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void setGG(Gerenciadores::Gerenciado_Grafico *gg);
		void Include(Entidade* entidade);
		void MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc);
		int VerificMortos();//retona a posicao do morto -> se -1 nao tem mortos!
		void matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes* gc);
		void encontraZonaYokai(Personagens::Heroi* jog);
		vector<Entidade*> returnVec();
	};

}