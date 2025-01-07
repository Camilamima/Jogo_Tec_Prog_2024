#include "Inimigo.h"

Inimigo::Inimigo(int id, const char* png) :
	Personagem(id, png)
{
	nivel_maldade = -1;
}

Inimigo::~Inimigo() {

}

void Inimigo::mover(float aux) {
	
		corpo.move(aux*atualizaDelta(), 0);

}

void Inimigo::setMaldade(int maldade) {
	nivel_maldade = maldade;
}