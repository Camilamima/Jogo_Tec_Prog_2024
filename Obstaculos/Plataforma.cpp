#include "Plataforma.h"  
using namespace Personagens;

namespace Obstaculos {
	Plataforma::Plataforma(int id, const char* png) :
		Obstaculo(id, png), x(0), y(860)
	{
		altura = 0;
		largura = 0;
		atrito = 1.0f;
		impede = true;
		//setCoordenadas(x, y);
	}
	Plataforma::~Plataforma() {
	}
	void Plataforma::geraPlataforma(float alt, float lar, float x, float y) {
		altura = alt;
		largura = lar;
		setCoordenadas(x, y);
		setCorpo(largura, altura);
	}
	void Plataforma::executar() {
		pGGrafico->desenha(corpo);
		if (!noChao) {
			mover();
		}
	}

	json Plataforma::salvar() const {
		json entidadeJson;

		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["altura"] = altura;
		entidadeJson["largura"] = largura;
		entidadeJson["png"] = png;

		return entidadeJson;
	}

	void Plataforma::obstacular(Personagem* jogador,int i) {
		if (i == 1) {
			jogador->setChao(corpo.getPosition().y - 100);
		}

		if (i == 2) {
			jogador->setMoviD(0);
		}
		if (i == 3) {

			jogador->setMoviE(0);
		}
		if (i == 4) {
			jogador->setVelocidadeY(0);
			if (jogador->getId() == 1 || jogador->getId() == 2) {
				Heroi* Heroi = static_cast<Personagens::Heroi*>(jogador);
				Heroi->pular(-100);
			}
		}
	}
}


