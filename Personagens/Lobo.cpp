#include "Lobo.h"
#include <stdexcept>
#include <iostream>
#include "../Personagens/Heroi.h"


using namespace std;
namespace Entidades {
	namespace Personagens {
		Lobo::Lobo(int id, const char* png) :
			Inimigo(id, png)
		{
			vidas = 3;
			setVelocidae(150, 0);
			relogio.restart();
			setCorpo(100, 65);
			distancia_percorrida = 0;
			setMaldade(1);
		}

		Lobo::~Lobo() {  }

		void Lobo::calculaDis() {
			if (velocidadeX > 0) {
				distancia_percorrida += velocidadeX * atualizaDelta(relogio);
			}
			else {
				distancia_percorrida += -velocidadeX * atualizaDelta(relogio);
			}
		}

		const int Lobo::setaCabecada(const int lado) {
			if (lado == 2 && velocidadeX <= 0) {
				return 500;
			}
			else if (lado == 3 && velocidadeX >= 0) {
				return 500;
			}
			else {
				return 300;
			}

		}

		void Lobo::danificar(Heroi* jog, int lado) {
			if (lado == 2) {
				if (!jog->getAtacado()) {
					jog->operator-=(nivel_maldade * 5);
					if (setaCabecada(lado) > 300) {

						jog->setAtordoado(1);
					}
					jog->pular(setaCabecada(lado));
					jog->setAtacado(1, 0);
				}
			}
			else if (lado == 3) {
				if (!jog->getAtacado()) {
					jog->operator-=(nivel_maldade * 5);
					if (setaCabecada(lado) > 300) {

						jog->setAtordoado(1);
					}
					jog->pular(setaCabecada(lado));
					jog->setAtacado(1, 1);
				}
			}
		}

		void Lobo::executar() {
			cont++;
			if (verificaVida()) {
				if (distancia_percorrida >= caminho) {

					velocidadeX = -velocidadeX;
					distancia_percorrida = 0;
				}
				calculaDis();
				if (!noChao) {
					mover(0);
				}
				if (velocidadeX > 0 && moviD) {
					mover(velocidadeX * atualizaDelta(relogio));
					if (cont % 4 == 0) {
						animacao(2, 5);//0 eh direita 
						val--;
					}
				}
				else if (velocidadeX < 0 && moviE) {
					mover(velocidadeX * atualizaDelta(relogio));
					if (cont % 4 == 0) {
						animacao(1, 5);//1 eh esquerda e 
						val++;
					}
				}

				pGGrafico->desenha(corpo);
			}

		}
		void Lobo::animacao(int num, int limite) {
			if (val >= limite) {
				val = 0;
			}

			if (num == 1) {//vai p esquerda
				try {
					if (!sprite.loadFromFile("assets/lobo/esquerda1.png")) {  // Se o arquivo não for encontrado
						throw std::runtime_error("Erro ao carregar a textura: assets/lobo/esquerda1.png");
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Excecao capturada: " << e.what() << std::endl;
				}

				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(100 * (val), 35, 100, 65));
			}
			else if (num == 2) {//vai p direita
				if (val == 0 || val == 1)
					val = limite;
				try {
					if (!sprite.loadFromFile("assets/lobo/direita1.png")) {  // Se o arquivo não for encontrado
						throw std::runtime_error("Erro ao carregar a textura: assets/lobo/direita1.png");
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Excecao capturada: " << e.what() << std::endl;
				}

				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(100 * (val), 35, 100, 65));
			}
		}

		json Lobo::salvar()const {

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

		int Lobo::caminho = 300;
	}
}