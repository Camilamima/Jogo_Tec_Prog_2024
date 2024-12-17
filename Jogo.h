#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"

class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Plataforma plat;
	Espinho esp;
	SlimeMau obst_facil;
public:
	Jogo();
	~Jogo();
	void executar();
};

