#pragma once
#include "Obstaculo.h"
#include "Slime.h"
#include "Slime2.h"

class Plataforma : public Obstaculo {
private:

	float x;
	float y;
  
public:
	Plataforma(int id, const char* png = "plataforma.png");
	~Plataforma();
	void setpJogador(Slime* jogador) { pJogador = jogador;	}
	void setpJogador2(Slime2* jogador2) { pJogador2 = jogador2; }
	Slime* getpJogador1() { return pJogador; }
	Slime2* getpJogador2() { return pJogador2; }

	void executar();
	void obstacular(Slime* jogador, Slime2* jogador2);
};