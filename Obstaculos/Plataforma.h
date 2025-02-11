#pragma once
#include "Obstaculo.h"

namespace Entidades {
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
			void obstacular(Personagens::Personagem* Jogador, int i = -1);
			void executar();
			virtual json salvar() const;
		};
	}
}