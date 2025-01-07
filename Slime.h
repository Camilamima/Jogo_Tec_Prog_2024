#pragma once
#include "Personagem.h"

#include <algorithm>

#define VX 500

class Slime : public Personagem
{
private:
	int pontos;
	bool noChao;
	bool wPress;
	float impulso;
public:
	Slime(int id, const char* png = "pngegg.png");
	~Slime();
	void mover(float aux);
	void executar();
	void processaEvento();

};
