#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"
#include "Rato.h"
#include "Gerenciador_Colisoes.h"

class Jogo
{
private:
	Gerenciadores::Gerenciador_Colisoes gerentC;
	Gerenciado_Grafico gerent;
	Slime Slime1;
	//Plataforma plat;
	Plataforma plat2;
	Plataforma plat3;
	Espinho esp;
	SlimeMau obst_facil;
	Rato ratinho;
	
public:
	Jogo();
	~Jogo();
	void executar();
};

