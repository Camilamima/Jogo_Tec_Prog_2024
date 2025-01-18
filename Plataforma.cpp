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
}

void Plataforma::obstacular(Slime* jogador) {

}

