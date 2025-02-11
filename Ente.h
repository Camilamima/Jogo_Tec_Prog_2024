#pragma once
#include "Gerenciadores\Gerenciado_Grafico.h"
class Ente
{
protected:
	int id;
	static Gerenciadores::Gerenciado_Grafico* pGGrafico;
	Texture sprite;
	const char* png;
public:
	Ente(int x, const char* png);
	Ente();
	virtual ~Ente();
	static void setGerenciador(Gerenciadores::Gerenciado_Grafico* g);
	void setId(int ide) { id = ide; }
	int getId() const {	return id; }
	virtual void executar() = 0;
};



