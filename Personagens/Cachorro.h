#pragma once
#include "Inimigo.h"
#include <ctime>
#include "Personagem.h"
#include "Slime.h"

namespace Personagens {
    class Cachorro : public Inimigo
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
        Cachorro(int id, const char* png = "assets/espadachim/Attack1.png");
        ~Cachorro();
        void executar();
        void deveSeguir(Slime* jog);
        void seguir(float x);
        void atacar(int d);
        void setSeguindo(bool i) { seguindo = i; }
        json salvar() const;
        void setYeXini(float x,float y) {
            xIni = x;
            yIni = y;
        }
		void setLadoAtacado(bool lado) { ladoAtaque = lado; }
		void setTempo(float t) { tempo = t; }
		void setAtacando(bool a) { atacando = a; }
        void animacao(int num, int limite);//eh virtual
    };
}
