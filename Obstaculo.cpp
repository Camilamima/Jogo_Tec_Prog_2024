#include "Obstaculo.h"

Obstaculo::Obstaculo(int id,const char* png) : Entidade(id, png)
{
	danoso = false;
}

Obstaculo::~Obstaculo()
{
}