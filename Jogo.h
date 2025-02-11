#pragma once
#include <stdio.h>
#include "Fases/Floresta_Profunda.h"
#include "Fases/Caverna_Obscura.h"
#include "Menu.h"

class Jogo: public Texto
{
private:
	//Fases::Floresta_Profunda Floresta_Profunda;
	Menu menu;
	Fases::Floresta_Profunda *Floresta_Profunda;
	Fases::Caverna_Obscura *Caverna_Obscura;
	Gerenciadores::Gerenciado_Grafico gerent;
	int fase;

public:
	Jogo();
	~Jogo();
	void setaTextos(int text);
	void lerFase();
	void executar2();
};

