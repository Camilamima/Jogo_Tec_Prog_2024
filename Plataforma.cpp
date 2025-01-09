#include "Plataforma.h"

Plataforma::Plataforma(int id, const char* png) :
Obstaculo(id, png)
{
	altura = 0;
	largura = 0;
	pJogador = nullptr;
	atrito = 1.0f;
	impede = true;

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
	obstacular(getpJogador(), atrito);
}

