#pragma once
#include "Ente.h"
class Entidade : public Ente
{
protected:
	float x;
	float y;
	RectangleShape corpo;
	Clock relogio;
public:
	Entidade(int id,const char* png);
	virtual ~Entidade();
	void setTamanhoCorpo(float largura, float altura) {
		corpo.setSize(Vector2f(largura, altura));
	}
	void setCoordenadas(float x1,float y1);
	void setCorpo(float largura, float altura);
	void setSoCorpo(float largura, float altura);
	RectangleShape getCorpo() { return corpo; }
	virtual void executar() = 0;

};

