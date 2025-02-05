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
        ladoAtaque = 0;
        vidas=10;
        seguindo = 0;
        atacando = 0;
        xIni = 0;
        yIni = 0;
        setVelocidae(150, 0);
        setCoordenadas(600, 0);
        chao = 600;
        relogio.restart();
        setCorpo(177.27, 100);
        setSoCorpo(177.27, 100);
        setMaldade(2);
        cont = 0;
        val = 0;
    }

    Cachorro::~Cachorro() {

    }

    const bool Cachorro::deveSeguir(Personagens::Slime* jog) const {
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

        // Verificando se a distância está dentro do raio de 130
        return distancia <= 400;
    }

    void Cachorro::seguir(float x) {
        float xC = corpo.getPosition().x + (corpo.getSize().x / 2);
        if (seguindo && !atacando) {
            if (xC != x) {
                //direita
                if (xC <= x + 150 && xC >= x) {
                    atacar(1);
                    atacando = 1;
                    seguindo = 0;
                    turnos.restart();
                    xIni = corpo.getPosition().x;
                    yIni = corpo.getPosition().y;
                }
                //esquerda
                else if (xC >= x - 150 && xC <= x) {
                    atacar(2);
                    atacando = 1;
                    seguindo = 0;
                    turnos.restart();
                    xIni = corpo.getPosition().x;
                    yIni = corpo.getPosition().y;
                }
                //esquerda
                else if (xC - x > 0) {
                    if (moviE) {
                        if (cont % 5 == 0) {
                            animacao(2, 8);//2 eh esquerda e 
                            val--;
                        }
                        mover(atualizaDelta() * -velocidadeX);
                    }
                }
                //direita
                else {
                    if (moviD) {
                        mover(atualizaDelta() * velocidadeX);
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

        xIni = corpo.getPosition().x;
        yIni = corpo.getPosition().y;

        //esquerda
        if (d == 1) {
            ladoAtaque = 1;
            setTamanhoCorpo(corpo.getSize().x + 50, corpo.getSize().y);
                sprite.loadFromFile("assets/espadachim/Attack1 esquerda.png");
                corpo.setTexture(&sprite);
                corpo.setTextureRect(IntRect(20+(200 * 1), 59, 160, 71));
				//setSoCorpo(160.0 + 50.0, 130.0);
            //mover(-50);
            pGGrafico->desenha(corpo);
        }
        //direita
        else if (d == 2) {
            //animacao(3, 4);
            setTamanhoCorpo(corpo.getSize().x + 50, corpo.getSize().y);
            sprite.loadFromFile("assets/espadachim/Attack1.png");
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(20 + (200*2), 59, 160, 71));
            pGGrafico->desenha(corpo);
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
            //setSoCorpo(227.27, 100);
        }
        else if (num == 2) {//vai p direita
            sprite.loadFromFile("assets/espadachim/Run esquerda.png");
            corpo.setTexture(&sprite);
            corpo.setTextureRect(IntRect(65 + (200 * (val)), 75, 70, 55));
            //setSoCorpo(227.27, 100);
        }

    }

    void Cachorro::executar() {

        cont++;

        
        if (verificaVida()) {

            if (atacando) {
                if (turnos.getElapsedTime().asSeconds() >= 1.5) {
                    if (ladoAtaque) {
                        xIni = xIni + 50;
                        ladoAtaque = 0;
                    }
                    setCoordenadas(xIni, yIni);
                    setCorpo(100, 100);
                    atacando = 0;
                    turnos.restart();
  
                }
            }
            if (!atacando && !seguindo) {
                sprite.loadFromFile("assets/espadachim/Attack1.png");
                corpo.setTexture(&sprite);
                corpo.setTextureRect(IntRect(65, 59, 70, 71));
            }
            if (!noChao) {
                mover(0);
            }
            pGGrafico->desenha(corpo);
        }
    }
}