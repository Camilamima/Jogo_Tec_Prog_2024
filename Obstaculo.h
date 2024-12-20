#pragma once
#include "Entidade.h"
#include "Slime.h"
		
class Obstaculo : public Entidade
{	
protected:
	bool danoso;
	bool atrapalha;
	float atrito;
	Slime* pJogador;

public:
	Obstaculo(int id, const char* png);
	~Obstaculo();
	virtual void executar() = 0;
	void obstacular(Slime* jogador, float atrito);

};
	
