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
	bool moviD;
	bool moviE;
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
	void setNoChao(float Xao) { noChao = Xao; }
	void setMoviD(bool a) { moviD = a; }
	void setMoviE(bool a) { moviE = a; }
	void setChao(float a) { chao = a; }
	void setAtacando(float a) { atacando = a; }
	void setAtacado(float x, float y) { atacado = x; ladoAtacado = y; };
	bool getAtacado() { return atacado; }
	void processaEvento();
};
