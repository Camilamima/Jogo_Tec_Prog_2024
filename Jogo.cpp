#include "Jogo.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
Jogo::Jogo()
{
}

Jogo::~Jogo()
{
}

void Jogo::executar()
{
	fase1.executar();
}