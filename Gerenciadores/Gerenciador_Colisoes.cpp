#include "Gerenciador_Colisoes.h"
#include "../Personagens/Cachorro.h"
#include "../Personagens/Chefao.h"
#include <list>
#include <iostream>


namespace Gerenciadores {
	Gerenciador_Colisoes::Gerenciador_Colisoes() :
		jog1(nullptr), jog2(nullptr) {
	}

	Gerenciador_Colisoes::~Gerenciador_Colisoes() {

	}


	void Gerenciador_Colisoes::trocaFase() {
		LObst.clear();
		LIni.clear();
		LProjetil.clear();
	}

	void Gerenciador_Colisoes::setJogadores(Personagens::Slime* j1, Personagens::Slime* j2) {
		jog1 = j1;
		jog2 = j2;
	}

	void Gerenciador_Colisoes::includeEntidade(Entidade* ent) {

		if (ent->getId() == 3 || ent->getId() == 9 || ent->getId() == 8 || ent->getId() == 11) {//obstaculo
			LObst.push_back(static_cast<Obstaculos::Obstaculo*>(ent));
			static_cast<Obstaculos::Obstaculo*>(ent)->setpJogador(jog1);

		}

		if (ent->getId() == 12) {
			LObst.push_back(static_cast<Obstaculos::Obstaculo*>(ent));
			static_cast<Obstaculos::Obstaculo*>(ent)->setpJogador(jog1);
		}

		else if (ent->getId() == 4 || ent->getId() == 6 || ent->getId() == 7) {//inimigo
			LIni.push_back(static_cast<Personagens::Inimigo*>(ent));
		}

		else if (ent->getId() == 1) {//jogador 1
			jog1 = static_cast<Personagens::Slime*>(ent);
		}
		else if (ent->getId() == 2) {//jogador 2
			jog2 = static_cast<Personagens::Slime*>(ent);
		}
		else if (ent->getId() == 5) {//projetil
			LProjetil.push_back(static_cast<Projetil*>(ent));
		}
		
	}

	int Gerenciador_Colisoes::veriColisao(Entidade* ent, Entidade* sl) {

		RectangleShape jogador;
		RectangleShape outro;
		jogador = sl->getCorpo();
		outro = ent->getCorpo();

		float x, y, x2, y2, xx, yy, xx2, yy2;

		x = jogador.getPosition().x;
		y = jogador.getPosition().y;
		x2 = x + jogador.getSize().x;
		y2 = y + jogador.getSize().y;

		xx = outro.getPosition().x;
		yy = outro.getPosition().y;
		xx2 = xx + outro.getSize().x;
		yy2 = yy + outro.getSize().y;

		//horizontal
		if ((x >= outro.getPosition().x && x <= (outro.getPosition().x + outro.getSize().x)) ||
			(x2 >= outro.getPosition().x && x2 <= (outro.getPosition().x + outro.getSize().x)))
		{
			//chão
			if (y2 >= yy - 15 && y2 <= yy + 15) {//teste antes 15
				return 1;
			}
			//teto
			if (y >= yy2 - 15 && y <= yy2 + 15) {
				return 4;
			}


		}

		//lados
		if ((y >= outro.getPosition().y && y <= (outro.getPosition().y + outro.getSize().y)) ||
			//esquerda
			(y2 >= outro.getPosition().y && y2 <= (outro.getPosition().y + outro.getSize().y))) {
			if (x2 >= xx + 5 && x2 <= xx + 15) {

				return 2;

			}
			//direita
			else if (x >= xx2 - 10 && x <= xx2) {
				return 3;
			}
		}

		if ((x >= outro.getPosition().x && x <= (outro.getPosition().x + outro.getSize().x)) ||
			(x2 >= outro.getPosition().x && x2 <= (outro.getPosition().x + outro.getSize().x)))//especifico p slime mau e espinho
		{
			if ((y >= outro.getPosition().y && y <= (outro.getPosition().y + outro.getSize().y)) ||
				(y2 >= outro.getPosition().y && y2 <= (outro.getPosition().y + outro.getSize().y))) {
				return 5;
			}
		}


		return 0;


	}


	void Gerenciador_Colisoes::verificaIni() {

		RectangleShape aux1, aux2, aux3;

		if (jog1 != nullptr) {
			aux2 = jog1->getCorpo();
			for (Personagens::Inimigo* inimigo : LIni) {

				aux1 = inimigo->getCorpo();

				if (!inimigo->verificaVida()) {
					continue;
				}

				if (inimigo->getMaldade() == 2) {

					Personagens::Cachorro* cachorro = static_cast<Personagens::Cachorro*>(inimigo);

					cachorro->deveSeguir(jog1);
				}

				if (veriColisao(inimigo, jog1) == 1) {
					jog1->atacarIni(inimigo);
					cout << "Vida inimigo atacado" << inimigo->getVidas() << endl;
				}

				else if (veriColisao(inimigo, jog1) == 2) {

					inimigo->ataca(jog1, 2);
					cout << "vidas jog1: " << jog1->getVidas() << endl;
				}
				else if (veriColisao(inimigo, jog1) == 3) {

					inimigo->ataca(jog1, 3);
					cout << "vidas jog1: " << jog1->getVidas() << endl;

				}
				else if (veriColisao(inimigo, jog1) == 5) {

						float xini = aux1.getPosition().x+aux1.getSize().x/2;

						float xjog = aux2.getPosition().x + aux2.getSize().x / 2;

						if (xini >= xjog) {
							inimigo->ataca(jog1, 2);
						}
						else {
							inimigo->ataca(jog1, 3);
						}


				}
			}
		}

		if (jog2 != nullptr) {
			aux2 = jog2->getCorpo();
			for (Personagens::Inimigo* inimigo : LIni) {

				aux1 = inimigo->getCorpo();

				if (!inimigo->verificaVida()) {
					continue;
				}

				if (inimigo->getMaldade() == 2) {

					Personagens::Cachorro* cachorro = static_cast<Personagens::Cachorro*>(inimigo);

					cachorro->deveSeguir(jog2);
				}

				if (veriColisao(inimigo, jog2) == 1) {
					jog1->atacarIni(inimigo);
				}

				else if (veriColisao(inimigo, jog2) == 2) {

					inimigo->ataca(jog2, 2);
				}
				else if (veriColisao(inimigo, jog2) == 3) {

					inimigo->ataca(jog2, 3);
				}
				else if (veriColisao(inimigo, jog2) == 5) {

					float xini = aux1.getPosition().x + aux1.getSize().x / 2;

					float xjog = aux2.getPosition().x + aux2.getSize().x / 2;

					if (xini >= xjog) {
						inimigo->ataca(jog2, 2);
					}
					else {
						inimigo->ataca(jog2, 3);
					}


				}
			}
		}

	}

	void Gerenciador_Colisoes::veriProjetil() {
		RectangleShape aux_jog1, aux_jog2, aux_proj;
		
		if (jog1 != nullptr) {

			aux_jog1 = jog1->getCorpo();

			for (Projetil* projetil : LProjetil) {

				aux_proj = projetil->getCorpo();

				if (projetil->getNoChao() == true) {
					continue;
				}

				if(projetil->getApareceu()==true){
					
					if (projetil->segueQuem(jog1)==true) {//se segue o jogador 1
						projetil->setSeguindo(true);
						projetil->setSeguiu(true);
						projetil->seguir(aux_jog1.getPosition().x + (aux_jog1.getSize().x / 2), aux_jog1.getPosition().y + (aux_jog1.getSize().y / 2));
					}
					if(projetil->segueQuem(jog1)==false) {//se nao segue o jogador 1
						projetil->setSeguindo(false);//nao segue
						projetil->mover();
					}

					if (veriColisao(projetil, jog1) == 2 || veriColisao(projetil, jog1) == 4) {
						projetil->danifica(jog1);
					}
				}

			}
		}

		if (jog2 != nullptr) {

			aux_jog2 = jog2->getCorpo();

			for (Projetil* projetil : LProjetil) {
				aux_proj = projetil->getCorpo();
				if (projetil->getNoChao() == true) {
					continue;
				}
				if (projetil->getApareceu() == true) {
					if (projetil->segueQuem(jog2)) {//se segue o jogador 1
						projetil->setSeguindo(true);
						projetil->setSeguiu(true);
						projetil->seguir(aux_jog2.getPosition().x + (aux_jog2.getSize().x / 2), aux_jog2.getPosition().y + (aux_jog2.getSize().y / 2));
					}
					if (projetil->segueQuem(jog2) == false) {//se nao segue o jogador 1
						projetil->setSeguindo(false);//nao segue
						projetil->mover();
					}

					if (veriColisao(projetil, jog2) == 2 || veriColisao(projetil, jog2) == 4) {
						projetil->danifica(jog2);
					}
				}
			}
		}
	}

	void Gerenciador_Colisoes::verificaObs() {

		RectangleShape aux;
		int tempo;
		bool emCima = 0;
		bool ladoD = 0;
		bool ladoE = 0;
		bool lentidao = 0;

		if (jog1 != nullptr) {
			for (Obstaculos::Obstaculo* obstaculo : LObst) {

				aux = obstaculo->getCorpo();

				if (veriColisao(obstaculo, jog1) == 5) {

					if (obstaculo->getAtrapalha() == true) {//se areia mov...
						obstaculo->obstacular(jog1);
						lentidao = 1;
					}

					if (obstaculo->getDanoso() == true) {//se espinho
						obstaculo->obstacular(jog1);
					}

				}

				if (obstaculo->getImpede() == true) {

					if (veriColisao(obstaculo, jog1) == 1) {
						jog1->setChao(aux.getPosition().y - 100);
						emCima = 1;
					}

					if (veriColisao(obstaculo, jog1) == 2) {
						jog1->setMoviD(0);
						ladoD = 1;
					}
					if (veriColisao(obstaculo, jog1) == 3) {

						jog1->setMoviE(0);
						ladoE = 1;
					}
					if (veriColisao(obstaculo, jog1) == 4) {
						jog1->setVelocidadeY(0);
						jog1->pular(-100);
						break;
					}
				}

				if (veriColisao(obstaculo, jog1) == 0) { //se nao tem colisao...

					if (obstaculo->getAtrapalha() == true) {
						if (!lentidao) {
							obstaculo->restaura(jog1);
						}
					}
				}

			}

			if (!emCima) {
				jog1->setChao(800);
				jog1->setNoChao(0);
			}


			if (!ladoD) {
				jog1->setMoviD(1);
			}

			if (!ladoE) {
				jog1->setMoviE(1);
			}

			emCima = 0;
			ladoD = 0;
			ladoE = 0;
			lentidao = 0;
		}

		if (jog2 != nullptr) {
			for (Obstaculos::Obstaculo* obstaculo : LObst) {

				aux = obstaculo->getCorpo();

				if (veriColisao(obstaculo, jog2) == 5) {

					if (obstaculo->getAtrapalha() == true) {//se areia mov...
						obstaculo->obstacular(jog2);
						lentidao = 1;
					}

					if (obstaculo->getDanoso() == true) {//se espinho
						obstaculo->obstacular(jog2);
					}

				}

				if (obstaculo->getImpede() == true) {

					if (veriColisao(obstaculo, jog2) == 1) {
						jog2->setChao(aux.getPosition().y - 100);
						emCima = 1;
					}

					if (veriColisao(obstaculo, jog2) == 2) {
						jog2->setMoviD(0);
						ladoD = 1;
					}
					if (veriColisao(obstaculo, jog2) == 3) {

						jog2->setMoviE(0);
						ladoE = 1;
					}
					if (veriColisao(obstaculo, jog2) == 4) {
						jog2->setVelocidadeY(0);
						jog2->pular(-100);
						break;
					}
				}

				if (veriColisao(obstaculo, jog2) == 0) { //se nao tem colisao...

					if (obstaculo->getAtrapalha() == true) {
						if (!lentidao) {
							obstaculo->restaura(jog2);
						}
					}
				}

			}

			if (!emCima) {
				jog2->setChao(800);
				jog2->setNoChao(0);
			}


			if (!ladoD) {
				jog2->setMoviD(1);
			}

			if (!ladoE) {
				jog2->setMoviE(1);
			}

			emCima = 0;
			ladoD = 0;
			ladoE = 0;
			lentidao = 0;
		}
	}


	void Gerenciador_Colisoes::removeEntidade(Entidade* ent) {
		if (ent->getId() == 4) {//se for inimigo ou chefao
			LIni.remove(static_cast<Personagens::Inimigo*>(ent));
		}
		if (ent->getId() == 6) {
			LIni.remove(static_cast<Personagens::Inimigo*>(ent));
		}
		else if (ent->getId() == 1) {//se for jogador 1
			setJogadores(nullptr, jog2);
		}
		else if (ent->getId() == 2) {//se for jogador 2
			setJogadores(jog1, nullptr);
		}
		else if (ent->getId() == 12) {
			LObst.remove(static_cast<Obstaculos::Plataforma*>(ent));
		}
	}

	void Gerenciador_Colisoes::verificaObsIni() {

		RectangleShape aux, aux2;
		bool emCima = 0;
		bool ladoD = 0;
		bool ladoE = 0;

		for (Personagens::Inimigo* inimigo : LIni) {

			if (!inimigo->verificaVida()) {
				continue;
			}
			aux2 = inimigo->getCorpo();

			for (Obstaculos::Obstaculo* obstaculo : LObst) {

				if (!obstaculo->getImpede()) {
					continue;
				}

				aux = obstaculo->getCorpo();



				if (veriColisao(obstaculo, inimigo) == 1) {
					inimigo->setChao(aux.getPosition().y);
					emCima = 1;
					inimigo->setNoChao(true);
				}

				if (veriColisao(obstaculo, inimigo) == 2) {

					inimigo->setMoviD(0);
					ladoD = 1;
				}

				if (veriColisao(obstaculo, inimigo) == 3) {

					inimigo->setMoviE(0);
					ladoE = 1;
				}

			}

			if (!emCima) {
				inimigo->setChao(800);
				inimigo->setNoChao(0);

			}

			if (!ladoD) {
				inimigo->setMoviD(1);
			}

			if (!ladoE) {
				inimigo->setMoviE(1);
			}

			emCima = 0;
			ladoD = 0;
			ladoE = 0;
		}
	}

	void Gerenciador_Colisoes::verificaObsProjetil() {

		RectangleShape aux, aux2;
		bool emCima = 0;
		bool ladoD = 0;
		bool ladoE = 0;
			
		for (Projetil* projetil : LProjetil) {

			if (projetil->getApareceu()==false) {
				continue;
			}
			aux2 = projetil->getCorpo();

			for (Obstaculos::Obstaculo* obstaculo : LObst) {

				if (obstaculo->getImpede() == false) {//se nao eh plataforma
					continue;
				}

				if (obstaculo->getId() == 12) {//se eh plataforma do chefao
					continue;
				}

				aux = obstaculo->getCorpo();

				
				if (veriColisao(obstaculo, projetil) == 1) {//se tocou no chao
					projetil->setChao(aux.getPosition().y - (projetil->getCorpo().getSize().y));
					emCima = 1;
					projetil->setNoChao(true);
				}

				/*if (veriColisao(obstaculo, projetil) == 2 || veriColisao(obstaculo, projetil) == 3) {

					projetil->setNoChao(true);//desaparece
				*/

			}

			if (!emCima) {
				projetil->setChao(800);
				projetil->setNoChao(false);

			}

			emCima = 0;
		}
	}

	void Gerenciador_Colisoes::executar() {
		verificaObsIni();
		verificaIni();
		verificaObs();
		veriProjetil();
		verificaObsProjetil();
	}
}



