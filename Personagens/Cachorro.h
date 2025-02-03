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
    public:
        Cachorro(int id, const char* png = "");
        ~Cachorro();
        void executar();
        const bool deveSeguir(Slime* jog) const;
        void seguir(float x);
        void atacar(int d);
        void setSeguindo(bool i) { seguindo = i; }
    };
}
