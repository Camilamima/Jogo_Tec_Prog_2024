#pragma once
#include "Ente.h"
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Texto
{
protected:
	static const char* FONTES;
	vector<String> nomes;
	vector<Text> textos;
	Font fonte;
public:
	Texto();
	~Texto();
	virtual void setaTextos(int text)=0;
	void desenhaTexto(Gerenciadores::Gerenciado_Grafico *G);
	void limpaTextos();
};

