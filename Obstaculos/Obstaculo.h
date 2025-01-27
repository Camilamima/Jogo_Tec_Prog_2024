#pragma once
#include "../Entidade.h"
#include "../Personagens/Slime.h"

namespace Obstaculos {
	class Obstaculo : public Entidade
	{
	protected:
		bool danoso;
		bool atrapalha;
		bool impede;
		bool acelera;

		float atrito;
		Personagens::Slime* pJogador;

	public:
		Obstaculo(int id, const char* png);
		~Obstaculo();
		virtual void executar() = 0;
		void obstacular(Personagens::Slime* jogador, float atrito) {};
		void setpJogador(Personagens::Slime* jogador) { pJogador = jogador; }
		bool  getImpede() const { return impede; }
		bool getAtrapalha() const { return atrapalha; }
		bool getDanoso() const { return danoso; }
		bool getAcelera() const { return acelera; }
		virtual void obstacular(Personagens::Slime* jogador) = 0;
		void restaura(Personagens::Slime* jogador);
	};
}