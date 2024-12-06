#pragma once
#include "Gerenciado_Grafico.h"
#include <stdio.h>
class Jogo
{
private:
	Gerenciado_Grafico gerent;
public:
	Jogo();
	~Jogo();
	void executar();
};

