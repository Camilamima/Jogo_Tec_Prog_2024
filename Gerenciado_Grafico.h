#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <ctime>
using namespace sf;
class Gerenciado_Grafico
{
private:
	RectangleShape quadrado;
	RenderWindow window;
	Texture textura;
	Clock relogio;
	bool noChao; //provavelmente sera inserida posteriormente em classes jogador
	float velocidadeY;//provavelmente sera inserida posteriormente na classe jogador
	bool wPress;
	
public:
	Gerenciado_Grafico();
	~Gerenciado_Grafico();
	void geraJogador(float y2, float x2);
	void movePersonagem();
	bool estaAberta();
	void processaEvento();      
	void renderiza();         
	float atualizaDelta();
	void atualizaFisica(float aux);

};

