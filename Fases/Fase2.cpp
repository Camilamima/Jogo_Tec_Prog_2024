#include "Fase2.h"
#include "../Menu.h"

namespace Fases {

	Fase2::Fase2() :
		Fase(),
		num_obs2(-1),
		num_chefoes(-1),
		num_projeteis(-1)
	{
		//gerent->BackGFloresta(2);
	}

	Fase2::Fase2(const json& dados, Gerenciadores::Gerenciado_Grafico* gC) :
		Fase(),
		num_obs2(-1),
		num_chefoes(-1),
		num_projeteis(-1)
	{
		num_fase = 2;
		cout << "cheguei1" << endl;
		setGerenciador(gC);
		zona_atual = dados["zona"];
		qnt_jogadores = dados["jogadores"];

		if (qnt_jogadores == 1) {
			std::cout << " Selecionado 1 jogador! " << std::endl;
			gerentC.setJogadores(&Slime1, nullptr);
		}
		if (qnt_jogadores == 2) {
			std::cout << " Selecionado 2 jogadores! " << std::endl;
			gerentC.setJogadores(&Slime1, &Slime2);
		}

		int id;
		float x, y;
		cout << "cheguei2" << endl;
		for (const auto& entidade : dados["entidades"]) {
			if (entidade.is_null()) {
				continue;
			}
			id = entidade["id"];
			x = entidade["x"];
			y = entidade["y"];

			// Aqui voc� pode criar as entidades e configur�-las conforme necess�rio
			if (id == 1) {
				// Crie e configure um objeto Rato
				Slime1.setCoordenadas(x, y);
				Slime1.setCorpo(100, 100);
				Slime1.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Slime1.setAtacando(entidade["atacando"]);
				Slime1.setChao(entidade["chao"]);
				Slime1.setVidas(entidade["vidas"]);
				Slime1.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Slime1.setChao(entidade["chao"]);
				Slime1.setImpulso(entidade["impulso"]);

			}
			else if (id == 2) {
				Slime2.setCoordenadas(x, y);
				Slime2.setCorpo(100, 100);
				Slime2.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Slime2.setAtacando(entidade["atacando"]);
				Slime2.setChao(entidade["chao"]);
				Slime2.setVidas(entidade["vidas"]);
				Slime2.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Slime2.setChao(entidade["chao"]);
				Slime2.setImpulso(entidade["impulso"]);

			}
			else if (id == 3) {

				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3);
				listaEntidades.Incluir(p, &gerentC);
				p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);

			}
			else if (id == 12) {

				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(12);
				listaEntidades.Incluir(p, &gerentC);
				p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);

			}
			else if (id == 4) {
				Personagens::Rato* r = new Personagens::Rato(4);
				listaEntidades.Incluir(r, &gerentC);
				r->setCoordenadas(x, y);
				r->setCorpo(100, 100);
				r->setDistancia(entidade["distancia_percorrida"]);
				r->setVidas(entidade["vidas"]);
				r->setNoChao(entidade["noChao"]);
			}
			else if (id == 9) {
				Obstaculos::Espinho* e = new Obstaculos::Espinho(9);
				e->setCoordenadas(x, y);
				e->setCorpo(100, 70);
				e->setEspinhos(entidade["num_espinhos"]);
				listaEntidades.Incluir(e, &gerentC);
			}
			else if (id == 6) {
				Personagens::Chefao* c = new Personagens::Chefao(6);
				c->setCoordenadas(x, y);
				c->setCorpo(224, 240);
				c->setMaldade(3);
				c->setPosInicialX(entidade["pos_inicial"]);
				c->setAtivo(entidade["ativo"]);
				c->setChao(entidade["chao"]);
				c->setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				c->setNoChao(entidade["noChao"]);
				c->setVidas(entidade["vidas"]);
				c->setTurno(entidade["turno"]);
				c->setIniZona(entidade["iniZona"]);
				c->setFinalZona(entidade["finalZona"]);
				c->setVal(entidade["val"]);
				c->setCont(entidade["cont"]);
				c->setNum_Projetil(entidade["num_projetil"]);
				listaEntidades.IncluirSalvamento(c, &gerentC);
			}
			else if (id == 5) {
				Projetil* p = new Projetil(5);
				p->setCoordenadas(x, y);
				p->setVelocidade(entidade["velocidadeX"], entidade["velocidadeY"]);
				p->setAtivo(entidade["segue"]);
				p->setNoChao(entidade["noChao"]);
				p->setChao(entidade["chao"]);
				p->setSeguindo(entidade["seguindo"]);
				p->setSeguiu(entidade["seguiu"]);
				p->setCont(entidade["cont"]);
				p->setVal(entidade["val"]);
				p->setApagado(entidade["apagado"]);
				p->setApareceu(entidade["apareceu"]);
				p->setCoordenadas(entidade["posX"], entidade["posY"]);
				p->setXY(entidade["posX"], entidade["posY"]);

				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
			//adicionar aqui outros ids
		}
		listaEntidades.Incluir(&Slime1, &gerentC);
		if (qnt_jogadores == 2) {
			listaEntidades.Incluir(&Slime2, &gerentC);
		}

		listaEntidades.setGG(gerent);
	}

	Fase2::~Fase2() {}

	/*Fase2::Fase2(const json& dados, Gerenciadores::Gerenciado_Grafico* gC) :
	num_obs2(-1),
	num_chefoes(-1),
	num_projeteis(-1)
	{
		num_fase = 2;
		cout << "cheguei2" << endl;
		setGerenciador(gC);
		zona_atual = dados["zona"];
		qnt_jogadores = dados["jogadores"];

		if (qnt_jogadores == 1) {
			std::cout << " Selecionado 1 jogador! " << std::endl;
			gerentC.setJogadores(&Slime1, nullptr);
		}
		if (qnt_jogadores == 2) {
			std::cout << " Selecionado 2 jogadores! " << std::endl;
			gerentC.setJogadores(&Slime1, &Slime2);
		}

		int id;
		float x, y;
		for (const auto& entidade : dados["entidades"]) {
			id = entidade["id"];
			x = entidade["x"];
			y = entidade["y"];

			// Aqui voc� pode criar as entidades e configur�-las conforme necess�rio
			if (id == 1) {
				// Crie e configure um objeto Rato
				Slime1.setCoordenadas(x, y);
				Slime1.setCorpo(100, 100);
				Slime1.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Slime1.setAtacando(entidade["atacando"]);
				Slime1.setChao(entidade["chao"]);
				Slime1.setVidas(entidade["vidas"]);
				Slime1.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Slime1.setChao(entidade["chao"]);
				Slime1.setImpulso(entidade["impulso"]);

			}
			else if (id == 2) {
				Slime2.setCoordenadas(x, y);
				Slime2.setCorpo(100, 100);
				Slime2.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Slime2.setAtacando(entidade["atacando"]);
				Slime2.setChao(entidade["chao"]);
				Slime2.setVidas(entidade["vidas"]);
				Slime2.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Slime2.setChao(entidade["chao"]);
				Slime2.setImpulso(entidade["impulso"]);

			}
			else if (id == 3) {//arrumar salvamento disso.......
				std::string png_str = entidade["png"];
				const char* png = png_str.c_str();
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, png);
				p->setCoordenadas(x, y);
				p->setCorpo(entidade["largura"], entidade["altura"]);
				//p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);
				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
			else if (id == 12) {//e disso
				std::string png_str = entidade["png"];
				const char* png = png_str.c_str();
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(12, png);
				p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);
				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
			else if (id == 4) {
				Personagens::Rato* r = new Personagens::Rato(4);
				r->setCoordenadas(x, y);
				r->setCorpo(100, 100);
				r->setDistancia(entidade["distancia_percorrida"]);
				r->setVidas(entidade["vidas"]);
				r->setNoChao(entidade["noChao"]);

				listaEntidades.IncluirSalvamento(r, &gerentC);
			}
			else if (id == 9) {
				Obstaculos::Espinho* e = new Obstaculos::Espinho(9);
				e->setCoordenadas(x, y);
				e->setCorpo(100, 70);
				e->setEspinhos(entidade["num_espinhos"]);
				listaEntidades.IncluirSalvamento(e, &gerentC);
			}
			else if (id == 11) {
				Obstaculos::SlimeMau* M = new Obstaculos::SlimeMau(11);
				M->setCoordenadas(x, y);
				M->setCorpo(entidade["largura"], entidade["altura"]);
				listaEntidades.IncluirSalvamento(M, &gerentC);
			}
	
			else if (id == 6) {
				Personagens::Chefao* c = new Personagens::Chefao(6);
				c->setCoordenadas(x, y);
				c->setCorpo(224, 240);
				c->setMaldade(3);
				c->setPosInicialX(entidade["pos_inicial"]);
				c->setAtivo(entidade["ativo"]);
				c->setChao(entidade["chao"]);
				c->setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				c->setNoChao(entidade["noChao"]);
				c->setVidas(entidade["vidas"]);
				c->setTurno(entidade["turno"]);
				c->setIniZona(entidade["iniZona"]);
				c->setFinalZona(entidade["finalZona"]);
				c->setVal(entidade["val"]);
				c->setCont(entidade["cont"]);
				c->setNum_Projetil(entidade["num_projetil"]);
				listaEntidades.IncluirSalvamento(c, &gerentC);
			}
			else if (id == 5) {
				Projetil* p = new Projetil(5);
				p->setCoordenadas(x, y);
				p->setVelocidade(entidade["velocidadeX"], entidade["velocidadeY"]);
				p->setAtivo(entidade["segue"]);
				p->setNoChao(entidade["noChao"]);
				p->setChao(entidade["chao"]);
				p->setSeguindo(entidade["seguindo"]);
				p->setSeguiu(entidade["seguiu"]);
				p->setCont(entidade["cont"]);
				p->setVal(entidade["val"]);
				p->setApagado(entidade["apagado"]);
				p->setApareceu(entidade["apareceu"]);
				p->setCoordenadas(entidade["posX"], entidade["posY"]);
				p->setXY(entidade["posX"], entidade["posY"]);

				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
		}

		listaEntidades.Incluir(&Slime1, &gerentC);
		if (qnt_jogadores == 2) {
			listaEntidades.Incluir(&Slime2, &gerentC);
		}

		listaEntidades.setGG(gerent);
	}*/

	void Fase2::inicializa() {

		num_fase = 2;
		/* Tirado gera Plataforma e geraInimigos, qualquer coisda descomentar */
		geraPlataformaFase();
		geraChao();
		geraChefao();
		geraEspinho();
		geraInimigos();
		geraProjeteis();
		//gerent->BackGFloresta(2);


		if (qnt_jogadores == 1) {
			cout << " Selecionado 1 jogador! " << endl;
			gerentC.setJogadores(&Slime1, nullptr);
			listaEntidades.Incluir(&Slime1, &gerentC);
		}
		if (qnt_jogadores == 2) {
			cout << " Selecionado 2 jogadores! " << endl;
			gerentC.setJogadores(&Slime1, &Slime2);
			listaEntidades.Incluir(&Slime1, &gerentC);
			listaEntidades.Incluir(&Slime2, &gerentC);
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
		for (int i = 0; i < 36; i++) {

			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3);
			p->geraPlataforma(100, 400, (float)i * 400, 760);
			listaEntidades.Incluir(p, &gerentC);
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
	/*
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

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			Pause = true;
			pMenu->restartTime();
			while (Pause) {
				pMenu->Pause();
			}

		}

		listaEntidades.Percorrer(&gerentC);//executar de td
		pos_morto = listaEntidades.VerificMortos();

		if (pos_morto != -1) {
			listaEntidades.matarEntidadePos(pos_morto, &gerentC);
		}

		/*if (Slime1.getVidas() <= 0 && apareceu1 == false) {
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
					};
				}
			}
		}*/
	/*
			gerent->mostrar();
	}
	*/

	void Fase2::geraChefao() {
		vector<int> posicoes;
		time_t tempo;
		srand((unsigned)time(&tempo));
		int altura = 190;

		int teste = 0;

		for (int i = 3; i < (tamanho_fase / tamanho_zona); i++) {//crio o vetor com posi��es aleatorias
			teste = rand() % 477;

			posicoes.push_back(static_cast<float>(i * tamanho_zona + 1200 + teste));

		}
		
		num_chefoes  = (rand() % 2) + 4; //de 4 a 5 entidades

		int pos = 0;

		for (int i = 0; i < num_chefoes && pos<=posicoes.size(); i++) {

			Personagens::Chefao* c = new Personagens::Chefao(6);
			Obstaculos::Obstaculo* o = new Obstaculos::Plataforma(12);
			Obstaculos::Obstaculo* o2 = new Obstaculos::Plataforma(3);

			
			c->setCoordenadas((float)posicoes[pos], altura);
			c->setPosInicialX((float)posicoes[pos]);
			c->setCorpo(224, 240);
			c->zonaChefao();

			o->setCoordenadas((float)(posicoes[pos] - 10), (float)(altura + 5 + c->getCorpo().getSize().y));
			o->setCorpo((float)(c->getCorpo().getSize().x + 20), (float)(600));

			int meioZona = (c->getFinalZona() - ((c->getFinalZona() - c->getIniZona()) / 2));
			o2->setCoordenadas((meioZona - 25), 760);
			o2->setCorpo(c->getCorpo().getSize().x + 50, 140);

			listaEntidades.Incluir(c, &gerentC);
			listaEntidades.Incluir(o, &gerentC);
			listaEntidades.Incluir(o2, &gerentC);


			posicoes.erase(posicoes.begin() + pos);
			
		}
	}
	
	void Fase2::geraProjeteis() {//ser criada DEPOIS do chefao

		num_projeteis = 10 * (num_chefoes);

		for (int i = 0; i <num_projeteis; i++) {
			Projetil* p = new Projetil(5);
			listaEntidades.Incluir(p, &gerentC);
		}
	}
}