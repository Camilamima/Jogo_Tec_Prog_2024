#pragma once
#include "Personagem.h"

#include <algorithm>

#define VX 500

namespace Personagens {

    class Slime : public Personagem {
    private:
        int pontos;
        bool wPress;
        bool aPress;
        bool dPress;
        bool morrendo;
        bool atacado;
        bool atacando;
        bool ladoAtacado;
        float impulso;
        int val;
        int cont;
        Clock turno;

    public:
        Slime(int id, const char* png = ""); // pngegg.png
        ~Slime();
        void mover(float aux);
        void executar();
        void pular(float imp);
        void setAtacando(float a) { atacando = a; }
        void setAtacado(float x, float y) { atacado = x; ladoAtacado = y; }
        bool getAtacado() const { return atacado; }
        int getCont() { return cont; }
		void setMorrendo(bool a) { morrendo = a; }
        void processaEvento();
        void processaEvento2();
        void animacaoJog1(int num, int limite);
        bool animacaoMorte(int cont, int limite);
    };

}
