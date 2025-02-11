#include "ListaEntidades.h"
#include "../Personagens/Heroi.h"
#include "../Personagens/Yokai.h"

namespace Listas {

	class Obstaculo;

	/*===== construtora =====*/
	ListaEntidade::ListaEntidade() :
		listaEntidades(new Lista<Entidades::Entidade*>()),
		chefoes(new std::vector<Entidades::Personagens::Yokai*>()),
		plataforma_Yokai(new std::queue<Entidades::Entidade*>())
	{
		pos_Yokai = 0;
		zona_Yokai = false;
		zona_Yokai_num = 0;
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
		delete chefoes;
		delete plataforma_Yokai;

	}
	
	

	/*===== percorre a lista entidade =====*/
	void ListaEntidade::Percorrer(Gerenciadores::Gerenciador_Colisoes* gc) {
		gc->executar();//executar do gerenciador de colisoes 


		for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			if ((*it)->getId() == 3) {//se for uma plataforma
				(*it)->executar();
			}
			if ((*it)->getId() == 5) {//se for um projetil
				if (static_cast<Entidades::Projetil*>(*it)->getApareceu() == true) {//se ele ja apareceu
						(*it)->executar();//executa o projetil
				}
			}
			else if ((*it)->getId() == 6) {//se for um Yokai
				if (static_cast<Entidades::Personagens::Yokai*>(*it)->getAtivo() == true) {
					(*it)->executar();
				}
			}
			else if ((*it)->getId() == 12) {
				(*it)->executar();
			}
			else {//se nao for projetil nem Yokai nem plat Yokai
				(*it)->executar();

				if ((*it)->getId() == 1) {//se for um jogador
					encontraZonaYokai(static_cast<Entidades::Personagens::Heroi*>(*it));//verifico qual zona ele tá
				}
			}
		}
	}

	/*===== inclui uma entidade na lista e verifica se eh Yokai ou projetil =====*/
	void ListaEntidade::Incluir(Entidades::Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc) {

		listaEntidades->adicionarElemento(entidade);//adiciono na lista
		gc->includeEntidade(entidade);//incluo no gerenciador de colisoes

		if (entidade->getId() == 6) {//se for Yokai adiciono-o no vector
			chefoes->push_back(static_cast<Entidades::Personagens::Yokai*>(entidade));//coloco o Yokai no vetor de Yokai
			
		}

		if(entidade->getId() == 5){//se for projetil, insiro no Yokai que tiver espaço livre

			bool inseri = false;
			int i = 0;
			int tam;

			tam = (int)chefoes->size();
			while (inseri != true && i<tam) {
				Entidades::Personagens::Yokai* Yokai = chefoes->operator[](i);

				if (Yokai->getNum_Projetil() < Yokai->getMaxProjetil()) {
					Yokai->criaProjeteis(static_cast<Entidades::Projetil*>(entidade));
					inseri = true;
				}
				else {
					i++;
				}
			}
		}

		if (entidade->getId() == 12) {//se for plataforma do Yokai
			plataforma_Yokai->push(entidade);
		}
	}

	/*=== Inclui entidade na lista ===*/ //*************** nao está sendo usado!!
	void ListaEntidade::Include(Entidades::Entidade* entidade) {
		listaEntidades->adicionarElemento(entidade);
	}

	/*=== incluir para o salvamento!! ===*/
	void ListaEntidade::IncluirSalvamento(Entidades::Entidade* entidade, Gerenciadores::Gerenciador_Colisoes* gc) {
		listaEntidades->adicionarElemento(entidade);//adiciono na lista
		gc->includeEntidade(entidade);//incluo no gerenciador de colisoes

		if (entidade->getId() == 6) {//se for Yokai adiciono-o no vector
			chefoes->push_back(static_cast<Entidades::Personagens::Yokai*>(entidade));//coloco o Yokai no vetor de Yokai

		}
		if (entidade->getId() == 5) {//se for projetil, insiro no Yokai que tiver espaço livre

			bool inseri = false;
			int i = 0;
			int tam;
			tam =(int) chefoes->size();
			while (inseri != true && i < tam) {
				Entidades::Personagens::Yokai* Yokai = chefoes->operator[](i);

				if (Yokai->getNum_Proj_Salv() < Yokai->getNum_Projetil()) {
					Yokai->criaProjeteisSalv((static_cast<Entidades::Projetil*>(entidade)));
					inseri = true;
				}
				else {
					i++;
				}
			}
		}
		if (entidade->getId() == 12) {//se for plataforma do Yokai
			plataforma_Yokai->push(entidade);
			cout << "Inseri plataforma Yokai" << endl;
		}

	}

	/*===== seta o gerenciador gráfico em todas as instâncias da lista =====*/
	void ListaEntidade::setGG(Gerenciadores::Gerenciado_Grafico* gg) {

		for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++)
		{
			//(*it)->setGerenciador(gg);
		}
	}

	/*===== verifica se há mortos na lista entidade e retorna a posição do morto =====*/
	int ListaEntidade::VerificMortos() {
		int tam = 0;
		bool temMortos = false;


		for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end() && temMortos == false; it++) {
			tam++;
			if ((*it)->getId() == 4 || (*it)->getId() == 6 || (*it)->getId() == 7) {
				if (static_cast<Entidades::Personagens::Inimigo*>(*it)->getVidas() <= 0) {
					temMortos = true;
					return listaEntidades->posicao(*it);
				}
			}
			if ((*it)->getId() == 5) {
				if (static_cast<Entidades::Projetil*>(*it)->getnoChao() == true || static_cast<Entidades::Projetil*>(*it)->getApagado()==true) {
					temMortos = true;
					return listaEntidades->posicao(*it);
				}
			}
		}
		return (-1);//se nao houver mortos, retorna -1
	}

	void ListaEntidade:: MatarEntidade(Entidades::Entidade* ent, Gerenciadores::Gerenciador_Colisoes* gc) {
		listaEntidades->removerElemento(ent);
		gc->removeEntidade(ent);
	}


	/*===== remove uma entidade com uma determinada posição na lista =====*/
	void ListaEntidade::matarEntidadePos(int pos, Gerenciadores::Gerenciador_Colisoes * gc){
		Entidades::Entidade* ent = listaEntidades->operator[](pos);

		if (ent->getId() == 7 || ent->getId() == 4) {
			MatarEntidade(ent, gc);
		}
		if (ent->getId() == 6) {//se for Yokai PRECISO remover a plataforma dele
			MatarEntidade(ent, gc);
			gc->removeEntidade(plataforma_Yokai->front());
			listaEntidades->removerElemento(plataforma_Yokai->front());
			plataforma_Yokai->pop();
		}

		if (ent->getId() == 5) {//projetil
			MatarEntidade(ent, gc);
		}
	}


	/*===== seta se um jogador está na zona de um determinado Yokai... =====*/
	void ListaEntidade::encontraZonaYokai(Entidades::Personagens::Heroi* jog) {
		bool achou = false;

		for (int i = 0; i < chefoes->size() && achou != true; i++) {
			achou = chefoes->operator[](i)->zonaYokai(jog);
			chefoes->operator[](i)->setAtivo(achou);
		}
	}

	vector<Entidades::Entidade*> ListaEntidade::returnVec() {
		vector<Entidades::Entidade*> aux;

		for (Lista<Entidades::Entidade*>::iterator it = listaEntidades->begin(); it != listaEntidades->end(); it++) {
			if ((*it)->getId() == 1 || (*it)->getId() == 2 || (*it)->getId() == 4 ||
				(*it)->getId() == 7 || (*it)->getId() == 6) {
				Entidades::Personagens::Personagem* p = static_cast<Entidades::Personagens::Personagem*>(*it);
				if (p->verificaVida()) {
					aux.push_back(*it);
				}
			}
			else {
				aux.push_back(*it);
			}
		}

		return aux;
  }

}//namespace Listas