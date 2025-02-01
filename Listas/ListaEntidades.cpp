#include "ListaEntidades.h"
#include "../Personagens/Slime.h"
#include "../Personagens/Chefao.h"

using namespace Personagens;
namespace Listas {

	class Obstaculo;

	//construtora
	ListaEntidade::ListaEntidade() :
		listaEntidades(new Lista<Entidade*>())
	{
		pos_chefao = 0;
	}

	//destrutora
	ListaEntidade::~ListaEntidade() {

		int i;
		int z = listaEntidades->tamanho();

		for (i = 0; i < z; i++)
		{
			listaEntidades->removerElemento(0);
		}
		delete listaEntidades;
	}

	//percorre a lista de entidades
	void ListaEntidade::Percorrer(Gerenciadores::Gerenciador_Colisoes* gc) {
		gc->executar();//executar do gerenciador de colisoes 

		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{	
			if ((*it)->getId() == 5) {//se for um projetil
				if (static_cast<Projetil*>(*it)->getApareceu() == true) {//se ele ja apareceu
					(*it)->executar();//executa
				}
			}
			else {//se for um id diferente de 5, ou seja, 1,2,3,4,6
				(*it)->executar();
			}
		}
	}

	//inclui uma entidade na lista e verifica se eh chefao ou projetil
	void ListaEntidade::Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc) {
		listaEntidades->adicionarElemento(entidade);
		gc->includeEntidade(entidade);

		if (entidade->getId() == 6) {//eh um chefao
			pos_chefao = listaEntidades->tamanho() - 1;//pego a posicao do chefao
		}

		if(entidade->getId() == 5){//ele eh um projetil
			Entidade* aux;
			aux = listaEntidades->operator[](pos_chefao);//retorno a pos do chefao como entidade
			Chefao* chefao = static_cast<Chefao*>(aux);//transformo em chefao
			chefao->criaProjeteis(static_cast<Projetil*>(entidade));//crio o projetil dentro do set do chefao

		}
	}

	void ListaEntidade::setGG(Gerenciadores::Gerenciado_Grafico* gg) {

		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			(*it)->setGerenciador(gg);
		}
	}

	int ListaEntidade::VerificMortos() {
		int tam = 0;
		bool temMortos = false;


		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end() && temMortos == false; it++) {
			tam++;
			if ((*it)->getId() == 4 || (*it)->getId() == 6) {
				if (static_cast<Inimigo*>(*it)->getVidas() <= 0) {
					temMortos = true;
					return listaEntidades->posicao(*it);
				}
			}
			if ((*it)->getId() == 5) {
				if (static_cast<Projetil*>(*it)->getNoChao() == true) {
					temMortos = true;
					return listaEntidades->posicao(*it);
				}
			}
		}
		return (-1);
	}

	void ListaEntidade::MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc) {
		
		listaEntidades->removerElemento(ent);
		gc->removeEntidade(ent);
	}

	void ListaEntidade::matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes * gc){
		Entidade* ent = listaEntidades->operator[](pos);

		if (ent->getId() == 4 || ent->getId() == 6) {
			MatarEntidade(ent, gc);
		}

		if (ent->getId() == 5) {
			Entidade* aux2 = listaEntidades->operator[](pos_chefao);//retorno a pos do chefao como entidade
			Chefao* chefao = static_cast<Chefao*>(aux2);
			chefao->apagaProjetil();
			MatarEntidade(ent, gc);
		}
	}

}//namespace Listas