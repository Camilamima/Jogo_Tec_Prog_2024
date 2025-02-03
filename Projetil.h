#pragma once
#include "Entidade.h"
#include "Personagens/Slime.h"

class Projetil : public Entidade {
private:
	int segue;
	float velocidadeX;
	float velocidadeY;
	float posX;
	float posY;
	bool noChao;
	float chao;
	bool seguindo;
	bool seguiu;
	bool apareceu;
	Clock relogioVida;
	int cont;
	int val;
	
public:
	Projetil(int id, const char* png = "assets/projetil/1.png");
	~Projetil();
	void executar();
	void realiza();
	void setAtivo(int ativo1) { segue = ativo1; }
	int getAtivo() const { return segue; }
	bool getNoChao() const { return noChao; }
	void setNoChao(bool noChao1) { noChao = noChao1; }
	void setSeguindo(bool x) { seguindo = x; }
	void setSeguiu(bool x) { seguiu = x; }
	bool getSeguindo() const { return seguindo; }
	bool getApareceu() const { return apareceu; }
	void setApareceu(bool x) { apareceu = x; }
	bool segueQuem(Personagens::Slime* jog);
	void setVelocidade(float x, float y);
	float getVelocidadeX() const { return velocidadeX; }
	float getVelocidadeY() const { return velocidadeY; }
	void moverSeguindo(float aux);
	void mover();
	float atualizaFPS();
	void seguir(float x_alvo, float y_alvo);
	void danifica(Personagens::Slime* jog);
	void animacao(int limite);
	void setChao(float x) { chao = x; }
};
