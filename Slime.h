#pragma once
#include "Personagem.h"

#include <algorithm>

#define VX 500

class Slime : public Personagem
{
private:
	int pontos;
	bool wPress;
	bool atacado;
	bool atacando;
	bool ladoAtacado;
	float impulso;
public:
	Slime(int id, const char* png = "");//pngegg.png
	~Slime();
	void mover(float aux);
	void executar();
	void pular(float imp);
	void setAtacando(float a) { atacando = a; }
	void setAtacado(float x, float y) { atacado = x; ladoAtacado = y; }
	bool getAtacado() const { return atacado; }
	void processaEvento();
	void processaEvento2();
};
