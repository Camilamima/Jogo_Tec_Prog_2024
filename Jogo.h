#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"
#include "Rato.h"
#include "Cachorro.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

class Jogo
{
private:
	Gerenciadores::Gerenciador_Colisoes gerentC;
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Slime Slime2;
	Plataforma plat;
	Plataforma plat2;
	Plataforma plat3;
	//Espinho esp;
	//SlimeMau obst_facil;
	Personagens::Cachorro doguinho;
	Rato ratinho;
	Listas::ListaEntidade listaEntidades;

public:
	Jogo();
	~Jogo();
	void executar();
};

