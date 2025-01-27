#include "Gerenciado_Grafico.h"
#include <ctime>
#include <algorithm>

namespace Gerenciadores {
	Gerenciado_Grafico::Gerenciado_Grafico() {
		window.create(VideoMode(1800, 900), "trabaio", Style::Default); // Cria a janela com o tamanho e título passados
		window.setFramerateLimit(60);
		camera = View(sf::FloatRect(0, 0, 1800, 900));
		window.setView(camera);
	}

	Gerenciado_Grafico::~Gerenciado_Grafico() {
	}

	void Gerenciado_Grafico::arrumaCamera(float x) {
		camera = View(sf::FloatRect(x, 0, 1800, 900));
		window.setView(camera);
	}

	const bool Gerenciado_Grafico::estaAberta() const {
		return window.isOpen();
	}

	void Gerenciado_Grafico::desenha(const RectangleShape& retangulo) {
		window.draw(retangulo);
	}

	void Gerenciado_Grafico::mostrar() {
		window.display();
	}

	void Gerenciado_Grafico::clear() {
		window.clear();
	}

	void Gerenciado_Grafico::fechar() {
		window.close();
	}
}