#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Jogo::Jogo() :
fase1()
{	
}

Jogo::~Jogo(){
}

void Jogo::executar(){
	fase1.executar();
}