#include "Plataforma.h"  

Plataforma::Plataforma(int id, const char* png) :
Obstaculo(id, png), x(0), y(860)
{
	altura = 0;
	largura = 0;
	pJogador = nullptr;
	atrito = 1.0f;
	impede = true;
	setCoordenadas(x, y);
	setCorpo(1800.0, 40.0);
}
Plataforma::~Plataforma() {
}
void Plataforma::geraPlataforma(float alt, float lar,float x, float y){
	altura = alt;
	largura = lar;
	setCoordenadas(x, y);
	setCorpo(largura, altura);
}
void Plataforma::executar() {
	pGGrafico->desenha(corpo);
	obstacular(getpJogador());
}

void Plataforma::obstacular(Slime* jogador) {

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

			jogador->setVelocidae((velX * atrito), velY);
		}
	}
	else
	{
		float velY = jogador->getVelocidadeY();
		jogador->setVelocidae(VX, velY);
	}
}

