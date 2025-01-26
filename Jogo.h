#pragma once
#include <stdio.h>
#include "Fase1.h"

class Jogo
{
private:
	Fase1 fase1;

public:
	Jogo();
	~Jogo();
	void executar();
};

