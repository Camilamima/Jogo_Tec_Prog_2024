#pragma once
#include "Jogador.h"
#include <stdio.h>
class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Jogador jogador1;
public:
	Jogo();
	~Jogo();
	void executar();
};

