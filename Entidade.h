#pragma once
#include "Ente.h"
class Entidade : public Ente
{
protected:
	float x;
	float y;
	RectangleShape corpo;
public:
	Entidade(int id,const char* png);
	virtual ~Entidade();
	void setCoordenadas(float x1,float y1);
	void setCorpo(float altura, float largura);
	RectangleShape getCorpo() { return corpo; }
	virtual void executar() = 0;
};

