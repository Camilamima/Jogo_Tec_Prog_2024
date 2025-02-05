#pragma once
#include "Fases/Fase.h"
#include <vector>
#define FONTES "assets/Fontes/PixelOperator8-Bold.ttf"

class Menu : public Ente
{
private:
	Font fonte;
	String nome;
	Text texto;
	RectangleShape seta;
	vector<String> nomes;
	vector<Text> textos;
	Clock timer;
	int selec;
public:
	Menu(int id,const char *png="assets/pointer.png");
	~Menu();
	void setaTextos();
	void moveSeta();
	void executar() {

		for (int i = 0; i < textos.size(); i++) {
			pGGrafico->window.draw(textos[i]);
		}

		pGGrafico->desenha(seta);
		// Exibir na tela
		pGGrafico->window.display();
		pGGrafico->clear();
		moveSeta();
	}

};

