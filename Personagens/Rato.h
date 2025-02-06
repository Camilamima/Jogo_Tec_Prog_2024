#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Rato : public Inimigo
	{
	private:
		int distancia_percorrida;
	public:
		Rato(int id, const char* png = "ratinho.png");
		~Rato();
		void setDistancia(int d) { distancia_percorrida = d; }
		void calculaDis();
		void executar();
		json salvar() const;

	};
}

