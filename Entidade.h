#pragma once
#include "Ente.h"
class Entidade : public Ente
{
protected:
	int x;
	int y;
	RectangleShape corpo;
public:
	Entidade(int id,const char* png);
	virtual ~Entidade();
	void setCoordenadas(int x1,int y1);
	void setCorpo(float altura, float largura);
	virtual void executar() = 0;
};

