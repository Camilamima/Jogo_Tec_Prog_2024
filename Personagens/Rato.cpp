#include "Rato.h"
#include "iostream"


using namespace std;
#define CAMIHO 300
namespace Personagens {
	Rato::Rato(int id, const char* png) :
		Inimigo(id, png)
	{
		setVelocidae(150, 0);
		relogio.restart();
		setCorpo(100, 100);
		distancia_percorrida = 0;
		setMaldade(1);
		val = 0;
		cont = 0;
	}

	Rato::~Rato() {  }

	void Rato::calculaDis() {
		if (velocidadeX > 0) {
			distancia_percorrida += velocidadeX * atualizaDelta();
		}
		else {
			distancia_percorrida += -velocidadeX * atualizaDelta();
		}
	}

	void Rato::executar() {
		//cont++;
		if (verificaVida()) {
			if (distancia_percorrida >= CAMIHO) {

				velocidadeX = -velocidadeX;
				distancia_percorrida = 0;
			}
			calculaDis();
			if (!noChao) {
				mover(0);
			}
			if (velocidadeX > 0 && moviD) {
				mover(velocidadeX * atualizaDelta());
				if (cont % 5 == 0) {
					//animacao(2, 5);//0 eh direita 
					val--;
				}
			}
			else if (velocidadeX < 0 && moviE) {
				mover(velocidadeX * atualizaDelta());
				if (cont % 5 == 0) {
					//animacao(1, 5);//1 eh esquerda e 
					val++;
				}
			}

			pGGrafico->desenha(corpo);
		}

	}
	void Rato::animacao(int num, int limite) {
		if (val >= limite) {
			val = 0;
		}

		if (num == 1) {//vai p esquerda
			sprite.loadFromFile("assets/lobo/esquerda.png");
			corpo.setTexture(&sprite);
			corpo.setTextureRect(IntRect(100 * (val), 101, 100, 100));
		}
		else if (num == 2) {//vai p direita
			if (val == 0 || val == 1)
				val = limite;
			sprite.loadFromFile("assets/lobo/direita.png");
			corpo.setTexture(&sprite);
			corpo.setTextureRect(IntRect(100 * (val), 101, 100, 100));
		}

	}

	json Rato::salvar()const {
	
		json entidadeJson;
		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["velocidadeY"] = velocidadeY;
		entidadeJson["velocidadeX"] = velocidadeX;
		entidadeJson["noChao"] = noChao;
		entidadeJson["vidas"] = vidas;
		entidadeJson["distancia_percorrida"] = distancia_percorrida;
		return entidadeJson;
	};
}