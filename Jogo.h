#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"

class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Plataforma plat;
public:
	Jogo();
	~Jogo();
	void executar();
};

