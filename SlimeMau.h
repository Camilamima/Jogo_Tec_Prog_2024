#pragma once
#include "Obstaculo.h"

class SlimeMau : public Obstaculo {
	float atrito;
	Slime* pJogador;
public:
	SlimeMau(int id, const char* png = "slimemau.png");
	~SlimeMau();
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
};