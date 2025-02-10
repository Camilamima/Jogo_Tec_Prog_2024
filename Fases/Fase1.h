
#include "Fase.h"

namespace Fases {
	class Fase1 : public Fase
	{
	private:
		int num_dificil;
		int obsFacil;

	public:
		Fase1();
		const int getPontos(const int i) {
			if (i == 1) {
				return Slime1.getPontos();

			}
			else {
				return Slime2.getPontos();
			}
		}
		Fase1(const json& dados, Gerenciadores::Gerenciado_Grafico* gC);
		~Fase1();
		void inicializa();
		void geraChao();
		void geraInimigos();
	};
}

