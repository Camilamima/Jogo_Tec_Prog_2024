#include "Entidade.h"

class Personagem : public Entidade {
protected:
	int vidas;
	float velocidadeY;
	float velocidadeX;
	static const float gravidade;
public:
	Personagem(int id,const char* png);
	~Personagem();
	virtual void executar() = 0;
	void setVidas(int vid);
	int getVidas() { return vidas; }
	void operator--();
	void operator*=(int dano) { vidas -= dano; }
	void setVelocidae(float vX, float vY);
	float getVelocidadeX();
	float getVelocidadeY();
};
