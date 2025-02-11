#pragma once
#include "Obstaculo.h"


namespace Entidades{
	namespace Obstaculos {
		class Espinho : public Obstaculo {
		private:
			int num_espinhos;
			int timer;
		public:
			Espinho(int id, const char* png ="assets/espinho2.png");
			~Espinho();
			void executar();
			int getEspinhos() const {
				return num_espinhos;
			}
			void setEspinhos(int e) {
				num_espinhos = e;
			}
			void obstacular(Entidades::Personagens::Personagem* jogador,int i=-1);
			json salvar() const;
		};
	}
}
