#include "Jogador.h"

Jogador::Jogador(int id, int vids, float vlX, float vlY, const char* png) :
	Personagem(id, png, vids, vlX, vlY)
{
	pontos = 0;
	noChao = 1;
	wPress = 0;
	relogio.restart();
	impulso = 600;
	setCorpo(875, 775);
}

Jogador::~Jogador() {
}

void Jogador::mover(float aux){
	if (!noChao)
	{

		velocidadeY += static_cast<float>(gravidade) * atualizaDelta();
		if ((corpo.getPosition().y + velocidadeY) > 775) {
			velocidadeY = 775 - corpo.getPosition().y;
		}

		if (!wPress && velocidadeY < 0) {

			if (velocidadeY < 0) {
				velocidadeY = 0;
			}

			wPress = 1;

			mover(aux);
		}

		corpo.move(aux, velocidadeY);

		if (corpo.getPosition().y >= 775){
			noChao = 1;
			velocidadeY = 0;

		}
	}
		else {
			corpo.move(aux, 0);
		}


}

void Jogador::processaEvento() {
	Event event;
	while (pgenGrafico->window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			pgenGrafico->window.close();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		mover(atualizaDelta() * velocidadeX);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		mover(atualizaDelta() * -velocidadeX);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if (noChao) {
			velocidadeY = -impulso * atualizaDelta();
			noChao = 0;
			wPress = 1;
		}
		mover(0);
	}
	else {
		wPress = 0;
		mover(0);
	}
}

float Jogador::atualizaDelta(){

	float deltaTimeAtual = relogio.restart().asSeconds();
	float minimoDeltaTime = 0.0667f;
	float maximoDeltaTime = 0.0167f;

	deltaTimeAtual = std::max(deltaTimeAtual, minimoDeltaTime);  // Limita para não ser menor que 15 FPS
	deltaTimeAtual = std::min(deltaTimeAtual, maximoDeltaTime);  // Limita para não ser maior que 60 FPS

	return deltaTimeAtual;
}

void Jogador::executar() {
	pgenGrafico->renderiza(corpo);
	processaEvento();
}

