#pragma once
#include <stdio.h>
#include "Fases/Fase1.h"

class Jogo
{
private:
	Fases::Fase1 fase1;

public:
	Jogo();
	~Jogo();
	void executar();
};

