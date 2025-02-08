#include "Slime.h"
#include <iostream>
#include "Inimigo.h"


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

		//setCorpo(62, 100);
		vidas = 25;
		setCorpo(50, 100);
		val = 0;
		cont = 0;
		morrendo = false;
		
		if (id == 1) {
			setCorpo(87.35f, 100.0f);
			sprite.loadFromFile("assets/jog1/Jump.png");
			corpo.setTexture(&sprite);
			corpo.setTextureRect(IntRect(868, 0, 56, 64));
		}
		else if (id == 2) {
			setCorpo(88.5, 100.0);
			sprite.loadFromFile("assets/jog2/Jump.png");
			corpo.setTexture(&sprite);
			corpo.setTextureRect(IntRect(21, 0, 54, 71));

		}
			
		
		//setCorpo(100, 100);
		//vidas = 200;
		vidas =	100;
	}

	Slime::~Slime() {
	}

	void Slime::mover(float aux) {


		if (!noChao)
		{
				animacao(3, 3);


			velocidadeY += static_cast<float>(gravidade) * atualizaDelta(relogio);
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
		velocidadeY = -impulso * atualizaDelta(relogio);
		noChao = 0;
	}



	void Slime::processaEvento() {
		if (getId() == 1) {
			if (!morrendo) {
				bool clicado;
				clicado = false;

				if (val == 7) {
					val = 0;
				}

				if (atacado) {

					if (!ladoAtacado) {
						if (moviE == 1) {
							mover(atualizaDelta(relogio) * -300);
						}
						else {
							mover(0);
						}
					}

					else if (ladoAtacado) {

						if (moviD == 1) {
							mover(atualizaDelta(relogio) * +300);
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
							if (cont % 5 == 0) {
								val++;
								animacao(1, 7);
							}
							mover(atualizaDelta(relogio) * velocidadeX);
							clicado = 1;
						}
					}

					else if (Keyboard::isKeyPressed(Keyboard::A)) {
						if (moviE == 1) {
							aPress = 1;
							dPress = 0;
							if (cont % 5 == 0) {
								val--;
								animacao(2, 7);//antes era 7
							}
							mover(atualizaDelta(relogio) * -velocidadeX);
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
					if (cont % 10 == 0) {
						val++;
						animacao(0, 9);//era 8

					}
				}
			}
		}
		if (getId() == 2) {
			if (!morrendo) {
				bool clicado;
				clicado = false;

				if (val == 7) {
					val = 0;
				}

				if (atacado) {

					if (!ladoAtacado) {
						if (moviE == 1) {
							mover(atualizaDelta(relogio) * -300);
						}
						else {
							mover(0);
						}
					}

					else if (ladoAtacado) {

						if (moviD == 1) {
							mover(atualizaDelta(relogio) * +300);
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
							if (cont % 5 == 0) {
								val++;
								animacao(1, 6);
							}
							mover(atualizaDelta(relogio) * velocidadeX);
							clicado = 1;
						}
					}
					else if (Keyboard::isKeyPressed(Keyboard::Left)) {
						if (moviE == 1) {
							aPress = 1;
							dPress = 0;
							if (cont % 5 == 0) {
								val--;
								animacao(2, 6);
							}
							mover(atualizaDelta(relogio) * -velocidadeX);
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
					if (cont % 10 == 0) {
						val++;
						if (getId() == 1) {
							animacao(0, 9);//era 8
						}
						else {
							animacao(0, 7);
						}

					}
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

		processaEvento();

		pGGrafico->desenha(corpo);

		if (cont == 2000) {
			cont = 0;
		}
	}



	void Slime::animacao(int num, int limite) {
		if (val >= limite) {
			val = 0;
		}
		if (val == -1) {
			val = limite-1;
		}
		
		if (getId() == 1) {//se for o jogador 1

			if (num == 0) {//parado
				if (dPress) {
					//sprite.loadFromFile("assets/Jogador1/parado.png");
					sprite.loadFromFile("assets/jog1/Idle.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/jog1/Idle esquerda.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(36 + (128 * val), 0, 56, 64));//50*val,0,50,100
				//setSoCorpo(74.87, 100);
			}
			else if (num == 1) {//andar direita
				//sprite.loadFromFile("assets/jogador1/andar direita.png");
				sprite.loadFromFile("assets/jog1/Run.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(36+(128 * val), 0, 56, 64));
				//setSoCorpo(74.87, 100);
			}
			else if (num == 2) {
				sprite.loadFromFile("assets/jog1/Run esquerda.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(36 + (128 * val), 0, 56, 64));
				//setSoCorpo(74.87, 100);
			}
			else if (num == 3) {//caindo
				if (dPress) {
					sprite.loadFromFile("assets/jog1/Jump.png");
					
					//sprite.loadFromFile("assets/jogador1/caiu.png");
					corpo.setTexture(&sprite);
					corpo.setTextureRect(IntRect(868, 0, 56, 64));
				}
				else if (aPress)
				{
					sprite.loadFromFile("assets/jog1/Jump esquerda.png");
					//sprite.loadFromFile("assets/jogador1/caiu esq.png");
					corpo.setTexture(&sprite);
					corpo.setTextureRect(IntRect(292, 0, 56, 64));
				}
				//corpo.setTexture(&sprite);
				//corpo.setTextureRect(IntRect(50 * val, 0, 50, 100));
				
				//setSoCorpo(87.35, 100.0);
			}
			else if (num == 4) {//sendo atacado
				if (dPress) {
					sprite.loadFromFile("assets/jog1/Hurt.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/jog1/Hurt esquerda.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(36, 0, 56, 64));
			}
		}

		if (getId() == 2) {
			if (num == 0) {//parado
				if (dPress) {
					//sprite.loadFromFile("assets/Jogador1/parado.png");
					sprite.loadFromFile("assets/jog2/Idle.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/jog2/Idle esquerda.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(21+(96 * val), 0, 54, 71));//50*val,0,50,100
				//setSoCorpo(53.49, 100.0);
			}
			else if (num == 1) {//andar direita
				//sprite.loadFromFile("assets/jogador1/andar direita.png");
				sprite.loadFromFile("assets/jog2/Run.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(21+(96 * val), 0, 54, 71));
				//setSoCorpo(149.29, 100.0);
			}
			else if (num == 2) {
				sprite.loadFromFile("assets/jog2/Run esquerda.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(21 + (96 * val), 0, 54, 71));
				//setSoCorpo(149.29, 100.0);
			}
			else if (num == 3) {//caindo
				if (dPress) {
					sprite.loadFromFile("assets/jog2/Jump.png");

					//sprite.loadFromFile("assets/jogador1/caiu.png");
					corpo.setTexture(&sprite);
					corpo.setTextureRect(IntRect(21, 0, 54, 71));
				}
				else if (aPress)
				{
					sprite.loadFromFile("assets/jog2/Jump esquerda.png");
					//sprite.loadFromFile("assets/jogador1/caiu esq.png");
					corpo.setTexture(&sprite);
					corpo.setTextureRect(IntRect(21, 0, 54, 71));
				}
			}
			else if (num == 4) {//sendo atacado
				if (dPress) {
					sprite.loadFromFile("assets/jog2/Hurt.png");
				}
				else if (aPress) {
					sprite.loadFromFile("assets/jog2/Hurt esquerda.png");
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(21, 0, 54, 71));
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
				return true;
			}
			else if (cont == 1) {
				setSoCorpo(96, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(125, 0, 96, 100));
				return true;
			}
			else if (cont == 2) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(293, 0, 105, 100));
				return true;
			}
			else if (cont == 3) {
				setSoCorpo(105, 100);
				sprite.loadFromFile("assets/jogador1/morte.png");
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(461, 0, 105, 100));
				return true;
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

	void Slime::atacarIni(Personagem* ini) {
		setAtacando(1);
		pular(300);
		--(*ini);
	}

	json Slime::salvar() const {
		json entidadeJson;
		entidadeJson["id"] = id;
		entidadeJson["x"] = corpo.getPosition().x;
		entidadeJson["y"] = corpo.getPosition().y;
		entidadeJson["velocidadeY"] = velocidadeY;
		entidadeJson["velocidadeX"] = velocidadeX;
		entidadeJson["noChao"] = noChao;
		entidadeJson["chao"] = chao;
		entidadeJson["atacando"] = atacando;
		entidadeJson["atacado"] = atacado;
		entidadeJson["ladoAtacado"] = ladoAtacado;
		entidadeJson["vidas"] = vidas;
		entidadeJson["cont"] = cont;
		entidadeJson["val"] = val;
		entidadeJson["morrendo"] = morrendo;
		entidadeJson["impulso"] = impulso;


		return entidadeJson;
	}
}

