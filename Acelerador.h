#pragma once
#include "Obstaculo.h"

class Acelerador : public Obstaculo
{
private: 
	float booster;
	int timer;
public:
	Acelerador(int id, const char* png = "Boost.png");
	~Acelerador();
	void executar();
	void obstacular(Slime* jogador);
	float getBooster()const { return booster; }
	int getTimer()const { return timer; }
	void setBooster(float boost) { booster = boost; }

};