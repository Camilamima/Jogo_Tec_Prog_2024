#include "Rato.h"
#include <stdexcept>
#include <iostream>


using namespace std;
#define CAMIHO 300
namespace Personagens {
	Rato::Rato(int id, const char* png) :
		Inimigo(id, png)
	{
		vidas = 3;
		setVelocidae(150, 0);
		relogio.restart();
		setCorpo(100, 65);
		distancia_percorrida = 0;
		setMaldade(1);
	}

	Rato::~Rato() {  }

	void Rato::calculaDis() {
		if (velocidadeX > 0) {
			distancia_percorrida += velocidadeX * atualizaDelta(relogio);
		}
		else {
			distancia_percorrida += -velocidadeX * atualizaDelta(relogio);
		}
	}

	void Rato::executar() {
		cont++;
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
	void Rato::animacao(int num, int limite) {
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