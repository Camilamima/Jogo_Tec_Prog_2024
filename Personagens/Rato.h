#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Rato : public Inimigo
	{
	private:
		int distancia_percorrida;

	public:
		Rato(int id, const char* png = "assets/lobo/direita.png");
		~Rato();
		void setDistancia(int d) { distancia_percorrida = d; }
		void calculaDis();
		void executar();
		void animacao(int num, int limite);//eh virtual
		json salvar() const;
	};
}

