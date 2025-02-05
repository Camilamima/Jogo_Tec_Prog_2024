#pragma once
#include "Ente.h"
#include <nlohmann/json.hpp> // Biblioteca JSON para C++
using json = nlohmann::json;

class Entidade : public Ente
{
protected:
	float x;
	float y;
	RectangleShape corpo;
	Clock relogio;
	static const float gravidade;
public:
	Entidade(int id,const char* png);
	virtual ~Entidade();
	void setTamanhoCorpo(float largura, float altura) {
		corpo.setSize(Vector2f(largura, altura));
	}
	void setCoordenadas(float x1,float y1);
	void setCorpo(float largura, float altura);
	void setSoCorpo(float largura, float altura);
	float getX()const { return x; }
	RectangleShape getCorpo() { return corpo; }
	virtual void executar() = 0;
	virtual json salvar() const = 0;

};

