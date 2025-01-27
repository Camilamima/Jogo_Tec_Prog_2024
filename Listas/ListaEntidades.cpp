#include "ListaEntidades.h"
#include "../Personagens/Slime.h"

using namespace Personagens;
namespace Listas {
	
	class Obstaculo;

	//construtora
	ListaEntidade::ListaEntidade():
	listaEntidades(new Lista<Entidade*>())
	{
	}

	//destrutora
	ListaEntidade::~ListaEntidade() {

		int i;
		int z = listaEntidades->tamanho();

		for (i=0; i<z; i++)
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

	void ListaEntidade::setGG(Gerenciadores::Gerenciado_Grafico *gg) {
		
		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			(*it)->setGerenciador(gg);
		}
	}

	void ListaEntidade::MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc) {

		listaEntidades->removerElemento(ent);
		gc->removeEntidade(ent);
	}
}