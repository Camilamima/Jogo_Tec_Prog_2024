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
        static const float gravidade;
        Clock relogio;

    public:
        Personagem(int id, const char* png);
        ~Personagem();
        bool verificaVida() { return vidas > 0; }
        virtual void mover(float aux) = 0;
        virtual void executar() = 0;
        void setVidas(int vid);
        int getVidas() { return vidas; }
        void operator--();
        void operator*=(int dano) { vidas -= dano; }
        void setVelocidae(float vX, float vY);
        void setVelocidadeY(float y) { velocidadeY = y; }
        void setMoviD(bool a) { moviD = a; }
        void setMoviE(bool a) { moviE = a; }
        float getVelocidadeX();
        float getVelocidadeY();
        float atualizaDelta();
        void setChao(float a) { chao = a; }
        void setNoChao(float Xao) { noChao = Xao; }
    };

}