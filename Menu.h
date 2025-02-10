#pragma once
#include <vector>
#include "Texto.h"

namespace Fases{
	class Fase;
}

using namespace std;

class Menu : public Ente, public Texto 
{
private:
	Font fonte;
	String nome;
	Fases::Fase *pfase;
	RectangleShape seta;
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
	const vector<string> lerScore();
	static void salvaScore(const string& nome, int pontos);
	void Pause();
	void setFase(Fases::Fase * f);
	void setaTextos(int text);
	void comandos();
	void executar(); 

};
