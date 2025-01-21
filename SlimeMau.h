#pragma once
#include "Obstaculo.h"

class SlimeMau : public Obstaculo {
private:
	float atrasador;
public:
	SlimeMau(int id, const char* png = "slimemau.png");
	~SlimeMau();
	Slime* getpJogador() { return pJogador; }
	void executar();
	void obstacular(Slime* jogador);
};