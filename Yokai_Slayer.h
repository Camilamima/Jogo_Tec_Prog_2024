#pragma once
#include <stdio.h>
#include "Fases/Floresta_Profunda.h"
#include "Fases/Caverna_Obscura.h"
#include "Menu.h"

class Yokai_Slayer: public Texto
{
private:
	Menu menu;
	Fases::Floresta_Profunda *Floresta_Profunda;
	Fases::Caverna_Obscura *Caverna_Obscura;
	Gerenciadores::Gerenciado_Grafico gerent;
	int fase;

public:
	Yokai_Slayer();
	~Yokai_Slayer();
	void setaTextos(int text);
	void lerFase();
	void executar();
};




