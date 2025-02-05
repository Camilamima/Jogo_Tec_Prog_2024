#pragma once
#include <stdio.h>
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"

class Jogo
{
private:
	//Fases::Fase1 fase1;
	Fases::Fase1 *fase1;
	Fases::Fase2 *fase2;
	Gerenciadores::Gerenciado_Grafico gerent;
	int fase;
	

public:
	Jogo();
	~Jogo();
	void lerFase();
	void executar();
};

