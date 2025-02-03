#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Acelerador : public Obstaculo
	{
	private:
		float booster;
		int timer;
	public:
		Acelerador(int id, const char* png = "assets/Boost.png");
		~Acelerador();
		void executar();
		void obstacular(Personagens::Slime* jogador);
		float getBooster()const { return booster; }
		int getTimer()const { return timer; }
		void setBooster(float boost) { booster = boost; }

	};
}