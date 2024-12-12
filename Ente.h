#pragma once
#include "Gerenciado_Grafico.h"
class Ente
{
protected:
	int id;
	Gerenciado_Grafico* pGGrafico;
	Texture sprite;
public:
	Ente(int x, const char* png);
	virtual ~Ente();
	virtual void executar() = 0;
	void setGerenciador(Gerenciado_Grafico* g);
};



