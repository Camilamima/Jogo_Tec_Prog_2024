#include "Slime.h"
#include <iostream>

using namespace std;
Slime::Slime(int id, const char* png) :
	Personagem(id, png)
{
	ladoAtacado = 0;
	atacado = 0;
	atacando = 0;
	chao = 800;
	setVelocidae(VX, 0);
	setCoordenadas(875, 800);
	pontos = 0;
	noChao = 1;
	moviD = 1;
	moviE = 1;
	wPress = 0;
	relogio.restart();
	impulso = -1;
	setCorpo(100, 100);
	vidas = 25;
}

Slime::~Slime() {
}

void Slime::mover(float aux) {


	if (!noChao)
	{

		velocidadeY += static_cast<float>(gravidade) * atualizaDelta();
		if ((corpo.getPosition().y + velocidadeY) >= chao) {
			velocidadeY = chao - corpo.getPosition().y;
		}
		if (!atacando && !atacado){
			if (!wPress && velocidadeY < 0) {

				if (velocidadeY < 0) {
					velocidadeY = 0;
				}

				wPress = 1;

				mover(aux);
			}
		}

		corpo.move(aux, velocidadeY);
		if (corpo.getPosition().y >= chao) {
			noChao = 1;
			velocidadeY = 0;
			atacando = 0;
			atacado = 0;
		}
	}
	else {
		corpo.move(aux, 0);
	}


}



void Slime::pular(float imp) {
	impulso = imp;
	velocidadeY = -impulso * atualizaDelta();
	noChao = 0;
}



void Slime::processaEvento() {

	if (atacado) {
		
		if (!ladoAtacado) {
			if (moviE == 1) {
			mover(atualizaDelta() * -300);
			}
			else {
				mover(0);
			}
		}

		else if (ladoAtacado){

			if (moviD == 1){
				mover(atualizaDelta() * +300);
			}
			else {
				mover(0);
			}
		}
	}
	else{

		if (Keyboard::isKeyPressed(Keyboard::D)) {
			if (moviD == 1) {
				mover(atualizaDelta() * velocidadeX);
			}
		}

		else if (Keyboard::isKeyPressed(Keyboard::A)) {
			if (moviE == 1) {
				mover(atualizaDelta() * -velocidadeX);
			}
		}

		if (Keyboard::isKeyPressed(sf::Keyboard::W)) {

			if (noChao) {
				pular(600);
				wPress = 1;
			}
			mover(0);
		}
		else {
			wPress = 0;
			mover(0);

		}
	}
}

void Slime::processaEvento2() {
	if (atacado) {

		if (!ladoAtacado) {
			if (moviE == 1) {
				mover(atualizaDelta() * -300);
			}
			else {
				mover(0);
			}
		}

		else if (ladoAtacado) {

			if (moviD == 1) {
				mover(atualizaDelta() * +300);
			}
			else {
				mover(0);
			}
		}
	}
	
	else {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (moviD == 1) {
				mover(atualizaDelta() * velocidadeX);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (moviE == 1) {
				mover(atualizaDelta() * -velocidadeX);
			}
		}

		if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {

			if (noChao) {
				pular(600);
				wPress = 1;
			}
			mover(0);
		}
		else {
			wPress = 0;
			mover(0);

		}
	}
}



void Slime::executar(){

	if (corpo.getPosition().y >= chao && !atacado) {
		noChao = 1;
		velocidadeY = 0;
		atacando = 0;
	}

	if (getId() == 1) {
		processaEvento();
	}
		
	if (getId() == 2) {
		processaEvento2();
	}

	pGGrafico->desenha(corpo);
	
}



