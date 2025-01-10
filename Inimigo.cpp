#include "Inimigo.h"

Entidades::Personagens::Inimigo::Inimigo(int id, const char* png) :
	Personagem(id, png)
{
	nivel_maldade = -1;
}

Entidades::Personagens::Inimigo::~Inimigo() {

}

void Entidades::Personagens::Inimigo::mover(float aux) {
	
		corpo.move(aux*atualizaDelta(), 0);

}

void Entidades::Personagens::Inimigo::setMaldade(int maldade) {
	nivel_maldade = maldade;
}