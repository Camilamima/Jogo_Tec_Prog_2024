#include "Chefao.h"
#include <iostream>
#include <set>

namespace Personagens {
	Chefao::Chefao(int id, const char* png) :
		Inimigo(id, png),
		ListProj()
	{
		danoProjetil = 10;
		qnt_projetil = 5;
		turno = false;
		vidas = 100;
		setCoordenadas(1500, 450);
		setCorpo(100, 100);
		setVelocidae(150, 0);
		setMaldade(3);

	}

	Chefao::~Chefao(){
	}

	void Chefao::teletransportar() {

		if (relogio1.getElapsedTime().asSeconds() >= 5.5 && !turno) {
			corpo.setPosition(1300, 700);
			setCoordenadas(1300, 700);
			setCorpo(100, 100);
			relogio1.restart();
			turno = true;
		}
		if(relogio1.getElapsedTime().asSeconds() >= 3.5 && turno){
			corpo.setPosition(1500, 450);
			setCoordenadas(1500, 450);
			setCorpo(100, 100);
			turno = false;
			relogio1.restart();
		}
	}

	void Chefao::executar()
	{
		if (verificaVida()) {
			pGGrafico->desenha(corpo);
			teletransportar();
		
			if (turno == false && relogioProjetil.getElapsedTime().asSeconds() >= 1.5) {
				//solta o projetil com o executar do primeiro projetil
				if (!ListProj.empty()){
				std::set<Projetil*>::iterator it = ListProj.begin();//aq deve estar nulo??
				(*it)->realiza();
				relogioProjetil.restart();
				}
			}
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
				ListProj.erase(it);//apagar o primeiro... parecido com um pop_front?
			}
		}
	}
}