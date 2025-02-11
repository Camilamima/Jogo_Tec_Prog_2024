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
		float atrito;
	public:
		Obstaculo(int id, const char* png);
		~Obstaculo();
		virtual void executar() = 0;
		void mover(float aux=0);
		float getAtrito() const {
			return atrito;
		}
		bool getImpede() const { return impede; }
		bool getAtrapalha() const { return atrapalha; }
		bool getDanoso() const { return danoso; }
		virtual void obstacular(Personagens::Slime* jogador,int i=-1) = 0;
		void restaura(Personagens::Slime* jogador);
		virtual json salvar() const = 0;
	};
}