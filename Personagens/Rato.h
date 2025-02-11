#pragma once
#include "Inimigo.h"


namespace Personagens {
	class Rato : public Inimigo
	{
	private:
		static int caminho;
		int distancia_percorrida;

	public:
		Rato(int id, const char* png = "assets/lobo/direita.png");
		~Rato();
		void setDistancia(int d) { distancia_percorrida = d; }
		void calculaDis();
		void executar();
		void animacao(int num, int limite);//eh virtual
		const int setaCabecada(const int lado);
		void ataca(Slime* jog, int lado) override;
		json salvar() const;
	};
}

