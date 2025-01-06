#pragma once
#include "Obstaculo.h"
#include "Slime.h"

class Plataforma : public Obstaculo {
private:
	int x;
	int y;
public:
	Plataforma(int id, const char* png = "plataforma.png");
	~Plataforma();
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
	void obstacular(Slime* jogador);
};