#include "Gerenciado_Grafico.h"
#include <ctime>
#include <algorithm>


Gerenciado_Grafico::Gerenciado_Grafico(){
	window.create(VideoMode(1800, 900), "trabaio",Style::Default); // Cria a janela com o tamanho e título passados
	window.setFramerateLimit(60);
}

Gerenciado_Grafico::~Gerenciado_Grafico() {
}


bool Gerenciado_Grafico::estaAberta() {
	return window.isOpen();
}


void Gerenciado_Grafico::renderiza(const RectangleShape& retangulo){
	window.clear();  
	window.draw(retangulo);
	window.display();
}
void Gerenciado_Grafico::desenha(const RectangleShape& retangulo) {
	window.draw(retangulo);
	window.display();
}
void Gerenciado_Grafico::clear() {
	window.clear();
}