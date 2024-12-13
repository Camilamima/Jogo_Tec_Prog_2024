#pragma once
#include "Obstaculo.h"
#include "Slime.h"

class Plataforma : public Obstaculo {
private:
	float atrito;
	bool atrapalha;
public:
	Plataforma(int id, const char* png = "plataformateste.png");
	~Plataforma();
	void executar();
	void obstacular(Slime* jogador);
	void restaura(Slime* jogador);
};