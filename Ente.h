#pragma once
#include "Gerenciadores\Gerenciado_Grafico.h"
class Ente
{
protected:
	int id;
	Gerenciadores::Gerenciado_Grafico* pGGrafico;
	Texture sprite;
public:
	Ente(int x, const char* png);
	virtual ~Ente();
	void setGerenciador(Gerenciadores::Gerenciado_Grafico* g);
	void setId(int ide) { id = ide; }
	int getId() { return id; }
	virtual void executar() = 0;
};



