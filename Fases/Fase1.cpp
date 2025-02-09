#include "Fase1.h"
#include <iostream>
#include <ctime>

namespace Fases {

    Fase1::Fase1() :
        Fase(),
        num_dificil(-1),
        obsFacil(-1)
    {
    }

    Fase1::Fase1(const json& dados, Gerenciadores::Gerenciado_Grafico* gC) :
        Fase(),
        num_dificil(-1),
        obsFacil(-1)
    {
        num_fase = 1;
        cout << "cheguei1" << endl;
        setGerenciador(gC);
        gerent->BackGFloresta(1);
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
                Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3,png);
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
            else if (id == 7) {
                Personagens::Cachorro* c = new Personagens::Cachorro(7);
                listaEntidades.Incluir(c, &gerentC);
                c->setCoordenadas(x, y);
                c->setCorpo(100, 100);
                c->setChao(entidade["chao"]);
                c->setVidas(entidade["vidas"]);
                c->setNoChao(entidade["noChao"]);
                c->setSeguindo(entidade["seguindo"]);
                c->setTempo(entidade["turnos"]);
                c->setAtacando(entidade["atacando"]);
                c->setChao(entidade["chao"]);
                c->setYeXini(entidade["xIni"], entidade["yIni"]);
            }
            else if (id == 11) {
                Obstaculos::SlimeMau* M = new Obstaculos::SlimeMau(11);
                M->setCoordenadas(x, y);
                M->setCorpo(entidade["largura"], entidade["altura"]);
                listaEntidades.Incluir(M, &gerentC);
            }
			else if (id == 9) {
				Obstaculos::Espinho* e = new Obstaculos::Espinho(9);
				e->setCoordenadas(x, y);
                e->setCorpo(100, 70);
				e->setEspinhos(entidade["num_espinhos"]);
				listaEntidades.Incluir(e, &gerentC);
            }
        }


        listaEntidades.Incluir(&Slime1, &gerentC);
        if (qnt_jogadores == 2) {
            listaEntidades.Incluir(&Slime2, &gerentC);
        }

        listaEntidades.setGG(gerent);
    }


    Fase1::~Fase1() {
    }

    void Fase1::inicializa() {
        gerent->BackGFloresta(1);
        num_fase = 1;
        obsFacil = -1;
        geraPlataformaFase();
        geraChao();
        //geraEspinho();
        geraInimigos();
        

        if (qnt_jogadores == 1) {
            std::cout << " Selecionado 1 jogador! " << std::endl;
            gerentC.setJogadores(&Slime1, nullptr);
            listaEntidades.Incluir(&Slime1, &gerentC);
        }
        if (qnt_jogadores == 2) {
            std::cout << " Selecionado 2 jogadores! " << std::endl;
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
        ladoE.geraPlataforma(900, 40, -40, 0);
        chao.geraPlataforma(40, (float)tamanho_fase, 0, 900);
    }

    void Fase1::geraChao() {
        int numeros[36] = { 0 };
        time_t tempo;
        srand((unsigned)time(&tempo));
        obsFacil = (int)((rand() % 13) + 5);

        for (int k = obsFacil; k > 0; k--) {
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
                Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3,"assets/Tiles.png");
                p->geraPlataforma(140, 400, (float)i * 400, 760);
                listaEntidades.Incluir(p, &gerentC);
            }
            else {
                Obstaculos::SlimeMau* M = new Obstaculos::SlimeMau(11);
                M->setCoordenadas((float)i * 400, 800);
                M->setCorpo(400, 100);
                listaEntidades.Incluir(M, &gerentC);
                for (int k = 0; k <= 4; k++) {
                    localizacao_obs.push_back((k * 100) + i * 400);
                }
            }
        }
    }

    void Fase1::geraInimigos() {
        int numeros[144] = { 0 };
        time_t tempo;
        srand((unsigned)time(&tempo));
        num_facil = (int)((rand() % 3) + 5);
        num_dificil = (int)((rand() % 3) + 3);
        int posicao = 0;

        for (int k = num_facil; k > 0; k--) {
            posicao = (rand() % 142) + 1;
            while ((numeros[posicao] != 0 || posicao % 1800 == 0) || posicao < 3) {
                posicao = (rand() % 142) + 1;
            }
            numeros[posicao] = 1;
        }

        for (int k = num_dificil; k > 0; k--) {
            posicao = (rand() % 142) + 1;
            while (((numeros[posicao] != 0 || posicao % 1800 == 0) || posicao < 6) || numeros[posicao] == 1) {
                posicao = (rand() % 142) + 1;
            }
            numeros[posicao] = 2;
        }

        for (int i = 0; i < 144; i++) {
            if (numeros[i] == 1) {
                Personagens::Rato* r = new Personagens::Rato(4);
                r->setCoordenadas((float)i * 100, 0);
                r->setCorpo(100, 100);
                listaEntidades.Incluir(r, &gerentC);
            }
            if (numeros[i] == 2) {
                Personagens::Cachorro* c = new Personagens::Cachorro(7);
                c->setCoordenadas((float)i * 100, 0);
                c->setCorpo(100, 100);
                listaEntidades.Incluir(c, &gerentC);
            }
        }
    }
}