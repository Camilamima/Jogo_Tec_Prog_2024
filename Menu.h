#pragma once
#include "Ente.h"
#define FONTES "assets/Fontes/PixelOperator8-Bold.ttf"
#include <vector>

namespace Fases{
	class Fase;
}

using namespace std;

class Menu : public Ente
{
private:
	Font fonte;
	String nome;
	Text texto;
	Fases::Fase *pfase;
	RectangleShape seta;
	vector<String> nomes;
	vector<Text> textos;
	bool continuar;
	Clock timer;
	int selec;
	int fase;
	int menu;
public:
	Menu(int id,const char *png="assets/pointer.png");
	~Menu();
	const int getFase() const {
		return fase;
	}
	void restartTime() {
		timer.restart();
	}
	const bool getContinuar() const {
		return continuar;
	}
	const int getMenu() const {
		return menu;
	}
	const int getSelect() const {
		return selec;
	}
	void setMenu(int i) {
		menu = i;
	}
	void Pause();
	void setFase(Fases::Fase * f);
	void setaTextos1();
	void setaTextos2();
	void setaTextos3();
	void setaPause();
	void comandos();
	void executar(); 

};

