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
	float velocidadeY;
	float chao;
	bool noChao;
public:
	Entidade(int id,const char* png);
	virtual ~Entidade();
	void setTamanhoCorpo(float largura, float altura) {
		corpo.setSize(Vector2f(largura, altura));
	}
	const bool getnoChao() const { return noChao; }
	void setChao(const float a) { chao = a; }
	void setNoChao(const float Xao) { noChao = Xao; }
	virtual void mover(float aux=0) = 0;
	void setCoordenadas(float x1,float y1);
	void setCorpo(float largura, float altura);
	void setSoCorpo(float largura, float altura);
	float getX()const { return x; }
	RectangleShape getCorpo() { return corpo; }
	virtual void executar() = 0;
	virtual json salvar() const = 0;

};

