#pragma once
#include "Entidade.h"
#include "Slime.h"
		
class Obstaculo : public Entidade
{	
protected:
	bool danoso;
	bool atrapalha;
	bool impede;
	bool acelera;

	float atrito;
	Slime* pJogador;

public:
	Obstaculo(int id, const char* png);
	~Obstaculo();
	virtual void executar() = 0;
	void obstacular(Slime* jogador, float atrito) {};
	void setpJogador(Slime* jogador) { pJogador = jogador; }
	bool  getImpede() const{ return impede; }
	bool getAtrapalha() const { return atrapalha; }
	bool getDanoso() const { return danoso; }
	bool getAcelera() const { return acelera; }
	virtual void obstacular(Slime* jogador) = 0;
	void restaura(Slime* jogador);
};