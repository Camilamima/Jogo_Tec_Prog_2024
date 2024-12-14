#pragma once

#include "Obstaculo.h"

class Espinho : public Obstaculo {
private:
	float atrito;
	Slime* pJogador;
public:
	Espinho(int id, const char* png = "espinho.png");
	~Espinho();
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
};
