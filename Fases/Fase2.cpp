#include "Fase2.h"
#include "../Menu.h"

namespace Fases {

	Fase2::Fase2() :
		Fase(),
		num_obs2(-1),
		num_chefoes(-1),
		num_projeteis(-1)
	{
		//pGGrafico->BackGFloresta(2);
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

			// Aqui você pode criar as entidades e configurá-las conforme necessário
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
				std::string png_str = entidade["png"];
				const char* png = png_str.c_str();
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
				//p->setAtivo(entidade["segue"]);
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

		listaEntidades.setGG(pGGrafico);
	}

	Fase2::~Fase2() {}

	

	void Fase2::inicializa() {

		num_fase = 2;
		/* Tirado gera Plataforma e geraInimigos, qualquer coisda descomentar */
		geraPlataformaFase();
		geraChao();
		geraChefao();
		geraEspinho();
		geraInimigos();
		geraProjeteis();

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
		listaEntidades.setGG(pGGrafico);

		/*==== gerando plataforma fixas ====*/
		ladoE.geraPlataforma(900, 40, 0, 0);
		chao.geraPlataforma(40, (float)tamanho_fase, 0, 900);

	}

	void Fase2::geraChao() {
		/*int numeros[36] = {0};
		for (int i = 0; i < 36; i++) {

			Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/plataforma_chao.png");
			p->geraPlataforma(100, 97.91, (float)i * 400, 760);//era 400
			listaEntidades.Incluir(p, &gerentC);
		}*/
		Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/chao.png");
		p->geraPlataforma(100, 14400, 0, 860);
		listaEntidades.Incluir(p, &gerentC);

		int numeros[36] = { 0 };
		int alterna = 1;
		for (int i = 0; i < 36; i++) {
			if (alterna == 1) {
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/pedra11.png");
				p->geraPlataforma(140, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna++;
			}

			else if (alterna == 2) {
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/pedra21.png");
				p->geraPlataforma(140, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna++;
			}
			else {
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/pedra31.png");
				p->geraPlataforma(140, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna = 1;
			}
		}
	}

	void Fase2::geraInimigos() {
		int numeros[144] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		num_facil = (int)((rand() % 3) + 3);
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

	void Fase2::geraChefao() {
		vector<int> posicoes;
		time_t tempo;
		srand((unsigned)time(&tempo));
		int altura = 190;

		int teste = 0;

		for (int i = 3; i < (tamanho_fase / tamanho_zona); i++) {//crio o vetor com posições aleatorias
			teste = rand() % 477;

			posicoes.push_back(static_cast<float>(i * tamanho_zona + 1200.0f + teste));

		}
		
		num_chefoes  = (rand() % 2) + 4; //de 4 a 5 entidades

		int pos = 0;

		for (int i = 0; i < num_chefoes && pos<=posicoes.size(); i++) {

			Personagens::Chefao* c = new Personagens::Chefao(6, "assets/chefao/Agis.png");
			Obstaculos::Obstaculo* o = new Obstaculos::Plataforma(12, "assets/parede11.png");

			
			c->setCoordenadas((float)posicoes[pos], altura);
			c->setPosInicialX((float)posicoes[pos]);
			c->setCorpo(224, 240);
			c->zonaChefao();

			o->setCoordenadas((float)(posicoes[pos] - 10), (float)(altura + 5 + c->getCorpo().getSize().y));
			o->setCorpo((float)(c->getCorpo().getSize().x + 20), (float)(600));

			int meioZona = (c->getFinalZona() - ((c->getFinalZona() - c->getIniZona()) / 2));

			listaEntidades.Incluir(c, &gerentC);
			listaEntidades.Incluir(o, &gerentC);


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