#include "Chefao.h"
#include <iostream>
#include <set>

namespace Personagens {
	Chefao::Chefao(int id, const char* png) :
		Inimigo(id, png),
		ListProj()
	{
		danoProjetil = 10;
		turno = false;
		vidas = 50;
		setCoordenadas(6960, 450);
		setCorpo(224, 240);
		setVelocidae(150, 0);
		setMaldade(3);
		val = 0;
		cont = 0;
	}

	Chefao::~Chefao(){
	}

	void Chefao::teletransportar() {

		if (relogio1.getElapsedTime().asSeconds() >= 5.5 && !turno) {
			corpo.setPosition(6250, 560);
			setCoordenadas(6250, 560);
			setCorpo(224, 240);
			relogio1.restart();
			turno = true;
		}
		if(relogio1.getElapsedTime().asSeconds() >= 3.5 && turno){
			corpo.setPosition(6960, 450);
			setCoordenadas(6960, 450);
			setCorpo(224, 240);
			turno = false;
			relogio1.restart();
		}
	}

	void Chefao::executar()
	{
		cont++;

		if (cont % 7 == 0) {
			val++;
			animacao(15);
		}
		if (verificaVida()) {
			pGGrafico->desenha(corpo);
			teletransportar();
		
			if (turno == false && relogioProjetil.getElapsedTime().asSeconds() >= 1.5 ) {
				//solta o projetil com o executar do primeiro projetil
				if (!ListProj.empty()){
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
}