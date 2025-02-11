#pragma once
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
		Texture Fundo;
		Texture Fundo2;
		Sprite sprite;
	public:
		RenderWindow window;
		Gerenciado_Grafico();
		~Gerenciado_Grafico();
		void BackGFloresta(int fase);
		const bool estaAberta() const;
		void arrumaCamera(float x);
		void clear();
		void desenha(const RectangleShape& retangulo);
		void desenha();
		void mostrar();
		void fechar();
	};
}

