#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class SlimeMau : public Obstaculo {
	private:
		float atrasador;
	public:
		SlimeMau(int id, const char* png = "assets/slimemau.png");
		~SlimeMau();
		void executar();
		void obstacular(Personagens::Slime* jogador,int i=-1);
		virtual json salvar() const;
	};
}