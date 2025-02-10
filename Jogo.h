#pragma once
#include <stdio.h>
#include "Fases/Fase1.h"
#include "Fases/Fase2.h"
#include "Menu.h"

class Jogo: public Texto
{
private:
	//Fases::Fase1 fase1;
	Menu menu;
	Fases::Fase1 *fase1;
	Fases::Fase2 *fase2;
	Gerenciadores::Gerenciado_Grafico gerent;
	int fase;

public:
	Jogo();
	~Jogo();
	void setaTextos(int text);
	void lerFase();
	void executar2();
};

