#include "Espinho.h"
#include "time.h"
#include "stdlib.h"
#include <iostream>

Espinho::Espinho(int id, const char* png) :
Obstaculo(id, png)
{
	pJogador = nullptr;
	atrito = 1.0f;
	danoso = true;
	setCoordenadas(1500, 800);
	setCorpo(100.0, 100.0);
	timer = 0;

	time_t tempo;//usei isso da prova de POO s73 1 sem23 do prof Simão

	srand((unsigned)time(&tempo));//isso tbm
	num_espinhos = (int)(rand() % 10);//isso tbm


}

Espinho::~Espinho() {
}

void Espinho::executar() {
	pGGrafico->desenha(corpo);
}

void Espinho::obstacular(Slime* jogador) {

	if (timer % 50 == 0) {
		jogador->operator*=(num_espinhos);
		std::cout << "Vidas depois: " << jogador->getVidas() << std::endl;
	}
	timer++;
}