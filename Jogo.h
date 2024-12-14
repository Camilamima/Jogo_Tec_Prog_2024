#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"

class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Plataforma plat;
	Espinho esp;
public:
	Jogo();
	~Jogo();
	void executar();
};

