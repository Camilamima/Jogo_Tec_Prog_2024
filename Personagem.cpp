#include "Personagem.h"


Personagem::Personagem(int id, const char* png, int vids, float vlX, float vlY) :
	Entidade(id,png),
	vidas(vids),
	velocidadeX(vlX),
	velocidadeY(vlY)
{

}

Personagem::~Personagem() {
	vidas = -1;
}

void Personagem::setVidas(int vid) {
	vidas = vid;
}

const float Personagem::gravidade = 7;