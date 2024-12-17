#pragma once

#include "Obstaculo.h"

class Espinho : public Obstaculo {
private:
	//futuramente ver se precisa de algo
public:
	Espinho(int id, const char* png = "espinho.png");
	~Espinho();
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
};
