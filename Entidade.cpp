#include "Entidade.h"

Entidade::Entidade(int id,const char* png):
	Ente(id,png)
{
	x = -1;
	y = -1;
}

Entidade::~Entidade() {
}

void Entidade::setCoordenadas(int x1, int y1) {
	x = x1;
	y = y1;
}

void Entidade::setCorpo(float altura, float largura) {
	corpo.setSize(Vector2f(150.f, 150.f));
	corpo.setTexture(&sprite);
	corpo.setPosition(x, y);
}