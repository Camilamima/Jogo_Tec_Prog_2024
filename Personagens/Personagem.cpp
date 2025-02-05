#include "Personagem.h"
#pragma once

namespace Personagens {
	Personagem::Personagem(int id, const char* png) :
		Entidade(id, png)
	{
		moviD = 1;
		moviE = 1;
		vivo = 0;
		noChao = 0;
		chao = 800;
		velocidadeX = 0;
		velocidadeY = 0;
		vidas = 5;
	}

	Personagem::~Personagem() {
		vidas = -1;
	}

	void Personagem::setVidas(int vid) {
		vidas = vid;
	}

	void Personagem::setVelocidae(float vX, float vY) {
		velocidadeX = vX;
		velocidadeY = vY;
	}

	float Personagem::getVelocidadeX() {
		return velocidadeX;
	}

	float Personagem::getVelocidadeY() {
		return velocidadeY;
	}
	void Personagem::operator--() {
		vidas--;
	}

	float Personagem::atualizaDelta() {

		float deltaTimeAtual = relogio.restart().asSeconds();
		float minimoDeltaTime = 0.0667f;
		float maximoDeltaTime = 0.0167f;

		deltaTimeAtual = std::max(deltaTimeAtual, minimoDeltaTime);  // Limita para não ser menor que 15 FPS
		deltaTimeAtual = std::min(deltaTimeAtual, maximoDeltaTime);  // Limita para não ser maior que 60 FPS

		return deltaTimeAtual;
	}
}