#pragma once
#include "Gerenciado_Grafico.h"
class Ente
{
private:
	//ser colocado depois, quando for criado lista
	//int id
	//statics int cont++;
	Gerenciado_Grafico* gGrafico;
	Textura sprite;
public:
	Ente();
	~Ente();
	virtual void executar() = 0;
	void setGerenciador(Gerenciado_Grafico* g);
	void setTextura(Texture textura);
	void getTextura();
	void desenhaFigura();

};

