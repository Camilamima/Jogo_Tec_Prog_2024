#include "ListaEntidades.h"

namespace Listas {
	
	//construtora
	ListaEntidade::ListaEntidade():
	listaEntidades(new Lista<Entidades::Entidade*>())
	{
	}

	//destrutora
	ListaEntidade::~ListaEntidade() {
		for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			delete* it;
		}
		delete listaEntidades;
	}

	//percorre a lista de entidades
	void ListaEntidade::Percorrer(/*Gerenciadores::Gerenciador_Colisoes* gc */) {
		//falta o gerenciador de colisões
	}

	//inclui uma entidade na lista
	void ListaEntidade::Incluir(Entidades::Entidade* entidade) {

		listaEntidades->adicionarElemento(entidade);
	}

}