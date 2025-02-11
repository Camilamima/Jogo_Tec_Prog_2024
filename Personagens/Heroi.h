#pragma once
#include <algorithm>
#include "Personagem.h"

#define VX 500
namespace Entidades {
    namespace Personagens {
        class Inimigo;
        class Heroi : public Personagem {
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
            bool atordoado;
            Clock turno;

        public:
            Heroi(int id, const char* png = ""); // pngegg.png
            ~Heroi();
            void mover(float aux);
            void atacarIni(Inimigo* ini);
            void executar();
            void setAtordoado(const bool at) {
                atordoado = at;
            }

            void pular(float imp);
            void setPonto(int ponto) {
                pontos = ponto;
            }
            void setImpulso(float i) { impulso = i; }
            void setAtacando(float a) { atacando = a; }
            void setAtacado(float x, float y) { atacado = x; ladoAtacado = y; }
            const bool getAtacado() const { return atacado; }
            int getCont()const { return cont; }
            void setMorrendo(bool a) { morrendo = a; }
            bool const getLadoAtacado() const { return ladoAtacado; }
            void processaEvento();//generalizado
            void animacao(int num, int limite);//eh virtual
            const int getPontos() const {
                return pontos;
            }
            json salvar() const;
        };

    }
}