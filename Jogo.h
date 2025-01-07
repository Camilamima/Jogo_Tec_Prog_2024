#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"
#include "Rato.h"

class Jogo
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Plataforma plat;
	Espinho esp;
	SlimeMau obst_facil;
	Rato ratinho;
	
public:
	Jogo();
	~Jogo();
	void executar();
};

