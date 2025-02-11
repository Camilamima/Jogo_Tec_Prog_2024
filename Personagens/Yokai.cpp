#include "Yokai.h"
#include <iostream>
#include <set>
#include <iostream>
#include <stdexcept>

namespace Entidades {
	namespace Personagens {

		Yokai::Yokai(int id, const char* png) :
			Inimigo(id, png),
			SetProj()
		{
			iniZona = 0;
			finalZona = 0;
			ativo = false;
			turno = false;
			vidas = 2;
			chao = 560;
			pos_inicial = 0;

			setVelocidae(0, 0);
			setMaldade(3);
			num_projetil = 0;
			num_proj_salvamento = 0;
			atirou = false;
		}

		Yokai::~Yokai() {
		}

		/*===== metodo que teletransporta =====*/
		void Yokai::teletransportar() {

			if (relogio1.getElapsedTime().asSeconds() >= 7.5 && !turno) {

				int meioZona = (finalZona - ((finalZona - iniZona) / 2));
				setCoordenadas(meioZona, 530);
				setCorpo(224, 240);
				relogio1.restart();
				turno = true;

			}

			if (relogio1.getElapsedTime().asSeconds() >= 3.5 && turno) {

				setCoordenadas(pos_inicial, 200);
				setCorpo(224, 240);
				turno = false;
				relogio1.restart();
			}
		}

		/*===== executar =====*/
		void Yokai::executar()
		{
			cont++;
			if (!noChao) {
				mover(0);
			}

			if (corpo.getPosition().y + 240 >= chao) {
				noChao = true;
			}

			if (ativo == true) {//se tem um jogador na zona

				if (verificaVida()) {
					pGGrafico->desenha(corpo);
					teletransportar();

					if (turno == false && relogioProjetil.getElapsedTime().asSeconds() >= 1.5) {
						if (!SetProj.empty() && atirou == false) {
							std::set<Projetil*>::iterator it = SetProj.begin();
							(*it)->setApareceu(true);
							relogioProjetil.restart();
							atirou = true;
						}
					}

					if (cont % 4 == 0) {
						val++;
						animacao(1, 10);
					}

					apagaProjetil();
				}
			}
		}

		/*===== cria um projetil =====*/
		void Yokai::criaProjeteis(Projetil* proj) {//cria todos os projeteis

			if (proj != nullptr) {
				proj->setCoordenadas(pos_inicial, 200);
				proj->setCorpo(200, 113.42);
				proj->setXY(pos_inicial, 200);
				num_projetil++;
				SetProj.insert(proj);
			}

		}

		void Yokai::criaProjeteisSalv(Projetil* proj) {
			if (proj != nullptr) {
				proj->setCorpo(200, 113.42);
				num_proj_salvamento++;
				SetProj.insert(proj);
			}
		}

		/*===== apaga um projetil =====*/
		void Yokai::apagaProjetil() {//apaga se ele tocou no chao...

			if (!SetProj.empty()) {//se a lista nao estiver vazia (se tiver projetil dentro dela
				std::set<Projetil*>::iterator it = SetProj.begin();
				if ((*it)->getnoChao() == true || (*it)->getCorpo().getPosition().x + (*it)->getCorpo().getSize().x <= iniZona) {//se o projetil tocou no chao
					std::cout << "Apaguei um projetil" << std::endl;
					(*it)->setApagado(true);
					SetProj.erase(it);//apagar o primeiro... parecido com um pop_front?
					num_projetil--;
					atirou = false;
				}
			}
		}

		/*===== animacao Yokai =====*/
		void Yokai::animacao(int num, int limite) {
			if (val >= limite) {
				val = 0;
			}

			if (num == 1) {
				try {
					if (!sprite.loadFromFile("assets/Yokai/Agis.png")) {  // Se o arquivo não for encontrado
						throw std::runtime_error("Erro ao carregar a textura: assets/Yokai/Agis.png");
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Exceção capturada: " << e.what() << std::endl;
				}
				corpo.setTexture(&sprite);
				corpo.setTextureRect(IntRect(224 * val, 0, 224, 240));
			}
		}

		void Yokai::operator++() {
			num_projetil++;
		}

		bool Yokai::zonaYokai(Heroi* jog) {
			int limiteSup_Yokai = 0;
			int limiteInf_Yokai = 0;
			bool fim = false;

			int num_ant = 0;

			//for pra descobrir a zona do Yokai
			for (int i = 1; i <= 8 && fim != true; i++) {
				if (corpo.getPosition().x >= num_ant && corpo.getPosition().x + corpo.getSize().x <= 1800 * i) {
					limiteSup_Yokai = 1800 * i;
					fim = true;
				}
				else {
					limiteInf_Yokai = 1800 * (i);
				}
			}

			iniZona = limiteInf_Yokai;
			finalZona = limiteSup_Yokai;

			if (jog->getCorpo().getPosition().x >= limiteInf_Yokai && jog->getCorpo().getPosition().x <= limiteSup_Yokai) {
				return true;
			}
			else
				return false;

		}

		void Yokai::zonaYokai() {
			bool fim = false;

			int num_ant = 0;

			iniZona = 0;

			//for pra descobrir a zona do Yokai
			for (int i = 1; i <= 8 && fim != true; i++) {

				if (corpo.getPosition().x >= iniZona && corpo.getPosition().x + corpo.getSize().x <= 1800 * i) {
					finalZona = 1800 * i;
					fim = true;
				}
				else {
					iniZona = 1800 * (i);
				}
			}

		}
		const int Yokai::max_projetil = 5;

		json Yokai::salvar() const {
			json entidadeJson;
			entidadeJson["id"] = id;
			entidadeJson["x"] = corpo.getPosition().x;
			entidadeJson["y"] = corpo.getPosition().y;
			entidadeJson["velocidadeY"] = velocidadeY;
			entidadeJson["velocidadeX"] = velocidadeX;
			entidadeJson["noChao"] = noChao;
			entidadeJson["chao"] = chao;
			entidadeJson["vidas"] = vidas;
			entidadeJson["turno"] = turno;
			entidadeJson["cont"] = cont;
			entidadeJson["num_projetil"] = num_projetil;
			entidadeJson["ativo"] = ativo;
			entidadeJson["val"] = val;
			entidadeJson["iniZona"] = iniZona;
			entidadeJson["finalZona"] = finalZona;
			entidadeJson["pos_inicial"] = pos_inicial;
			return entidadeJson;
		}
	}
}