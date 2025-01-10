#pragma once
#include "Fase1.h"
#include <stdio.h>

class Jogo
{
private:
	Fase1 fase1;
	
public:
	Jogo();
	~Jogo();
	void executar();
};

