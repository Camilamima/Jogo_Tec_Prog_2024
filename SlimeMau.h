#pragma once
#include "Obstaculo.h"

class SlimeMau : public Obstaculo {
private:
	//futuramente ver se precisa de algo
public:
	SlimeMau(int id, const char* png = "slimemau.png");
	~SlimeMau();
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
};