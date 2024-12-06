#include "Jogo.h"

using namespace sf;

Jogo::Jogo() {
}

Jogo::~Jogo(){
}

void Jogo::executar(){
    gerent.geraJogador(875,775);

    while (gerent.estaAberta()) { 
        gerent.processaEvento();
        gerent.atualizaFisica(0);
        gerent.renderiza();        
    }
	
}