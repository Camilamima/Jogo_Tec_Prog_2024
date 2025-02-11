
#include "Fase.h"

namespace Fases {
	class Floresta_Profunda : public Fase
	{
	private:
		int num_dificil;
		int obsFacil;

	public:
		Floresta_Profunda();
		const int getPontos(const int i) {
			if (i == 1) {
				return Heroi1.getPontos();

			}
			else {
				return Heroi2.getPontos();
			}
		}//
		Floresta_Profunda(const json& dados);
		~Floresta_Profunda();
		void inicializa();//
		void geraChao();//
		void geraInimigos();//
	};
}

