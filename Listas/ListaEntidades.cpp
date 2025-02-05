#include "ListaEntidades.h"
#include "../Personagens/Slime.h"
#include "../Personagens/Chefao.h"

using namespace Personagens;
namespace Listas {

	class Obstaculo;

	/*===== construtora =====*/
	ListaEntidade::ListaEntidade() :
		listaEntidades(new Lista<Entidade*>()),
		chefoes(new std::vector<Chefao*>())
	{
		pos_chefao = 0;
		zona_chefao = false;
		zona_chefao_num = 0;
	}

	/*===== destrutora =====*/
	ListaEntidade::~ListaEntidade() {

		int i;
		int z = listaEntidades->tamanho();

		for (i = 0; i < z; i++)
		{
			listaEntidades->removerElemento(0);
		}
		delete listaEntidades;
	}
	
	

	/*===== percorre a lista entidade =====*/
	void ListaEntidade::Percorrer(Gerenciadores::Gerenciador_Colisoes* gc) {
		gc->executar();//executar do gerenciador de colisoes 

		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			if ((*it)->getId() == 5) {//se for um projetil
				if (static_cast<Projetil*>(*it)->getApareceu() == true) {//se ele ja apareceu
					//cout << "Apareceu" << endl;
						(*it)->executar();//executa o projetil
				}
			}

			else {//se for um id diferente de 5 ou seja, 1,2,3,4,6
				(*it)->executar();

				if ((*it)->getId() == 1) {//se for um jogador
					encontraZonaChefao(static_cast<Slime*>(*it));//verifico qual zona ele tá
				}
			}
		}
	}

	/*===== inclui uma entidade na lista e verifica se eh chefao ou projetil =====*/
	void ListaEntidade::Incluir(Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc) {

		listaEntidades->adicionarElemento(entidade);//adiciono na lista
		gc->includeEntidade(entidade);//incluo no gerenciador de colisoes

		if (entidade->getId() == 6) {//se for chefao adiciono-o no vector
			//pos_chefao = listaEntidades->tamanho() - 1;//pego a posicao do chefao
			chefoes->push_back(static_cast<Chefao*>(entidade));//coloco o chefao no vetor de chefao
			
		}

		if(entidade->getId() == 5){//se for projetil, insiro no chefao que tiver espaço livre

			bool inseri = false;
			int i = 0;
			int tam;
			tam = chefoes->size();
			while (inseri != true && i<tam) {
				Chefao* chefao = chefoes->operator[](i);

				if (chefao->getNum_Projetil() < chefao->getMaxProjetil()) {
					chefao->criaProjeteis(static_cast<Projetil*>(entidade));
					inseri = true;
					//cout << "Inseri proj em: " << i << endl;
				}
				else {
					i++;
				}
			}
		}
	}

	void ListaEntidade::Include(Entidade* entidade) {
		listaEntidades->adicionarElemento(entidade);
	}

	/*===== seta o gerenciador gráfico em todas as instâncias da lista =====*/
	void ListaEntidade::setGG(Gerenciadores::Gerenciado_Grafico* gg) {

		for (Lista<Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			(*it)->setGerenciador(gg);
		}
	}

	/*===== verifica se há mortos na lista entidade e retorna a posição do morto =====*/
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
				if (static_cast<Projetil*>(*it)->getNoChao() == true || static_cast<Projetil*>(*it)->getApagado()==true) {
					temMortos = true;
					return listaEntidades->posicao(*it);
				}
			}
		}
		return (-1);//se nao houver mortos, retorna -1
	}

	/*===== remove uma determinada entidade da lista =====*/
	void ListaEntidade::MatarEntidade(Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc) {
		
		listaEntidades->removerElemento(ent);
		gc->removeEntidade(ent);
	}

	/*===== remove uma entidade com uma determinada posição na lista =====*/
	void ListaEntidade::matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes * gc){
		Entidade* ent = listaEntidades->operator[](pos);

		if (ent->getId() == 4 || ent->getId() == 7 || ent->getId() == 6) {//inimigos
			MatarEntidade(ent, gc);
		}

		if (ent->getId() == 5) {//projetil
			MatarEntidade(ent, gc);
		}
	}

	/*===== seta se um jogador está na zona de um determinado chefao... =====*/
	void ListaEntidade::encontraZonaChefao(Slime* jog) {
		bool achou = false;

		for (int i = 0; i < chefoes->size() && achou != true; i++) {
			achou = chefoes->operator[](i)->zonaChefao(jog);
			chefoes->operator[](i)->setAtivo(achou);
		}
	}

}//namespace Listas