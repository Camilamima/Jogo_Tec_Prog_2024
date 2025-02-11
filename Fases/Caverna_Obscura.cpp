#include "Caverna_Obscura.h"
#include "../Menu.h"

namespace Fases {

	Caverna_Obscura::Caverna_Obscura() :
		Fase(),
		num_obs2(-1),
		num_chefoes(-1),
		num_projeteis(-1)
	{
		
	}

	Caverna_Obscura::Caverna_Obscura(const json& dados, Gerenciadores::Gerenciado_Grafico* gC) :
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
			gerentC.setJogadores(&Heroi1, nullptr);
		}
		if (qnt_jogadores == 2) {
			std::cout << " Selecionado 2 jogadores! " << std::endl;
			gerentC.setJogadores(&Heroi1, &Heroi2);
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
				// Crie e configure um objeto Lobo
				Heroi1.setCoordenadas(x, y);
				Heroi1.setCorpo(100, 100);
				Heroi1.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Heroi1.setAtacando(entidade["atacando"]);
				Heroi1.setChao(entidade["chao"]);
				Heroi1.setVidas(entidade["vidas"]);
				Heroi1.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Heroi1.setChao(entidade["chao"]);
				Heroi1.setImpulso(entidade["impulso"]);

			}
			else if (id == 2) {
				Heroi2.setCoordenadas(x, y);
				Heroi2.setCorpo(100, 100);
				Heroi2.setAtacado(entidade["atacado"], entidade["ladoAtacado"]);
				Heroi2.setAtacando(entidade["atacando"]);
				Heroi2.setChao(entidade["chao"]);
				Heroi2.setVidas(entidade["vidas"]);
				Heroi2.setVelocidae(entidade["velocidadeX"], entidade["velocidadeY"]);
				Heroi2.setChao(entidade["chao"]);
				Heroi2.setImpulso(entidade["impulso"]);

			}

			else if (id == 3) {
				std::string png_str = entidade["png"];
				const char* png = png_str.c_str();
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(3, png);
				p->setCoordenadas(x, y);
				p->setCorpo(entidade["largura"], entidade["altura"]);
				p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);
				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
			else if (id == 12) {//ARRUMAR!!!!!!!!!
				cout << "criei plat Yokai" << endl;
				std::string png_str = entidade["png"];
				const char* png = png_str.c_str();
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(12, png);
				p->geraPlataforma(600, 224 + 20, x, y);
				listaEntidades.IncluirSalvamento(p, &gerentC);
			}
			else if (id == 4) {
				Entidades::Personagens::Lobo* r = new Entidades::Personagens::Lobo(4);
				listaEntidades.IncluirSalvamento(r, &gerentC);
				r->setCoordenadas(x, y);
				r->setCorpo(100, 100);
				r->setDistancia(entidade["distancia_percorrida"]);
				r->setVidas(entidade["vidas"]);
				r->setNoChao(entidade["noChao"]);
			}
			else if (id == 9) {
				Entidades::Obstaculos::Espinho* e = new Entidades::Obstaculos::Espinho(9);
				e->setCoordenadas(x, y);
				e->setCorpo(100, 70);
				e->setEspinhos(entidade["num_espinhos"]);
				listaEntidades.IncluirSalvamento(e, &gerentC);
			}
			else if (id == 6) {
				Entidades::Personagens::Yokai* c = new Entidades::Personagens::Yokai(6);
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
				c->setNum_Projetil(entidade["num_Entidades::Projetil::"]);
				listaEntidades.IncluirSalvamento(c, &gerentC);
			}
			else if (id == 5) {
				Entidades::Projetil* p = new Entidades::Projetil(5);
				p->setCoordenadas(x, y);
				p->setVelocidade(entidade["velocidadeX"], entidade["velocidadeY"]);
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
		listaEntidades.Incluir(&Heroi1, &gerentC);
		if (qnt_jogadores == 2) {
			listaEntidades.Incluir(&Heroi2, &gerentC);
		}

		listaEntidades.setGG(pGGrafico);
	}

	Caverna_Obscura::~Caverna_Obscura() {}

	void Caverna_Obscura::inicializa() {

		num_fase = 2;
		/* Tirado gera Plataforma e geraInimigos, qualquer coisda descomentar */
		geraPlataformaFase();
		geraChao();
		geraEspinho();
		geraYokai();
		geraInimigos();
		geraProjeteis();


		if (qnt_jogadores == 1) {
			cout << " Selecionado 1 jogador! " << endl;
			gerentC.setJogadores(&Heroi1, nullptr);
			listaEntidades.Incluir(&Heroi1, &gerentC);
			Heroi1.setVidas(200);
		}
		if (qnt_jogadores == 2) {
			cout << " Selecionado 2 jogadores! " << endl;
			gerentC.setJogadores(&Heroi1, &Heroi2);
			listaEntidades.Incluir(&Heroi1, &gerentC);
			listaEntidades.Incluir(&Heroi2, &gerentC);
			Heroi2.setVidas(200);
		}

		/*=== Colocando elementos constantes na lista ===*/
		listaEntidades.Incluir(&chao, &gerentC);
		listaEntidades.Incluir(&ladoE, &gerentC);

		/*==== setando o gerenciador grafico ====*/
		listaEntidades.setGG(pGGrafico);

		/*==== gerando plataforma fixas ====*/
		ladoE.geraPlataforma(900, 40, -40, 0);
		chao.geraPlataforma(40, (float)tamanho_fase, 0, 900);

	}

	void Caverna_Obscura::geraChao() {
		int numeros[36] = {0};
		int alterna = 1;
		for (int i = 0; i < 36; i++) {

			if (alterna == 1) {
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(3, "assets/pedra11.png");
				p->geraPlataforma(100, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna++;
			}
			else if (alterna == 2) {
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(3, "assets/pedra21.png");
				p->geraPlataforma(100, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna++;
			}
			else {
				Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(3, "assets/pedra31.png");
				p->geraPlataforma(100, 400, (float)i * 400, 760);//era 400
				listaEntidades.Incluir(p, &gerentC);
				alterna = 1;
			}
		}
		Entidades::Obstaculos::Plataforma* p = new Entidades::Obstaculos::Plataforma(3, "assets/chao.png");
		p->geraPlataforma(100, 14400, 0, 860);
		listaEntidades.Incluir(p, &gerentC);
	}

	void Caverna_Obscura::geraInimigos() {
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
				Entidades::Personagens::Lobo* r = new Entidades::Personagens::Lobo(4);
				r->setCoordenadas((float)i * 100, 0);
				r->setCorpo(100, 100);
				listaEntidades.Incluir(r, &gerentC);
			}

		}
	}

	void Caverna_Obscura::geraYokai() {
		vector<int> posicoes;
		time_t tempo;
		srand((unsigned)time(&tempo));
		int altura = 190;

		int teste = 0;

		for (int i = 3; i < (tamanho_fase / tamanho_zona); i++) {//crio o vetor com posições aleatorias
			teste = rand() % 400;

			posicoes.push_back(static_cast<int>(i * tamanho_zona + 1100 + teste));

		}
		
		num_chefoes  = (rand() % 2) + 4; //de 4 a 5 entidades

		int pos = 0;

		for (int i = 0; i < num_chefoes && pos<=posicoes.size(); i++) {

			Entidades::Personagens::Yokai* c = new Entidades::Personagens::Yokai(6, "assets/Yokai/Agis.png");
			Entidades::Obstaculos::Obstaculo* o = new Entidades::Obstaculos::Plataforma(12, "assets/parede11.png");
			
			c->setCoordenadas((float)posicoes[pos], (float)altura);
			c->setPosInicialX((float)posicoes[pos]);
			c->setCorpo(224, 240);
			c->zonaYokai();

			o->setCoordenadas((float)(posicoes[pos] - 10), (float)(altura + 5 + c->getCorpo().getSize().y));
			o->setCorpo((float)(c->getCorpo().getSize().x + 20), (float)(600));

			int meioZona = (c->getFinalZona() - ((c->getFinalZona() - c->getIniZona()) / 2));

			listaEntidades.Incluir(c, &gerentC);
			listaEntidades.Incluir(o, &gerentC);


			posicoes.erase(posicoes.begin() + pos);
			
		}
	}
	
	void Caverna_Obscura::geraProjeteis() {//ser criada DEPOIS do Yokai

		num_projeteis = 5 * (num_chefoes);

		for (int i = 0; i <num_projeteis; i++) {
			Entidades::Projetil* p = new Entidades::Projetil(5);
			listaEntidades.Incluir(p, &gerentC);
		}
	}
}