#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
#include "Slime.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "SlimeMau.h"
#include "Espinho.h"
#include "Acelerador.h"
#include <list>
#include <iostream>

using namespace Gerenciadores;
using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes():
	jog1(nullptr), jog2(nullptr) {
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    
}


void Gerenciador_Colisoes::trocaFase(){
	LObst.clear();
	LIni.clear();
}

void Gerenciador_Colisoes::setJogadores(Slime* j1, Slime* j2) {
	jog1 = j1;
	jog2 = j2;
}

void Gerenciador_Colisoes::includeEntidade(Entidade* ent) {
	if (ent->getId() == 3) {
		LObst.push_back(static_cast<Obstaculo*>(ent));
		static_cast<Obstaculo*>(ent)->setpJogador(jog1);

	}
	else if (ent->getId() == 4) {
		LIni.push_back(static_cast<Inimigo*>(ent));
	}
}

int Gerenciador_Colisoes::veriColisao(Entidade* ent,Slime* sl) {

	RectangleShape jogador;
	RectangleShape outro;
	jogador = sl->getCorpo();
	outro = ent->getCorpo();

	float x, y, x2, y2,xx,yy,xx2,yy2;

	x = jogador.getPosition().x;
	y = jogador.getPosition().y;
	x2 = x + jogador.getSize().x;
	y2 = y + jogador.getSize().y;

	xx = outro.getPosition().x;
	yy = outro.getPosition().y;
	xx2 = xx + outro.getSize().x;
	yy2 = yy + outro.getSize().y;

	//horizontal
	if ((x >= outro.getPosition().x && x <= (outro.getPosition().x + outro.getSize().x)) ||
		(x2 >= outro.getPosition().x && x2 <= (outro.getPosition().x + outro.getSize().x)))
	{
		//chão
		if (y2 >= yy-9.8 && y2 <= yy+9.8) {
			return 1;
		}
		//teto
		if (y >= yy2 - 9.8 && y <= yy2 + 9.8) {
			return 4;
		}


	}

	//lados
	if ((y >= outro.getPosition().y && y <= (outro.getPosition().y + outro.getSize().y)) ||
		//esquerda
		(y2 >= outro.getPosition().y && y2 <= (outro.getPosition().y + outro.getSize().y))) {
		if (x2 >= xx+5  && x2 <= xx+15 ) {

			return 2;

		}
		//direita
		else if (x >= xx2 - 10 && x<= xx2 ) {
			return 3;
		}
	}

	if ((x >= outro.getPosition().x && x <= (outro.getPosition().x + outro.getSize().x)) ||
		(x2 >= outro.getPosition().x && x2 <= (outro.getPosition().x + outro.getSize().x)))//especifico p slime mau e espinho
	{
		if ((y >= outro.getPosition().y && y <= (outro.getPosition().y + outro.getSize().y)) ||
			(y2 >= outro.getPosition().y && y2 <= (outro.getPosition().y + outro.getSize().y))) {
			return 5;
		}
	}


	return 0;

	
}


void Gerenciador_Colisoes::verificaIni() {

	RectangleShape aux;

	for (Inimigo* inimigo : LIni) {

		if (!inimigo->verificaVida()) {
			continue;
		}

		aux = inimigo->getCorpo();

		if (veriColisao(inimigo, jog1) == 1) {
			jog1->setAtacando(1);
			jog1->pular(300);
			--(*inimigo);
			cout << "vidas do ratinho: " << inimigo->getVidas() << endl;
		}

		else if (veriColisao(inimigo, jog1) == 2) {

			if (!jog1->getAtacado()) {
				--(*jog1);
				jog1->pular(300);
				jog1->setAtacado(1, 0);
				cout << "vidas slime: " << jog1->getVidas() << endl;
			}
		}
		else if (veriColisao(inimigo, jog1) == 3) {
			if (!jog1->getAtacado()){
				--(*jog1);
				jog1->pular(300);
				jog1->setAtacado(1, 1);
				cout << "vidas slime: " << jog1->getVidas() << endl;
			}

		}
	}

	if (jog2 != nullptr) {

		for (Inimigo* inimigo : LIni) {

			if (!inimigo->verificaVida()) {
				continue;
			}

			aux = inimigo->getCorpo();

			if (veriColisao(inimigo, jog2) == 1) {
				jog2->setAtacando(1);
				jog2->pular(300);
				--(*inimigo);
				cout << "vidas do ratinho: " << inimigo->getVidas() << endl;
			}

			else if (veriColisao(inimigo, jog2) == 2) {

				if (!jog2->getAtacado()) {
					--(*jog2);
					jog2->pular(300);
					jog2->setAtacado(1, 0);
					cout << "vidas slime: " << jog2->getVidas() << endl;
				}
			}
			else if (veriColisao(inimigo, jog2) == 3) {
				if (!jog2->getAtacado()) {
					--(*jog2);
					jog2->pular(300);
					jog2->setAtacado(1, 1);
					cout << "vidas slime: " << jog2->getVidas() << endl;
				}

			}
		}
	}

}


void Gerenciador_Colisoes::verificaObs() {

	RectangleShape aux;
	int tempo;
	bool emCima = 0;
	bool ladoD = 0;
	bool ladoE = 0;

	for (Obstaculo* obstaculo : LObst) {

		aux = obstaculo->getCorpo();

		if (veriColisao(obstaculo, jog1) == 5) {

			if (obstaculo->getAtrapalha() == true) {//se areia mov...
				obstaculo->obstacular(jog1);
			}

			if (obstaculo->getDanoso() == true) {//se espinho
				obstaculo->obstacular(jog1);
			}

			if (obstaculo->getAcelera() == true) {
				obstaculo->obstacular(jog1);
			}

		}

		if (obstaculo->getImpede() == true) {

			if (veriColisao(obstaculo, jog1) == 1) {
				jog1->setChao(aux.getPosition().y - 100);
				emCima = 1;
			}

			if (veriColisao(obstaculo, jog1) == 2) {

				jog1->setMoviD(0);
				ladoD = 1;
			}

			if (veriColisao(obstaculo, jog1) == 3) {

				jog1->setMoviE(0);
				ladoE = 1;
			}

			if (veriColisao(obstaculo, jog1) == 4) {
				jog1->setVelocidadeY(0);
				jog1->pular(-100);
				break;
			}
		}

		if (veriColisao(obstaculo, jog1) == 0) { //se nao tem colisao...

			if (obstaculo->getAtrapalha() == true) {
				obstaculo->restaura(jog1);
			}
			if (obstaculo->getAcelera() == true) {
				tempo = static_cast<Acelerador*>(obstaculo)->getTimer();

				if (tempo % 200 == 0) {
					obstaculo->restaura(jog1);
				}
			}
		}

	}

	if (!emCima) {
		jog1->setChao(800);
		jog1->setNoChao(0);
	}

	if (!ladoD) {
		jog1->setMoviD(1);
	}

	if (!ladoE) {
		jog1->setMoviE(1);
	}

	emCima = 0;
	ladoD = 0;
	ladoE = 0;

	if (jog2 != nullptr) {

		for (Obstaculo* obstaculo : LObst) {

			aux = obstaculo->getCorpo();

			if (veriColisao(obstaculo, jog2) == 5) {

				if (obstaculo->getAtrapalha() == true) {//se areia mov...
					obstaculo->obstacular(jog2);
				}

				if (obstaculo->getDanoso() == true) {//se espinho
					obstaculo->obstacular(jog2);
				}

				if (obstaculo->getAcelera() == true) {
					obstaculo->obstacular(jog2);
				}
			}

			if (obstaculo->getImpede() == true) {

				if (veriColisao(obstaculo, jog2) == 1) {
					jog2->setChao(aux.getPosition().y - 100);
					emCima = 1;
				}

				if (veriColisao(obstaculo, jog2) == 2) {

					jog2->setMoviD(0);
					ladoD = 1;
				}

				if (veriColisao(obstaculo, jog2) == 3) {

					jog2->setMoviE(0);
					ladoE = 1;
				}

				if (veriColisao(obstaculo, jog2) == 4) {
					jog2->setVelocidadeY(0);
					jog2->pular(-100);
					break;
				}
			}

			if (veriColisao(obstaculo, jog2) == 0) { //se nao tem colisao...

				if (obstaculo->getAtrapalha() == true) {
					obstaculo->restaura(jog2);
				}
				if (obstaculo->getAcelera() == true) {
					tempo = static_cast<Acelerador*>(obstaculo)->getTimer();
					
					if (tempo % 200 == 0) {
						obstaculo->restaura(jog2);
					}
				}
				
			}

		}

		if (!emCima) {
			jog2->setChao(800);
			jog2->setNoChao(0);
		}

		if (!ladoD) {
			jog2->setMoviD(1);
		}

		if (!ladoE) {
			jog2->setMoviE(1);
		}

		emCima = 0;
		ladoD = 0;
		ladoE = 0;
	}
}

void Gerenciador_Colisoes::executar(){
	verificaIni();
	verificaObs();
}



