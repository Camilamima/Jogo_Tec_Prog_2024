#pragma once
#include "Slime.h"
#include <stdio.h>
class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
public:
	Jogo();
	~Jogo();
	void executar();
};

