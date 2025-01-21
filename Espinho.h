#pragma once

#include "Obstaculo.h"

class Espinho : public Obstaculo {
private:
	int num_espinhos;
	int timer;
public:
	Espinho(int id, const char* png = "espinho.png");
	~Espinho();
	Slime* getpJogador() { return pJogador; }
	void executar();
	void obstacular(Slime* jogador);
};
