#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream> 
#include "Fase.h"
#include"../Menu.h"



using namespace sf;
using namespace std;

namespace Fases {
	Fase::Fase():
		Ente(),
		Texto(),
		num_fase(-1),
		Heroi1(1),
		Heroi2(2),
		listaEntidades(),
		gerentC(),
		num_facil(-1),
		chao(3),
		ladoE(3),
		tamanho_fase(14400),
		tamanho_zona(1800),
		zona_atual(0),
		qnt_jogadores(-1),
		Pause(0)
	{
		qnt_jogadores_ini = -1;
		pMenu = nullptr;
	}

	Fase::~Fase() {
		limpaVec();
	}

	void Fase::limpaVec() {
     localizacao_obs.clear();
	}

	const bool Fase::checaLocaliza(float x,int ver) const {
		if (ver == 1) {
			for (int i = 0; i < localizacao_obs.size(); i++) {
				if (localizacao_obs[i] == x) {
					return 1;
				}
			}
		}
		else
		{
			for (int i = 0; i < localizacao_obs.size(); i++) {
				if (localizacao_obs[i] >= x-3  && localizacao_obs[i]<=x+400+3) {
					return 1;
				}
			}
		}
		return 0;
	}

	float Fase::checaZona() {

		if (qnt_jogadores == 1) {

			if (Heroi1.getVidas() <= 0) {
				int xJog1;
				xJog1 = (int)Heroi2.getCorpo().getPosition().x;
				xJog1 = xJog1 + (int)Heroi2.getCorpo().getSize().x / 2;

				zona_atual = (xJog1 / tamanho_zona);

				return (float)(zona_atual * tamanho_zona);
			}


			else if (Heroi2.getVidas() <= 0 || gerentC.getJogador2() == nullptr) {
				int xJog1;
				xJog1 = (int)Heroi1.getCorpo().getPosition().x;
				xJog1 = xJog1 + (int)Heroi1.getCorpo().getSize().x / 2;

				zona_atual = (xJog1 / tamanho_zona);

				return (float)(zona_atual * tamanho_zona);
			}
		}
		else if(qnt_jogadores==2) {
			if (Heroi1.getVidas() > 0 && Heroi2.getVidas() > 0) {
				int xJog1, xJog2;
				xJog1 = (int)Heroi1.getCorpo().getPosition().x;
				xJog1 = xJog1 + (int)Heroi1.getCorpo().getSize().x / 2;
				xJog2 = (int)Heroi2.getCorpo().getPosition().x;
				xJog2 = xJog2 + (int)Heroi1.getCorpo().getSize().x / 2;

				zona_atual = (xJog1 / tamanho_zona);

				if (xJog2 / tamanho_zona < zona_atual) {
					zona_atual = xJog2 / tamanho_zona;
				}

				return (float)zona_atual * tamanho_zona;
			}
			else if (Heroi1.getVidas() > 0 && Heroi2.getVidas() <= 0) {
				int xJog1;
				xJog1 = (int)Heroi1.getCorpo().getPosition().x;
				xJog1 = xJog1 + (int)Heroi1.getCorpo().getSize().x / 2;

				zona_atual = (xJog1 / tamanho_zona);

				return (float)(zona_atual * tamanho_zona);
			}
			else if (Heroi1.getVidas() <= 0 && Heroi2.getVidas() > 0) {

				int xJog1;
				xJog1 = (int)Heroi2.getCorpo().getPosition().x;
				xJog1 = xJog1 + (int)Heroi2.getCorpo().getSize().x / 2;

				zona_atual = (xJog1 / tamanho_zona);

				return (float)(zona_atual * tamanho_zona);
			}
		}
		return 0;

	}


	void Fase::geraEspinho() {
		int quantidade;
		int numeros[144] = { 0 };
		time_t tempo;
		srand((unsigned)time(&tempo));
		quantidade = (int)((rand() % 10) + 10);
		int posicao = 0;
		for (int k = quantidade; k > 0; k--) {
			posicao = (rand() % 142) + 1;
			while (numeros[posicao] != 0 || checaLocaliza((float)posicao * 100,1) ||
				(posicao < 143 && (numeros[posicao + 1] == 1 || numeros[posicao - 1] == 1)) ||
				(posicao < 142 && (numeros[posicao + 1] == 1 && numeros[posicao + 2] == 1)) ||
				(posicao > 1 && (numeros[posicao - 1] == 1 && numeros[posicao - 2] == 1) ||
				posicao%1800==0 )   
				) {
				posicao = (rand() % 142) + 1;
			}
			numeros[posicao] = 1;
		}

		//tamanho fase: 14400, 1400/144=100 cada espinho
		for (int i = 0; i < 144; i++) {
			if (numeros[i] != 0 && i > 3) {
				Obstaculos::Espinho* p = new Obstaculos::Espinho(9);
				p->setCoordenadas((float)i * 100, 700);
				p->setCorpo(100, 70);
				listaEntidades.Incluir(p, &gerentC);
			}

		}
	}



	void Fase::geraPlataformaFase(){
		if (num_fase == 1) {
			float lugar = 0;
			int tipo = 0;
			int plataforma = 0;
			time_t tempo;
			srand((unsigned)time(&tempo));

			for (float zona = 0; zona <= 7; zona++) {
				lugar = static_cast<float>((((rand() % 16) + 1) * 100) + (zona * 1800));
				tipo = (rand() % 4) + 1;
				TipoPlataforma(tipo, lugar);

			}
		}
		else if (num_fase == 2) {
			float lugar = 0;
			int tipo = 0;
			int plataforma = 0;
			time_t tempo;
			srand((unsigned)time(&tempo));

			for (float zona = 0; zona < 3; zona++) {
				lugar = static_cast<float>((((rand() % 16) + 1) * 100) + (zona * 1800));
				tipo = (rand() % 4) + 1;
				TipoPlataforma(tipo, lugar);//tipo
			}	

			//==== teste ===//
			lugar = static_cast<float>((((rand() % 10) + 1) * 50) + (1 * 1800));
			TipoPlataforma(2, lugar);
			//==============//
		}
	}

	void Fase::TipoPlataforma(int tipo, float x) {
		if (num_fase == 1) {
			if (tipo == 1) { // a em formato L invertido
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/pedra_tiles.png");
				p->geraPlataforma(300, 200, x, 560);
				listaEntidades.Incluir(p, &gerentC);

				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/tronco.png");
				p2->geraPlataforma(100, 600, x + 10, 460);
				listaEntidades.Incluir(p2, &gerentC);

				localizacao_obs.push_back((int)x);
				localizacao_obs.push_back((int)x + 100);
			}
			else if (tipo == 2) { // plataforma simples
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/planta.png");
				p->geraPlataforma(150, 100, x, 610);
				listaEntidades.Incluir(p, &gerentC);

				localizacao_obs.push_back((int)x);
			}
			else if (tipo == 3) { // plataforma com folhas
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/tronco2.png");
				p->geraPlataforma(200, 100, x, 560);
				listaEntidades.Incluir(p, &gerentC);

				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/folhas_3x.png");
				p2->geraPlataforma(100, 400, x - 50, 520);
				listaEntidades.Incluir(p2, &gerentC);

				localizacao_obs.push_back((int)x);
			}
			else if (tipo == 4) { // plataforma dupla
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/Tiles.png");
				p->geraPlataforma(200, 300, x, 560);
				listaEntidades.Incluir(p, &gerentC);
				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/Tiles.png");
				p2->geraPlataforma(100, 200, x + 200, 455);
				listaEntidades.Incluir(p2, &gerentC);
				localizacao_obs.push_back((int)x);
				localizacao_obs.push_back((int)x + 100);
				localizacao_obs.push_back((int)x + 200);
			}
		}
		else if (num_fase == 2) {
			if (tipo == 1) { // conjunto de plataformas empilhadas
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/parede41.png");
				p->geraPlataforma(300, 200, x, 560);
				listaEntidades.Incluir(p, &gerentC);

				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/pedra11.png");
				p2->geraPlataforma(100, 100, x + 10, 460);

				Obstaculos::Plataforma* p3 = new Obstaculos::Plataforma(3, "assets/pedra21.png");
				p3->geraPlataforma(100, 100, x + 110, 460);

				Obstaculos::Plataforma* p4 = new Obstaculos::Plataforma(3, "assets/pedra31.png");
				p4->geraPlataforma(100, 100, x + 210, 460);

				Obstaculos::Plataforma* p5 = new Obstaculos::Plataforma(3, "assets/pedra11.png");
				p5->geraPlataforma(100, 100, x + 310, 460);

				Obstaculos::Plataforma* p6 = new Obstaculos::Plataforma(3, "assets/pedra21.png");
				p6->geraPlataforma(100, 100, x + 410, 460);

				Obstaculos::Plataforma* p7 = new Obstaculos::Plataforma(3, "assets/pedra31.png");
				p7->geraPlataforma(100, 100, x + 510, 460);

				listaEntidades.Incluir(p2, &gerentC);
				listaEntidades.Incluir(p3, &gerentC);
				listaEntidades.Incluir(p4, &gerentC);
				listaEntidades.Incluir(p5, &gerentC);
				listaEntidades.Incluir(p6, &gerentC);
				listaEntidades.Incluir(p7, &gerentC);

				localizacao_obs.push_back((int)x);
				localizacao_obs.push_back((int)x + 100);
			}
			else if (tipo == 2) { // plataforma pequena
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/parede11.png");
				p->geraPlataforma(150, 100, x, 610);
				listaEntidades.Incluir(p, &gerentC);

				localizacao_obs.push_back((int)x);
			}
			else if (tipo == 3) { // plataforma alta
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/parede61.png");
				p->geraPlataforma(200, 300, x, 560);
				listaEntidades.Incluir(p, &gerentC);

				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/parede21.png");
				p2->geraPlataforma(100, 200, x + 200, 460);
				listaEntidades.Incluir(p2, &gerentC);

				localizacao_obs.push_back((int)x);
				localizacao_obs.push_back((int)x + 100);
				localizacao_obs.push_back((int)x + 200);
			}
			else if (tipo == 4) { // plataforma em T
				Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3, "assets/parede41.png");
				p->geraPlataforma(200, 100, x, 560);
				listaEntidades.Incluir(p, &gerentC);

				Obstaculos::Plataforma* p2 = new Obstaculos::Plataforma(3, "assets/pedra11.png");
				p2->geraPlataforma(100, 100, x - 50, 520);

				Obstaculos::Plataforma* p3 = new Obstaculos::Plataforma(3, "assets/pedra21.png");
				p3->geraPlataforma(100, 100, x + 50, 520);

				Obstaculos::Plataforma* p4 = new Obstaculos::Plataforma(3, "assets/pedra31.png");
				p4->geraPlataforma(100, 100, x + 150, 520);

				listaEntidades.Incluir(p2, &gerentC);
				listaEntidades.Incluir(p3, &gerentC);
				listaEntidades.Incluir(p4, &gerentC);

				localizacao_obs.push_back((int)x);
			}
		}
	}

	void Fase::executar() {
		bool apareceu1 = false;
		bool apareceu2 = false;
		int cont1 = 0;
		int cont2 = 0;
		bool morreu = false;
		bool morreu2 = false;
		int pos_morto = -1;

		if (qnt_jogadores > 0) {
			if (gerentC.getJogador2() != nullptr) {
				qnt_jogadores = 2;
			}
			if (qnt_jogadores_ini == -1) {

				qnt_jogadores_ini = qnt_jogadores;


			}

			pGGrafico->arrumaCamera(checaZona());

			pGGrafico->clear();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				Pause = true;

				pMenu->restartTime();
				while (Pause) {
					pMenu->Pause();
					pGGrafico->clear();
				}

			}
			pGGrafico->desenha();
			listaEntidades.Percorrer(&gerentC);

			pos_morto = listaEntidades.VerificMortos();

			if (pos_morto != -1) {
				listaEntidades.matarEntidadePos(pos_morto, &gerentC);
			}


			if (Heroi1.getVidas() <= 0) {
				Heroi1.setMorrendo(true);
				if (Heroi1.getCont() % 8 == 0) {
					cont1++;
					if (morreu == true) {
						listaEntidades.MatarEntidade(&Heroi1, &gerentC);
						qnt_jogadores--;
						apareceu1 = true;
					}
				}
			}

			if (gerentC.getJogador2() != nullptr && apareceu2 == false) {
				if (Heroi2.getVidas() <= 0) {
					listaEntidades.MatarEntidade(&Heroi2, &gerentC);
					qnt_jogadores--;
					apareceu2 = true;
				}
			}
		}

		else if (qnt_jogadores == 0) {

			if (Heroi1.getVidas() <= 0) {

				if (qnt_jogadores_ini ==1) {
					setaTextos(2);
					Pause = true;
					pGGrafico->clear();
					while (Pause) {
						desenhaTexto(pGGrafico);
						pGGrafico->window.display();
						pGGrafico->clear();
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
							Pause = false;
						}
					}
					Pause = true;
					qnt_jogadores = -1;
					pGGrafico->clear();
					textos.clear();
				}

				else if (qnt_jogadores_ini ==2 && Heroi2.getVidas()<=0) {

					setaTextos(3);
					Pause = true;
					pGGrafico->clear();
					while (Pause) {
						desenhaTexto(pGGrafico);
						pGGrafico->window.display();
						pGGrafico->clear();
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
							Pause = false;
						}
					}
					Pause = true;
					qnt_jogadores = -1;
					pGGrafico->clear();
					textos.clear();

				}

			}
		}
		else if(qnt_jogadores==-1)
		{
			digitarNome();
			pGGrafico->window.close();
		}


		pGGrafico->mostrar();
			
	}
	
	void Fase::digitarNome() {
		Clock t;
		t.restart();
		setaTextos(6);
		Pause = true;
		std::string input = "";
		sf::Event event;
		vector <Text> digitar;

		Text textoInput;
		textoInput.setFont(fonte);
		textoInput.setCharacterSize(30);
		textoInput.setFillColor(sf::Color::White);
		textoInput.setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f);

		desenhaTexto(pGGrafico);

		while (Pause) {
			
			while (pGGrafico->window.pollEvent(event)) {
				float tempo = t.getElapsedTime().asSeconds();

				if (event.type == sf::Event::TextEntered) {

					// Verifica se o caractere está entre A-Z ou a-z (ASCII)
					if ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') ||
						(event.text.unicode >= 'a' && event.text.unicode <= 'z')) {

						// Adiciona o caractere ao input
						input += static_cast<char>(event.text.unicode);
					}
					else if (event.text.unicode == 8 && input.length() > 0) {
						input.pop_back();
					}

					textoInput.setString(input);
					t.restart();
					pGGrafico->window.display();
					// Se apertar Enter, finaliza o input
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {

					Pause = false;
					break;

				}

				// Limpa a tela, desenha os textos e exibe
				pGGrafico->clear();
				desenhaTexto(pGGrafico);  // Mostra a mensagem inicial
				pGGrafico->window.draw(textoInput); // Mostra o nome digitado
				pGGrafico->window.display();
				t.restart();

			}
		}
		pMenu->salvaScore(input, Heroi1.getPontos());

		if (qnt_jogadores_ini == 2) {
			t.restart();
			Pause = true;
			input = "";
			setaTextos(7);
			textoInput.setString("");

			desenhaTexto(pGGrafico);

			Text textoInput2;
			textoInput2.setFont(fonte);
			textoInput2.setCharacterSize(30);
			textoInput2.setFillColor(sf::Color::White);
			textoInput2.setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f);

			while (Pause) {

				while (pGGrafico->window.pollEvent(event)) {
					float tempo = t.getElapsedTime().asSeconds();

					if (event.type == sf::Event::TextEntered) {

						// Verifica se o caractere está entre A-Z ou a-z (ASCII)
						if ((event.text.unicode >= 'A' && event.text.unicode <= 'Z') ||
							(event.text.unicode >= 'a' && event.text.unicode <= 'z')) {

							// Adiciona o caractere ao input
							input += static_cast<char>(event.text.unicode);
						}
						else if (event.text.unicode == 8 && input.length() > 0) {
							input.pop_back();
						}

						textoInput2.setString(input);
						t.restart();
						pGGrafico->window.display();
						// Se apertar Enter, finaliza o input
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {

						Pause = false;
						break;

					}

					// Limpa a tela, desenha os textos e exibe
					pGGrafico->clear();
					desenhaTexto(pGGrafico);  // Mostra a mensagem inicial
					pGGrafico->window.draw(textoInput2); // Mostra o nome digitado
					pGGrafico->window.display();
					t.restart();

				}
			}
			pMenu->salvaScore(input, Heroi2.getPontos());

		}

	}

	void Fase::salvaFase() {
		vector<Entidade*> vec = listaEntidades.returnVec();

		json jsonData;//Json pra juntar tudo
		int i;
		jsonData["Fase"] = num_fase;
		jsonData["zona"] = zona_atual;
		jsonData["jogadores"] = qnt_jogadores;

		jsonData["entidades"] = json::array();
		for (i = 0; i < vec.size(); i++) {
			if (vec[i] != nullptr) {
				jsonData["entidades"].push_back(vec[i]->salvar());
			}
		}

		std::ofstream outFile("Save/fase.json");
		outFile << jsonData.dump(4);  // "4" para indentação legível
		outFile.close();  // Fecha o arquivo

		std::cout << "Fase salva com sucesso!" << std::endl;

	}

	void Fase::setaTextos(int text) {
		limpaTextos();
		pGGrafico->clear();  // Limpa a tela antes de desenhar
		textos.clear();   // Garante que apenas os textos atuais serão desenhados
		nomes.clear();
		if (text == 1) {
			nomes.push_back("Próxima fase, aperte X para continuar...");
			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual*1800.0f)+200.0f, 300.0f + (float)i * 60.0f);
			}
		}
		else if (text == 2) {
			nomes.push_back("Você morreu...");
			nomes.push_back("Quantidade de pontos:");
			nomes.push_back(std::to_string(Heroi1.getPontos()));
			nomes.push_back("aperte x para sair");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f + (float)i * 60.0f);
			}
		}
		else if (text == 3) {
			nomes.push_back("Vocês morreram...");
			nomes.push_back("Quantidade de pontos:");
			nomes.push_back("Jogador1: " + std::to_string(Heroi1.getPontos()));
			nomes.push_back("Jogador2: " + std::to_string(Heroi2.getPontos()));
			nomes.push_back("aperte x para sair");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f + i * 60.0f);
			}
		}
		else if (text == 4) {
			nomes.push_back("Você ganhou o jogo");
			nomes.push_back("Quantidade de pontos:");
			nomes.push_back(std::to_string(Heroi1.getPontos()));
			nomes.push_back("aperte x para sair");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f + (float)i * 60.0f);
			}
		}
		else if (text == 5) {
			nomes.push_back("Vocês ganharam o jogo");
			nomes.push_back("Quantidade de pontos:");
			nomes.push_back(std::to_string(Heroi1.getPontos()));
			nomes.push_back(std::to_string(Heroi2.getPontos()));
			nomes.push_back("aperte x para sair");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 300.0f + (float)i * 60.0f);
			}
		}
		else if (text == 6) {
			nomes.push_back("Jogador 1, digite o seu nome:");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 200);
			}
		}
		else if (text == 7) {
			nomes.push_back("Jogador 2, digite o seu nome:");

			textos.resize(nomes.size()); // Garante que textos tenha o mesmo número de elementos que nomes

			for (int i = 0; i < nomes.size(); i++) {
				textos[i].setFont(fonte);
				textos[i].setString(nomes[i]);
				textos[i].setCharacterSize(30);
				textos[i].setFillColor(sf::Color::White);
				textos[i].setPosition(((float)zona_atual * 1800.0f) + 200.0f, 200);
			}
		}
	}

}