#pragma once
#include "Personagem.h"
#include <ctime>
#include <algorithm>
class Slime : public Personagem
{
private:
	int pontos;
	bool noChao;
	bool wPress;
	float impulso;
	Clock relogio;
public:
	Slime(int id, const char* png = "pngegg.png");
	~Slime();
	void mover(float aux);
	void executar();
	void processaEvento();
	float atualizaDelta();

};
