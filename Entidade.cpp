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

void Entidade::setCorpo(float largura, float altura) {
	corpo.setSize(Vector2f(largura, altura));
	corpo.setTexture(&sprite);
	corpo.setPosition(x, y);
}

void Entidade::setSoCorpo(float largura, float altura) {
	corpo.setSize(Vector2f(largura, altura));
}


const float Entidade::gravidade = 9.8f;