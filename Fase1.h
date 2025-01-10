#pragma once
#include "Slime.h"
#include "Slime2.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"
#include "Rato.h"

class Fase1
{
private:
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Slime2 Slime2;
	Plataforma plat;
	Espinho esp;
	SlimeMau obst_facil;
	Rato ratinho;

public:
	Fase1();
	~Fase1();
	void executar();
};
