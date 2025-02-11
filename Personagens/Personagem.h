#include "../Entidades/Entidade.h"
#include <ctime>
#pragma once

namespace Entidades {
    namespace Personagens {

        class Personagem : public Entidade {
        protected:
            int vidas;
            bool vivo;
            bool moviD;
            bool moviE;
            float velocidadeX;
            int cont;
            int val;

        public:
            Personagem(int id, const char* png);//
            ~Personagem();//
            const bool verificaVida() const { return vidas > 0; }//
            virtual void mover(float aux) = 0;//
            virtual void executar() = 0;//
            void setVidas(int vid);//
            const int getVidas() const { return vidas; }//
            void operator--();//
            void operator-=(int dano) { vidas -= dano; }//
            void setVelocidae(float vX, float vY);//
            void setVelocidadeX(float velx) {
                velocidadeX = velx;
            }//
            void setVelocidadeY(float y) { velocidadeY = y; }//
            void setMoviD(bool a) { moviD = a; }//
            void setMoviE(bool a) { moviE = a; }//
            const float getVelocidadeX() const;//
            const float getVelocidadeY() const;//
            static float atualizaDelta(Clock relogio);//
            virtual void animacao(int num, int limite) = 0;
            virtual json salvar() const = 0;
        };

    }
}