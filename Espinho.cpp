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
	setCoordenadas(1500, 775);
	setCorpo(80.0, 80.0);

	time_t tempo;//usei isso da prova de POO s73 1 sem23 do prof Simão

	srand((unsigned)time(&tempo));//isso tbm
	num_espinhos = (int)(rand() % 10);//isso tbm

}

Espinho::~Espinho() {
}

void Espinho::executar() {
	pGGrafico->desenha(corpo);
	obstacular(pJogador);
}

void Espinho::obstacular(Slime* jogador) {

	RectangleShape teste;
	Vector2f pos;
	pos.x = corpo.getPosition().x + corpo.getSize().x;
	pos.y = corpo.getPosition().y + corpo.getSize().y;
	teste = jogador->getCorpo();
	if ((teste.getPosition().x <= pos.x) && (teste.getPosition().x >= corpo.getPosition().x))
	{

		if ((teste.getPosition().y <= pos.y) && (teste.getPosition().y >= corpo.getPosition().y))
		{
			if (danoso)
			{
				std::cout << "Num do espinho: " << num_espinhos << std::endl;
				std::cout << "Vidas antes: " << jogador->getVidas() << std::endl;
				jogador->operator*=(num_espinhos);
				std::cout << "Vidas depois: " << jogador->getVidas() << std::endl;
			}
		}
	}
}