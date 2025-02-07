#include "Cachorro.h"
#include <cmath>

using namespace std;

namespace Personagens {
    Cachorro::Cachorro(int id, const char* png) :
        Inimigo(id, png)
    {
        //sprite.loadFromFile();
        //corpo.setTexture(&sprite);
        corpo.setTextureRect(IntRect(65, 59, 70, 71));

        tempo = 0;
        ladoAtaque = 0;
        vidas=5;
        seguindo = 0;
        atacando = 0;
        xIni = 0;
        yIni = 0;
        setVelocidae(150, 0);
        setCoordenadas(600, 0);
        chao = 600;
        relogio.restart();
        setCorpo(177.27f, 100);
        setSoCorpo(177.27f, 100);
        setMaldade(2);
        cont = 0;
        val = 0;
    }

    Cachorro::~Cachorro() {

    }

    void Cachorro::deveSeguir(Personagens::Slime* jog) {
        RectangleShape aux = jog->getCorpo();
        float x, y, xJog, yJog;
        x = corpo.getPosition().x + (corpo.getSize().x / 2);
        y = corpo.getPosition().y + (corpo.getSize().y / 2);

        xJog = aux.getPosition().x + (aux.getSize().x / 2);
        yJog = aux.getPosition().y + (aux.getSize().y / 2);

        // Calculando a diferença entre as posições (distância entre os pontos)
        float dx = xJog - x;
        float dy = yJog - y;

        // Calculando a distância euclidiana
        float distancia = std::sqrt(dx * dx + dy * dy);

        if (distancia <= 600) {
            seguindo = 1;
            seguir(aux.getPosition().x + (aux.getSize().x / 2));
        }
        else {
            seguindo = 0;
        }

    }

    void Cachorro::seguir(float x) {
        float xC = corpo.getPosition().x + (corpo.getSize().x / 2);
        if (seguindo && !atacando) {
            if (xC != x) {
                //direita
                if (xC <= x + 100 && xC >= x) {
                    xIni = corpo.getPosition().x;
                    yIni = corpo.getPosition().y;

                    atacar(1);
                    atacando = 1;
                    seguindo = 0;
                    turnos.restart();

                }
                //esquerda
                else if (xC >= x - 100 && xC <= x) {
                    xIni = corpo.getPosition().x;
                    yIni = corpo.getPosition().y;

                    atacar(2);
                    atacando = 1;
                    seguindo = 0;
                    turnos.restart();

                }
                //esquerda
                else if (xC - x > 0) {
                    if (moviE) {
                        if (cont % 5 == 0) {
                            animacao(2, 8);//2 eh esquerda e 
                            val--;
                        }
                        mover(atualizaDelta(relogio) * -velocidadeX);
                    }
                }
                //direita
                else {
                    if (moviD) {
                        mover(atualizaDelta(relogio) * velocidadeX);
                        if (cont % 5 == 0) {
                            animacao(1, 8);//1 eh direita 
                            val++;
                        }
                    }
                }
            }
        }
        else if (atacando && !seguindo) {
            //direita
            if (xC <= x + 150 && xC >= x) {
                atacar(1);
            }
            //esquerda
            else if (xC >= x - 150 && xC <= x) {
                atacar(2);
            }
        }
    }

    void Cachorro::atacar(int d) {


        //esquerda
        if (d == 1) {
            if (moviE) {
                ladoAtaque = 1;
                setTamanhoCorpo(corpo.getSize().x + 60.0f, corpo.getSize().y+35.0f);
                corpo.move(-60.0f,-35.0f);
                sprite.loadFromFile("assets/espadachim/Attack1 esquerda.png");
                corpo.setTexture(&sprite);
                corpo.setTextureRect(IntRect(20 + (200 * 1), 59, 160, 71));
                pGGrafico->desenha(corpo);
            }
        }
        //direita
        else if (d == 2) {
            if (moviD) {
                setTamanhoCorpo(corpo.getSize().x + 60.0f, corpo.getSize().y +35.0f);
                corpo.move(0.0f, -35.0f);
                sprite.loadFromFile("assets/espadachim/Attack1.png");
                corpo.setTexture(&sprite);
                corpo.setTextureRect(IntRect(20 + (200 * 2), 59, 160, 71));
                pGGrafico->desenha(corpo);
            }
        }
    }
    
    void Cachorro::animacao(int num, int limite) {
        if (val >= limite) {
            val = 0;
        }

        if (val < 0) {
			val = limite-1;
        }

        if (num == 1) {//vai p direita
            sprite.loadFromFile("assets/espadachim/Run.png");
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(65+(200 * (val)), 75, 70, 55));
        }
        else if (num == 2) {//vai p direita
            sprite.loadFromFile("assets/espadachim/Run esquerda.png");
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(65 + (200 * (val)), 75, 70, 55));
        }
    }

    void Cachorro::executar() {

        cont++;

        tempo = turnos.getElapsedTime().asSeconds();
        
        if (verificaVida()) {

            if (atacando) {
                if (tempo >= 1.5) {
                    atacando = 0;
                    ladoAtaque = 0;
                    setCoordenadas(xIni, yIni);
                    setCorpo(100, 100);
                    turnos.restart();
  
                }
            }
            if (!atacando && !seguindo) {
                if(cont % 5 == 0) {
                    sprite.loadFromFile("assets/espadachim/Attack1.png");
                    corpo.setTexture(&sprite);
                    corpo.setTextureRect(IntRect(65, 59, 70, 71));
                }
            }
            if (!noChao) {
                mover(0);
            }
            pGGrafico->desenha(corpo);
        }
    }

    json Cachorro::salvar() const {
        json entidadeJson;
        entidadeJson["id"] = id;
        entidadeJson["x"] = corpo.getPosition().x;
        entidadeJson["y"] = corpo.getPosition().y;
        entidadeJson["velocidadeY"] = velocidadeY;
        entidadeJson["velocidadeX"] = velocidadeX;
        entidadeJson["noChao"] = noChao;
		entidadeJson["chao"] = chao;    
        entidadeJson["vidas"] = vidas;
        entidadeJson["atacando"] = atacando;
        entidadeJson["cont"] = cont;
        entidadeJson["seguindo"] = seguindo;
        entidadeJson["ladoAtaque"] = ladoAtaque;
        entidadeJson["val"] = val;
        entidadeJson["turnos"] = tempo;
        entidadeJson["xIni"] = xIni;
        entidadeJson["yIni"] = yIni;
        return entidadeJson;
    }
}