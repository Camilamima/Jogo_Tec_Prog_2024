#pragma once
#include "Lista.h"
#include "Entidades/Entidade.h"
//#include "Gerenciador_Colisoes.h

namespace Listas {

	class ListaEntidade {
	private:
		Lista <Entidades::Entidade*>* listaEntidades;
	public:
		ListaEntidade();
		~ListaEntidade();
		void Percorrer(/*Gerenciadores::Gerenciador_Colisoes* gc */);
		void Incluir(Entidades::Entidade* entidade);
	};

}