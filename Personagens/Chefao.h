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
		//int danoProjetil; n usei
		bool turno;
		Clock relogio1;
		Clock relogio2;
		Clock relogioProjetil;
		int cont;
		int val;
		//Efeito* teletransporte;
		//bool fim_animacao;
		static const int max_projetil;
		int num_projetil;
		bool ativo;
		int iniZona;
		int finalZona;
		float pos_inicial;
		
	public:
		Chefao(int id, const char* png = "assets/chefao/Agis.png");
		~Chefao();
		//void setTeletransporte(Efeito* tp) { teletransporte = tp; }
		void executar();
		void teletransportar();
		void criaProjeteis(Projetil* proj);
		void apagaProjetil();
		void animacao(int limite);
		//void animacaoTp(int limite);
		static int getMaxProjetil() { return max_projetil; }
		int getNum_Projetil()const { return num_projetil; }
		void operator++();
		bool zonaChefao(Slime* jog);
		void zonaChefao();
		void setAtivo(bool x) { ativo = x; }
		void setPosInicialX(float x) { pos_inicial = x; }
		float getPosInicial() { return pos_inicial; }
		int getFinalZona() { return finalZona; }
		int getIniZona() { return iniZona; }
	};
}