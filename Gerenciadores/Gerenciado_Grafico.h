#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
using namespace sf;
namespace Gerenciadores {
	class Gerenciado_Grafico
	{
	private:
		View camera;
	public:
		RenderWindow window;
		Gerenciado_Grafico();
		~Gerenciado_Grafico();
		const bool estaAberta() const;
		void arrumaCamera(float x);
		void clear();
		void desenha(const RectangleShape& retangulo);
		void mostrar();
		void fechar();
	};
}

