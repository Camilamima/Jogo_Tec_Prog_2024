#include "Entidade.h"

Entidade::Entidade(int id,const char* png):
	Ente(id,png)
{
	x = 60;
	y = 60;
}

Entidade::~Entidade() {
}

void Entidade::setCoordenadas(float x1, float y1) {
	x = x1;
	y = y1;
}

void Entidade::setCorpo(float altura, float largura) {
	corpo.setSize(Vector2f(altura, largura));
	corpo.setTexture(&sprite);
	corpo.setPosition(x, y);
}