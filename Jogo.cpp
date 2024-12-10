#include "Jogo.h"

using namespace sf;

Jogo::Jogo():
jogador1(-1,-1),
gerent()
{
    jogador1.setGerenciador(&gerent);
}

Jogo::~Jogo(){
}

void Jogo::executar(){
        
    while (gerent.estaAberta()) { 
        jogador1.executar();
    }
	
}