#pragma once
#include "Inimigo.h"
class Rato : public Inimigo
{
private:
	int distancia_percorrida;
public:
	Rato(int id, const char *png = "ratinho.png");
	~Rato();
	void calculaDis();
	void executar();

};

