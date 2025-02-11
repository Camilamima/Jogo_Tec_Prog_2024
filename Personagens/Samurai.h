#pragma once
#include "Inimigo.h"
#include <ctime>
#include "Personagem.h"
#include "Heroi.h"

namespace Personagens {
    class Samurai : public Inimigo
    {
    private: 
        float xIni;
        float yIni;
        Clock turnos;
        bool seguindo;
        bool atacando;
        bool ladoAtaque;
        float tempo;
    public:
        Samurai(int id, const char* png = "assets/espadachim/Attack1.png");
        ~Samurai();
        void executar();
        void deveSeguir(Heroi* jog);
        void seguir(float x);
        void atacar(int d);
        void setSeguindo(bool i) { seguindo = i; }
        json salvar() const;
        void setYeXini(float x1,float y1) {
            xIni = x1;
            yIni = y1;
        }
		void setLadoAtacado(bool lado) { ladoAtaque = lado; }
		void setTempo(float t) { tempo = t; }
		void setAtacando(bool a) { atacando = a; }
        void animacao(int num, int limite);//eh virtual
    };
}
