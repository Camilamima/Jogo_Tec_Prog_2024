#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
using namespace sf;
class Gerenciado_Grafico
{	
public: 
	RenderWindow window;
	Gerenciado_Grafico();
	~Gerenciado_Grafico();
	bool estaAberta();      
	void clear();
	void desenha(const RectangleShape& retangulo);
	void mostrar();
	void fechar();
};

