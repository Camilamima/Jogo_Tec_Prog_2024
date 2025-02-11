#include "Floresta_Profunda.h"
#include <iostream>
#include <ctime>

namespace Fases {

    Floresta_Profunda::Floresta_Profunda() :
        Fase(),
        num_dificil(-1),
        obsFacil(-1)
    {
    }

    Floresta_Profunda::Floresta_Profunda(const json& dados, Gerenciadores::Gerenciado_Grafico* gC) :
        Fase(),
        num_dificil(-1),
        obsFacil(-1)
    {
        num_fase = 1;
        cout << "cheguei1" << endl;
        setGerenciador(gC);
        pGGrafico->BackGFloresta(1);
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
                Obstaculos::Plataforma* p = new Obstaculos::Plataforma(3,png);
                listaEntidades.Incluir(p, &gerentC);
                p->geraPlataforma(entidade["altura"], entidade["largura"], x, y);
            }
            else if (id == 4) {
                Personagens::Lobo* r = new Personagens::Lobo(4);
                listaEntidades.Incluir(r, &gerentC);
                r->setCoordenadas(x, y);
                r->setCorpo(100, 100);
                r->setDistancia(entidade["distancia_percorrida"]);
                r->setVidas(entidade["vidas"]);
                r->setNoChao(entidade["noChao"]);
            }
            else if (id == 7) {
                Personagens::Samurai* c = new Personagens::Samurai(7);
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
                Obstaculos::Rio* M = new Obstaculos::Rio(11);
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


        listaEntidades.Incluir(&Heroi1, &gerentC);
        if (qnt_jogadores == 2) {
            listaEntidades.Incluir(&Heroi2, &gerentC);
        }

        listaEntidades.setGG(pGGrafico);
    }


    Floresta_Profunda::~Floresta_Profunda() {
        pGGrafico->clear();
    }

    void Floresta_Profunda::inicializa() {
        pGGrafico->BackGFloresta(1);
        num_fase = 1;
        obsFacil = -1;
        geraPlataformaFase();
        geraChao();
        //geraEspinho();
        geraInimigos();
        

        if (qnt_jogadores == 1) {
            std::cout << " Selecionado 1 jogador! " << std::endl;
            gerentC.setJogadores(&Heroi1, nullptr);
            listaEntidades.Incluir(&Heroi1, &gerentC);
        }
        if (qnt_jogadores == 2) {
            std::cout << " Selecionado 2 jogadores! " << std::endl;
            gerentC.setJogadores(&Heroi1, &Heroi2);
            listaEntidades.Incluir(&Heroi1, &gerentC);
            listaEntidades.Incluir(&Heroi2, &gerentC);
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

    void Floresta_Profunda::geraChao() {
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
                Obstaculos::Rio* M = new Obstaculos::Rio(11);
                M->setCoordenadas((float)i * 400, 800);
                M->setCorpo(400, 100);
                listaEntidades.Incluir(M, &gerentC);
                for (int k = 0; k <= 4; k++) {
                    localizacao_obs.push_back((k * 100) + i * 400);
                }
            }
        }
    }

    void Floresta_Profunda::geraInimigos() {
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
                Personagens::Lobo* r = new Personagens::Lobo(4);
                r->setCoordenadas((float)i * 100, 0);
                r->setCorpo(100, 100);
                listaEntidades.Incluir(r, &gerentC);
            }
            if (numeros[i] == 2) {
                Personagens::Samurai* c = new Personagens::Samurai(7);
                c->setCoordenadas((float)i * 100, 0);
                c->setCorpo(100, 100);
                listaEntidades.Incluir(c, &gerentC);
            }
        }
    }
}