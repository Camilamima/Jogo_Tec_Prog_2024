#include "ListaEntidades.h"
#include "Slime.h"


namespace Listas {
	
	class Obstaculo;

	//construtora
	ListaEntidade::ListaEntidade():
	listaEntidades(new Lista<Entidade*>())
	{
	}

	//destrutora --- RESOLVER AQ
	ListaEntidade::~ListaEntidade() {

		int i;

		for (i=0; i<listaEntidades->tamanho(); i++)
		{
			listaEntidades->removerElemento(0);
		}
		delete listaEntidades;
	}

	//percorre a lista de entidades
	void ListaEntidade::Percorrer(Gerenciadores::Gerenciador_Colisoes* gc ) {
		gc->executar();

		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			(*it)->executar();
		}

	}

	//inclui uma entidade na lista
	void ListaEntidade::Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc) {
		listaEntidades->adicionarElemento(entidade);
		gc->includeEntidade(entidade);
	}

	void ListaEntidade::setGG(Gerenciado_Grafico *gg) {
		
		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			(*it)->setGerenciador(gg);
		}
	}

}