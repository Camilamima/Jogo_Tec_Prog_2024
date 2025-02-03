#pragma once
#include "Inimigo.h"
#include "../Projetil.h"
#include "../Listas/Lista.h"
#include "Efeitos.h"
#include <set>

namespace Personagens {
	class Chefao : public Inimigo
	{
	private:
		//Listas::Lista<Projetil*>* ListProj;//transformar em um set
		std::set<Projetil*> ListProj;
		int danoProjetil;
		//int qnt_projetil;
		bool turno;
		Clock relogio1;
		Clock relogio2;
		Clock relogioProjetil;
		int cont;
		int val;
		Efeito* teletransporte;
		bool fim_animacao;
		
	public:
		Chefao(int id, const char* png = "assets/chefao/Agis.png");
		~Chefao();
		void setTeletransporte(Efeito* tp) { teletransporte = tp; }
		void executar();
		void teletransportar();
		void criaProjeteis(Projetil* proj);
		void apagaProjetil();
		void animacao(int limite);
		void animacaoTp(int limite);
	};
}