#include "Chefao.h"
#include <iostream>
#include <set>

namespace Personagens {

	Chefao::Chefao(int id, const char* png) :
		Inimigo(id, png),
		ListProj()//,
		//teletransporte(nullptr)
	{
		iniZona = 0;
		finalZona = 0;
		ativo = false;
		turno = false;
		vidas = 50;
		chao = 560;
		val = 0;
		cont = 0;
		pos_inicial = 0;

		//setCoordenadas(6960, 450);
		setCorpo(224, 240);
		setVelocidae(0, 0);
		setMaldade(3);

		//fim_animacao = true;
		num_projetil = 0; //qnd adicionar 1 projetil, soma +1
		//zonaChefao();//seta a zona do chefao ---- chamar qnd dar new
		

	}

	Chefao::~Chefao() {
	}

	/*===== metodo que teletransporta =====*/
	void Chefao::teletransportar() {

		if (relogio1.getElapsedTime().asSeconds() >= 7.5 && !turno) {
			
			//std::cout << "Fim da zona do chefao" << finalZona <<std::endl;
			//std::cout << "teste" << std::endl;
			int meioZona = (finalZona - ((finalZona-iniZona)/2));
			//std::cout << meioZona << std::endl;
			setCoordenadas(meioZona, 530);
			setCorpo(224, 240);
			relogio1.restart();
			turno = true;

		}

		if (relogio1.getElapsedTime().asSeconds() >= 3.5 && turno) {
			//if (cont % 5 == 0) {
				//teletransporte->animacao();
				//animacaoTp(15);

				//if (fim_animacao == true) {//teletransporte->getApareceu()==false) {
					//teletransporte->setCoordenadas(6960, 450);
					//teletransporte->setCorpo(250, 250);
					//corpo.setPosition(6960, 450);
					setCoordenadas(pos_inicial, 300);
					setCorpo(224, 240);
					turno = false;
					relogio1.restart();
				//}
			//}
		}
	}

	/*===== executar =====*/
	void Chefao::executar()
	{
		cont++;
		/*if (!noChao) { ********************MEXER NISSO P ELE TER GRAVIDADE
			mover(0);
		}

		if (corpo.getPosition().y+240 >= chao) {
			noChao = true;
		}*/

		if (ativo == true) {//se tem um jogador na zona

			if (cont % 7 == 0) {
				val++;
				animacao(15);
			}

			if (verificaVida()) {
				pGGrafico->desenha(corpo);
				teletransportar();

				if (turno == false && relogioProjetil.getElapsedTime().asSeconds() >= 1.5) {
					//solta o projetil com o executar do primeiro projetil
					if (!ListProj.empty()) {
						std::set<Projetil*>::iterator it = ListProj.begin();//o primeiro da lista
						(*it)->setApareceu(true);
						relogioProjetil.restart();
					}
				}

				apagaProjetil();
			}
		}
		/*else {//se nao tem jogador na zona
			if (!ListProj.empty()) {
				std::set<Projetil*>::iterator it = ListProj.begin();//o primeiro da lista
				(*it)->setApareceu(false);
			}
		}*/
		//metodo que solta um projetil
	}

	/*===== cria um projetil =====*/
	void Chefao::criaProjeteis(Projetil* proj) {//cria todos os projeteis

		if (proj != nullptr) {
			proj->setCoordenadas(pos_inicial, 300);
			proj->setCorpo(64, 32);
			proj->setXY(pos_inicial, 300);
			num_projetil++;
			ListProj.insert(proj);
		}

	}

	/*===== apaga um projetil =====*/
	void Chefao::apagaProjetil() {//apaga se ele tocou no chao...

		if (!ListProj.empty()) {//se a lista nao estiver vazia (se tiver projetil dentro dela
			std::set<Projetil*>::iterator it = ListProj.begin();
			if ((*it)->getNoChao() == true) {//se o projetil tocou no chao
				std::cout << "Apaguei um projetil" << std::endl;
				ListProj.erase(it);//apagar o primeiro... parecido com um pop_front?
			}
		}
	}

	/*===== animacao chefao =====*/
	void Chefao::animacao(int limite) {
		if (val >= limite) {
			val = 0;
		}

		sprite.loadFromFile("assets/chefao/Agis.png");
		corpo.setTexture(&sprite);
		corpo.setTextureRect(IntRect(224 * val, 0, 224, 240));

	}

	void Chefao::operator++() {
		num_projetil++;
	}

	bool Chefao::zonaChefao(Slime* jog) {
		int limiteSup_chefao = 0;
		int limiteInf_chefao = 0;
		bool fim = false;

		int num_ant = 0;

		//for pra descobrir a zona do chefao
		for (int i = 1; i <= 8 && fim != true; i++) {
			if (corpo.getPosition().x >= num_ant && corpo.getPosition().x + corpo.getSize().x <= 1800 * i) {
				limiteSup_chefao = 1800 * i;
				fim = true;
			}
			else {
				limiteInf_chefao = 1800 * (i);
			}
		}

		iniZona = limiteInf_chefao;
		finalZona = limiteSup_chefao;

		if (jog->getCorpo().getPosition().x >= limiteInf_chefao && jog->getCorpo().getPosition().x <= limiteSup_chefao) {
			return true;
		}
		else
			return false;

	}
	
	void Chefao::zonaChefao() {
		bool fim = false;

		int num_ant = 0;

		iniZona = 0;

		//for pra descobrir a zona do chefao
		for (int i = 1; i <= 8 && fim != true; i++) {
			//std::cout << "Posicao x: " << corpo.getPosition().x << std::endl;

			if (corpo.getPosition().x >= num_ant && corpo.getPosition().x + corpo.getSize().x <= 1800 * i) {
				finalZona = 1800 * i;
				//std::cout << "iniZona: " << iniZona << std::endl;
				fim = true;
			}
			else {
				//std::cout << "finalZona: " << finalZona << std::endl;
				iniZona = 1800 * (i);
			}
		}
		std::cout << "iniZona: " << iniZona << std::endl;
		std::cout << "finalZona: " << finalZona << std::endl;
		
	}
	const int Chefao::max_projetil = 10;
}