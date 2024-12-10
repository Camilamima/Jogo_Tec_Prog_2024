#pragma once
#include "Personagem.h"
#include <ctime>
#include <algorithm>
class Jogador : public Personagem
{
private:
	int pontos;
	bool noChao;
	bool wPress;
	float impulso;
	Clock relogio;
public:
	Jogador(int id, int vids, float vlX=500, float vlY=0, const char* png="pngegg.png");
	~Jogador();
	void mover(float aux);
	void executar() override;
	void processaEvento();
	float atualizaDelta();

};

