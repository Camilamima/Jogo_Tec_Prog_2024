#include "Chefao.h"
#include <iostream>
#include <set>

namespace Personagens {

	Chefao::Chefao(int id, const char* png) :
		Inimigo(id, png),
		ListProj(),
		teletransporte(nullptr)
	{
		danoProjetil = 10;
		turno = false;
		vidas = 50;
		chao = 600;
		setCoordenadas(600, 0);
		setCorpo(224, 240);
		setVelocidae(0, 0);
		setMaldade(3);
		val = 0;
		cont = 0;
		//teletransporte->setCoordenadas(6960, 450);
		//teletransporte->setCorpo(250, 250);
		fim_animacao = true;
	}

	Chefao::~Chefao() {
	}

	void Chefao::teletransportar() {

		if (relogio1.getElapsedTime().asSeconds() >= 5.5 && !turno) {
			//if (cont % 5 == 0) {
				//animacaoTp(15);
				//if (fim_animacao == true) {//teletransporte->getApareceu()==false) {
					//teletransporte->setCoordenadas(6250, 560);
					//teletransporte->setCorpo(250, 250);
					//corpo.setPosition(6250, 560);
					setCoordenadas(6250, 560);
					setCorpo(224, 240);
					relogio1.restart();
					turno = true;
				//}
			//}
		}

		if (relogio1.getElapsedTime().asSeconds() >= 3.5 && turno) {
			//if (cont % 5 == 0) {
				//teletransporte->animacao();
				//animacaoTp(15);

				//if (fim_animacao == true) {//teletransporte->getApareceu()==false) {
					//teletransporte->setCoordenadas(6960, 450);
					//teletransporte->setCorpo(250, 250);
					corpo.setPosition(6960, 450);
					setCoordenadas(6960, 450);
					setCorpo(224, 240);
					turno = false;
					relogio1.restart();
				//}
			//}
		}
	}

	void Chefao::executar()
	{
		cont++;
		/*if (!noChao) { ********************MEXER NISSO P ELE TER GRAVIDADE
			mover(0);
		}

		if (corpo.getPosition().y+240 >= chao) {
			noChao = true;
		}*/

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
					(*it)->realiza();
					relogioProjetil.restart();
				}
			}

			apagaProjetil();
		}
		//metodo que solta um projetil
	}


	void Chefao::criaProjeteis(Projetil* proj) {//cria todos os projeteis

		if (proj != nullptr) {
			ListProj.insert(proj);
		}

	}

	void Chefao::apagaProjetil() {//apaga se ele tocou no chao...

		if (!ListProj.empty()) {//se a lista nao estiver vazia (se tiver projetil dentro dela
			std::set<Projetil*>::iterator it = ListProj.begin();
			if ((*it)->getNoChao() == true) {//se o projetil tocou no chao
				std::cout << "Apaguei um projetil" << std::endl;
				ListProj.erase(it);//apagar o primeiro... parecido com um pop_front?
			}
		}
	}

	void Chefao::animacao(int limite) {
		if (val >= limite) {
			val = 0;
		}

		sprite.loadFromFile("assets/chefao/Agis.png");
		corpo.setTexture(&sprite);
		corpo.setTextureRect(IntRect(224 * val, 0, 224, 240));

	}

	void Chefao::animacaoTp(int limite) {
		fim_animacao = false;

		if (val >= limite) {
			fim_animacao = true;
			val = 0;
		}

		setSoCorpo(250, 250);
		sprite.loadFromFile("assets/efeito/teletransporte.png");
		corpo.setTexture(&sprite);
		corpo.setTextureRect(IntRect(250 * val, 0, 250, 250));
	}
}