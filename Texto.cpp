#include "Texto.h"

Texto::Texto() {
	fonte.loadFromFile(FONTES);
}

Texto::~Texto() {
	
}

void Texto::desenhaTexto(Gerenciadores::Gerenciado_Grafico* G) {
	for (int i = 0; i < textos.size(); i++) {
		G->window.draw(textos[i]);
	}
}

void Texto::limpaTextos() {
	nomes.clear(); 
	textos.clear();
}

const char* Texto::FONTES = "assets/Fontes/Pixeloperator8-Bold.ttf";