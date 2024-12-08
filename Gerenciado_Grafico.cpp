#include "Gerenciado_Grafico.h"
#include <ctime>
#include <algorithm>

#define SPEED_X 500//21 pixel com 0,6 m
#define ALTURA_INICIAL 775
#define GRAVIDADE  7
#define FORCA_PULO  600
#define ALTURA_MAX_PUL 200

Gerenciado_Grafico::Gerenciado_Grafico(){
	wPress = 0;
	velocidadeY = 0.f;
	noChao = 1;
	relogio.restart();
	window.create(VideoMode(1800, 900), "trabaio",Style::Default); // Cria a janela com o tamanho e título passados
	window.setFramerateLimit(60);
	textura.loadFromFile("pngegg.png");
	
}

Gerenciado_Grafico::~Gerenciado_Grafico() {
}

void Gerenciado_Grafico::geraJogador(float x2, float y2) {
	quadrado.setSize(Vector2f(150.f, 150.f));
	quadrado.setTexture(&textura);
	quadrado.setPosition(x2, y2);
	window.draw(quadrado);
}

void Gerenciado_Grafico::movePersonagem() {

}

bool Gerenciado_Grafico::estaAberta() {
	return window.isOpen();
}
void Gerenciado_Grafico::processaEvento(){//provavelmente vai pra classe personagem
									  // ou entidade, conversar melhor sobre isso

	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D)) {
		atualizaFisica(atualizaDelta() * SPEED_X);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		atualizaFisica(atualizaDelta() * -SPEED_X);
	}

	if (Keyboard::isKeyPressed(sf::Keyboard::W)){
			if (noChao) {
				velocidadeY = -FORCA_PULO*atualizaDelta();
				noChao = 0;
				wPress = 1;
			}
			atualizaFisica(0);
	}
	else {
		wPress = 0;
		atualizaFisica(0);
	}
}

void Gerenciado_Grafico::renderiza(){
	window.clear();  
	window.draw(quadrado);
	window.display();
}


float Gerenciado_Grafico::atualizaDelta() {//provavelmente vai pra classe entidade

	float deltaTimeAtual = relogio.restart().asSeconds();
	float minimoDeltaTime = 0.0667f; 
	float maximoDeltaTime = 0.0167f; 

	deltaTimeAtual = std::max(deltaTimeAtual, minimoDeltaTime);  // Limita para não ser menor que 15 FPS
	deltaTimeAtual = std::min(deltaTimeAtual, maximoDeltaTime);  // Limita para não ser maior que 60 FPS

	return deltaTimeAtual;
}


void Gerenciado_Grafico::atualizaFisica(float aux) {//provavermente vai pra classe ente/personagem, n sei
	if (!noChao) 
	{

		velocidadeY += static_cast<float>(GRAVIDADE)*atualizaDelta();
		if ((quadrado.getPosition().y + velocidadeY) > ALTURA_INICIAL) {
			velocidadeY = ALTURA_INICIAL - quadrado.getPosition().y;
		}

		if (!wPress && velocidadeY<0){

			if (velocidadeY < 0) {
				velocidadeY = 0;
			}

			wPress = 1;

			atualizaFisica(aux);
		}

		quadrado.move(aux, velocidadeY);

		if(quadrado.getPosition().y>=ALTURA_INICIAL){
			noChao = 1;
			velocidadeY = 0;

		}
	}
	else {
		quadrado.move(aux, 0);
	}

}