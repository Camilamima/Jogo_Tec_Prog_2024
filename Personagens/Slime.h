#pragma once
#include <algorithm>
#include "Personagem.h"

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
        Clock turno;

    public:
        Slime(int id, const char* png = ""); // pngegg.png
        ~Slime();
        void mover(float aux);
        void atacarIni(Personagem* ini);
        void executar();
        void pular(float imp);
		void setImpulso(float i) { impulso = i; }
        void setAtacando(float a) { atacando = a; }
        void setAtacado(float x, float y) { atacado = x; ladoAtacado = y; }
        const bool getAtacado() const { return atacado; }
        int getCont()const { return cont; }
		void setMorrendo(bool a) { morrendo = a; }
        bool const getLadoAtacado() const { return ladoAtacado; }
        void processaEvento();//generalizado
        void animacao(int num, int limite);//eh virtual
        bool animacaoMorte(int cont, int limite);
        json salvar() const;
    };

}
