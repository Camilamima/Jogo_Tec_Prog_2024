#include "SlimeMau.h"

SlimeMau::SlimeMau(int id, const char* png) :
	Obstaculo(id, png)
{	
	pJogador = nullptr;
	setCoordenadas(1200, 775);
	setCorpo(80.0, 80.00);
	atrasador = atrito * 0.91;
}

SlimeMau::~SlimeMau() {
}

void SlimeMau::executar() {
	pGGrafico->desenha(corpo);
	obstacular(pJogador);
}

void SlimeMau::obstacular(Slime* jogador) {

	RectangleShape teste;
	Vector2f pos;
	pos.x = corpo.getPosition().x + corpo.getSize().x;
	pos.y = corpo.getPosition().y + corpo.getSize().y;
	teste = jogador->getCorpo();

	if ((teste.getPosition().x <= pos.x) && (teste.getPosition().x >= corpo.getPosition().x))
	{

		if ((teste.getPosition().y <= pos.y) && (teste.getPosition().y >= corpo.getPosition().y))
		{
				float velX = jogador->getVelocidadeX();
				float velY = jogador->getVelocidadeY();

				jogador->setVelocidae((velX * atrasador), velY);

		}
	}
	else
	{
		float velY = jogador->getVelocidadeY();

		jogador->setVelocidae(VX, velY);		
	}

}