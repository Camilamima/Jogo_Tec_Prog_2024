#include "Inimigo.h"

Entidades::Inimigo::Inimigo(int id, const char* png) :
	Personagem(id, png)
{
	nivel_maldade = -1;
}

Entidades::Inimigo::~Inimigo() {

}

void Entidades::Inimigo::mover(float aux) {
	
		corpo.move(aux*atualizaDelta(), 0);

}

void Entidades::Inimigo::setMaldade(int maldade) {
	nivel_maldade = maldade;
}