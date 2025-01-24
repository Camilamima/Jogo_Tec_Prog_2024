#include "Cachorro.h"
#include "Slime.h"
#include <cmath>

using namespace Personagens;
using namespace std;

Cachorro::Cachorro(int id,const char* png):
	Inimigo(id, png)
{
    seguindo = 0;
    atacando = 0;
    xIni = 0;
    yIni = 0;
	setVelocidae(150, 0);
	setCoordenadas(600, 0);
    chao = 600;
	relogio.restart();
	setCorpo(100, 100);
	setMaldade(2);
}

Cachorro::~Cachorro() {

}

const bool Cachorro::deveSeguir(Slime* jog) const {
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
    if (seguindo && !atacando){
        if (xC != x){
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
                    mover(atualizaDelta() * -velocidadeX);
                }
            }
            //direita
            else {
                if (moviD) {
                    mover(atualizaDelta() * velocidadeX);
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

    setTamanhoCorpo(corpo.getSize().x + 50, corpo.getSize().y);
    mover(-50);
    pGGrafico->desenha(corpo);
    }
    //direita
    else if(d == 2){

        setTamanhoCorpo(corpo.getSize().x + 50, corpo.getSize().y);
        pGGrafico->desenha(corpo);
    }
}

void Cachorro::executar(){
    if (verificaVida()){
        if (atacando) {
            if (turnos.getElapsedTime().asSeconds() >= 1.5) {
                atacando = 0;
                setCoordenadas(xIni, yIni);
                setTamanhoCorpo(100, 100);
                turnos.restart();
            }
        }
        if (!noChao) {
            mover(0);
        }
        pGGrafico->desenha(corpo);
    }
}