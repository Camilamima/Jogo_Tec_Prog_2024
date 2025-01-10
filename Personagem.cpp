#include "Personagem.h"
#pragma once

Entidades::Personagens::Personagem::Personagem(int id, const char* png) :
	Entidade(id, png)
{
	velocidadeX = 0;
	velocidadeY = 0;
	vidas = -1;
}

Entidades::Personagens::Personagem::~Personagem() {
	vidas = -1;
}

void Entidades::Personagens::Personagem::setVidas(int vid) {
	vidas = vid;
}

void Entidades::Personagens::Personagem::setVelocidae(float vX, float vY) {
	velocidadeX = vX;
	velocidadeY = vY;
}

float Entidades::Personagens::Personagem::getVelocidadeX() {
	return velocidadeX;
}

float Entidades::Personagens::Personagem::getVelocidadeY() {
	return velocidadeY;
}
void Entidades::Personagens::Personagem::operator--() {
	vidas--;
}

float Entidades::Personagens::Personagem::atualizaDelta() {

	float deltaTimeAtual = relogio.restart().asSeconds();
	float minimoDeltaTime = 0.0667f;
	float maximoDeltaTime = 0.0167f;

	deltaTimeAtual = std::max(deltaTimeAtual, minimoDeltaTime);  // Limita para não ser menor que 15 FPS
	deltaTimeAtual = std::min(deltaTimeAtual, maximoDeltaTime);  // Limita para não ser maior que 60 FPS

	return deltaTimeAtual;
}


const float Entidades::Personagens::Personagem::gravidade = 9.8;