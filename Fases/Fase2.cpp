#include "Fase2.h"

namespace Fases {

	Fase2::Fase2() :
		num_obs2(-1)
	{
	}
	Fase2::~Fase2() {}

	void Fase2::inicializa() {
		num_obs2 = -1;
		geraPlataformaFase();
		geraChao();
		geraEspinho();
		geraInimigos();

		/*==== setando numero de jogadores ====*/
		int num_jogadores;

		cout << "Para 1 jogador tecle 1" << endl;
		cout << "Para 2 jogadores tecle 2" << endl;
		//cin >> num_jogadores;
		num_jogadores = 1;

		if (num_jogadores == 1) {
			cout << " Selecionado 1 jogador! " << endl;
			gerentC.setJogadores(&Slime1, nullptr);
			listaEntidades.Incluir(&Slime1, &gerentC);
		}
		if (num_jogadores == 2) {
			cout << " Selecionado 2 jogadores! " << endl;
			gerentC.setJogadores(&Slime1, &Slime2);
			listaEntidades.Incluir(&Slime1, &gerentC);
			listaEntidades.Incluir(&Slime2, &gerentC);
		}
		if (num_jogadores != 1 && num_jogadores != 2) {
			cout << "Numero invalido de jogadores!" << endl;
			cout << "Selecionado 1 jogador!" << endl;
			gerentC.setJogadores(&Slime1, nullptr);
			listaEntidades.Incluir(&Slime1, &gerentC);
		}

		/*=== Colocando elementos constantes na lista ===*/
		listaEntidades.Incluir(&chao, &gerentC);
		listaEntidades.Incluir(&ladoE, &gerentC);

		/*==== setando o gerenciador grafico ====*/
		listaEntidades.setGG(gerent);

		/*==== gerando plataforma fixas ====*/
		ladoE.geraPlataforma(900, 40, 0, 0);
		chao.geraPlataforma(40, (float)tamanho_fase, 0, 900);
	}

	void Fase2::geraChao() {
		int numeros[36] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		num_obs2 = (int)((rand() % 13) + 5);

		for (int k = num_obs2; k > 0; k--) {
			int posicao = (rand() % 33) + 1;
			while (numeros[posicao] != 0 ||
				checaLocaliza((float)posicao * 400, 2)) {
				posicao = (rand() % 33) + 1;
			}
			numeros[posicao] = 1;
		}

		//tamanho fase: 14400, 8 segmentos, 7200/36=400 cada bloco
		for (int i = 0; i < 36; i++) {
			if (i == 0 || numeros[i] == 0) {
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3);
				p->geraPlataforma(140, 400, (float)i * 400, 760);
				listaEntidades.Incluir(p, &gerentC);
			}
			else {
				Obstaculos::Acelerador* M = new Obstaculos::Acelerador(3);
				M->setCoordenadas((float)i * 400, 800);
				M->setCorpo(400, 130);
				listaEntidades.Incluir(M, &gerentC);
				for (int k = 0; k <= 4; k++) {
					localizacao_obs.push_back((k * 100) + i * 400);
				}
			}
		}
	}

	void Fase2::geraInimigos() {
		int numeros[144] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		num_facil = (int)((rand() % 3) + 5);
		//num_dificil = (int)((rand() % 3) + 3);
		int posicao = 0;

		for (int k = num_facil; k > 0; k--) {
			posicao = (rand() % 142) + 1;
			while ((numeros[posicao] != 0 || posicao % 1800 == 0) || posicao < 3) {
				posicao = (rand() % 142) + 1;
			}
			numeros[posicao] = 1;
		}

		

		for (int i = 0; i < 144; i++) {
			if (numeros[i] == 1) {
				Personagens::Rato* r = new Personagens::Rato(4);
				r->setCoordenadas((float)i * 100, 0);
				r->setCorpo(100, 100);
				listaEntidades.Incluir(r, &gerentC);
			}

		}
	}

}