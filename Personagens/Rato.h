#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Rato : public Inimigo
	{
	private:
		int distancia_percorrida;
		int val;
		int cont;

	public:
		Rato(int id, const char* png = "ratinho.png");
		~Rato();
		void calculaDis();
		void executar();
		void animacao(int num, int limite);

	};
}

