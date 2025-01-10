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
	Entidades::Personagens::Slime Slime1;
	Entidades::Personagens::Slime2 Slime2;
	Entidades::Obstaculos::Plataforma plat;
	Entidades::Obstaculos::Espinho esp;
	Entidades::Obstaculos::SlimeMau obst_facil;
	Entidades::Personagens::Rato ratinho;

public:
	Fase1();
	~Fase1();
	void executar();
};
