#pragma once
#include "Lista.h"
#include "../Entidade.h"
#include "../Gerenciadores/Gerenciador_Colisoes.h"

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidade*>* listaEntidades;
		int pos_chefao;
	public:
		ListaEntidade();
		~ListaEntidade();
		void Percorrer(Gerenciadores::Gerenciador_Colisoes* gc);
		void Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc);
		void setGG(Gerenciadores::Gerenciado_Grafico *gg);
		void MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc);
		int VerificMortos();//retona a posicao do morto -> se -1 nao tem mortos!
		void matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes* gc);
	};

}