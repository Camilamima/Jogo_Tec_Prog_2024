#include "Obstaculo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Entidades::Obstaculos::Obstaculo::Obstaculo(int id, const char* png) :
	Entidade(id, png),
	atrito(1.0f),
	pJogador(nullptr),
	pJogador2(nullptr)
{
	danoso = false;
}

Entidades::Obstaculos::Obstaculo::~Obstaculo()
{
}
