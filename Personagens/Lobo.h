#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		class Lobo : public Inimigo
		{
		private:
			static int caminho;
			int distancia_percorrida;

		public:
			Lobo(int id, const char* png = "assets/lobo/direita.png");
			~Lobo();
			void setDistancia(int d) { distancia_percorrida = d; }
			void calculaDis();
			void executar();
			void animacao(int num, int limite);//eh virtual
			const int setaCabecada(const int lado);
			void ataca(Heroi* jog, int lado) override;
			json salvar() const;
		};
	}
}

