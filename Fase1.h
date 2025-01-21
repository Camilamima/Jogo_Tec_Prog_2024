#pragma once
#include "Slime.h"
#include <stdio.h>
#include "Plataforma.h"
#include "Espinho.h"
#include "SlimeMau.h"
#include "Rato.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

class Fase1 {

private:
	Gerenciadores::Gerenciador_Colisoes gerentC;
	Gerenciado_Grafico gerent;
	Slime Slime1;
	Slime Slime2;
	Plataforma plat;
	Plataforma plat2;
	Plataforma plat3;
	Espinho esp;
	SlimeMau obst_facil;
	Rato ratinho;
	Listas::ListaEntidade listaEntidades;

public:
	Fase1();
	~Fase1();
	void executar();
};
