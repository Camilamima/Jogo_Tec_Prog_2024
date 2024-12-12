#include "Jogo.h"

using namespace sf;

Jogo::Jogo():
Slime1(-1),
gerent()
{
    Slime1.setGerenciador(&gerent);
}

Jogo::~Jogo(){
}

void Jogo::executar(){
        
    while (gerent.estaAberta()) { 
        Slime1.executar();
    }
	
}