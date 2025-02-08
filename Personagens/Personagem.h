#include "../Entidade.h"
#include <ctime>
#pragma once


namespace Personagens {

    class Personagem : public Entidade {
    protected:
        int vidas;
        bool vivo;
        float chao;
        bool noChao;
        bool moviD;
        bool moviE;
        float velocidadeY;
        float velocidadeX;

    public:
        Personagem(int id, const char* png);
        ~Personagem();
        const bool verificaVida() const{ return vidas > 0; }
        virtual void mover(float aux) = 0;
        virtual void executar() = 0;
        void setVidas(int vid);
        int getVidas() const{ return vidas; }
        void operator--();
        void operator*=(int dano) { vidas -= dano; }
        void setVelocidae(float vX, float vY);
        void setVelocidadeY(float y) { velocidadeY = y; }
        void setMoviD(bool a) { moviD = a; }
        void setMoviE(bool a) { moviE = a; }
        float getVelocidadeX();
        float getVelocidadeY();
        static float atualizaDelta(Clock relogio);
        const bool getnoChao() const {return noChao;}
        void setChao(float a) { chao = a; }
        void setNoChao(float Xao) { noChao = Xao; }
        virtual json salvar() const = 0;
    };

}