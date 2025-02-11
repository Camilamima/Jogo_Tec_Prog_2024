#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Rio : public Obstaculo {
	private:
		float atrasador;
	public:
		Rio(int id, const char* png = "assets/slimemau.png");
		~Rio();
		void executar();
		void obstacular(Personagens::Personagem* jogador,int i=-1);
		virtual json salvar() const;
	};
}