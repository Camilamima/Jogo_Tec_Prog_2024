#include "Gerenciador_Colisoes.h"
#include "Plataforma.h"
#include "Slime.h"
#include "Inimigo.h"
#include "iostream"
using namespace Gerenciadores;
using namespace std;

Gerenciador_Colisoes::Gerenciador_Colisoes():
	jog1(nullptr), jog2(nullptr) {
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    
}


void Gerenciador_Colisoes::trocaFase(){
	LPlat.clear();
}

void Gerenciador_Colisoes::setJogadores(Slime* j1, Slime* j2) {
	jog1 = j1;
	jog2 = j2;
}

void Gerenciador_Colisoes::includeObstaculo(Plataforma* plat) {
	LPlat.push_back(plat);
}

void Gerenciador_Colisoes::includeInimigo(Inimigo* ini) {
	LIni.push_back(ini);
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
		//ch�o
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

}


void Gerenciador_Colisoes:: verificaObs(){

	RectangleShape aux;
	bool emCima=0;
	bool ladoD=0;
	bool ladoE=0;

	for (Obstaculo* obstaculo : LPlat) {
		aux = obstaculo->getCorpo();
			if (veriColisao(obstaculo, jog1)==1){
				if (obstaculo->getImpede()){
					jog1->setChao(aux.getPosition().y-100);
					emCima = 1;
				}

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
	if (!emCima) {
		jog1->setChao(800);
		jog1->setNoChao(0);
	}
	if (!ladoD) {

		jog1->setMoviD(1);
	}
	if(!ladoE){
		jog1->setMoviE(1);
	}

	emCima = 0;
	ladoD = 0;
	ladoE = 0;

}

void Gerenciador_Colisoes::executar(){
	verificaIni();
	verificaObs();
}



