#include "Fase2.h"

namespace Fases {

	Fase2::Fase2() :
		teste2(6),//chefao
		p1(5),
		p2(5),
		p3(5),
		p4(5),
		p5(5),
		p6(5),
		p7(5),
		p8(5),
		p9(5),
		p10(5),
		num_obs2(-1)
	{
	}
	Fase2::~Fase2() {}

	void Fase2::inicializa() {

		num_fase = 2;
		/* Tirado gera Plataforma e geraInimigos, qualquer coisda descomentar */
		//geraPlataformaFase();
		geraChao();
		geraEspinho();
		//geraInimigos();

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
		listaEntidades.Incluir(&teste2, &gerentC);
		listaEntidades.Incluir(&p1, &gerentC);
		listaEntidades.Incluir(&p2, &gerentC);
		listaEntidades.Incluir(&p3, &gerentC);
		listaEntidades.Incluir(&p4, &gerentC);
		listaEntidades.Incluir(&p5, &gerentC);
		listaEntidades.Incluir(&p6, &gerentC);
		listaEntidades.Incluir(&p7, &gerentC);
		listaEntidades.Incluir(&p8, &gerentC);
		listaEntidades.Incluir(&p9, &gerentC);
		listaEntidades.Incluir(&p10, &gerentC);

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
				Obstaculos::Acelerador* M = new Obstaculos::Acelerador(8);
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
	void Fase2::executar() {

		int qnt_jogadores = 1;
		bool apareceu1 = false;
		bool apareceu2 = false;
		int cont1 = 0;
		int cont2 = 0;
		bool morreu = false;
		bool morreu2 = false;
		int pos_morto = 0;


		if (gerentC.getJogador2() != nullptr)
			qnt_jogadores = 2;

		gerent->arrumaCamera(checaZona());

		gerent->clear();

		listaEntidades.Percorrer(&gerentC);//executar de td
		pos_morto = listaEntidades.VerificMortos();

		if (pos_morto != -1) {
			listaEntidades.matarEntidadePos(pos_morto, &gerentC);
		}

		if (Slime1.getVidas() <= 0 && apareceu1 == false) {
			Slime1.setMorrendo(true);
			if (Slime1.getCont() % 8 == 0) {
				morreu = Slime1.animacaoMorte(cont1, 10);
				cont1++;
				if (morreu == true) {
					cout << "Jogador 1 morreu!" << endl;
					listaEntidades.MatarEntidade(&Slime1, &gerentC);
					qnt_jogadores--;
					apareceu1 = true;
				}
			}
		}

		if (gerentC.getJogador2() != nullptr) {
			if (Slime2.getVidas() <= 0 && apareceu2 == false) {
				Slime2.setMorrendo(true);
				if (Slime2.getCont() % 8 == 0) {
					morreu2 = Slime2.animacaoMorte(cont2, 10);
					cont2++;
					if (morreu2 == true) {
						cout << "Jogador 2 morreu!" << endl;
						listaEntidades.MatarEntidade(&Slime2, &gerentC);
						qnt_jogadores--;
						apareceu2 = true;
					}
				}
			}
		}

			gerent->mostrar();
	}
	const int numero_projeteis = 20;
}