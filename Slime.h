#pragma once
#include "Personagem.h"

#include <algorithm>

#define VX 500

class Slime : public Personagem
{
private:
	int pontos;
	float chao;
	bool noChao;
	bool moviX;
	bool moviY;
	bool wPress;
	float impulso;
public:
	Slime(int id, const char* png = "");//pngegg.png
	~Slime();
	void mover(float aux);
	void executar();
	void setNoChao(bool Xao) { noChao = Xao; }
	void setMoviX(bool a) { moviX = a; }
	void setMoviY(bool a) { moviY = a; }
	void setChao(float a) { chao = a; }
	void processaEvento();
};
