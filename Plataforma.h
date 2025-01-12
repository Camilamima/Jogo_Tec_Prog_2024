#pragma once
#include "Obstaculo.h"
#include "Slime.h"

class Plataforma : public Obstaculo {
private:

	float altura;
	float largura;
	float x;
	float y;
  
public:
	Plataforma(int id, const char* png = "");//plataforma.png
	~Plataforma();
	void geraPlataforma(float alt, float lar,float x, float y);
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	Slime* getpJogador() { return pJogador; }
	void executar();
	void obstacular(Slime* jogador);
};