#include "Gerenciador_Colisoes.h"
#include "Obstaculo.h"
#include "Slime.h"
using namespace Gerenciadores;

Gerenciador_Colisoes::Gerenciador_Colisoes():
	jog1(nullptr), jog2(nullptr) {
	horizontal = 0;
	vertical = 0;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
    
}


void Gerenciador_Colisoes::trocaFase(){
	LObs.clear();
}

void Gerenciador_Colisoes::setJogadores(Slime* j1, Slime* j2) {
	jog1 = j1;
	jog2 = j2;
}

void Gerenciador_Colisoes::includeObstaculo(Obstaculo* obs) {
	LObs.push_back(obs);
}

bool Gerenciador_Colisoes::veriColisao(Entidade* ent,Slime* sl) {
	vertical = 0;
	horizontal = 0;
	RectangleShape jogador;
	RectangleShape outro;
	jogador = sl->getCorpo();
	outro = ent->getCorpo();

	float x, y, x2, y2;

	x = jogador.getPosition().x;
	y = jogador.getPosition().y;
	x2 = x + jogador.getSize().x;
	y2 = y + jogador.getSize().y;

	if ((x >= outro.getPosition().x && x <= (outro.getPosition().x + outro.getSize().x)) ||
		(x2 >= outro.getPosition().x && x2 <= (outro.getPosition().x + outro.getSize().x)))
	{
		horizontal = 1;

	}
	if ((y >= outro.getPosition().y && y <= (outro.getPosition().y + outro.getSize().y)) ||
		(y2 >= outro.getPosition().y && y2 <= (outro.getPosition().y + outro.getSize().y))) {
		vertical = 1;
	}

	if (vertical == 1 && horizontal == 1) {
		return 1;
	}

	return 0;

}

void Gerenciador_Colisoes:: verificaObs() {

	RectangleShape aux;

	for (Obstaculo* obstaculo : LObs) {
		aux = obstaculo->getCorpo();
		if (obstaculo) {
			if (veriColisao(obstaculo, jog1)) {
				if (obstaculo->getImpede()){
					jog1->setChao(aux.getPosition().y);
					break;
				}

			}
			else {
				jog1->setChao(800);
				jog1->setNoChao(0);
			}

		}
	}
}

void Gerenciador_Colisoes::executar(){
	verificaObs();
}



