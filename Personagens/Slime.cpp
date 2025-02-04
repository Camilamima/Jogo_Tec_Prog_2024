#include "Slime.h"
#include <iostream>


using namespace std;

namespace Personagens {
	Slime::Slime(int id, const char* png) :
		Personagem(id, png)
	{
		ladoAtacado = 0;
		atacado = 0;
		atacando = 0;
		setVelocidae(VX, 0);
		setCoordenadas(60, 0);
		pontos = 0;
		wPress = 0;
		aPress = 0;
		dPress = 1;
		relogio.restart();
		impulso = -1;

		setCorpo(50, 100);
		vidas = 25;
		val = 0;
		cont = 0;
		morrendo = false;

		//setCorpo(100, 100);
		//vidas = 200;
	}

	Slime::~Slime() {
	}

	void Slime::mover(float aux) {


		if (!noChao)
		{
			if (cont % 10 == 0) {
				val++;
				animacaoJog(3, 3);
			}

			velocidadeY += static_cast<float>(gravidade) * atualizaDelta();
			if ((corpo.getPosition().y + velocidadeY) >= chao) {
				velocidadeY = chao - corpo.getPosition().y;
			}
			if (!atacando && !atacado) {
				if (!wPress && velocidadeY < 0) {

					if (velocidadeY < 0) {
						velocidadeY = 0;
					}

					wPress = 1;

					mover(aux);
				}
			}

			corpo.move(aux, velocidadeY);
			if (corpo.getPosition().y >= chao) {
				noChao = 1;
				velocidadeY = 0;
				atacando = 0;
				atacado = 0;
			}
		}
		else {
			corpo.move(aux, 0);
		}


	}



	void Slime::pular(float imp) {
		impulso = imp;
		velocidadeY = -impulso * atualizaDelta();
		noChao = 0;
	}



	void Slime::processaEvento() {
		if (!morrendo) {
			bool clicado;
			clicado = false;

			if (val == 7) {
				val = 0;
			}

			if (atacado) {

				if (!ladoAtacado) {
					if (moviE == 1) {
						mover(atualizaDelta() * -300);
					}
					else {
						mover(0);
					}
				}

				else if (ladoAtacado) {

					if (moviD == 1) {
						mover(atualizaDelta() * +300);
					}
					else {
						mover(0);
					}
				}
			}

			else {

				if (Keyboard::isKeyPressed(Keyboard::D)) {
					if (moviD == 1) {
						dPress = 1;
						aPress = 0;
						if (cont % 10 == 0) {
							val++;
							animacaoJog(1, 7);
						}
						mover(atualizaDelta() * velocidadeX);
						clicado = 1;
					}
				}

				else if (Keyboard::isKeyPressed(Keyboard::A)) {
					if (moviE == 1) {
						aPress = 1;
						dPress = 0;
						if (cont % 10 == 0) {
							val++;
							animacaoJog(2, 7);
						}
						mover(atualizaDelta() * -velocidadeX);
						clicado = 1;
					}
				}

				if (Keyboard::isKeyPressed(sf::Keyboard::W)) {
					clicado = 1;
					if (noChao) {
						pular(600);
						wPress = 1;
					}
					mover(0);
				}
				else {
					wPress = 0;
					mover(0);


				}
			}

			if (clicado == 0) {
				mover(0);
				if (cont % 15 == 0) {
					val++;
					animacaoJog(0, 8);
				}
			}
		}
	}

	void Slime::processaEvento2() {
		
		if (!morrendo) {
			bool clicado;
			clicado = false;

			if (val == 7) {
				val = 0;
			}

			if (atacado) {

				if (!ladoAtacado) {
					if (moviE == 1) {
						mover(atualizaDelta() * -300);
					}
					else {
						mover(0);
					}
				}

				else if (ladoAtacado) {

					if (moviD == 1) {
						mover(atualizaDelta() * +300);
					}
					else {
						mover(0);
					}
				}
			}

			else {
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					if (moviD == 1) {
						dPress = 1;
						aPress = 0;
						if (cont % 10 == 0) {
							val++;
							animacaoJog(1, 7);
						}
						mover(atualizaDelta() * velocidadeX);
						clicado = 1;
					}
				}
				else if (Keyboard::isKeyPressed(Keyboard::Left)) {
					if (moviE == 1) {
						aPress = 1;
						dPress = 0;
						if (cont % 10 == 0) {
							val++;
							animacaoJog(2, 7);
						}
						mover(atualizaDelta() * -velocidadeX);
						clicado = 1;
					}
				}

				if (Keyboard::isKeyPressed(sf::Keyboard::Up)) {

					if (noChao) {
						clicado = 1;
						pular(600);
						wPress = 1;
					}
					mover(0);
				}
				else {
					wPress = 0;
					mover(0);

				}
			}

			if (clicado == 0) {
				mover(0);
				if (cont % 15 == 0) {
					val++;
					animacaoJog(0, 8);
				}
			}
		}
	}



	void Slime::executar() {

		cont++;

		if (corpo.getPosition().y >= chao && !atacado) {
			noChao = 1;
			velocidadeY = 0;
			atacando = 0;
		}


		if (getId() == 1) {
			processaEvento();
		}

		if (getId() == 2) {
			processaEvento2();
		}

		pGGrafico->desenha(corpo);

		if (cont == 2000) {
			cont = 0;
		}
	}



	void Slime::animacaoJog(int num, int limite) {
		if (val >= limite) {
			val = 0;
		}
		if (getId() == 1) {//se for o jogador 1
			if (num == 0) {//parado
				if (dPress) {
					sprite.loadFromFile("assets/Jogador1/parado.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/Jogador1/parado esq.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 1) {//andar direita
				sprite.loadFromFile("assets/jogador1/andar direita.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 2) {
				sprite.loadFromFile("assets/jogador1/andar esquerda.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 3) {//caindo
				if (dPress) {
					sprite.loadFromFile("assets/jogador1/caiu.png");
				}
				else if (aPress)
				{
					sprite.loadFromFile("assets/jogador1/caiu esq.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
		}

		if (getId() == 2) {
			if (num == 0) {//parado
				if (dPress) {
					sprite.loadFromFile("assets/Jogador2/parado.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/Jogador2/parado esq.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 1) {//andar direita
				sprite.loadFromFile("assets/jogador2/andar direita.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 2) {
				sprite.loadFromFile("assets/jogador2/andar esquerda.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
			else if (num == 3) {//caindo
				if (dPress) {
					sprite.loadFromFile("assets/jogador2/caiu.png");
				}
				else if (aPress)
				{
					sprite.loadFromFile("assets/jogador2/caiu esq.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
			}
		
		}
	}
	bool Slime::animacaoMorte(int cont, int limite) {
		bool fim = 0;

		if (cont >= limite) {
			return true;
		}

		if (getId() == 1) {//se for o jogador 1
			if (cont == 0) {
				setSoCorpo(62, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(0, 0, 62, 100));
			}
			else if (cont == 1) {
				setSoCorpo(96, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(125, 0, 96, 100));
			}
			else if (cont == 2) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(293, 0, 105, 100));
			}
			else if (cont == 3) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(461, 0, 105, 100));
			}
			else {
				setSoCorpo(108, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(626, 0, 108, 100));
				return false;
			}

			/*primeiro 62x100 - 0, 0
			segundo 96x100 - 125,0
			terceiro 105x100 - 293,0
			quarto 105x100 - 461,0
			quinto	108x100 -626,0*/
		}

		else if (getId() == 2) {//se for o jogador 2
			if (cont == 0) {
				setSoCorpo(62, 100);
				sprite.loadFromFile("assets/jogador2/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(0, 0, 62, 100));
			}
			else if (cont == 1) {
				setSoCorpo(96, 100);
				sprite.loadFromFile("assets/jogador2/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(125, 0, 96, 100));
			}
			else if (cont == 2) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador2/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(293, 0, 105, 100));
			}
			else if (cont == 3) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador2/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(461, 0, 105, 100));
			}
			else {
				setSoCorpo(108, 100);
				sprite.loadFromFile("assets/jogador2/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(626, 0, 108, 100));
				return false;
			}
		}


	}
}

