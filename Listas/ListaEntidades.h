#pragma once
#include "Lista.h"
#include "../Entidade.h"
#include "../Personagens/Chefao.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"
#include <vector>

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidade*>* listaEntidades;
		vector<Personagens::Chefao*> *chefoes;
		int pos_chefao;
		bool zona_chefao;//zona onde está o chefao
		int zona_chefao_num;
	public:
		ListaEntidade();
		~ListaEntidade();
		void Percorrer(Gerenciadores::Gerenciador_Colisoes* gc);
		void Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void setGG(Gerenciadores::Gerenciado_Grafico *gg);
		void Include(Entidade* entidade);
		void MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc);
		int VerificMortos();//retona a posicao do morto -> se -1 nao tem mortos!
		void matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes* gc);
		void encontraZonaChefao(Personagens::Slime* jog);
		vector<Entidade*> returnVec();
	};

}