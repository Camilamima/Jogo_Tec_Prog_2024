#include "Plataforma.h"  
using namespace Personagens;

namespace Obstaculos {
	Plataforma::Plataforma(int id, const char* png) :
		Obstaculo(id, png), x(0), y(860)
	{
		altura = 0;
		largura = 0;
		pJogador = nullptr;
		atrito = 1.0f;
		impede = true;
		setCoordenadas(x, y);
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
	}

	json Plataforma::salvar() const {
		json entidadeJson;

		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["altura"] = altura;
		entidadeJson["largura"] = largura;
		entidadeJson["danoso"] = danoso;
		entidadeJson["impede"] = impede;
		entidadeJson["acelera"] = acelera;
		entidadeJson["atrito"] = atrito;

		return entidadeJson;
	}
}


