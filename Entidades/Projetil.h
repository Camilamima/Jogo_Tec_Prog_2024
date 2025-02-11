#pragma once
#include "Entidade.h"
#include "../Personagens/Heroi.h"
namespace Entidades {
	class Projetil : public Entidade {
	private:
		//int segue;
		float velocidadeX;
		float velocidadeY;
		float posX;
		float posY;
		bool noChao;
		float chao;
		bool seguindo;
		bool seguiu;
		bool apareceu;
		Clock relogioVida;//relogio para dar dano
		int cont;//cont para animacao
		int val;//cont para animacao
		bool apagado;
		static const float gravidade;
		static const float forcaMistica;//forca que atua para eliminar a gravidade

	public:
		Projetil(int id, const char* png = "assets/proj/1.png");
		~Projetil();
		void executar();
		//void realiza();
		//void setAtivo(int ativo1) { segue = ativo1; }
		//int getAtivo() const { return segue; }
		bool getNoChao() const { return noChao; }
		void setNoChao(bool noChao1) { noChao = noChao1; }
		void setSeguindo(bool x) { seguindo = x; }
		void setSeguiu(bool x) { seguiu = x; }
		bool getSeguindo() const { return seguindo; }
		bool getApareceu() const { return apareceu; }
		void setApareceu(bool x) { apareceu = x; }
		bool segueQuem(Personagens::Heroi* jog);
		void setVelocidade(float x, float y);
		float getVelocidadeX() const { return velocidadeX; }
		float getVelocidadeY() const { return velocidadeY; }
		void setApagado(bool x) { apagado = x; }
		bool getApagado() { return apagado; }
		void moverSeguindo(float aux);
		void mover(float aux = 0);
		float atualizaFPS();
		void seguir(float x_alvo, float y_alvo);
		void danifica(Personagens::Heroi* jog);
		void animacao(int limite);
		void setChao(float x) { chao = x; }
		void setXY(float x1, float y1) { posX = x1; posY = y1; }
		void setCont(int a) { cont = a; }
		void setVal(int a) { val = a; }
		json salvar() const;
	};
}
