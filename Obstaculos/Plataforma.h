#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class Plataforma : public Obstaculo {
	private:
		float altura;
		float largura;
		float x;
		float y;

	public:
		Plataforma(int id, const char* png = "");//plataforma.png
		~Plataforma();
		void geraPlataforma(float alt, float lar, float x, float y);
		Personagens::Slime* getpJogador() { return pJogador; }
		void obstacular(Personagens::Slime* Jogador) {}
		void executar();
		virtual json salvar() const;
	};
}